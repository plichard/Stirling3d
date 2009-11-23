import scene/MovableObject


MyObject: class extends MovableObject {
	init: func ~object (filename: String) {
		model loadFromObj(filename)
		super()
	}
}
