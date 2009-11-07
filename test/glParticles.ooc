use sdl
import Stirling3d
import gfx/[ParticleGenerator, Particle, FreeFlyCamera, BasicCamera, Scene]
import math/Vector3d
import sdl/Sdl

usleep: extern proto func(UInt)

main: func {
	engine := Stirling3d new()
	engine window(1280,800,32,SDL_OPENGL | SDL_FULLSCREEN)
	engine newScene()
	engine drawAxes(false)
	pg := ParticleGenerator new (
		10,1,    				//life, max life variation
		100,50,						//spawn time, max spawn time variation
		Vector3d new(0,0,10), 		 //initial velocity
		Vector3d new(5,5,5),			//maximal velocity variation
		-1						//fertiliy time
	)
	
	engine scene as Scene camera = FreeFlyCamera new(Vector3d new(10,10,0))
	//engine scene as Scene camera = pg getParticleCamera()
	
	tornade := func(a,b: Vector3d) -> Vector3d {
		return a ^ b
	}
	
	lorenz := func(p: Particle) {
		p vel x = 28.0*(p pos y - p pos x)
		p vel y = p pos x * (46.92 - p pos z) - p pos y
		p vel z = p pos x * p pos y - 4.0 * p pos z
	}
	//pg addFunction(lorenz)
	pg addConstantForce(Vector3d new(0,0,-9.81))
	pg speed = 1
	pg spawnMultiplier = 1
	
	engine scene add(pg)
	
	engine mainLoop()

	usleep(1000000)
}
