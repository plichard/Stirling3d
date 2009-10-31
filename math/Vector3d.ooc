/* Temporary Vector class that will be replaced with the sdk version */

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
	
	clone: func  -> Vector3d {
		return Vector3d new(x,y,z)
	}
}

operator + (a,b: Vector3d) -> Vector3d{
	return Vector3d new(a x + b x, a y + b y,a z + b z)
}

operator - (a,b: Vector3d) -> Vector3d{
	return Vector3d new(a x - b x, a y - b y,a z - b z)
}

operator / (v: Vector3d, n: Double) -> Vector3d{
	return Vector3d new(v x / n, v y / n, v z / n )
}
