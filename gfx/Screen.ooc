use sdl,gl,glu
import sdl.[Sdl, Video]
import gl.Gl
import glu.Glu

Screen: class {
	x, y, bpp : Int
	title := "Unnamed"
	init: func(=x,=y,=bpp) {
		SDL init(INIT_EVERYTHING)
		setRes(x,y,bpp)
	}
	
	setRes: func(=x,=y,=bpp) {
		SDLVideo setMode(x,y,bpp,OPENGL)
		GL matrixMode( PROJECTION );
		GL loadIdentity();
		GLU perspective(70,x/y as Double,0.001,100);
		GL viewport(0,0,x,y)
		GL enable(DEPTH_TEST);
		//glEnable(GL_TEXTURE_2D);
	}
	
	title: func(=title) {
		SDLVideo wmSetCaption(title, null)
	}
	
	close: func() {
		SDL quit()
	}
	
}
