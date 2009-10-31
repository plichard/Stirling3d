usleep: extern proto func(UInt)

import gfx/[Scene,Screen,Drawable, FreeFlyCamera]
import sdl/[Event, Sdl]

Stirling3d: class {
	
	scene: Scene
	screen: Screen
	isRunning := false
	pTime = 0, cTime = 0: UInt32 

	init: func {}
	
	window: func(x,y,bpp,flags: Int) {
		screen = Screen new(x,y,bpp,flags)
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
                
                case SDL_KEYDOWN => { scene camera as FreeFlyCamera onKeyboard(event key) 
					if(event key keysym sym == SDLK_c ) {
						scene clear = !(scene clear)
					}
					else if (event key keysym sym == SDLK_ESCAPE) {
						SDL quit()
					}
				}
				
				case SDL_MOUSEMOTION => scene camera as FreeFlyCamera onMouseMotion(event motion)
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
