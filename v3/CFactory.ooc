import CProduct
import structs/HashMap

CFactory: class {
	
	meshes := HashMap<StaticMesh> new()
	
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
	
	
	loadStatic: func(productType: Int, filename: String) -> CProduct{
		match(productType) {
			case MESH =>  {
				mesh : StaticMesh = null
				mesh = meshes get(filename)
				if(!mesh) {
					printf("loading %s for the first time\n",filename)
					mesh = StaticMesh new(filename)
					meshes add(filename, mesh)
				} else {
					printf("already have %s, returning reference\n",filename)
				}
				
				return mesh	
			}
			case TEXTURE => StaticTexture new()
		}
		return null
	}
}