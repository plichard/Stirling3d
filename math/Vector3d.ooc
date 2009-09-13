/* Temporary Vector class that will be replaced with the sdk version */

Vector3d: class {
	
	x = 0, y = 0, z = 0 : Double
	
	init: func(=x,=y,=z) {
		
	}
	
	print: func {
		printf("(%0.2f , %0.2f , %0.2f)\n",x,y,z)
	}
}

operator + (a,b: Vector3d) -> Vector3d{
	return Vector3d new(a x + b x, a y + b y,a z + b z)
}

/*
main: func {
	
	v1 :=  new Vector3d
	v1 print()
}*/
