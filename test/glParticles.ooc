use gl,glu
import gl.Gl
import glu.Glu
import math.Vector3d
import gfx.[Screen, Particle, Scene]
import sdl.[Sdl, Video]

usleep: extern proto func(UInt)

main: func {
	screen := Screen new(1280,800,32)
	scene := Scene new()
	p1 := Particle new(1000, Vector3d new(0,0,0), Vector3d new(0,0,0.2))
	scene add(p1)
	scene loop()

	usleep(1000000)
}
