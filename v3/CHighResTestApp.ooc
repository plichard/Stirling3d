
use sdl,glew,glu
import glew,ITask,sdl/Event,CGlobalTimer,CInputTask,CKernel,glu/Glu,CFactory,CProduct

abs: extern func(...) -> Int

CHighResTestApp: class extends ITask {
	
	monkey : StaticMesh
	wire := false
	
	init: func ~cpongtask {
		super()
	}

	start: func -> Bool {
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
		glEnable(GL_BLEND)
		//glEnable(GL_FACE_CULL)
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA)
		
		monkey = CFactory get() loadStatic(MESH,"models/notex-cube.s3d")
		monkey prepare()
		return true
	}
	
	update: func {
		glClear(GL_COLOR_BUFFER_BIT)
	    glMatrixMode(GL_MODELVIEW)
	    glLoadIdentity()
	    gluLookAt(2,2,2,0,0,0,0,1,0)
	    
	    if(CInputTask get() keyDown(SDLK_t)) {
			wire = !wire
		}
		
		if(CInputTask get() mouseDown(SDL_BUTTON_LEFT))CKernel get() killAllTasks()
		//glEnable(GL_LIGHTING)
		
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
	}
}
