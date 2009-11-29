import CVideoUpdate, CGlobalTimer, CKernel, CInputTask, CPongTask

CApplication: class {
	videoTask: CVideoUpdate
	globalTimer: CGlobalTimer
	inputTask: CInputTask
	
	//singleton =============
	instance : static This = null
	
	snew: static func {
		if(instance)
			Exception new(This name + " was lonely =)") throw()
			
		instance = This new()
	}
	
	get: static func -> This {
		return instance
	}
	//========================
	
	init: func {}

	run: func {
		kernel := CKernel snew()
		
		globalTimer = CGlobalTimer snew()
		globalTimer priority = 10
		
		inputTask = CInputTask snew()
		inputTask priority = 20
		
		pong := CPongTask new()
		pong priority = 100
		
		videoTask = CVideoUpdate snew()
		videoTask priority = 10000
		
		kernel addTask(globalTimer)
		kernel addTask(inputTask)
		kernel addTask(pong)
		kernel addTask(videoTask)
		
		kernel execute()
	}
}
