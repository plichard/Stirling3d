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
			dbg("got a line: " + line + "\n")
			type := String new(32)
			sscanf(line,"%s",type)
			if(type == "v") {
				dbg("it is a vertex: ")
				a,b,c: Double
				sscanf(line,"%s %f %f %f",type,a&,b&,c&)
			} else {
				dbg("\tunknown line :( \n")
			}
		}
	}
	
	addGroup: func(g: VertexGroup) {
		if(!g) {
			Exception new(This, "Trying to add a null VertexGroup!!!") throw()
		}
		groups add(g)
	}
	
	render: func {
		printf("rendering RenderModel\n")
		for(group: VertexGroup in groups) {
			for(gface: Face in group faces) {
				glBegin(GL_QUADS)
				face := gface as Quad
				if(!(face hasTexCoords) && face hasColors) {
					glNormal3d(face n as Vector3d x, face n as Vector3d y, face n as Vector3d z)
					
					glColor4d(face c1 r,face c1 g,face c1 b, face c1 a)	
					glVertex3d(face v1 x,face v1 y, face v1 z)
					
					glColor4d(face c2 r,face c2 g,face c2 b, face c2 a)
					glVertex3d(face v2 x,face v2 y, face v2 z)
					
					glColor4d(face c3 r,face c3 g,face c3 b, face c3 a)
					glVertex3d(face v3 x,face v3 y, face v3 z)
					
					glColor4d(face c4 r,face c4 g,face c4 b, face c4 a)
					glVertex3d(face v4 x,face v4 y, face v4 z)
				}
				glEnd()
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
