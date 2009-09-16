use gl,glu
import gl.Gl
import glu.Glu
import math.Vector3d
import gfx.Drawable

Particle: class extends Drawable{
	
	params = null : static Quadric
	
	life := 1000
	vel := Vector3d new(0,0,4) as Vector3d
	
	isAlive: func -> Bool {
		if(life > 0){
			return true
		}
		
		life = 0
		return false	
	}
	
	init: func ~lifePosVal (=life, =pos, =vel) {
		if(!params){
			params = GLU newQuadric()
		}
	}
	
	update: func {
		pos = pos + vel
		life-=1
	}
	
	_draw: func {
		printf("Drawing da sphere!!!")
		GLU sphere(params, 1, 10 ,10)
	}
}
