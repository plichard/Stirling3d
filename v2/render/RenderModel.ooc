use glew
import glew
import structs/ArrayList
import VertexGroup

RenderModel: class {
	
	groups := ArrayList<VertexGroup> new()
	
	init: func {
	}
	
	loadFromObj: func(filename: String) {
		
	}
	
	addGroup: func(g: VertexGroup) {
		if(!g) {
			Exception new(This, "Trying to add a null VertexGroup!!!") throw()
		}
		groups add(g)
	}
	
	render: func {
		for(group: VertexGroup in groups) {
			for(gface: Face in group faces) {
				glBegin(GL_QUADS)
				face := gface as Quad
				if(!(face hasTexCoords) && face hasColors) {
					glColor4d(face c1 r,face c1 g,face c1 b, face c1 a)
					
					glVertex3d(face v1 x,face v1 y, face v1 z)
					glVertex3d(face v2 x,face v2 y, face v2 z)
					glVertex3d(face v3 x,face v3 y, face v3 z)
					glVertex3d(face v4 x,face v4 y, face v4 z)
				}
				glEnd()
			}
		}
	}
	
}
