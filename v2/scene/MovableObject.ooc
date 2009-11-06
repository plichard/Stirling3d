use sdl
import sdl/Event

import utils/Vector3d

import render/Renderable

MovableObject: abstract class extends Renderable{
	position: Vector3d
	rotation: Vector3d
	scale: Vector3d
	candidate : Bool
	
	init: func {
		position = Vector3d  new(0,0,0)
		rotation = Vector3d  new(0,0,0)
		scale = Vector3d  new(0,0,0)
		candidate = false
		super()
	}
	
	handleEvent: func(e: Event*) {}
}
