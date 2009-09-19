use sdl

import math/ChainedList
import Particle
import sdl/Sdl
import Drawable
import math/Vector3d

ParticleGenerator: class extends Drawable{
	
	
	ddt: Double  //Maximum variation of the spawn time (in ms)
	dt: Double  //Spawn time of a particle (in ms)
	vel: Vector3d //Initial velocity of the particles
	dv: Vector3d //Maximum velocity variation  
	//time: UInt32
	
	//particles := ChainedList new()
	
	
	init: func {
		setTime(1000,0)
		setVel(Vector3d new(0,0,1), Vector3d new(0,0,0))
	}
	
	setTime: func(=dt, =ddt){}
	
	setVel: func(=vel,=dv){}
	
	start: func {
		//time = SDL getTicks()
	}
	
	stop: func {
	}
	
	_draw: func {
		printf("Particle generator operational :)\n")
	}
	
}
