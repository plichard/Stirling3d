use glew
import glew
import scene/MovableObject

Light: class extends MovableObject {
	
	nLight = 0 : static Int
		lightAmbient : Double*
	
	init: func ~lightInit {
		printf("Setting up light\n")
		lightAmbient = [0.5, 0.5, 0.5, 1.0]
		glLightfv(GL_LIGHT0, GL_AMBIENT,lightAmbient)
		glEnable(GL_LIGHT0)
		glEnable(GL_LIGHTING)
		super()
	}
	
	cacou: func {
	}
	
}
