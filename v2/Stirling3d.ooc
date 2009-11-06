use sdl
import sdl/Event
import render/RenderWindow
import scene/[Scene, MovableObject]
import structs/ArrayList
import utils/Debug

usleep: extern func(...)

Stirling3d: class {
	running := false
	
	defaultRenderWindow: RenderWindow = null
	defaultScene : Scene = null
	eventCandidates : ArrayList<MovableObject>
	
	
	init: func {
		dbg(" ===================== Stirling 3d ======================\n")
		eventCandidates = ArrayList<MovableObject> new()
	}
	
	newRenderWindow: func(x,y,bpp: Int, f: Bool) {
		defaultRenderWindow = RenderWindow new(x,y,bpp,f)
	}
	
	newScene: func(=defaultScene) {
		if(!defaultScene) {
			Exception new(This, "Trying to add a null scene!!!") throw()
		}
		
	}
	
	quit: func {
		defaultRenderWindow quit(0)
		dbg( "Exited cleanly =)\n")
	}
	
	mainLoop: func {
		running = true
		eventCandidates = defaultScene getEventCandidates()
		while(running){
			handleEvent()
			if(defaultScene) {
				defaultScene render()
			}
			usleep(30000)
		}
	   
		quit()
	}
	
	handleEvent: func {
		event: Event
		while ( SDLEvent poll( event& ) ) {
		    if(defaultRenderWindow) {
				if(!defaultRenderWindow handleEvent(event&)) {
					running = false
				}
			}
			for( candidate in eventCandidates ) {
				candidate handleEvent(event&)
			}
		}
	}
}


/* Should fullscreen use the screen resolution or the current window one? */
/** TODO implement fullscreen behavior */
MATCH_NATIVE := 0
MATCH_CURRENT := 1
/* ......................................... */
