use glew
import glew
import structs/ArrayList
import utils/Vector3d

Vertex3d: class {
	x, y, z: Double
	set: func(=x,=y,=z) {}
	init: func(=x,=y,=z) {}
	glPrint: func {
		glPushMatrix()
		glBegin(GL_LINES)
		glVertex3d(0,0,0)
		glVertex3d(x,y,z)
		glEnd()
		glPopMatrix()
	}
}

operator + (a,b: Vertex3d) -> Vertex3d {
	return Vertex3d new(a x + b x, a y + b y,a z + b z)
}

operator / (v: Vertex3d, n: Double) -> Vertex3d{
	return Vertex3d new(v x / n, v y / n, v z / n )
}

operator - (a,b: Vertex3d) -> Vector3d{
	return Vector3d new(a x - b x, a y - b y,a z - b z)
}

Color4d: class{
	r, g, b, a: Double
	set: func(=r,=g,=b,=a) {}
	init: func(=r,=g,=b,=a) {}
}

Face: abstract class {
	init: func {}
	computeNormal: func{}
	draw: func {}
	hasColors := false
	hasTexCoords := false
	n: Vector3d				//face normal
}

Triangle: class extends Face {
	v1, v2, v3: Vertex3d	//vertices
	t1, t2, t3: Vertex3d	//tex coords
	c1, c2, c3: Color4d		//colors
	n1, n2, n3: Vector3d	//normals
	
	init: func ~vertices (=v1,=v2,=v3) {}
	
	init: func ~verticescolors (=v1, =v2, =v3,
			=c1, =c2, =c3){hasColors = true;computeNormal()}
	
	init: func ~allParams (
		=v1, =v2, =v3,
		=t1, =t2, =t3,
		=c1, =c2, =c3
		){computeNormal()}
	
	computeNormal: func {
		n = (v2-v1)^(v3-v1)
		}
}

Quad: class extends Face {
	v1, v2, v3, v4: Vertex3d
	t1, t2, t3, t4: Vertex3d
	c1, c2, c3, c4: Color4d		//colors
	
	init: func {}
	init: func ~vertices (=v1, =v2, =v3, =v4){}
	
	init: func ~verticescolors (=v1, =v2, =v3, =v4,
			=c1, =c2, =c3, =c4 ){hasColors = true;computeNormal()}
	
	init: func ~allParams (
		=v1, =v2, =v3, =v4,
		=t1, =t2, =t3, =t4,
		=c1, =c2, =c3, =c4,
		) {hasColors = true; hasTexCoords = true;computeNormal()}
	
	computeNormal: func{
		n = (v2-v1)^(v3-v1)
		}
}

VertexGroup: class {
	vertices := ArrayList<Vertex3d> new()
	faces := ArrayList<Face> new()
	normals := ArrayList<Vector3d> new()
	texture := 0   /* TODO this texture reference is rubbish =) */
	
	init: func {
	}
}
