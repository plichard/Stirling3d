use sdl
import sdl/Sdl
import ITask,Singleton
import structs/LinkedList

CKernel: class extends Singleton<CKernel>{
	
	taskList : static LinkedList<ITask>
	pausedTaskList : static LinkedList<ITask>
	
	init: func ~ckernel {
		T = This
		super()
		taskList = LinkedList<ITask> new()
		pausedTaskList = LinkedList<ITask> new()
		SDL init(0)
	}
	
	
	addTask: static func(t: ITask) -> Bool {
		
		if(!t start()) {return false}
		pos := 0
		for(task in taskList) {
			if(task priority > t priority)
				break
			pos += 1
		}
		taskList add(pos,t)
		printf("taskList add(%d,%p)\n",pos,t)
		return true
	}
	
	/*execute: func -> Int {
		printf("[Execute] size = %d\n",taskList size())
		while(taskList size() > 0) {
			for(task in taskList) {
				if(!task canKill)
					task update()
			}
			
			for(task in taskList) {
				if(task canKill) {
					task stop()
					taskList remove(task)
				}
			}
		}
		return 0
	}
	
	suspendTask: func(t: ITask) {
		if(taskList indexOf(t) != -1) {
			t onSuspend()
			taskList remove(t)
			pausedTaskList add(t)
		}
	}
	
	resumeTask: func(t: ITask) {
		if(pausedTaskList indexOf(t) != -1) {
			t onResume()
			pausedTaskList remove(t)
			pos := 0
			for(task in taskList) {
				if(task priority > t priority)
					break
				pos += 1
			}
			taskList add(pos,t)
		}
	}
	
	removeTask: func(t: ITask) {
		t canKill = true
	}
	
	killAllTasks: func {
		for(task in taskList) {
			task canKill = true
		}
	}
	
	onQuit: func {
		SDL quit()
	}*/
	
}