import CProduct
import structs/[HashMap,LinkedList]

CFactory: class {
	
	meshes := HashMap<StaticMesh> new()
	names := LinkedList<String> new()
	id := 0
	
	// singleton
	instance : static This = null
	get: static func -> This{
		if(!instance) {
			instance = new()
		}
		return instance
	}
	//
	init: func {}
	
	
	loadStatic: func(productType: Int, filename: String) -> CProduct {
		match(productType) {
			case MESH =>  {
				mesh : StaticMesh = null
				mesh = meshes get(filename)
				if(!mesh) {
					printf("loading %s for the first time\n",filename)
					mesh = StaticMesh new(filename)
					meshes add(filename, mesh)
					names add(filename)
					mesh prepare()
					mesh id = id
					id += 1
				} else {
					//printf("already have %s, returning cached version\n",filename)
				}
				
				return mesh	
			}
			case TEXTURE => StaticTexture new()
		}
		return null
	}
	
	clear: func {
		meshes clear()
		id = 0
	}
}
