use glew
import glew
import structs/ArrayList
import VertexGroup
import utils/Vector3d
import io/FileReader
import utils/Debug

getchar: extern func()

RenderModel: class {
	
	groups: ArrayList<VertexGroup>
	
	
	init: func {
		groups = ArrayList<VertexGroup> new()
	}
	
	clear: func {
		groups clear()
	}
	
	loadFromObj: func(filename: String) {
		dbg("Loading " + filename + "\n")
		file := FileReader new(filename)
		group := VertexGroup new()
		
		nline := 0
		while(file hasNext()) {
			c := file read()
			if(c == '\n') {
				nline += 1
			}
		}
		
		file reset(0)
		for(i in 0..nline) {
			line := readLine(file)
			//dbg("got a line: " + line + "\n")
			//printf("#%d: %s -> ",i,line)
			type := String new(32)
			sscanf(line,"%s",type)
			if(type == "v") {
				a,b,c: Float
				n := sscanf(line,"%s %f %f %f",type,a&,b&,c&)
				if(n != 4) {
					//printf("Wrong line!\n")
				} else {
					//printf(" it is a vertex: (%1.1f,%1.1f,%1.1f)\n",a,b,c)
					group vertices add(Vertex3d new(a,b,c))
				}
			} else if(type == "f") {
				v1,v2,v3: Int
				n1,n2,n3: Int
				n := sscanf(line,"%s %d//%d %d//%d %d//%d",type,v1&,n1&,v2&,n2&,v3&,n3&)
				if(n != 7) {
					//printf("Wrong line!\n")
				} else {
					red := Color4d new(0,0,1,1)
					face := Triangle new(group vertices[v1 - 1],group vertices[v2 - 1],group vertices[v3 - 1],red,red,red)
					face n1 = group normals get(n1 - 1)
					face n2 = group normals get(n2 - 1)
					face n3 = group normals get(n3 - 1)
					group faces add(face)
				}
			} else if(type == "vn") {
				a,b,c: Float
				n := sscanf(line,"%s %f %f %f",type,a&,b&,c&)
				if(n != 4) {
					//printf("Wrong line!\n")
				} else {
					//printf(" it is a vertex: (%1.1f,%1.1f,%1.1f)\n",a,b,c)
					group normals add(Vector3d new(a,b,c))
				}	
				
			}else {
				printf(" unknown line :( \n")
			}
		}
		printf("found %d vertices and %d faces\n",group vertices size(),group faces size())
		groups add(group)
	}
	
	addGroup: func(g: VertexGroup) {
		if(!g) {
			Exception new(This, "Trying to add a null VertexGroup!!!") throw()
		}
		groups add(g)
	}
	
	render: func {
		printf("Rendering model\n")
		for(group: VertexGroup in groups) {
			for(gface: Face in group faces) {
				glPushMatrix()
				glBegin(GL_TRIANGLES)
				face := gface as Triangle
				if(!(face hasTexCoords) && face hasColors) {
					glNormal3d(face n1 as Vector3d x, face n1 as Vector3d y, face n1 as Vector3d z)
					glColor4d(face c1 r,face c1 g,face c1 b, face c1 a)	
					glVertex3d(face v1 x,face v1 y, face v1 z)
					
					glNormal3d(face n2 as Vector3d x, face n2 as Vector3d y, face n2 as Vector3d z)
					glColor4d(face c2 r,face c2 g,face c2 b, face c2 a)
					glVertex3d(face v2 x,face v2 y, face v2 z)
					
					glNormal3d(face n3 as Vector3d x, face n3 as Vector3d y, face n3 as Vector3d z)
					glColor4d(face c3 r,face c3 g,face c3 b, face c3 a)
					glVertex3d(face v3 x,face v3 y, face v3 z)
				}
				glEnd()
				glPopMatrix()
				/*glPushMatrix()
				faceCenter := (face v1 + face v2 + face v3)/3
				glTranslated(faceCenter x, faceCenter y, faceCenter z)
				glColor4d(1,0,0,1)
				faceCenter glPrint()
				glPopMatrix()*/
			}
		}
	}
	
}

readLine: func(filereader: FileReader) -> String{
		i := 0
		nChars := 0
		//line : Char[256]
		while(filereader hasNext() && filereader read() != '\n' ) {
			nChars += 1
		}
		
		line := String new(nChars)
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
		return line as String clone()
	}

