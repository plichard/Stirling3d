/* gfx.Particle header file, generated with ooc */
#ifndef ___gfx_Particle__fwd__
#define ___gfx_Particle__fwd__


#include <GL/glew.h>
#include <GL/glu.h>
struct _gfx__Particle;
typedef struct _gfx__Particle gfx__Particle;
struct _gfx__ParticleClass;
typedef struct _gfx__ParticleClass gfx__ParticleClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <Stirling3d/gfx/Drawable.h>
#include <out/glew-fwd.h>
#include <ooc-glu/glu/Glu-fwd.h>
#include <Stirling3d/math/Vector3d-fwd.h>
lang__Class *Particle_class();

void Particle___load__();
void Particle___defaults__(struct _gfx__Particle *this);
void Particle___defaults___impl(struct _gfx__Particle *this);
void Particle___destroy__(struct _gfx__Particle *this);
void Particle___destroy___impl(struct _gfx__Particle *this);
bool Particle_isAlive(struct _gfx__Particle *this);
bool Particle_isAlive_impl(struct _gfx__Particle *this);
struct _gfx__Particle *Particle_new_lifePosVal(int life, struct _math__Vector3d *pos, struct _math__Vector3d *vel);
void Particle_init_lifePosVal(struct _gfx__Particle *this, int life, struct _math__Vector3d *pos, struct _math__Vector3d *vel);
void Particle_init_lifePosVal_impl(struct _gfx__Particle *this, int life, struct _math__Vector3d *pos, struct _math__Vector3d *vel);
void Particle_update(struct _gfx__Particle *this, int t);
void Particle_update_impl(struct _gfx__Particle *this, int t);
void Particle_addForce(struct _gfx__Particle *this, struct _math__Vector3d *f);
void Particle_addForce_impl(struct _gfx__Particle *this, struct _math__Vector3d *f);
void Particle_print(struct _gfx__Particle *this);
void Particle_print_impl(struct _gfx__Particle *this);
void Particle__draw(struct _gfx__Particle *this);
void Particle__draw_impl(struct _gfx__Particle *this);


#endif // ___gfx_Particle__fwd__

