import Stirling3d
import scene/[Scene, SceneNode, FreeFlyCamera, Light]
import SimpleCube
import utils/Vector3d

main: func {
	engine := Stirling3d new()
	engine newRenderWindow(800,600,32,false)
	cube := SimpleCube new()
	cube2 := SimpleCube new()
	cube2 position set(3,3,3)
	scene := Scene new()
	scene1 := SceneNode new(USE_ARRAYLIST)
	
	scene1 addObject(cube)
	scene1 addObject(cube2)
	scene addNode(scene1)
	scene addLight(Light new())
	
	scene newCamera(FreeFlyCamera new(Vector3d new(10,10,10)))
	
	engine newScene(scene)
	engine mainLoop()
}
