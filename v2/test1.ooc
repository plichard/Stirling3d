import Stirling3d
import scene/[Scene, SceneNode, FreeFlyCamera, Light]
import SimpleCube
import utils/Vector3d
import MyObject

main: func {
	engine := Stirling3d new(1280,800,32,false)
	
	monkey := MyObject new("render/models/vadertie-1.obj")
	scene := Scene new()
	scene1 := SceneNode new(USE_ARRAYLIST)
	
	scene1 addObject(monkey)
	scene addNode(scene1)
	scene addLight(Light new())
	
	scene newCamera(FreeFlyCamera new(Vector3d new(10,10,10)))
	
	engine newScene(scene)
	engine mainLoop()
}
