use gl,glu
import gl/Gl
import glu/Glu
import math/Vector3d
import gfx/[Screen, Particle, Scene]
import sdl/[Sdl, Video]
import gfx/ParticleGenerator

usleep: extern proto func(UInt)

main: func {
	screen := Screen new(1280,800,32)
	scene := Scene new()
	p1 := ParticleGenerator new()
	scene add(p1)
	scene loop()

	usleep(1000000)
}
