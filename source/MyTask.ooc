use sdl,glew
import glew
import sdl/[Sdl,Event]
import ITask,CKernel,CInputTask

MyTask: class extends ITask {
	init: func ~mytask {super()}
	start: func -> Bool {printf("mytask started\n");return true}
	stop: func {}
	update: func {
		glClear(GL_COLOR_BUFFER_BIT)
		if(CInputTask get() mouseDown(SDL_BUTTON_LEFT))
			CKernel get() killAllTasks()
	}
}
