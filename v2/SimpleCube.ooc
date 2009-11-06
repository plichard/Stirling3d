import render/Renderable
import render/basicmodels/Cube
import scene/MovableObject

SimpleCube: class extends MovableObject {
	init: func ~simpleCubeInit {
		fprintf(stderr, "Loading simple cube... ")
		model = Cube new()
		super()	
		fprintf(stderr, "[OK]\n")
	}
}
