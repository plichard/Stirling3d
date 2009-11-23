use glew
import glew
import RenderModel

Renderable: abstract class {
	
	isStatic := true   /* Can we use a single display list to render it? */
	hasList := false
	displayList : GLuint
	model := RenderModel new()
	
	init: func ~renderableInit {
		if(isStatic && !hasList) {
			if(model) {
				makeDisplayList()
				hasList = true
				model clear()
			}
		}
	}
	
	
	render: func {
		glPushMatrix()
		if(isStatic && hasList) {
			glCallList(displayList)
		} else {
			model render()
		}
		glPopMatrix()
	}
	
	setRenderModel: func(=model) {
		if(!model) {
			Exception new(This,"Trying to add a null render model !!!") throw()
		}
	}
	
	makeDisplayList: func {
		if(!isStatic) {
			fprintf(stderr, "Warning: Creating a display list for a non-static object!\n")
		}
		displayList = glGenLists(1)
		glNewList(displayList, GL_COMPILE)
		model render()
		glEndList()
	}
	
}
