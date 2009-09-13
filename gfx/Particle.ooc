use gl
import gl.Gl
import math.Vector3d

Particle: class {
	
	life := 1000
	pos := Vector3d new(0,0,0)
	vel := Vector3d new(0,0,4)
	
	isAlive: func -> Bool {
		if(life > 0)
			return true
		else{
			life = 0
			return false
		}
	}
	
	init: func(=life, =pos, =vel) {
	}
	update: func {
		pos = pos + vel
		life-=1
	}
}
