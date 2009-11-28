import CLog,Singleton,RingBuffer,CKernel,MyTask,TestClass

main: func {
	clog := CLog new()
	clog write(LOG_SERVER,"babouuuuuuu\n")
	
	CKernel new()
	//CKernel addTask(MyTask new())
	//task := MyTask new()
	//kernel addTask(task)
	
	//kernel execute()
	
	//TestClass new()
	
	//printf("TestClass beuh = %d\n",TestClass beuh)
	
}
