import ITask

MyTask: class extends ITask {
	init: func ~mytask {super()}
	start: func -> Bool {printf("mytask started\n");return true}
	stop: func {}
	update: func {printf("Hellow from MyTask!!!\n")}
}
