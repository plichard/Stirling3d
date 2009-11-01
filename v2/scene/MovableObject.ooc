use sdl
import sdl/Event

import utils/Vector3d

MovableObject: abstract class {
	position: Vector3d
	rotation: Vector3d
	scale: Vector3d
	candidate := false
	
	init: func {
		position = Vector3d  new(0,0,0)
		rotation = Vector3d  new(0,0,0)
		scale = Vector3d  new(0,0,0)
	}
	
	handleEvent: func(e: Event*) {}
}
