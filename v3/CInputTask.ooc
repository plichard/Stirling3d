use sdl
import sdl/[Sdl,Event]
import ITask

memcpy: extern func(...)
CInputTask: class extends ITask {
	
	keys: UChar*
	oldKeys: UChar*
	keyCount: Int
	
	dX,dY: Int
	buttons: UInt
	oldButtons: UInt

	//singleton =============
	instance : static This = null
	
	snew: static func -> This {
		if(instance)
			Exception new(This name + " was lonely =)") throw()
			
		instance = This new()
		return instance
	}
	
	get: static func -> This {
		return instance
	}
	
	//=========================
	
	init: func ~cinputtask{
		super()
	}
	
	start: func -> Bool {
		keys = SDL getKeyState(keyCount&)
		//oldKeys = new CMMDynamicBlob<unsigned char>(keyCount);
		oldKeys = gc_calloc(keyCount,sizeof(UChar))
		dX = 0 ; dY = 0
		SDLEvent pump(); SDLEvent pump()
		return true

	}
	
	stop: func {
		keys = 0
		oldKeys = 0
	}
	
	update: func {
		SDLEvent pump()

		oldButtons = buttons
		buttons = SDL getRelativeMouseState(dX&,dY&)

		memcpy(oldKeys,keys,sizeof(UChar)*keyCount)
		keys = SDL getKeyState(keyCount&)
		
		//printf("hellow from cinputtask\n")
	}

	curKey: func (index: Int) -> Bool {
		return keys[index] != 0
	}
	
	oldKey: func (index: Int) -> Bool {
		return oldKeys[index] != 0
	}
	
	keyDown: func(index: Int) -> Bool{
		return curKey(index) && (!oldKey(index))
	}
	
	keyStillDown: func(index: Int) -> Bool{
		return curKey(index) && (oldKey(index))
	}
	
	keyUp: func(index: Int) -> Bool {
		return (!curKey(index)) && (oldKey(index))
	}
	
	keyStillUp: func(index: Int) -> Bool {
		return (!curKey(index)) && (!oldKey(index))
	}
	
	curMouse: func(button: Int) -> Bool {
		return (buttons & button) != 0
	}
	
	oldMouse: func(button: Int) -> Bool {
		return (oldButtons & button) != 0
	}
	
	mouseDown: func(button: Int) -> Bool {
		return curMouse(button) && (!oldMouse(button))
	}
	
	mouseStillDown: func(button: Int) -> Bool {
		return curMouse(button) && (oldMouse(button))
	}
	
	mouseUp: func(button: Int) -> Bool {
		return (!curMouse(button)) && (oldMouse(button))
	}
	
	mouseStillUp: func(button: Int) -> Bool {
		return (!curMouse(button)) && (!oldMouse(button))
	}




}
