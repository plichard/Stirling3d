
use sdl,glew,glu
import glew,ITask,sdl/[Sdl,Event],CGlobalTimer,CInputTask,CKernel,glu/Glu,CFactory,CProduct
import FFCamera
import utils/types
import World
import GameObject
import structs/LinkedList

abs: extern func(...) -> Int

LevelEditor: class extends ITask {
	
	NONE := 0
	GRAB := 1
	SCALE := 2
	ROTATE := 3
	ADDMODEL := 4
	
	currentModelName : Node<String>
	currentModelType : CProduct
	
	//these variables lock directions when editing an object in the world
	grabLock := Int3 new(0,0,0)  //1 means the direction is avlaible
	rotLock := Int3 new(0,0,0)
	sclLock := Int3 new(0,0,0)
	
	camera : FFCamera
	wire := false
	world := World new()
	
	mode := false  //false means that we are in freefly mode, true is edit mode
	editMode := NONE
	backupPos := Double3 new(0,0,0)
	
	
	init: func ~levelEditor {
		super()
	}
	
	
	//this function will cache a model type(mainly used for testing)
	preLoad: func(name: String) {
		printf("Caching %s...\n",name)
		CFactory get() loadStatic(MESH,name)
	}

	start: func -> Bool {
		CInputTask get() regEvent(this)
		
		preLoad("models/midres-notex-monkey.s3d")
		preLoad("models/mountains.s3d")
		preLoad("models/notex-cube.s3d")
		preLoad("models/basic/mod1.s3d")
		preLoad("models/basic/mod2.s3d")
		preLoad("models/basic/mod3.s3d")
		preLoad("models/head.s3d")
		preLoad("models/terrain1.s3d")
		preLoad("models/gun.s3d")
		
		/*for(i in 0..10){
			world add(GameObject new("models/midres-notex-monkey.s3d",Double3 new(rand() % 20 - 10,rand() % 20 - 10,rand() % 20 - 10)))
		}*/
		
		camera = FFCamera new(Double3 new(5,5,5))
		
		//initRandomNumbers()
		glViewport(0,0,1280,800)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()
	    gluPerspective(60, 1280 as Float / 800 as Float, 0.01, 1000)
	    glMatrixMode(GL_MODELVIEW)
	    glLoadIdentity()

		glClearColor(0.0, 0.0, 0.0, 1.0)
		glShadeModel(GL_SMOOTH)
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL)
		
		glRenderMode(GL_RENDER) //the level editor starts in the freefly camera mode, therefore no picking, only rendering
		//glEnable(GL_BLEND)
		//glEnable(GL_FACE_CULL)
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA)
		
		
		glEnable(GL_COLOR_MATERIAL)
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE)
		
		// Lets enable lighting
		glEnable(GL_LIGHTING)
		glEnable(GL_LIGHT0)
		 
		// Create light components
		ambientLight: GLfloat[] = [ 0.2, 0.2, 0.2, 1.0 ]
		diffuseLight: GLfloat[] = [ 0.8, 0.8, 0.8, 1.0 ]
		specularLight: GLfloat[] = [ 0.5, 0.5, 0.5, 1.0 ]
		position: GLfloat[] = [ -1.5, 1.0, -1.0, 1.0 ]
		 
		// Assign created components to GL_LIGHT0
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight)
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight)
		glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight)
		glLightfv(GL_LIGHT0, GL_POSITION, position)
		SDL showCursor(SDL_ENABLE)
		return true
	}
	
	update: func {
		glClearColor(0,0,0,0)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	    glMatrixMode(GL_MODELVIEW)
	    glLoadIdentity()
	    camera update()
		camera look()
	    	   
		glEnable(GL_DEPTH_TEST)
		glDisable(GL_BLEND)
		
		if(wire) {
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE )
		}
		else {
			glPolygonMode( GL_FRONT_AND_BACK, GL_FILL )
		}
		
		world render(GL_RENDER)
		if(editMode == ADDMODEL && currentModelType) {
			glPushMatrix()
			currentModelType render()
			glPopMatrix()
		}
		drawMainAxes()
		drawGridLock()
		
	}
	stop: func {
		CInputTask get() unRegEvent(this)
	}
	
	handleEvent: func(event: Event) {
		match( event type ) {
			case SDL_QUIT => CKernel get() killAllTasks()
			case SDL_KEYDOWN => handleKeyPress( event key keysym)
			case SDL_MOUSEBUTTONUP => handleMouseButton(event)
			case SDL_MOUSEMOTION => handleMotion(event)
			
		}
	}
	
	handleMotion: func(event: Event) {
		if(mode && world picked && editMode == GRAB) {
			mouse := getMouseVector(event motion x,event motion y)
			moveObject(mouse)
		}	
	}
	
	moveObject: func(mouse: Double3) {
		if(grabLock x && grabLock y) {
			t : Double = (world picked position z-camera position z)/(mouse z-camera position z)
			Mx : Double = t*(mouse x-camera position x)+ camera position x
			My : Double = t*(mouse y-camera position y)+ camera position y
			Mz : Double = world picked position z
			world picked position = [Mx,My,Mz]
		}
		else if(grabLock x && grabLock z) {
			t : Double = (world picked position y-camera position y)/(mouse y-camera position y)
			Mx : Double = t*(mouse x-camera position x)+ camera position x
			My : Double = world picked position y
			Mz : Double = t*(mouse z-camera position z)+ camera position z
			world picked position = [Mx,My,Mz]
		}
		else if(grabLock y && grabLock z) {
			t : Double = (world picked position x-camera position x)/(mouse x-camera position x)
			Mx : Double = world picked position x
			My : Double = t*(mouse y-camera position y)+ camera position y
			Mz : Double = t*(mouse z-camera position z)+ camera position z
			world picked position = [Mx,My,Mz]
		}
		else if(grabLock x) {
			t : Double = (world picked position z-camera position z)/(mouse z-camera position z)
			Mx : Double = t*(mouse x-camera position x)+ camera position x
			My : Double = world picked position y
			Mz : Double = world picked position z
			world picked position = [Mx,My,Mz]
		}
		else if(grabLock y) {
			t : Double = (world picked position z-camera position z)/(mouse z-camera position z)
			Mx : Double = world picked position x
			My : Double = t*(mouse y-camera position y)+ camera position y
			Mz : Double = world picked position z
			world picked position = [Mx,My,Mz]
		}
		else if(grabLock z) {
			t : Double = (world picked position x-camera position x)/(mouse x-camera position x)
			Mx : Double = world picked position x
			My : Double = world picked position y
			Mz : Double = t*(mouse z-camera position z)+ camera position z
			world picked position = [Mx,My,Mz]
		}
		
	}
	
	handleMouseButton: func(event: Event) {
		match(event button button) {
			case SDL_BUTTON_LEFT => {
				if(editMode == GRAB) {
					editMode = NONE
					grabLock = [0,0,0]
					rotLock  = [0,0,0]
					sclLock  = [0,0,0]
				} else if(editMode == NONE){
					world picking(event motion x,event motion y,camera)
				} else if(editMode == ADDMODEL && currentModelName) {
					editMode = NONE
					world add(GameObject new(currentModelName data,Double3 new(0,0,0)))
				}
			}
			case SDL_BUTTON_WHEELUP => {
				if(editMode == ADDMODEL && currentModelName) {
					if(currentModelName next) {
						currentModelName = currentModelName next
						currentModelType = CFactory get() loadStatic(MESH,currentModelName data)
					} else if(CFactory get() names size > 0) {
						currentModelName = CFactory get() names first
						currentModelType = CFactory get() loadStatic(MESH,currentModelName data)
					}
				}
			}
		}
	}
	
	handleKeyPress: func(keysym: Keysym) {
		match (keysym sym ) {
			case SDLK_q => CKernel get() killAllTasks()
			case SDLK_t => wire = !wire
			case SDLK_p => world save("world_save_2.dat")  //why p? because it's nicely right to o =)
			case SDLK_o => world load("world_save_2.dat") //or "'O'pen"
			case SDLK_g => {
				grabLock = [0,0,0]
				rotLock  = [0,0,0]
				sclLock  = [0,0,0]
				if(mode) {
					editMode = GRAB
					if(world picked) {
						backupPos = Double3 new(world picked position)
					}
				}
			}
			case SDLK_s => {
				if(mode) {
					editMode = SCALE
				}
			}
			case SDLK_r => {
				if(mode) {
					editMode = ROTATE
				}
			}
			case SDLK_ESCAPE => {
				editMode = NONE
				if(world picked)
					world picked position = backupPos
				currentModelName = null
				currentModelType = null
			}
			case SDLK_x => {grabLock x = !grabLock x;rotLock x = !rotLock x;sclLock x = !sclLock x}
			case SDLK_y => {grabLock y = !grabLock y;rotLock y = !rotLock y;sclLock y = !sclLock y}
			case SDLK_z => {grabLock z = !grabLock z;rotLock z = !rotLock z;sclLock z = !sclLock z}
			
			case SDLK_LSHIFT => {
				mode = !mode 
				camera enabled = !(camera enabled)
				 if(!mode){
					 SDL showCursor(SDL_DISABLE)  //freefly mode, do not show the now useless cursor
					 editMode = NONE
					 
				 }
				else {
					SDL showCursor(SDL_ENABLE)  //show the cursor for editing
					editMode = NONE
					grabLock = [0,0,0]
					rotLock  = [0,0,0]
					sclLock  = [0,0,0]
				}
			}
			case SDLK_a => {
				if(mode){
					editMode = ADDMODEL
					currentModelName = CFactory get() names first
					currentModelType = CFactory get() loadStatic(MESH,currentModelName data)
				}
			}
		}
		
	}
	
	drawGridLock: func {
		if(!mode)
			return
			
		match(editMode) {
			case GRAB => {
				if(world picked) {
					if(grabLock x && grabLock y && grabLock z) {
					}
					else if(grabLock x && grabLock y) {
						drawGrid(world picked position,Double3 new(0,0,0),Double3 new(1,1,1))  //world xy plane
					}
					else if(grabLock x && grabLock z) {
						drawGrid(world picked position,Double3 new(1,0,0),Double3 new(1,1,1))  //world xz plane
					}
					else if(grabLock y && grabLock z) {
						drawGrid(world picked position,Double3 new(0,1,1),Double3 new(1,1,1))  //world yz plane
					}
					else if(grabLock x || grabLock y || grabLock z) {
						drawAxis(world picked position,Double3 new(0,0,0),Double3 new(1,1,1))
					}
						
				}
			}
			
		}
	}
	
	drawMainAxes: func {
		glPushMatrix()
		glBegin(GL_LINES)
			glColor3ub(128,0,0)
			glVertex3d(-50,0,0)
			glColor3ub(255,0,0)
			glVertex3d(50,0,0)
			
			glColor3ub(0,128,0)
			glVertex3d(0,-50,0)
			glColor3ub(0,255,0)
			glVertex3d(0,50,0)
			
			glColor3ub(0,0,128)
			glVertex3d(0,0,-50)
			glColor3ub(0,0,255)
			glVertex3d(0,0,50)
		glEnd()
		glPopMatrix()
	}
	
	drawAxis: func(pos,rot,scl:Double3) {
		glPushMatrix()
		glTranslated(pos x, pos y, pos z)
		if(rot x) {
			glRotated(90,1, 0, 0)
		}
		if(rot y) {
			glRotated(90,0, 1, 0)
		}
		if(rot z) {
			glRotated(90,0, 0, 1)
		}
		glBegin(GL_LINE_STRIP)
			if(grabLock x) {
				glColor3ub(128,0,0)
				glVertex3d(-100,0,0)
				glVertex3d(-10,0,0)
				
				glColor3ub(255,0,0)
				glVertex3d(0,0,0)
				
				glColor3ub(128,0,0)
				glVertex3d(10,0,0)
				glVertex3d(100,0,0)
			} 
			if(grabLock y) {
				glColor3ub(0,128,0)
				glVertex3d(0,-100,0)
				glVertex3d(0,-10,0)
				
				glColor3ub(0,255,0)
				glVertex3d(0,0,0)
				
				glColor3ub(0,128,0)
				glVertex3d(0,10,0)
				glVertex3d(0,100,0)
			}
			if(grabLock z) {
				glColor3ub(0,0,128)
				glVertex3d(0,0,-100)
				glVertex3d(0,0,-10)
				
				glColor3ub(0,0,255)
				glVertex3d(0,0,0)	
						
				glColor3ub(0,0,128)
				glVertex3d(0,0,10)
				glVertex3d(0,0,100)
			}
				
		glEnd()
		glPopMatrix()
	}
	
	drawGrid: func(pos,rot,scl: Double3) {
		glPushMatrix()
		glTranslated(pos x, pos y, pos z)
		if(rot x) {
			glRotated(90,1, 0, 0)
		}
		if(rot y) {
			glRotated(90,0, 1, 0)
		}
		if(rot z) {
			glRotated(90,0, 0, 1)
		}
		glScaled(scl x, scl y, scl z)
		
		glBegin(GL_LINES)
			/*for(i in (-50)..51) {
				glColor3ub(64,64,64)
				glVertex3d(-50,i,-0.01)
				glVertex3d(50,i,-0.01)
			}*/
			
			/*for(i in 6..51) {
				glColor3ub(64,64,64)
				glVertex3d(-50,i,0)
				glVertex3d(50,i,0)
			}*/
			
			/*for(i in (-50)..51) {
				glColor3ub(64,64,64)
				glVertex3d(i,-50,-0.01)
				glVertex3d(i,50,-0.01)
			}*/
			
			/*for(i in 6..51) {
				glColor3ub(64,64,64)
				glVertex3d(i,-50,0)
				glVertex3d(i,50,0)
			}*/
			
			for(i in (-4)..5) {
				glColor3ub(64,64,64)
				glVertex3d(-5,i,0)
				
				glColor3ub(255,255,255)
				glVertex3d(0,i,0)
				glVertex3d(0,i,0)
				
				glColor3ub(64,64,64)
				glVertex3d(5,i,0)
			}
			
			for(i in (-4)..5) {
				glColor3ub(0,0,0)
				glVertex3d(i,-5,0)
				
				glColor3ub(255,255,255)
				glVertex3d(i,0,0)
				glVertex3d(i,0,0)
				
				glColor3ub(0,0,0)
				glVertex3d(i,5,0)
			}
		glEnd()
		glEnable(GL_BLEND)	
			glColor4ub(255,255,255,64)
			glBegin(GL_QUADS)
				glVertex3d(-5,-5,0)
				glVertex3d(-5,5,0)
				glVertex3d(5,5,0)
				glVertex3d(5,-5,0)
			glEnd()
		glDisable(GL_BLEND)
		
		glPopMatrix()
	}
	
	getMouseVector: func(mousex,mousey: Int) -> Double3 {
		Bx,By,Bz: GLdouble
		viewport: GLint[4]
		mvmatrix: GLdouble[16]
		projmatrix : GLdouble[16]
		glGetDoublev(GL_MODELVIEW_MATRIX,mvmatrix )
		glGetDoublev(GL_PROJECTION_MATRIX,projmatrix )
		glGetIntegerv(GL_VIEWPORT,viewport )
		gluUnProject(mousex,viewport[3]-mousey,0, mvmatrix, projmatrix,viewport,Bx&,By&,Bz&)
		return Double3 new(Bx,By,Bz)
	}
}
