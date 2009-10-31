
use sdl
import sdl/[Event, Sdl]
import math/Vector3d

gluLookAt: extern func(...)

Mouse: cover {
	x,y: Double
}

Camera: class {
	SPEED = 1 : const Double
	theta = 0, phi = PI/2.0: Double // vertical and horizonal orientation angles
	
	first := true
	
	p,l,u,s: Vector3d
	
	init: func(=p,=theta,=phi,=u) {
		
		l = Vector3d new(0,0,0)
		s = Vector3d new(0,0,0)
	}
	
	call: func(e: Event) {
		match(e type) {	
			case SDL_KEYDOWN => match (e key keysym sym)
				{
				case SDLK_w =>	printf("key up!!\n")
					moveForward(SPEED)
					
				case SDLK_s => printf("key down!!\n")
					moveForward(-SPEED)
					
				case SDLK_a => printf("key left!!\n")
					p y += SPEED
					
				case SDLK_d => printf("key right!!\n")
					p y -= SPEED
					
				case SDLK_LEFT =>
					//rotate(-0.1)
					
				case SDLK_RIGHT =>
					//rotate(0.1)
					
					
				case SDLK_ESCAPE =>
					exit(0)
					
				} 
			case SDL_MOUSEMOTION =>
				rotate(e motion xrel, e motion yrel)
				
		}
		
		
	}
	
	moveForward: func(speed: Double) {
		setDirection()
		p = p + s * speed
		l = p + s
		printf("pos: (%f,%f,%f)\n",p x, p y, p z)
	}
	
	moveSide: func(speed: Double) {
		setDirection()
	}
	
	rotate: func(x,y: Int) {
		theta -= x / 180.0
		phi += y / 180.0
		setDirection()
		l = p + s
		printf("===================\n")
		printf("theta = %f\n",theta)
		//phi += r y / 180.0
		printf("   pos: "); p print()
		printf("lookAt: "); l print()
	}
	
	setDirection: func {
		printf("[setdirection]\n")
		printf("cos(theta) = %f\n",cos(theta))
		printf("sin(theta) = %f\n",sin(theta))
		printf("cos(phi)   = %f\n",cos(phi))
		s x = sin(phi) * cos(theta)
		s y = sin(phi) * sin(theta)
		s z = cos(phi)
	}
	
	lookAt: func {
		gluLookAt(p x,p y,p z,l x,l y,l z,u x,u y,u z)
	}
}
