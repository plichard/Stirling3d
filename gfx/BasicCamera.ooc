use sdl
import math/Vector3d
import sdl/[Sdl, Event]

gluLookAt: extern func(...)

BasicCamera: class {
	position, target : Vector3d
	init: func ~basicCamera {
		position := Vector3d new(0,0,0)
		target := Vector3d new(0,0,0)
	}
	
	onMouseMotion: func ~basicCamera(e: Motion) {
	}
	
	onKeyboard: func ~basicCamera(e: Key) {
	}
	
	look: func() {
		gluLookAt(position x + 0.1,position y + 0.1,position z + 0.1,
              target x, target y, target z,
              0,0,1)
		}
}
