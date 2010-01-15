
use sdl,glew,glu
import glew,ITask,sdl/[Sdl,Event],CGlobalTimer,CInputTask,CKernel,glu/Glu,CFactory,CProduct
import FFCamera
import utils/types

abs: extern func(...) -> Int

CHighResTestApp: class extends ITask {
	
	monkey : StaticMesh
	monkey2 : StaticMesh
	camera : FFCamera
	wire := false
	
	init: func ~cpongtask {
		super()
	}

	start: func -> Bool {
		CInputTask get() regEvent(this)
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
		//glEnable(GL_BLEND)
		//glEnable(GL_FACE_CULL)
		//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA)
		
		monkey = CFactory get() loadStatic(MESH,"models/midres-notex-monkey.s3d")
		
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
		
		return true
	}
	
	update: func {
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
		glPushMatrix()
		glCallList(monkey dlist)
		glPopMatrix()
	}
	stop: func {
		CInputTask get() unRegEvent(this)
	}
	
	handleEvent: func(event: Event) {
		match( event type ) {
			case SDL_QUIT => CKernel get() killAllTasks()
			case SDL_KEYDOWN => handleKeyPress( event key keysym)
			
		}
	}
	
	handleKeyPress: func(keysym: Keysym) {
		match (keysym sym )
		{
		case SDLK_ESCAPE => CKernel get() killAllTasks()
		case SDLK_t => wire = !wire
	}
}
