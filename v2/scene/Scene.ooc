use glew,sdl
import glew
import sdl/Video
import structs/ArrayList
import SceneNode, BasicCamera, MovableObject, Light
import utils/Debug

Scene: class {
	
	nodes := ArrayList<SceneNode> new()
	camera : BasicCamera = null
	lights := ArrayList<Light> new()
	
	init: func {
	}
	 
	addNode: func (node: SceneNode) {
		if(!node) {
			Exception new(This, "Trying to add a null node!!!") throw()
		}
		nodes add(node)
		
	}
	
	newCamera: func(=camera) {  
		if(!camera) {
			Exception new(This, "Trying to add a null camera!!!")
		}
	}
	
	getEventCandidates: func -> ArrayList<MovableObject> {
		printf("getting candidates\n")
		candidates := ArrayList<MovableObject> new()
		if(camera && camera candidate) {
			printf("Adding camera to candidates\n")
			candidates add(camera)
		}
			
		for(node: SceneNode in nodes) {
			candidates addAll(node getEventCandidates())
		}
		return candidates
	}
	
	render: func {
		glClear( GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT )
		glEnable(GL_DEPTH_TEST)
		lightAmbient := [1, 1, 1, 1]
		glLightfv(GL_LIGHT0, GL_AMBIENT,lightAmbient)
		glEnable(GL_LIGHT0)
		glEnable(GL_LIGHTING)
		
		glMatrixMode( GL_MODELVIEW )
		glLoadIdentity( )
		camera look()
		for(node: SceneNode in nodes) {
			node render()
		}
		glFlush()
		SDLVideo glSwapBuffers()
	}
	
	addLight: func(l: Light) {
		lights add(l)
	}
}
