import math.Vector3d

Drawable: /*abstract*/ class {
	
	/* Self explanatory =) */
	show := true
	
	/* Draw axes for every drawable?? */
	axes = false : static Bool
	
	pos := new Vector3d(0,0,0)  //position of the drawable
	rot := new Vector3d(0,0,0)  //rotation of the drawable arround the 3 axes
	scl := new Vector3d(1,1,1)  //scale of the drawable
	
	new: func {
		
	}
	
	/* Function used publicly to draw a drawable */
	draw: func {
		if(show) {
			/* TODO: Apply position, rotation and scale */
			_draw()
			if(axes) {
				_drawAxes()
			}
		}
	}
	
	/* Function that will be overloaded by every child of Drawable
	 * -> the real drawing function
	 */
	_draw: func {
		printf("Drawing something...\n")
	}
	
	/* Draws centered axes on local coordinates */
	_drawAxes: func {
		printf ("Drawing axes...\n")
		/* Code will be added later... */
	}
	
	
}

/*
main: func {
	d1 := new Drawable
	d1 draw()
}*/
