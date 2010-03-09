import io/FileWriter

LOG_APP := 1 
LOG_CLIENT := 2
LOG_SERVER := 4
LOG_USER := 8

MAX_LOG_STRINGS := 256

CLog: class {
	
	
	
	appLog: FileWriter
	clientLog: FileWriter
	serverLog: FileWriter
	
	//singleton =============
	
	instance : static This = null
	
	get: static func -> This{
		if(!(This instance))	This instance = This new()
		return This instance
	}
	
	//=========================
	
	init: func {
		start()
	}
	
	
	
	
	
	start: func -> Bool {
		appLog = FileWriter new("applog.txt")
		clientLog = FileWriter new("clntlog.txt")
		serverLog = FileWriter new("srvrlog.txt")
		return true
	}
	
	write: func ~string(target: Int,msg: String ) {
		if(target & LOG_APP)
			appLog write(msg)
			
		if(target & LOG_CLIENT)
			clientLog write(msg)
			
		if(target & LOG_SERVER) {
			serverLog write(msg)
			printf("writing server log\n")
		}
			
		if(target & LOG_USER)
			appLog write(msg)
	}
	write: func ~id(target: Int,msgID: ULong ) {
		
	}
	
	
	
}
