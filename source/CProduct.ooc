use glew
import glew
import io/FileReader
import utils/types
import structs/ArrayList

CProduct: abstract class {
	init: func ~cproduct {
	}
	filename: String
	render: func {}
	id: Int
}

MESH := 0

StaticMesh: class extends CProduct {
	vertices : ArrayList<Float3>
	normals : ArrayList<Float3>
	faces : ArrayList<FaceNoTex>
	dlist : GLuint = 0
	
	init: func ~mesh(=filename) {
		super()
		source := FileReader new(filename)
		nVertices : Int = 0
		nNormals : Int = 0
		nFaces : Int = 0
		source read(nVertices&,0,Int size)
		source read(nFaces&,0,Int size)
		
		nNormals = nVertices
		
		printf("%d vertices, %d faces and %d vertex normals\n",nVertices, nFaces, nNormals)
		
		vertices = ArrayList<Float3> new(nVertices)
		normals = ArrayList<Float3> new(nVertices)
		faces = ArrayList<VFace> new(nFaces)
		
		source read(vertices data,0,Float3 size * nVertices)
		source read(normals data,0,Float3 size * nVertices)
		source read(faces data,0,VFace size * nFaces)
		
	}
	
	prepare: func {
		dlist = glGenLists(1)
		glNewList(dlist,GL_COMPILE)
		draw()
		glEndList()
		
		/*glEnableClientState(GL_VERTEX_ARRAY)
		glEnableClientState(GL_NORMAL_ARRAY)
		
		glVertexPointer(3, GL_FLOAT, 0, vertices data)
		glNormalPointer(GL_FLOAT, 0, normals data)
		
		glDrawElements(GL_TRIANGLES, faces size, )
		
		glDisableClientState(GL_VERTEX_ARRAY)
		glDisableClientState(GL_NORMAL_ARRAY)*/
	}
	
	draw: func {
		//glColor3ub(255,255,255)
		glBegin(GL_TRIANGLES)
		printf("%d faces\n",faces size)
		for(i in 0..faces size) {
			//glColor3ub(rand() % 255,rand() % 255,rand() % 255)
			glNormal3f(normals[faces[i] v1] x,normals[faces[i] v1] y,normals[faces[i] v1] z)
			glVertex3f(vertices[faces[i] v1] x,vertices[faces[i] v1] y,vertices[faces[i] v1] z)
			//printf("%f,%f,%f\n",normals[faces[i] v1] x,normals[faces[i] v1] y,normals[faces[i] v1] z)
			
			glNormal3f(normals[faces[i] v2] x,normals[faces[i] v2] y,normals[faces[i] v2] z)
			glVertex3f(vertices[faces[i] v2] x,vertices[faces[i] v2] y,vertices[faces[i] v2] z)
			//printf("%f,%f,%f\n",normals[faces[i] v2] x,normals[faces[i] v2] y,normals[faces[i] v2] z)
			
			glNormal3f(normals[faces[i] v3] x,normals[faces[i] v3] y,normals[faces[i] v3] z)
			glVertex3f(vertices[faces[i] v3] x,vertices[faces[i] v3] y,vertices[faces[i] v3] z)
			//printf("%f,%f,%f\n",normals[faces[i] v3] x,normals[faces[i] v3] y,normals[faces[i] v3] z)
		}
		glEnd()
	}
	
	render: func {
		glCallList(dlist)
	}
}

TEXTURE := 1

StaticTexture: class extends CProduct {
	
	init: func ~texture {
	}
	
}

