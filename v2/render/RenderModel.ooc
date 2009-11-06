use glew
import glew
import structs/ArrayList
import VertexGroup
import utils/Vector3d
import io/FileReader

RenderModel: class {
	
	groups: ArrayList<VertexGroup>
	
	
	init: func {
		groups = ArrayList<VertexGroup> new()
	}
	
	loadFromObj: func(filename: String) {
		file := FileReader new("render/models/cube.obj")
		group := VertexGroup new()
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
