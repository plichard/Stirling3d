use sdl
import sdl/Event

InputCandidate: abstract class {
	handleEvent: func(e: Event*) {}
	init: func {}
}
