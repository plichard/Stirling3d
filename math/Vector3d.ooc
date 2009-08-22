/* Temporary Vector class that will be replaced with the sdk version */

Vector3d: class {
	
	x = 0, y = 0, z = 0 : Double
	
	new: func(=x,=y,=z) {
		
	}
	
	print: func {
		printf("(%0.2f , %0.2f , %0.2f)\n",x,y,z)
	}
}

/*
main: func {
	
	v1 :=  new Vector3d
	v1 print()
}*/
