use gl,glu,sdl
import gl/Gl
import glu/Glu
import gfx/[Drawable, Particle]
import sdl/[Sdl, Video]

usleep: extern proto func(UInt)

Scene: class {
	d1: Drawable
	init: func(){
		
	}
	
	clear: func() {
	}
	
	draw: func(){
		GL clear( COLOR_BUFFER_BIT | DEPTH_BUFFER_BIT )
		GL matrixMode( MODELVIEW )
		GL loadIdentity( )
		GLU lookAt(20,20,20,0,0,0,0,0,1)
		
		if(d1){
			d1 draw()
			printf("d1 show=%s\n",d1 show repr())
			printf("d1 draw()...\n")
		}
		
		
		GL flush()
		SDLVideo glSwapBuffers()
	}
	
	loop: func {
		while(true){
			(d1 as Particle) update()
			draw()
			d1 pos print()
			usleep(30000)
		}
	}
	
	add: func(d: Drawable){
		d1 = d
	}
	
}
