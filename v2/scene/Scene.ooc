import structs/ArrayList
import SceneNode, BasicCamera, MovableObject

Scene: class {
	
	nodes := ArrayList<SceneNode> new()
	camera : BasicCamera = null
	
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
		candidates := ArrayList<MovableObject> new()
		if(camera)
			candidates add(camera)
			
		for(node: SceneNode in nodes) {
			node getEventCandidates()
		}
	}
	
}
