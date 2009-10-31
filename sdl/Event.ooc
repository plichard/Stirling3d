use sdl
import sdl/Sdl

Event: cover from SDL_Event {
	type: extern Int
}
SDLEvent: cover {
	wait: extern(SDL_WaitEvent) static func(Event*) -> Int
	poll: extern(SDL_PollEvent) static func(Event*) -> Int
}
