usleep: extern proto func(UInt)

import gfx/[Scene,Screen,Drawable]
import sdl/[Event, Sdl]

Stirling3d: class {
	
	scene: Scene
	screen: Screen
	isRunning := false

	init: func {}
	
	window: func(x,y: Int) {
		screen = Screen new(x,y,32)
	}
	
	newScene: func {
		scene = Scene new()
	}
	
	drawAxes: func(b: Bool) {
		Drawable axes = b
	}
	
	handleInput: func {
		event: Event
		while(SDLEvent poll(event&)) {
			match(event type)
            {
                case SDL_QUIT =>  exit(0)
            
            }

		}
	}

	mainLoop: func {
		isRunning = true
		while(isRunning){
			handleInput()
			scene update()
			scene draw()
			usleep(30000)
		}
	}
}
