import render/Renderable
import render/basicmodels/Cube

SimpleCube: class extends Renderable {
	init: func {
		model = Cube new()
	}
}
