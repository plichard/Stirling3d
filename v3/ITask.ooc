
ITask: abstract class {
	canKill: Bool
	priority: Long
	
	init: func() {
		canKill = false
		priority = 5000
	}
	
	start: abstract func -> Bool
	
	onSuspend: func {}
	
	update: abstract func
	
	onResume: func {}
	
	stop: abstract func
	
}
