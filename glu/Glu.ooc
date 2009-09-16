use glu

Quadric: cover from GLUquadric*

GLU: cover {
	
	perspective: extern(gluPerspective) static func(Double, Double, Double, Double)
	sphere: extern(gluSphere) static func(Quadric, Double , Int, Int)
	newQuadric: extern(gluNewQuadric) static func() -> Quadric
	lookAt: extern(gluLookAt) static func(Double,Double,Double,Double,Double,Double,Double,Double,Double)
}
