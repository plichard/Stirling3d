use glew,glu
import glew,glu/Glu
import structs/[LinkedList,HashMap,Array]
import GameObject
import io/[FileWriter,FileReader]
import CFactory
import CProduct
import utils/[types,text]
import Camera,FFCamera

World: class {
	
	objects := LinkedList<GameObject> new()
	
	init: func {}
	id := 0
	
	render: func(mode: GLenum)  {
		if(mode == GL_SELECT) {
			//printf("rendering in select mode!!!\n")
			for(object in objects) {
				glLoadName(object id)
				//printf("%d",id)
				object render()
			}
			//println()
		} else {
			for(object in objects) {
				object render()
			}
		}
	}
	
	picking: func (x,y: Int,cam: Camera)  {
		BUFSIZE := 512
		selectBuf : GLuint[BUFSIZE]
		hits: GLint
		viewport : GLint[4]
		
		
		glSelectBuffer(BUFSIZE, selectBuf)
		glGetIntegerv(GL_VIEWPORT, viewport)
		
		glRenderMode(GL_SELECT)
		glInitNames()
		glPushName(0)

		glMatrixMode(GL_PROJECTION)
		glPushMatrix()
			glLoadIdentity()
			
			gluPickMatrix(x as GLdouble, (viewport[3] - y) as GLdouble,
						 5.0, 5.0, viewport)
			gluPerspective(60, 1280 as Float / 800 as Float, 0.01, 1000)
			glMatrixMode(GL_MODELVIEW)	
			//glLoadIdentity()  //
			//cam look()
			render(GL_SELECT)
			glMatrixMode(GL_PROJECTION)
		glPopMatrix()
		

		hits = glRenderMode(GL_RENDER)
		processHits(hits, selectBuf)
		
		glMatrixMode(GL_MODELVIEW)
		glFlush()
		
	}
	
	processHits: func(hits: GLint, buffer: GLuint*) {
		i,j: UInt
		names: GLuint
		ptr: GLuint*
		if(hits == 0)
			return
		else {
			printf(".")
			fflush(stdout)
			return
		}
		printf("hits = %d\n", hits)
		ptr = buffer as GLuint*
		for (i in 0..hits) {  /* for each hit  */
			names = ptr@
			printf(" number of names for hit = %d\n", names); ptr += 1
			printf("  z1 is %g;", (ptr@/0x7fffffff) as Float); ptr += 1
			printf(" z2 is %g\n", (ptr@/0x7fffffff) as Float); ptr += 1
			printf("   the name is ")
			for(j in 0..names) { /* for each name */
				printf("%d ", ptr@); ptr += 1
			}
			println()
		}
	}
	
	add: func(object: GameObject) {
		objects add(object)
		object id = id
		id += 1
	}
	
	
	//removes all the objects in the world
	clean: func {
		objects clear()
		}
	
	save: func(filename: String) -> Bool {
		printf("Opening %s...\n",filename)
		target := FileWriter new(filename)
		if(!target) {
			printf("O_O: Cannot open %s !\n",filename)
			return false
		}
		
		target write( CFactory get() meshes size toString())
		target write("\n")
		for(mesh in CFactory get() meshes) {
			target write(mesh id toString())
			target write(" ")
			target write(mesh filename + "\n")
		}
		
		target write(objects size&,Int size)
		for(object in objects) {
			target write(object model id&, Int size)
			target write(object position x&,Double size)
			target write(object position y&,Double size)
			target write(object position z&,Double size)
			
			target write(object rotation x&,Double size)
			target write(object rotation y&,Double size)
			target write(object rotation z&,Double size)
			
			target write(object scale x&,Double size)
			target write(object scale y&,Double size)
			target write(object scale z&,Double size)
		}
		printf("Level saved =)\n")
			
		return true
	}
	
	load: func(filename: String) -> Bool {
		printf("Opening %s...\n",filename)
		source := FileReader new(filename)
		if(!source) {
			printf("O_O: Cannot open %s !\n",filename)
			return false
		}
		objects clear()
		CFactory get() clear()
		fileMeshes := HashMap<String> new()
		line := readLine(source)
		nMeshes := 0
		sscanf(line,"%d",nMeshes&)
		printf("nMeshes: %d\n",nMeshes)
		for(i in 0..nMeshes) {
			line := readLine(source)
			id: Int
			filename := String new(1024)
			sscanf(line,"%d %s",id&,filename)
			printf("id: %d, filename: %s\n",id,filename)
			fileMeshes add(id toString(),filename)
		}
		
		nObjects: Int
		source read(nObjects&,0,Int size)
		printf("nObjects: %d\n",nObjects)
		for(i in 0..nObjects) {
			id: Int
			source read(id&,0,Int size)
			px,py,pz,rx,ry,rz,sx,sy,sz: Double
			source read(px&,0,Double size)
			source read(py&,0,Double size)
			source read(pz&,0,Double size)
			
			source read(rx&,0,Double size)
			source read(ry&,0,Double size)
			source read(rz&,0,Double size)
			
			source read(sx&,0,Double size)
			source read(sy&,0,Double size)
			source read(sz&,0,Double size)
			
			pos := Double3 new(px,py,pz)
			rot := Double3 new(rx,ry,rz)
			scl := Double3 new(sx,sy,sz)
			
			printf("id: %d, pos: %s, rot: %s, scl: %s\n",id, pos toString(), rot toString(), scl toString())
			add(GameObject new(fileMeshes get(id toString()),pos,rot,scl))
		}
		
		printf("Level loaded =)\n")
			
		return true
	}
}
