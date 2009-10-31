use sdl,glew,glu
import sdl/[Sdl, Video]
import glew
import glu/Glu

Screen: class {
	x, y, bpp : Int
	title := "Unnamed"
	init: func(=x,=y,=bpp) {
		SDL init(INIT_EVERYTHING)
		setRes(x,y,bpp)
	}
	
	setRes: func(=x,=y,=bpp) {
		SDLVideo setMode(x,y,bpp,OPENGL)
		glMatrixMode(GL_PROJECTION )
		glLoadIdentity()
		gluPerspective(70,x/y as Double,0.001,1000)
		glViewport(0,0,x,y)
		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_TEXTURE_2D);
	}
	
	title: func(=title) {
		SDLVideo wmSetCaption(title, null)
	}
	
	close: func() {
		SDL quit()
	}
	
}
