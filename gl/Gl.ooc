use gl

PROJECTION: extern(GL_PROJECTION) const UInt32
DEPTH_TEST: extern(GL_DEPTH_TEST) const UInt32
COLOR_BUFFER_BIT: extern(GL_COLOR_BUFFER_BIT) const UInt32
DEPTH_BUFFER_BIT: extern(GL_DEPTH_BUFFER_BIT) const UInt32
MODELVIEW: extern(GL_MODELVIEW) const UInt32

GL: cover {
	matrixMode: extern(glMatrixMode) static func(UInt32)
	loadIdentity: extern(glLoadIdentity) static func()
	viewport: extern(glViewport) static func(Int, Int, Int, Int)
	enable: extern(glEnable) static func(UInt32)
	vertex3d: extern(glVertex3d) static func(Double, Double, Double)
	vertex2d: extern(glVertex2d) static func(Double, Double)
	rotated: extern(glRotated) static func(Double, Double, Double, Double)
	scaled: extern(glScaled) static func(Double, Double, Double)
	translated: extern(glTranslated) static func(Double, Double, Double)
	popMatrix: extern(glPopMatrix) static func()
	pushMatrix: extern(glPushMatrix) static func()
	clear: extern(glClear) static func(UInt32)
	flush: extern(glFlush) static func()
}
