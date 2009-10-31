/* test.glParticles source file, generated with ooc */
#include "glParticles.h"
#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <Stirling3d/Stirling3d.h>
#include <Stirling3d/gfx/ParticleGenerator.h>
#include <Stirling3d/math/Vector3d.h>
int main() {
	GC_INIT();
	_test_glParticles_load();
	#line 8 "./test/glParticles.ooc"
	Stirling3d *engine = Stirling3d_new();
	#line 9 "./test/glParticles.ooc"
	Stirling3d_window(engine, 800, 600);
	#line 10 "./test/glParticles.ooc"
	Stirling3d_newScene(engine);
	#line 11 "./test/glParticles.ooc"
	Stirling3d_drawAxes(engine, true);
	#line 12 "./test/glParticles.ooc"
	gfx__ParticleGenerator *pg = ParticleGenerator_new_withParams(400, 100, 100, 50, Vector3d_new_withParams(0, 0, 50), Vector3d_new_withParams(0, 20, 0));
	#line 18 "./test/glParticles.ooc"
	ParticleGenerator_addConstantForce(pg, Vector3d_new_withParams(0, 0, 0 - 9.81));
	#line 20 "./test/glParticles.ooc"
	Scene_add(engine->scene, ((gfx__Drawable *) (pg)));
	#line 22 "./test/glParticles.ooc"
	Stirling3d_mainLoop(engine);
	#line 24 "./test/glParticles.ooc"
	usleep(((unsigned int) (1000000)));
	#line 7 "./test/glParticles.ooc"
	return 0;
}


void _test_glParticles_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_Stirling3d_load();
		_gfx_ParticleGenerator_load();
		_math_Vector3d_load();
	}
}

