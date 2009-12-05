import io/FileReader

getline: extern func(...) -> Int

readLine: func(filereader: FileReader) -> String{
	/*i := 0
	nChars := 0
	//line : Char[256]
	while(filereader hasNext() && filereader read() != '\n' ) {
		nChars += 1
	}
	
	
	line : Char[nChars + 1]
	filereader rewind(nChars + 1)
	i = 0
	while(i < nChars) {
		line[i] = filereader read()
		i += 1
	}
	line[i] = '\0'
	
	// skip the '\n'
	filereader read()
	
	//printf("Got line %s\n", line)
	return line as String clone()*/
	line := String new(254)
	nbytes := 254
	nchars := 0
	nchars = getline(line&,nbytes&,filereader file)
	return line 
}


getFirstToken: func(line: String) -> String{
	buffer := String new(8)
	//printf("[getToken] line: %s\n",line)
	i := 0
	n := 0
	while(line[i] == ' ') {
		i += 1
	}
	
	while(line[i] != ' ' && line[i] != '\0') {
		buffer[n] = line[i]
		
		if(n >= 8) {
			printf("line: %s\n",line)
			Exception new("getFirstToken: Buffer overflow") throw()
		}
		i += 1
		n += 1
	}
	
	return buffer
}
