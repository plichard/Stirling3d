use glew, glu

import glew

PI := 3.14159265 

Vector3d: class {
	
	x = 0, y = 0, z = 0 : Double
	
	init: func ~withParams (=x,=y,=z) {
		
	}
	
	init: func {}
		
	isNull: func -> Bool{
		if(x && y && z)
			return true
		else
			return false
	}
	
	set: func(=x,=y,=z) {}
	
	print: func {
		printf("(%0.2f , %0.2f , %0.2f)\n",x,y,z)
	}
	
	length: func -> Double{
		sqrt(x*x + y*y + z*z)
	}
	
	glPrint: func {
		glPushMatrix()
		glBegin(GL_LINES)
		glVertex3d(0,0,0)
		glVertex3d(x,y,z)
		glEnd()
		glPopMatrix()
	}
	
	clone: func  -> Vector3d {
		return Vector3d new(x,y,z)
	}
	
	normalize: func {
		l := length()
		x /= l
		y /= l
		z /= l
	}
}

operator + (a,b: Vector3d) -> Vector3d{
	return Vector3d new(a x + b x, a y + b y,a z + b z)
}

operator += (a,b: Vector3d) {
	a x += b x
	a y += b y
	a z += b z
}

operator - (a,b: Vector3d) -> Vector3d{
	return Vector3d new(a x - b x, a y - b y,a z - b z)
}

operator -= (a,b: Vector3d) {
	a x -= b x
	a y -= b y
	a z -= b z
}

operator * (v: Vector3d, n: Int) -> Vector3d{
	return Vector3d new(v x * n, v y * n,v z * n)
}

operator * ~asDouble (v: Vector3d, n: Double) -> Vector3d{
	return Vector3d new(v x * n, v y * n,v z * n)
}

operator / (v: Vector3d, n: Double) -> Vector3d{
	return Vector3d new(v x / n, v y / n, v z / n )
}

operator ^ (a,b: Vector3d) -> Vector3d {
	return Vector3d new(a y * b z - a z * b y,
						a z * b x - a x * b z,
						a x * b y - a y * b x)
}
