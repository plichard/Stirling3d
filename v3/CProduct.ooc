use glew
import glew
import io/FileReader
import utils/types
import structs/Array

CProduct: abstract class {
	
	init: func ~cproduct {
	}
}

MESH := 0

StaticMesh: class extends CProduct {
	vertices : Array<Float3>
	normals : Array<Float3>
	faces : Array<FaceNoTex>
	dlist : GLuint = 0
	
	init: func ~mesh(filename: String) {
		super()
		source := FileReader new(filename)
		nVertices := 0
		nNormals := 0
		nFaces := 0
		source read(nVertices&,0,Int size)
		source read(nNormals&,0,Int size)
		source read(nFaces&,0,Int size)
		
		printf("%d vertices, %d faces and %d vertex normals\n",nVertices, nFaces, nNormals)
		
		vertices = Array<Float3> new(nVertices)
		normals = Array<Float3> new(nNormals)
		faces = Array<FaceNoTex> new(nFaces)
		
		source read(vertices data,0,Float3 size * nVertices)
		source read(normals data,0,Float3 size * nNormals)
		source read(faces data,0,FaceNoTex size * nFaces)
	}
	
	prepare: func {
		dlist = glGenLists(1)
		glNewList(dlist,GL_COMPILE)
		glColor3ub(255,255,255)
		glBegin(GL_TRIANGLES)
		for(i in 0..faces size) {
			glNormal3f(normals[faces[i] n1] x,normals[faces[i] n1] y,normals[faces[i] n1] z)
			glVertex3f(vertices[faces[i] v1] x,vertices[faces[i] v1] y,vertices[faces[i] v1] z)
			
			glNormal3f(normals[faces[i] n2] x,normals[faces[i] n2] y,normals[faces[i] n2] z)
			glVertex3f(vertices[faces[i] v2] x,vertices[faces[i] v2] y,vertices[faces[i] v2] z)
			
			glNormal3f(normals[faces[i] n3] x,normals[faces[i] n3] y,normals[faces[i] n3] z)
			glVertex3f(vertices[faces[i] v3] x,vertices[faces[i] v3] y,vertices[faces[i] v3] z)
		}
		glEnd()
		glEndList()
		
		/*glEnableClientState(GL_VERTEX_ARRAY)
		glEnableClientState(GL_NORMAL_ARRAY)
		
		glVertexPointer(3, GL_FLOAT, 0, vertices data)
		glNormalPointer(GL_FLOAT, 0, normals data)
		
		glDrawElements(GL_TRIANGLES, faces size, )
		
		glDisableClientState(GL_VERTEX_ARRAY)
		glDisableClientState(GL_NORMAL_ARRAY)*/
	}
}

TEXTURE := 1

StaticTexture: class extends CProduct {
	
	init: func ~texture {
	}
	
}

