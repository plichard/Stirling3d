use sdl,glew,glu
import utils/types
import sdl/[Sdl, Event]
import glew
import Movable
import Listener
import glu/Glu


Camera: class extends Listener {
	target := Double3 new(0,0,0)
	position := Double3 new(1,1,1)
	rotation := Double3 new(0,0,0)
	scale := Double3 new(1,1,1)
	
	init: func ~camera {
		super()
	}
	
	look: func() {
		gluLookAt(position x + 0.1,position y + 0.1,position z + 0.1,
              target x + position x, target y + position y, target z + position z,
              position x,position y,position z)
		}
		
	handleEvent: func(event: Event) {
	}	
}
