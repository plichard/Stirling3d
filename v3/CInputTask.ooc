use sdl
import sdl/[Sdl,Event]
import ITask
import structs/LinkedList

memcpy: extern func(...)
usleep: extern func(...)

import Listener
CInputTask: class extends ITask {
	
	keys: UInt8*
	oldKeys: UInt8*
	keyCount: Int
	
	dX,dY: Int
	buttons: UInt
	oldButtons: UInt
	
	event: Event
	
	listeners: LinkedList<Listener>

	//singleton =============
	instance : static This = null
	
	get: static func -> This{
		if(!instance) {
			instance = new()
		}
		return instance
	}
	
	//=========================
	
	init: func ~cinputtask{
		super()
		listeners = LinkedList<Listener> new()
	}
	
	start: func -> Bool {
		dX = 0 ; dY = 0
		return true

	}
	
	stop: func {
		keys = 0
		oldKeys = 0
	}
	
	update: func {
		while(SDLEvent poll(event&)) {
			for(listener in listeners) {
				listener handleEvent(event)
			}
		}
	}
	
	handleEvent: func(event: Event) {}
	
	regEvent: func (listener: Listener) {
		listeners add(listener)
	}
	
	unRegEvent: func (listener: Listener) {
		listeners remove(listener)
	}
