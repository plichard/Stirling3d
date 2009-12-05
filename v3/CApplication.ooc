import CVideoUpdate, CGlobalTimer, CKernel, CInputTask, CPongTask, CHighResTestApp

CApplication: class {
	videoTask: CVideoUpdate
	globalTimer: CGlobalTimer
	inputTask: CInputTask
	
	//singleton =============
	instance : static This = null
	
	get: static func -> This {
		if(!instance) {
			instance = new()
		}
		return instance
	}
	//========================
	
	init: func {}

	run: func {
		
		globalTimer = CGlobalTimer snew()
		globalTimer priority = 10
		
		inputTask = CInputTask snew()
		inputTask priority = 20
		
		//pong := CPongTask new()
		//pong priority = 100
		
		test := CHighResTestApp new()
		test priority = 100
		
		videoTask = CVideoUpdate snew()
		videoTask priority = 10000
		
		kernel := CKernel get()
		kernel addTask(globalTimer)
		kernel addTask(inputTask)
		kernel addTask(videoTask)
		kernel addTask(test)	
		kernel execute()
	}
}
