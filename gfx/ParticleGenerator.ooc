use sdl
import structs/[LinkedList, ArrayList]
import Particle
import sdl/Sdl
import Drawable
import math/Vector3d
import BasicCamera

/*
Quadric: cover from GLUquadric*
gluNewQuadric: extern func(...) -> Quadric
gluSphere: extern func(...)
*/

ParticleGenerator: class extends Drawable{
	
	
	ddt: Int  //Maximum variation of the spawn time (in ms)
	dt: Int  //Spawn time of a particle (in ms)
	life: Int //default life time of the particles
	dlife: Int //Maximum variation of the lifetime 
	vel: Vector3d //Initial velocity of the particles
	dv: Vector3d //Maximum velocity variation  
	fertileTime := -1.0
	pTime,cTime: UInt32
	lastSpawn = 0 : UInt32
	initTime : UInt32
	//params := gluNewQuadric()
	
	particles := LinkedList <Particle> new()
	constantForces := LinkedList <Vector3d> new()
	functions := LinkedList <Pointer> new()
	
	particleCamera := BasicCamera new()
	
	speed = 1 : Double
	
	ended := false
	
	getParticleCamera: func() -> BasicCamera{
		cam := BasicCamera new()
		particles add(Particle new(600000,pos + Vector3d new(1.0,1.0,1.0),Vector3d new(0,0,0)))
		particles get(0) as Particle pshow = false
		cam position = particles get(0) as Particle pos
		cam target = particles get(0) as Particle vel
		return cam
	}
	
	
	init: func {
		setTime(1000,0)
		life = 2000
		setVel(Vector3d new(0,0,1), Vector3d new(0,0,0))
		pTime = cTime = 0
		//printf("vel: %p\n",vel)
		
	}
	
	init: func ~withParams (=life,=dlife,=dt,=ddt,=vel,=dv,=fertileTime) {
		print()
		initTime = SDL getTicks()
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
		cTime = SDL getTicks()
		applyForces()
		applyFunctions()
		if(cTime - initTime < fertileTime || fertileTime == -1) {
		
			if(cTime - lastSpawn > (dt + rand() % (2*ddt) - ddt)) {
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
				
				
				particles add(Particle new(nlife,pos + Vector3d new(1.0,1.0,1.0),nvel))
				lastSpawn = cTime
				
			}
		} else {
			
			if(!ended) {
				printf("Particle generation ended after %d seconds, n = %d\n",fertileTime / 1000 ,particles size())
				ended = true
			}
		}
		
		iter := particles iterator()
		while(iter hasNext()) {
			p := iter nextNode()
			p data as Particle update(((cTime - pTime) as Double) * speed)
			if(!(p data as Particle isAlive())) {particles removeNode(p)}
		}
		pTime = cTime
	}
	
	stop: func {
	}
	
	_draw: func {
		iter := particles iterator()
		//gluSphere(params, 10, 10 ,10)
		while(iter hasNext()) {
			iter next() draw()
		}
	}
	
	addConstantForce: func(f: Vector3d) {
		constantForces add(f)
	}
	
	addTornade: func(axe: Vector3d) {
		for(p in particles) {
			p addForce((axe ^ (p pos / p pos length())) * 15)
		}
	}
	
	addFunction: func(f: Func(Particle)) {
		functions add(f)
	}
	
	applyForces: func {
		tempForce := Vector3d new(0,0,0)
		for(f in constantForces) {
			tempForce = tempForce + f
		}
		for(p in particles) {
			p addForce(tempForce)
		}
	}
	
	applyFunctions: func {
		for(f: Func in functions) {
			for(p in particles) {
				f(p)
			}
		}
	}
	
	
}
