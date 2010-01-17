use sdl,glew,glu
import structs/HashMap
import utils/types
import sdl/[Sdl,Event],glew,glu/Glu
import Camera
import CInputTask


FFCamera: class extends Camera {
	speed, sensivity: Double
	phi, theta: Double
	forward := Double3 new(0,0,0)
	left := Double3 new(0,0,0)
	
	kforward := false
	kbackward := false
	kstrafe_left := false
	kstrafe_right := false
	
	keyconf := HashMap<Int> new()
	keystates := HashMap<Bool> new()
	
	enabled := true //shall it receive the events from the mouse and wsad keys?
	
	init: func ~ffCameraInit (.position) {
		super()
		phi = 0
		theta = 0
		this position = position
		vectorsFromAngles()
		
		speed = 1
		sensivity = 0.2
		
		keystates put("forward",false)
		keystates put("backward",false)
		keystates put("strafe_left",false)
		keystates put("strafe_right",false)
		keystates put("boost",false)
		
		///TODO grab input!!!!
		//SDL WM_GrabInput(SDL_GRAB_ON)
		
		target = Double3 new(0,0,0)
		CInputTask get() regEvent(this)
	}
	
	
	
	onMouseMotion: func(e: Motion) {
		theta -= e xrel * sensivity
		phi -= e yrel * sensivity
		vectorsFromAngles()
	}
	
	look: func  {	
		gluLookAt(position x,position y ,position z,
				  target x , target y , target z ,
				  0,0,1)
		//fprintf(stderr,"looking at: (%f,%f,%f) from (%f,%f,%f)\n",target x, target y, target z,position x, position y, position z)
	}
	
	handleEvent: func(event: Event) {
		if(!enabled)
			return
		match(event type) {
			case SDL_MOUSEMOTION => onMouseMotion(event motion)
			case SDL_KEYDOWN => onKeyDown(event key)
			case SDL_KEYUP => onKeyUp(event key)
		}
	}
	
	onKeyDown: func(e: Key) {
		a := e keysym sym
		match(a) {
			case SDLK_w => kforward = true
			case SDLK_s => kbackward = true
			case SDLK_a => kstrafe_left = true
			case SDLK_d => kstrafe_right = true
		}
		
	}
	
	onKeyUp: func(e: Key) {
		a := e keysym sym
		match(a) {
			case SDLK_w => kforward = false
			case SDLK_s => kbackward = false
			case SDLK_a => kstrafe_left = false
			case SDLK_d => kstrafe_right = false
		}
		
	}
	
	setSpeed: func(=speed) {
	}
	
	setSensivity: func(=sensivity) {}
	
	setPosition: func(=position) {}
	
	vectorsFromAngles: func {
		up := Double3 new(0,0,1)
		if(phi > 89)
			phi = 89
		else if(phi < -89)
			phi = -89
			
		rTemp := cos(phi*PI/180.0)
		forward z = sin(phi * PI / 180.0)
		forward x = rTemp * cos(theta * PI / 180.0)
		forward y = rTemp * sin(theta * PI / 180.0)
		
		left = up ^ forward
		left normalize()
		
		target = position + forward
	}
	
	update: func {
		if(kforward) { position = position + forward * speed }
		if(kbackward) { position = position - forward * speed }
		if(kstrafe_left) { position = position + left * speed }
		if(kstrafe_right) { position = position - left * speed }
		target = position + forward
	}
}
