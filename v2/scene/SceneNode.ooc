use glew
import glew
import utils/[Vector3d, Debug]
import MovableObject
import structs/[ArrayList, LinkedList, List]

SceneNode: class {
	position : Vector3d
	objects : List<MovableObject>
	nodes : ArrayList<SceneNode>
	
	init: func(container: Int) {
		position = Vector3d new(0,0,0)
		match(container) {
			case USE_LINKEDLIST => objects = LinkedList<MovableObject> new()
			case USE_ARRAYLIST  => objects = ArrayList<MovableObject> new()
		}
		nodes = ArrayList<SceneNode> new()
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
	
	render: func {
		glPushMatrix()
		glTranslated(position x, position y, position z)
		for(object in objects) {
			glPushMatrix()
			//printf("translating to: ");object position print()
			glTranslated(object position x, object position y, object position z)
			object render()
			glPopMatrix()
		}
		
		for(node in nodes) {
			node render()
		}
		glPopMatrix()
	}
}

USE_LINKEDLIST := 0
USE_ARRAYLIST := 1
