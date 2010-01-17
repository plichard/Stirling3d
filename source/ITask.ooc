import Listener
ITask: abstract class extends Listener {
	canKill: Bool
	priority: Long
	
	init: func() {
		super()
		canKill = false
		priority = 5000
	}
	
	start: abstract func -> Bool
	
	onSuspend: func {}
	
	update: abstract func
	
	onResume: func {}
	
	stop: abstract func
	
}
