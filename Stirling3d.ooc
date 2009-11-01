usleep: extern proto func(UInt)
use glew
import glew

import gfx/[Scene,Screen,Drawable, FreeFlyCamera, BasicCamera]
import sdl/[Event, Sdl]

Stirling3d: class {
	
	scene: Scene
	screen: Screen
	isRunning := false
	pTime = 0, cTime = 0: UInt32 
	dispList : GLuint =  glGenLists(1)

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
                
                case SDL_KEYDOWN => { scene camera onKeyboard(event key) 
					if(event key keysym sym == SDLK_c ) {
						scene clear = !(scene clear)
						glClear( GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT )
					}
					else if(event key keysym sym == SDLK_b ) {
						scene blend = !(scene blend)
					}
					else if (event key keysym sym == SDLK_ESCAPE) {
						isRunning = false
					}
				}
				
				case SDL_MOUSEMOTION => scene camera onMouseMotion(event motion)
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
