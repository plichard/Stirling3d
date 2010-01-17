import CVideoUpdate, CGlobalTimer, CKernel, CInputTask, LevelEditor

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
		
		globalTimer = CGlobalTimer get()
		globalTimer priority = 10
		
		inputTask = CInputTask get()
		inputTask priority = 20
		
		//pong := CPongTask new()
		//pong priority = 100
		
		test := LevelEditor new()
		test priority = 100
		
		videoTask = CVideoUpdate get()
		videoTask priority = 10000
		
		kernel := CKernel get()
		kernel addTask(globalTimer)
		kernel addTask(inputTask)
		kernel addTask(videoTask)
		kernel addTask(test)	
		kernel execute()
	}
}