use glew, glu
import glew, glu/Glu
import gfx/[Drawable, Particle, FreeFlyCamera, BasicCamera]
import sdl/[Sdl, Video]
import structs/LinkedList
import math/Vector3d

usleep: extern proto func(UInt)

Scene: class {
	drawables := LinkedList<Drawable> new()
	camera : FreeFlyCamera
	clear := true

	init: func(){
		glEnable(GL_BLEND)
		glBlendFunc(GL_SRC_ALPHA,GL_ONE)
		glDisable(GL_DEPTH_TEST)
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE)
		glEnable(GL_COLOR_MATERIAL)
		glColor4f(0.1,0.1,1,0.1)
		//glClearColor(0,0,0,0.01)
		
		
	}
	
	clear: func() {
	}
	
	draw: func(){
		if(clear)
			glClear( GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT )
			
		glClear(GL_DEPTH_BUFFER_BIT)
		glMatrixMode( GL_MODELVIEW )
		glLoadIdentity( )
		camera look()
		
		for(d in drawables) {
			d as Drawable draw()
		}
		
		glFlush()
		SDLVideo glSwapBuffers()
	}
	
	
	update: func {
		iter := drawables iterator()
		while(iter hasNext()) {
			iter next() as Drawable update(1)
		}
	}
	
	add: func(d: Drawable) {
		drawables add(d)
	}
	
}
