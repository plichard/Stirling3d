/* gfx.ParticleGenerator header file, generated with ooc */
#ifndef ___gfx_ParticleGenerator__fwd__
#define ___gfx_ParticleGenerator__fwd__


#include <SDL/SDL.h>
struct _gfx__ParticleGenerator;
typedef struct _gfx__ParticleGenerator gfx__ParticleGenerator;
struct _gfx__ParticleGeneratorClass;
typedef struct _gfx__ParticleGeneratorClass gfx__ParticleGeneratorClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <Stirling3d/gfx/Drawable.h>
#include <sdk/structs/LinkedList-fwd.h>
#include <sdk/structs/ArrayList-fwd.h>
#include <Stirling3d/gfx/Particle-fwd.h>
#include <Stirling3d/sdl/Sdl-fwd.h>
#include <Stirling3d/math/Vector3d-fwd.h>
lang__Class *ParticleGenerator_class();

void ParticleGenerator___load__();
void ParticleGenerator___defaults__(struct _gfx__ParticleGenerator *this);
void ParticleGenerator___defaults___impl(struct _gfx__ParticleGenerator *this);
void ParticleGenerator___destroy__(struct _gfx__ParticleGenerator *this);
void ParticleGenerator___destroy___impl(struct _gfx__ParticleGenerator *this);
struct _gfx__ParticleGenerator *ParticleGenerator_new();
void ParticleGenerator_init(struct _gfx__ParticleGenerator *this);
void ParticleGenerator_init_impl(struct _gfx__ParticleGenerator *this);
struct _gfx__ParticleGenerator *ParticleGenerator_new_withParams(int life, int dlife, int dt, int ddt, struct _math__Vector3d *vel, struct _math__Vector3d *dv);
void ParticleGenerator_init_withParams(struct _gfx__ParticleGenerator *this, int life, int dlife, int dt, int ddt, struct _math__Vector3d *vel, struct _math__Vector3d *dv);
void ParticleGenerator_init_withParams_impl(struct _gfx__ParticleGenerator *this, int life, int dlife, int dt, int ddt, struct _math__Vector3d *vel, struct _math__Vector3d *dv);
void ParticleGenerator_print(struct _gfx__ParticleGenerator *this);
void ParticleGenerator_print_impl(struct _gfx__ParticleGenerator *this);
void ParticleGenerator_setTime(struct _gfx__ParticleGenerator *this, int dt, int ddt);
void ParticleGenerator_setTime_impl(struct _gfx__ParticleGenerator *this, int dt, int ddt);
void ParticleGenerator_setVel(struct _gfx__ParticleGenerator *this, struct _math__Vector3d *vel, struct _math__Vector3d *dv);
void ParticleGenerator_setVel_impl(struct _gfx__ParticleGenerator *this, struct _math__Vector3d *vel, struct _math__Vector3d *dv);
void ParticleGenerator_update(struct _gfx__ParticleGenerator *this, int t);
void ParticleGenerator_update_impl(struct _gfx__ParticleGenerator *this, int t);
void ParticleGenerator_stop(struct _gfx__ParticleGenerator *this);
void ParticleGenerator_stop_impl(struct _gfx__ParticleGenerator *this);
void ParticleGenerator__draw(struct _gfx__ParticleGenerator *this);
void ParticleGenerator__draw_impl(struct _gfx__ParticleGenerator *this);
void ParticleGenerator_addConstantForce(struct _gfx__ParticleGenerator *this, struct _math__Vector3d *f);
void ParticleGenerator_addConstantForce_impl(struct _gfx__ParticleGenerator *this, struct _math__Vector3d *f);
void ParticleGenerator_applyForces(struct _gfx__ParticleGenerator *this);
void ParticleGenerator_applyForces_impl(struct _gfx__ParticleGenerator *this);


#endif // ___gfx_ParticleGenerator__fwd__

