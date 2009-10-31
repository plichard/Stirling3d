use glew,glu
import glew,glu/Glu
import math/Vector3d
import gfx/Drawable

Particle: class extends Drawable{
	
	params = null : static Quadric
	
	life := 1000
	vel := Vector3d new(0,0,1) as Vector3d
	force := Vector3d new(0,0,0)
	
	isAlive: func -> Bool {
		if(life > 0){
			return true
		}
		
		life = 0
		return false	
	}
	
	init: func ~lifePosVal (=life, .pos, .vel) {
		this pos = pos clone()
		this vel = vel clone() 
		if(!params){
			params = gluNewQuadric()
		}
		
	}
	
	update: func(t: Int) {
		vel = vel + force / t as Double
		dpos := vel / t as Double
		pos = pos + dpos
		life -= 1
		force set(0,0,0)
	}
	
	addForce: func(f: Vector3d) {
		force = force + f
		//printf("Adding force: (%f,%f,%f)\n",force x, force y, force z)
	}
	
	print: func {
		println()
		printf("life: %d\n",life)
		printf("pos: (%f,%f,%f)\n",pos x, pos y, pos z)
		printf("vel: (%f,%f,%f)\n",vel x, vel y, vel z)
	}
	
	_draw: func {
		//printf("Drawing da sphere!!!")
		gluSphere(params, 5, 10 ,10)
	}
}
