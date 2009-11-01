import Stirling3d

main: func {
	engine := Stirling3d new()
	engine newRenderWindow(1280,800,32,true)
	engine newScene(null)
	engine mainLoop()
}
