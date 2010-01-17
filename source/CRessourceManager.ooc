import Singleton

CRessourceManager: class  {
	
	instance : static This = null  // this class is a singleton
	
	init: func {
	}
	
	get: static func -> This {
		if(!instance) {
			instance = new()
		}
		return instance
	}
	
	loadStaticObj: func {
		printf("wouhuuuu")
	}
	
	
}
