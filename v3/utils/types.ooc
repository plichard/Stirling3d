


Float2: cover {
	x,y: Float
	new: static func(x,y: Float) -> This {
		f2 : This
		f2 x = x
		f2 y = y
		return f2
	}
}

Float3: cover {
	x,y,z: Float
	new: static func(x,y,z: Float) -> This {
		f3 : This
		f3 x = x
		f3 y = y
		f3 z = z
		return f3
	}
	
	new: static func ~copy(f: This) -> This {
		return This new(f x, f y, f z)
	}
}

operator == (a,b: Float3) -> Bool {
	if(a x == b x && a y == b y && a z == b z) {
		return true
	}
	return false
}

operator += (a,b: Float3) {
	a x += b x
	a y += b y
	a z += b z
}

operator + (a,b: Float3) -> Float3 {
	return Float3 new(a x + b x, a y + b y, a z + b z,)
}

operator / (a: Float3, d: Float) -> Float3 {
	return Float3 new(a x/d,a y/d,a z/d)
}

Float4: cover {
	x,y,z,w: Float
	new: static func(x,y,z,w: Float) -> This {
		f4 : This
		f4 x = x
		f4 y = y
		f4 z = z
		f4 w = w
		return f4
	}
}

Octet3: cover {
	x,y,z: Octet
	new: static func(x,y,z: Octet) -> This {
		f3 : This
		f3 x = x
		f3 y = y
		f3 z = z
		return f3
	}
}

Octet4: cover {
	x,y,z,w: Octet
	new: static func(x,y,z,w: Octet) -> This {
		f4 : This
		f4 x = x
		f4 y = y
		f4 z = z
		f4 w = w
		return f4
	}
}

Int3: cover {
	x,y,z: Int
	new: static func(x,y,z: Int) -> This {
		f3 : This
		f3 x = x
		f3 y = y
		f3 z = z
		return f3
	}
}

Int2: cover {
	x,y: Int
	new: static func(x,y: Int) -> This {
		f2 : This
		f2 x = x
		f2 y = y
		return f2
	}
}

//vertex face, contains only vertices and texture coordinates since the normals and vertices have the same index
VFace: cover {
	v1,v2,v3: Int
	t1,t2,t3: Int
}

Face: cover {
	v1,v2,v3: Int	//vertices
	t1,t2,t3: Int	//tex coords
	n1,n2,n3: Int	//normals
}

FaceNoTex: cover {
	v1,v2,v3: Int	//vertices
	n1,n2,n3: Int	//normals
}
