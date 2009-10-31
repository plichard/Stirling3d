use sdl

import structs/[LinkedList, ArrayList]
import Particle
import sdl/Sdl
import Drawable
import math/Vector3d

ParticleGenerator: class extends Drawable{
	
	
	ddt: Int  //Maximum variation of the spawn time (in ms)
	dt: Int  //Spawn time of a particle (in ms)
	life: Int //default life time of the particles
	dlife: Int //Maximum variation of the lifetime 
	vel: Vector3d //Initial velocity of the particles
	dv: Vector3d //Maximum velocity variation  
	pTime,cTime: UInt32
	
	particles := LinkedList <Drawable> new()
	constantForces := LinkedList <Vector3d> new()
	
	init: func {
		setTime(1000,0)
		life = 2000
		setVel(Vector3d new(0,0,1), Vector3d new(0,0,0))
		pTime = cTime = 0
		//printf("vel: %p\n",vel)
		
	}
	
	init: func ~withParams (=life,=dlife,=dt,=ddt,=vel,=dv) {
		print()
		}
	
	print: func {
		printf("\nParticleGenerator params: \n")
		printf("life: %d\n",life)
		printf(" vel: (%f,%f,%f)\n",vel x, vel y, vel z)
		printf("dvel: (%f,%f,%f)\n",dv x, dv y, dv z)
	}
	setTime: func(=dt, =ddt){}
	
	setVel: func(=vel,=dv){}
	
	update: func(t: Int) {
		//printf("Freaking updating ParticleGenerator!!!\n")
		cTime = SDL getTicks()
		applyForces()
		if(cTime - pTime > dt + rand() % ddt - 2*ddt) {
			nvel := vel clone()
			nlife := life
			if(dv x) {
				nvel x = vel x + rand() % (2*dv x as Int) - dv x 
			}
			if(dv y) {
				nvel y = vel y + rand() % (2*dv y as Int) - dv y 
			}
			if(dv z) {
				nvel z = vel z + rand() % (2*dv z as Int) - dv z 
			}
			
			if(dlife) {
				nlife += rand() % dlife -   dlife
			}
			
			
			particles add(Particle new(nlife,pos,nvel))
			
		}
		
		iter := particles iterator()
		while(iter hasNext()) {
			p := iter nextNode()
			p data as Particle update(cTime - pTime)
			if(!(p data as Particle isAlive())) {particles removeNode(p)}
		}
		pTime = cTime
	}
	
	stop: func {
	}
	
	_draw: func {
		//printf("Particle generator operational :)\n")
		iter := particles iterator()
		while(iter hasNext()) {
			iter next() as Particle draw()
		}
	}
	
	addConstantForce: func(f: Vector3d) {
		constantForces add(f)
	}
	
	applyForces: func {
		for(f in constantForces) {
			for(p in particles) {
				p as Particle addForce(f)
			}
		}
	}
}
