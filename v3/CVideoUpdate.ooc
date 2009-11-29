use sdl
import sdl/[Sdl,Video,Event]
import ITask,CLog,CInputTask

CVideoUpdate: class extends ITask {
	
	scrWidth, scrHeight, scrBPP: Int
	
	init: func ~videowithParams (=scrWidth, =scrHeight, =scrBPP){
		super()
	}
	
	init: func ~cvideoupdate {
		super()
	}
	
	//singleton =============
	instance : static This = null
	
	snew: static func -> This {
		if(instance)
			Exception new(This name + " was lonely =)") throw()
			
		instance = This new(1280,800,32)
		return instance
	}
	
	get: static func -> This {
		return instance
	}
	//========================

	start: func -> Bool {
		if(-1 == SDL initSubSystem(SDL_INIT_VIDEO))
		{
			/*CLog::Get().Write(LOG_CLIENT,IDS_GENERIC_SUB_INIT_FAIL,
			"Video",SDL_GetError());*/
			CLog get() write(LOG_CLIENT,"Video: " + SDL getError())
			return false;
		}
		SDL GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 )
		SDL GL_SetAttribute( SDL_GL_RED_SIZE, 8 )
		SDL GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 )
		SDL GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 )
		SDL GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 )
		SDL GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 )

		flags := SDL_OPENGL | SDL_ANYFORMAT | SDL_FULLSCREEN

		if(!SDLVideo setMode(scrWidth, scrHeight, scrBPP, flags)) {
			/*CLog::Get().Write(LOG_CLIENT, IDS_BAD_DISPLAYMODE,
			scrWidth, scrHeight, scrBPP, SDL_GetError());*/
			CLog get() write(LOG_CLIENT,"Video: " + SDL getError())
			return false
		}

		SDL showCursor(SDL_DISABLE)

		return true;

	}
	
	stop: func {
		SDL quitSubSystem(SDL_INIT_VIDEO)
	}
	
	update: func {
		if(CInputTask get() curKey(SDLK_ESCAPE)) {
			canKill = true
		}
		SDLVideo glSwapBuffers()
	}

}
