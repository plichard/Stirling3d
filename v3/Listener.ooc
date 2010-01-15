use sdl
import sdl/[Event]

Listener: abstract class {
	
	init: func ~listener{
	}
	
	handleEvent: abstract func(event: Event) 
	
	
}
