use sdl
import sdl.Sdl

Event: cover from SDL_Event
SDLEvent: cover {
	wait: extern(SDL_WaitEvent) static func(Event*) -> Int
	
}
