import utils/Vector3d
import MovableObject
import structs/[ArrayList, LinkedList, List]

SceneNode: class {
	position := Vector3d new(0,0,0)
	objects : List<MovableObject>
	nodes : ArrayList<SceneNode>
	
	init: func(container: Int) {
		match(container) {
			case USE_LINKEDLIST => objects = ArrayList<MovableObject> new()
			case USE_ARRAYLIST  => objects = LinkedList<MovableObject> new()
		}
	}
	
	setPos: func (x,y,z: Double){
		position set(x,y,z)
	}
	
	getPos: func -> Vector3d {
		return position clone()
	}
	
	getEventCandidates: func -> ArrayList<MovableObject> {
		candidates := ArrayList<MovableObject> new()
		for(object in objects) {
			if(object candidate) {
				candidates add(object)
			}
		}
		
		for(node in nodes) {
			if(node getEventCandidates() size() > 0) {
				candidates addAll(node getEventCandidates())
			}
		}
		return candidates
	}
	
	addObject: func(object: MovableObject) {
		if(!object) {
			Exception new(This, "Trying to add a null object!!!")
		}
		objects add(object)
	}
	
	
}

USE_LINKEDLIST := 0
USE_ARRAYLIST := 1
