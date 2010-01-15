use sdl
import sdl/Event

import utils/types


Movable: abstract class {
	position: Double3
	rotation: Double3
	scale: Double3
	
	init: func {
		position = Double3  new(0,0,0)
		rotation = Double3  new(0,0,0)
		scale = Double3  new(0,0,0)
	}
}
