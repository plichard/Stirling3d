use glew,glu
import glew,glu/Glu
import structs/[LinkedList,HashMap,ArrayList]
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
	pickedID := -1
	picked : GameObject = null
	
	render: func(mode: GLenum)  {
		if(mode == GL_SELECT) {
			for(object in objects) {
				glLoadName(object id)
				object render()
			}
		} else {
			picked = null
			for(object in objects) {
				if(object id == pickedID) {
					picked = object
					glColor3ub(255,0,0)
				} else {
					glColor3ub(255,255,255)
				}
				object render()
			}
		}
	}
	
	picking: func (x,y: Int,cam: Camera)  -> Int {
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
			glLoadIdentity()
			cam look()
			render(GL_SELECT)
			glMatrixMode(GL_PROJECTION)
		glPopMatrix()
		

		hits = glRenderMode(GL_RENDER)
		//processHits(hits, selectBuf)
		glMatrixMode(GL_MODELVIEW)
		glFlush()
		
		
		if(hits > 0) {
			minz := 0xFFFFFFFF
			minid := -1
			for(i in 0..hits) {
				if(selectBuf[i * 4 + 1] < minz) {
					minz = selectBuf[i * 4 + 1]
					minid = selectBuf[i * 4 + 3] as GLubyte
				}
			}
			pickedID = minid
			return minid
		} 
	
		pickedID = -1
		return -1	
		
	}
	
	processHits: func(hits: GLint, names: GLuint*) {
		printf("%d hits:\n", hits)
		jayjay := 0x7fffffff
		for (i in 0..hits) {
			printf(	"Number: %d\nMin Z: 0x%0x\nMax Z: 0x%0x\nName on stack: %d\n",
					names[i * 4] as GLubyte,
					/*(names[i * 4 + 1]) as Float / (jayjay& as Float*)@,
					(names[i * 4 + 2]) as Float / (jayjay& as Float*)@,*/
					(names[i * 4 + 1]),
					(names[i * 4 + 2]),
					names[i * 4 + 3] as GLubyte)
				}
		
		println()
	}
	
	add: func(object: GameObject) {
		objects add(object)
		object id = id
		id += 1
	}
	
	
	//removes all the objects in the world
	clean: func {
		objects clear()
		CFactory get() clear()
		}
	
	save: func(filename: String) -> Bool {
		printf("Opening %s...\n",filename)
		target := FileWriter new(filename)
		if(!target) {
			printf("O_O: Cannot open %s !\n",filename)
			return false
		}
		
		printf("Saving %d meshes...\n",CFactory get() meshes size)
		target write( CFactory get() meshes size toString())
		target write("\n")
		for(mesh in CFactory get() meshes) {
			target write(mesh id toString())
			target write(" ")
			target write(mesh filename + "\n")
		}
		
		printf("Saving %d objects...\n",objects size)
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
		target close()
			
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
			
			//printf("id: %d, pos: %s, rot: %s, scl: %s\n",id, pos toString(), rot toString(), scl toString())
			add(GameObject new(fileMeshes get(id toString()),pos,rot,scl))
		}
		printf("Loaded %d objects\n",objects size)
		printf("Level loaded =)\n")
		source close()
			
		return true
	}
}
