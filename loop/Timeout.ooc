

Timeout: class {
	
	/* Interval in ms when _call has to be called */
	timeout := 0
	
	/*_call: func {
	}*/
	
	_call := 0
	
	/* Accumulates passed time */
	accumulator = 0: Long
	
	//new: func(=_call, =timeout)
	
	/* call _call if the timeout has passed */
	call: func(delta: Int) {
		accumulator += delta
			if(accumulator > timeout) {
				accumulator = 0
				// _call()
			}
	}
}

