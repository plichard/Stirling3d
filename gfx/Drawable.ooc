use glew
import glew
import math/Vector3d

Color4ub: class {
	r,g,b,a: UInt32
	init: func(=r,=g,=b,=a) {
	}
}

Drawable: abstract class {
	
	/* Self explanatory =) */
	show := true
	
	/* Draw axes for every drawable?? */
	axes = false : static Bool
	
	pos := Vector3d new(0,0,0)  as Vector3d//position of the drawable
	rot := Vector3d new(0,0,0)  //rotation of the drawable arround the 3 axes
	scl := Vector3d new(1,1,1)  //scale of the drawable
	
	color := Color4ub new(rand() % 254,rand() % 254,rand() % 254,255)
	
	init: func ~drawableAbstract () {
		
	}
	
	/* Function used publicly to draw a drawable */
	draw: func {
		if(show) {
			glPushMatrix()
			/* TODO: Apply rotation and scale */
			glTranslated(pos x, pos y, pos z)
			//printf("calling specific _draw...\n")
			_draw()
			if(axes) {
				_drawAxes()
			}
			glPopMatrix()
		}
	}
	
	/* Function that will be overloaded by every child of Drawable
	 * -> the real drawing function
	 */
	_draw: func {
		printf("Empty drawable trying to display itself, strange...\n")
	}
	
	/* Draws centered axes on local coordinates */
	_drawAxes: func {
		//printf ("Drawing axes...\n")
		/* Code will be added later... */
		glPushMatrix()
		glScaled(5,5,5)
		glBegin(GL_LINES)
			glColor3d(1,0,0)
			glVertex3d(0,0,0) ; glVertex3d(1,0,0)
			glColor3d(0,1,0)
			glVertex3d(0,0,0) ; glVertex3d(0,1,0)
			glColor3d(0,0,1)
			glVertex3d(0,0,0) ; glVertex3d(0,0,1)
		glEnd()
		glPopMatrix()
	}
	
	update: func(t: Int) {
	}
	
}

