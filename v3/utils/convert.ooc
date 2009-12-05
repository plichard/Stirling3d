import utils/[types,text]
import io/[FileReader, FileWriter]
import text/StringTokenizer
import structs/Array


objtoS3D: func(fromName, toName: String) -> Bool {
	
	nVertices : Long = 0
	nVertexNormals : Long = 0
	nFaces : Long = 0
	nTexCoordinates := 0
	nLines : Long = 0
	source := FileReader new(fromName)
	
	//lets count how much of each(vertices, faces...) we got in order to alloc everything at once
	
	
	while(source hasNext()) {
		line := readLine(source)
		ftoken := getFirstToken(line)
		if( ftoken == "v" ) {
			nVertices += 1
		} else if(ftoken == "f") {
			nFaces += 1
		} else if(ftoken == "vt") {
			nTexCoordinates += 1
		} else if(ftoken == "vn") {
			nVertexNormals += 1
		} else if(ftoken == "#") {
			//printf("%s",line)
		} else {
			//printf("unknown line: %s\n",line)
		}
		nLines += 1
	}
	
	
	printf("%d vertices, %d faces, %d vertex normals and %d texture coordinates\n",nVertices, nFaces, nVertexNormals, nTexCoordinates)
	
	source reset(0)
	
	vertices :  Float3* = gc_malloc(nVertices * Float3 size)
	normals :   Float3* = gc_malloc(nVertexNormals * Float3 size)
	texCoords : Float2* = gc_malloc(nTexCoordinates * Float2 size)
	
	faces :  	  Face* = 	   gc_malloc(nFaces * Face size)
	notexfaces :  FaceNoTex* = gc_malloc(nFaces * FaceNoTex size)
	
	nVertices = 0
	nVertexNormals = 0
	nFaces = 0
	nTexCoordinates = 0
	currentLine : Long = 0
	
	while(source hasNext()) {
		//printf("#%Ld\n",currentLine)
		line := readLine(source)
		tok := StringTokenizer new(line," /")
		/*printf("tokenized line: ")
		t := 0
		while(tok hasNext()) {
			printf("%s|",tok nextToken())
		}
		println()*/
		ftoken := tok nextToken()
		if( ftoken == "v" ) {
			vertices[nVertices] x = tok nextToken() toFloat()
			vertices[nVertices] y = tok nextToken() toFloat()
			vertices[nVertices] z = tok nextToken() toFloat()
			nVertices += 1
		} else if(ftoken == "f" && nTexCoordinates > 0) {
			faces[nFaces] v1 = tok nextToken() toInt() - 1
			faces[nFaces] n1 = tok nextToken() toInt() - 1
			faces[nFaces] t1 = tok nextToken() toInt() - 1
			
			faces[nFaces] v2 = tok nextToken() toInt() - 1
			faces[nFaces] n2 = tok nextToken() toInt() - 1
			faces[nFaces] t2 = tok nextToken() toInt() - 1
			
			faces[nFaces] v3 = tok nextToken() toInt() - 1
			faces[nFaces] n3 = tok nextToken() toInt() - 1 
			faces[nFaces] t3 = tok nextToken() toInt() - 1
			nFaces += 1
		} else if(ftoken == "f" && nTexCoordinates == 0) {
			notexfaces[nFaces] v1 = tok nextToken() toInt() - 1
			notexfaces[nFaces] n1 = tok nextToken() toInt() - 1
			
			notexfaces[nFaces] v2 = tok nextToken() toInt() - 1
			notexfaces[nFaces] n2 = tok nextToken() toInt() - 1
			
			notexfaces[nFaces] v3 = tok nextToken() toInt() - 1
			notexfaces[nFaces] n3 = tok nextToken() toInt() - 1
			nFaces += 1
		} else if(ftoken == "vt") {
			texCoords[nTexCoordinates] x = tok nextToken() toFloat()
			texCoords[nTexCoordinates] y = tok nextToken() toFloat()
			nTexCoordinates += 1
		} else if(ftoken == "vn") {
			normals[nVertexNormals] x = tok nextToken() toFloat()
			normals[nVertexNormals] y = tok nextToken() toFloat()
			normals[nVertexNormals] z = tok nextToken() toFloat()
			nVertexNormals += 1
		} else if(ftoken == "#") {
			printf("%s",line)
		} else {
			//printf("unknow line: %s\n",line)
		}
		currentLine += 1
		//printf("currentLine: %d\n",currentLine)
		//printf("nLines: %d\n",nLines)
		if(currentLine % (nLines/100 + 1) == 0) {
			printf("%d%%\n",currentLine*100/nLines)
		}
	}
	printf("100%%\n")
	
	//close the source file and open the destination one
	//we will write it without texture informations for now....
	source close()
	dest := FileWriter new(toName,"wb")
	//write the number of vertices
	dest write(nVertices&,Int size)
	//write the number of normals
	dest write(nVertexNormals&, Int size)
	//write the number of faces
	dest write(nFaces&, Int size)
	
	//write the vertices
	dest write(vertices, Float3 size * nVertices)
	
	//write the normals
	dest write(normals, Float3 size * nVertexNormals)
	
	//write the faces
	if(nTexCoordinates == 0) {
		dest write(notexfaces, FaceNoTex size * nFaces)
	} else {
		printf("sorry, tex coords unsupported yet :(\n")
	}
	
	dest close()
	
	return true
}
