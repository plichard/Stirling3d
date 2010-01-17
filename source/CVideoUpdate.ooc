use sdl,glew
import glew
import sdl/[Sdl,Video,Event]
import ITask,CLog,CInputTask


CVideoUpdate: class extends ITask {
	
	scrWidth, scrHeight, scrBPP: Int
	surface: Surface*
	
	init: func ~videowithParams (=scrWidth, =scrHeight, =scrBPP){
		super()
	}
	
	init: func ~cvideoupdate {
		super()
	}
	
	//singleton =============
	instance : static This = null
	
	get: static func -> This{
		if(!instance) {
			instance = This new(1280,800,32)
		}
		return instance
	}
	
	//========================

	start: func -> Bool {
		if(-1 == SDL init(SDL_INIT_EVERYTHING))
		{
			/*CLog::Get().Write(LOG_CLIENT,IDS_GENERIC_SUB_INIT_FAIL,
			"Video",SDL_GetError());*/
			CLog get() write(LOG_CLIENT,"Video: " + SDL getError())
			return false;
		}
		
		CInputTask get() regEvent(this)
		

		flags := SDL_OPENGL | SDL_ANYFORMAT// | SDL_FULLSCREEN

		surface = SDLVideo setMode(scrWidth, scrHeight, scrBPP, flags)
		if(!surface) {
			/*CLog::Get().Write(LOG_CLIENT, IDS_BAD_DISPLAYMODE,
			scrWidth, scrHeight, scrBPP, SDL_GetError());*/
			CLog get() write(LOG_CLIENT,"Video: " + SDL getError())
			return false
		}
		
		SDL GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 )
		SDL GL_SetAttribute( SDL_GL_RED_SIZE, 8 )
		SDL GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 )
		SDL GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 )
		SDL GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 )
		SDL GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 )
		
		glShadeModel(GL_SMOOTH)
		glEnable(GL_DEPTH_TEST)

		SDL showCursor(SDL_DISABLE)

		return true;

	}
	
	stop: func {
		CInputTask get() unRegEvent(this)
		SDL quitSubSystem(SDL_INIT_VIDEO)
	}
	
	update: func {
			//canKill = true
		SDLVideo glSwapBuffers()
	}
	
	handleEvent: func (event: Event) {
		match( event type ) {
			case SDL_KEYDOWN => handleKeyPress( event key keysym)
		}
	}
	handleKeyPress: func(keysym: Keysym) {
		match (keysym sym ) {
			case SDLK_F1 => SDL WM_ToggleFullScreen( surface )
		}
	}
}
