use sdl,glew,glu
import glew,ITask,sdl/[Sdl,Event],CGlobalTimer,CInputTask,CKernel,glu/Glu,CFactory,CProduct
import FFCamera
import utils/types

Functions: class extends ITask {
	camera : FFCamera
	init: func ~functions {
		super()
	}
	
	start: func -> Bool {
		CInputTask get() regEvent(this)
		camera = FFCamera new(Double3 new(5,5,5))
		glViewport(0,0,1280,800)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()
	    gluPerspective(60, 1280 as Float / 800 as Float, 0.01, 1000)
	    glMatrixMode(GL_MODELVIEW)
	    glLoadIdentity()

		glClearColor(0.0, 0.0, 0.0, 1.0)
		glShadeModel(GL_SMOOTH)
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL)
		return true
	}
	
	update: func {
		glClearColor(0,0,0,0)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	    glMatrixMode(GL_MODELVIEW)
	    glLoadIdentity()
	    camera update()
		camera look()
		drawMainAxes()
	}
	
	stop: func {
		CInputTask get() unRegEvent(this)
	}
	
	handleEvent: func(event: Event) {
		match( event type ) {
			case SDL_QUIT => CKernel get() killAllTasks()
			case SDL_KEYDOWN => handleKeyPress( event key keysym)
			//case SDL_MOUSEBUTTONUP => handleMouseButton(event)
			case SDL_MOUSEMOTION => handleMotion(event)
			
		}
	}
	
	handleMotion: func(event: Event) {
	}
	
	
	handleKeyPress: func(keysym: Keysym) {
		match (keysym sym ) {
			case SDLK_q => CKernel get() killAllTasks()
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
	
	drawXYtoZ: func(mx,my,px,py,step: Float) {
		glBegin(GL_LINES)
		for(x := mx; x < px ; x += step) {
			for(y := my; y < py ; y += step) {
				glColor3f((px - my))
					
				
			}
		}
	}
}
