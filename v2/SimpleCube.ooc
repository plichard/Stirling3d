import render/Renderable
import render/RenderModel
import render/basicmodels/Cube
import scene/MovableObject

SimpleCube: class extends MovableObject {
	init: func ~simpleCubeInit {
		fprintf(stderr, "Loading simple cube... ")
		model = RenderModel new()
		model loadFromObj("render/models/cube.obj")
		super()	
		fprintf(stderr, "[OK]\n")
	}
}
