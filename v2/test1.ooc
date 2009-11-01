import Stirling3d
import scene/Scene
import SimpleCube

main: func {
	engine := Stirling3d new()
	engine newRenderWindow(1280,800,32,true)
	
	scene := Scene new()
	
	engine newScene(scene)
	engine mainLoop()
}
