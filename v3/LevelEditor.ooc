
use sdl,glew,glu
import glew,ITask,sdl/[Sdl,Event],CGlobalTimer,CInputTask,CKernel,glu/Glu,CFactory,CProduct
import FFCamera
import utils/types
import World
import GameObject

abs: extern func(...) -> Int

LevelEditor: class extends ITask {
	
	camera : FFCamera
	wire := false
	world := World new()
	
	mode := false  //false means that we are in freefly mode, true is edit mode
	
	
	init: func ~levelEditor {
		super()
	}

	start: func -> Bool {
		CInputTask get() regEvent(this)
		
		world add(GameObject new("models/midres-notex-monkey.s3d",Double3 new(3,0,-5)))
		
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
		//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA)
		
		
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
		SDL showCursor(SDL_DISABLE)
		return true
	}
	
	update: func {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	    glMatrixMode(GL_MODELVIEW)
	    glLoadIdentity()
	    camera update()
		//camera look()
	    	   
		glEnable(GL_DEPTH_TEST)
		glDisable(GL_BLEND)
		
		if(wire) {
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE )
		}
		else {
			glPolygonMode( GL_FRONT_AND_BACK, GL_FILL )
		}
		
		world render(GL_RENDER)
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
		world picking(event motion x,event motion y,camera)
	}
	
	handleMouseButton: func(event: Event) {
		match(event button button) {
			case SDL_BUTTON_LEFT => {printf("click at (%d,%d)\n",event motion x, event motion y);world picking(event motion x,event motion y,camera)}
		}
	}
	
	handleKeyPress: func(keysym: Keysym) {
		match (keysym sym ) {
			case SDLK_ESCAPE => CKernel get() killAllTasks()
			case SDLK_t => wire = !wire
			case SDLK_p => world save("world_save_2.dat")  //why p? because it's nicely right to o =)
			case SDLK_o => world load("world_save_2.dat") //or "'O'pen"
			case SDLK_LSHIFT => {
				mode = !mode 
				camera enabled = !(camera enabled)
				 if(!mode){
					 SDL showCursor(SDL_DISABLE)  //freefly mode, do not show the now useless cursor
				 }
				else {
					SDL showCursor(SDL_ENABLE)  //show the cursor for editing
				}
			}
		}
		
	}
}
