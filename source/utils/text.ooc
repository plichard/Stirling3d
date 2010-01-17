import io/FileReader

getline: extern func(...) -> Int

readLine: func(filereader: FileReader) -> String{
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
