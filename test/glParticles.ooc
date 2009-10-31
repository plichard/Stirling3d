import Stirling3d
import gfx/ParticleGenerator
import math/Vector3d

usleep: extern proto func(UInt)

main: func {
	engine := Stirling3d new()
	engine window(800,600)
	engine newScene()
	engine drawAxes(true)
	pg := ParticleGenerator new (
		400,100,    				//life, max life variation
		100,50,						//spawn time, max spawn time variation
		Vector3d new(0,0,50), 		 //initial velocity
		Vector3d new(0,20,0)			//maximal velocity variation
	) 
	pg addConstantForce(Vector3d new(0,0,-9.81))
	
	engine scene add(pg)
	
	engine mainLoop()

	usleep(1000000)
}
