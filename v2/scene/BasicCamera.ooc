use sdl
import utils/Vector3d
import sdl/[Sdl, Event]
import MovableObject

gluLookAt: extern func(...)

BasicCamera: class extends MovableObject{
	target : Vector3d
	init: func ~basicCamera {
		super()
		target = Vector3d new(0,0,0)
		candidate = false
	}
	
	handleEvent: func (e: Event*) {
		
	}
	
	onMouseMotion: func (e: Motion) {
	}
	
	onKeyboard: func (e: Key) {
	}
	
	look: func() {
		gluLookAt(position x + 0.1,position y + 0.1,position z + 0.1,
              target x + position x, target y + position y, target z + position z,
              position x,position y,position z)
		}
		
}
