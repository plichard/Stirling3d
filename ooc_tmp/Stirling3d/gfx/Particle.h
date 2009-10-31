/* gfx.Particle header file, generated with ooc */
#ifndef ___gfx_Particle__
#define ___gfx_Particle__


#include "Particle-fwd.h"


struct _gfx__Particle{
	struct _gfx__Drawable __super__;
	int life;
	struct _math__Vector3d *vel;
	struct _math__Vector3d *force;
};


struct _gfx__ParticleClass{
	struct _gfx__DrawableClass __super__;
	bool (*isAlive)(struct _gfx__Particle *);
	struct _gfx__Particle * (*new_lifePosVal)(int, struct _math__Vector3d *, struct _math__Vector3d *);
	void (*init_lifePosVal)(struct _gfx__Particle *, int, struct _math__Vector3d *, struct _math__Vector3d *);
	void (*addForce)(struct _gfx__Particle *, struct _math__Vector3d *);
	void (*print)(struct _gfx__Particle *);
	GLUquadric *params;
};


void _gfx_Particle_load();

#endif // ___gfx_Particle__

