usleep: extern proto func(UInt)

import gfx/[Scene,Screen,Drawable]
import sdl/[Event, Sdl]

Stirling3d: class {
	
	scene: Scene
	screen: Screen
	isRunning := false
	pTime = 0, cTime = 0: UInt32 

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
			cTime = SDL getTicks()
			if(cTime - pTime > 30) {
				handleInput()
				scene update()
				scene draw()
				pTime = cTime
			}
			else {
				usleep((30 - cTime  + pTime) * 1000 )
			}		
		}
	}
}
