use sdl
import structs/HashMap
import math/Vector3d
import sdl/[Sdl,Event]
import BasicCamera

gluLookAt: extern func(...)

FreeFlyCamera: class extends BasicCamera{
	speed, sensivity: Double
	phi, theta: Double
	forward := Vector3d new(0,0,0)
	left := Vector3d new(0,0,0)
	
	keyconf := HashMap<Int> new()
	keystates := HashMap<Bool> new()
	
	init: func(=position) {
		phi = 0
		theta = 0
		vectorsFromAngles()
		
		speed = 1
		sensivity = 0.2
		
		keystates put("forward",false)
		keystates put("backward",false)
		keystates put("strafe_left",false)
		keystates put("strafe_right",false)
		keystates put("boost",false)
		
		SDL WM_GrabInput(SDL_GRAB_ON)
		SDL showCursor(SDL_DISABLE)
		target := Vector3d new()
	}
	
	onMouseMotion: func(e: Motion) {
		theta -= e xrel * sensivity
		phi -= e yrel * sensivity
		vectorsFromAngles()
	}
	
	onKeyboard: func(e: Key) {
		a := e keysym sym
		match(a) {
			case SDLK_ESCAPE => exit(0)
			case SDLK_w => position += forward * speed ;
			case SDLK_s => position -= forward * speed ;
			case SDLK_a => position += left * speed ;
			case SDLK_d => position -= left * speed ;
		}
		target = position + forward
	}
	
	setSpeed: func(=speed) {
	}
	
	setSensivity: func(=sensivity) {}
	
	setPosition: func(=position) {}
	
	vectorsFromAngles: func {
		up := Vector3d new(0,0,1)
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
}
