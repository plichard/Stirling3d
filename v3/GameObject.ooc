use glew
import glew
import Movable
import CFactory,CProduct
import utils/types

BOX := 0
PLANE := 1
SPHERE := 2


GameObject: class extends Movable {
	
	model: CProduct = null
	bounds := BOX
	boundScale := Double3 new(1,1,1)
	
	renderBounds := false
	
	id: Int
	
	init: func ~gameObject {
		super()
	}
	
	init: func ~withNamePos (name: String,pos: Double3 ) {
		super()
		position = pos
		setDisplayModel(name)
	}
	
	init: func ~withNamePosRotScale (name: String,pos,rot,scale: Double3 ) {
		super()
		position = pos
		rotation = rot
		this scale = scale
		setDisplayModel(name)
	}

	render: func {
		glPushMatrix()
		glTranslated(position x, position y, position z)
		glRotated(1,rotation x, rotation y, rotation z)
		glScaled(scale x, scale y, scale z)
		if(model)
			model render()
			
		glPopMatrix()
	}
	
	
	setDisplayModel: func(name: String) {
		model = CFactory get() loadStatic(MESH,name)
	}

}
