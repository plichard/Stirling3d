
Singleton: abstract class<T> {
	//instance: T* = null
	//instance: static T* = null
	
	instance : T
	
	init: func ~singleton {
		instance = null
		printf("created singleton for: %s",This name)
	}
	
	snew: abstract func
	
	get: static func -> T {
	}
}
