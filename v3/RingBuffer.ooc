RingBuffer: class <T> {
	bufSize : UInt32
	buf : T*
	read,write: ULong
	
	init: func(=bufSize) {
		buf = gc_calloc(bufSize, T size)
		read = 0
		write = 1
	}
    
    fwrite: func(obj: T) -> Bool{
		buf[write] = obj;
		write += 1
		while(write >= bufSize)
			write -= bufSize
			
		if(write == read) {
			write -= 1
			while(write < 0)
				write += bufSize
			return false
		}
		return true
	} 
	
	
    
    fread: func(res: T) -> Bool {
		read += 1
		while(read >= bufSize)
			read -= bufSize
		if(read == write) {
			write += 1
			while(write >= bufSize)
				write -= bufSize
			return false
		}
		res = buf[read]
		return true
	}
	
   
	dataSize: func -> ULong {
		wc := write
		while(wc < read)
			wc += bufSize
		return wc - read - 1
	}
      
    flood: func(value: T) {
		read = 0
		for(write in 0..bufSize)
			buf[write] = value
		write = 1
	} 
}


