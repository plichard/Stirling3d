use glew,glu
import glew,glu/Glu
import gfx/[Drawable, Particle]
import sdl/[Sdl, Video]
import structs/LinkedList

usleep: extern proto func(UInt)

Scene: class {
	drawables := LinkedList<Drawable> new()
	
	init: func(){
	}
	
	clear: func() {
	}
	
	draw: func(){
		glClear( GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT )
		glMatrixMode( GL_MODELVIEW )
		glLoadIdentity( )
		gluLookAt(100,0,0,0,0,0,0,0,1)
		
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
