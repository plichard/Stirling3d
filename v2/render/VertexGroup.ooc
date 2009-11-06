import structs/ArrayList
import utils/Vector3d

Vertex3d: class {
	x, y, z: Double
	set: func(=x,=y,=z) {}
	init: func(=x,=y,=z) {}
}

operator - (a,b: Vertex3d) -> Vector3d{
	return Vector3d new(a x - b x, a y - b y,a z - b z)
}

Color4d: class{
	r, g, b, a: Double
	set: func(=r,=g,=b,=a) {}
	init: func(=r,=g,=b,=a) {}
}

Face: class {
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
	
	
	init: func {}
	
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
	texture := 0   /* TODO this texture reference is rubbish =) */
	
	init: func {
	}
}
