
import render/RenderModel
import render/VertexGroup

Cube: class extends RenderModel {
	init: func {
		cube := VertexGroup new()
		v1 := Vertex3d new(-1, 1,-1)
		v2 := Vertex3d new(-1, 1, 1)
		v3 := Vertex3d new( 1, 1, 1)
		v4 := Vertex3d new( 1, 1,-1)
		v5 := Vertex3d new(-1,-1,-1)
		v6 := Vertex3d new(-1,-1, 1)
		v7 := Vertex3d new( 1,-1, 1)
		v8 := Vertex3d new( 1,-1,-1)
		
		cube vertices add(v1)
		cube vertices add(v2)
		cube vertices add(v3)
		cube vertices add(v4)
		cube vertices add(v5)
		cube vertices add(v6)
		cube vertices add(v7)
		cube vertices add(v8)
		
		c1 := Color3d new(1,0,0,1)
		c2 := Color3d new(0,1,0,1)
		c3 := Color3d new(0,0,1,1)
		
		f1 := Quad new(v1, v2, v3, v4,
					   c1, c1, c1, c1)
		f2 := Quad new(v2, v3, v6, v7,
					   c1, c1, c1, c1)
		f3 := Quad new(v6, v7, v5, v8,
					   c1, c1, c1, c1)
		f4 := Quad new(v1, v2, v8, v5,
					   c1, c1, c1, c1)
		f5 := Quad new(v3, v4, v8, v7,
					   c1, c1, c1, c1)
		f6 := Quad new(v1, v2, v5, v6,
					   c1, c1, c1, c1)
					   
		cube faces add(f1)
		cube faces add(f2)
		cube faces add(f3)
		cube faces add(f4)
		cube faces add(f5)
		cube faces add(f6)
		
		addGroup(cube)
		
		isStatic = true
	}	

}
