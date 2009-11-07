use sdl,glew,glu
import sdl/[Sdl, Video]
import glew
import glu/Glu

Screen: class {
	x, y, bpp, flags : Int
	title := "Unnamed"
	
	lightAmbient : Double* = [0.5, 0.5, 0.5, 1.0]
	lightDiffuse : Double* = [1.0, 1.0, 1.0, 1.0]
	lightPos : Double* = [0.0, 0.0, 2.0, 1.0]
	
	 no_mat : Double* = [0.0, 0.0, 0.0, 1.0]
     mat_ambient : Double* = [0.7, 0.7, 0.7, 1.0]
     mat_ambient_color : Double* = [0.8, 0.8, 0.2, 1.0]
     mat_diffuse : Double* = [0.1, 0.5, 0.8, 1.0]
     mat_specular : Double* = [1.0, 1.0, 1.0, 1.0]
     no_shininess : Double = 0.0
     low_shininess : Double = 5.0
     high_shininess : Double = 100.0
     mat_emission : Double* = [0.3, 0.2, 0.2, 0.0]
	
	
	init: func(=x,=y,=bpp,=flags) {
		SDL init(SDL_INIT_EVERYTHING)
		setRes(x,y,bpp,flags)
	}
	
	setRes: func(=x,=y,=bpp,=flags) {
		SDLVideo setMode(x,y,bpp,flags)
		glMatrixMode(GL_PROJECTION )
		glLoadIdentity()
		gluPerspective(70,x/y as Double,0.001,1000)
		glViewport(0,0,x,y)
		//glEnable(GL_TEXTURE_2D);
		SDL enableKeyRepeat(10, 10)
		glShadeModel(GL_SMOOTH)
		
		glLightfv(GL_LIGHT0, GL_AMBIENT,lightAmbient)
		//glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse)
		//glLightfv(GL_LIGHT0, GL_POSITION,lightPos)
		
		/*
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient)
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse)
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular)
        glMaterialf(GL_FRONT, GL_SHININESS, low_shininess)
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission)
        */
 
		
		glEnable(GL_LIGHT0)
		glEnable(GL_LIGHTING)
	}
	
	
	title: func(=title) {
		SDLVideo wmSetCaption(title, null)
	}
	
	setMode: func(=x,=y,=bpp,=flags) {
		SDLVideo setMode(x,y,bpp,flags)
	}
	
	close: func() {
		SDL quit()
	}
	
}
