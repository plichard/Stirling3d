use sdl
import sdl/[Sdl,Event]
import ITask
CGlobalTimer: class extends ITask {
  
	dT: Float
	lastFrameIndex: ULong
	thisFrameIndex: ULong
	
	//singleton =============
	instance : static This = null
	
	get: static func -> This{
		if(!(This instance)) {
			This instance = new()
		}
		return This instance
	}
	//========================
	
	init: func ~cglobaltimer {
		super()
	}
	
	start: func -> Bool {
		thisFrameIndex = SDL getTicks()
		lastFrameIndex = thisFrameIndex
		dT = 0
		return true;
	}
	
	update: func {
		lastFrameIndex = thisFrameIndex
		thisFrameIndex = SDL getTicks()
		dT=((thisFrameIndex-lastFrameIndex) as Float)/1000.0
		//printf("hellow from global timer =)\n")
	}
	
	handleEvent: func(event: Event) {
	}
	
	stop: func {
	}
}
