/* gfx.ParticleGenerator header file, generated with ooc */
#ifndef ___gfx_ParticleGenerator__
#define ___gfx_ParticleGenerator__


#include "ParticleGenerator-fwd.h"


struct _gfx__ParticleGenerator{
	struct _gfx__Drawable __super__;
	int ddt;
	int dt;
	int life;
	int dlife;
	struct _math__Vector3d *vel;
	struct _math__Vector3d *dv;
	uint32_t pTime, cTime;
	struct _structs__LinkedList *particles;
	struct _structs__LinkedList *constantForces;
};


struct _gfx__ParticleGeneratorClass{
	struct _gfx__DrawableClass __super__;
	struct _gfx__ParticleGenerator * (*new)();
	void (*init)(struct _gfx__ParticleGenerator *);
	struct _gfx__ParticleGenerator * (*new_withParams)(int, int, int, int, struct _math__Vector3d *, struct _math__Vector3d *);
	void (*init_withParams)(struct _gfx__ParticleGenerator *, int, int, int, int, struct _math__Vector3d *, struct _math__Vector3d *);
	void (*print)(struct _gfx__ParticleGenerator *);
	void (*setTime)(struct _gfx__ParticleGenerator *, int, int);
	void (*setVel)(struct _gfx__ParticleGenerator *, struct _math__Vector3d *, struct _math__Vector3d *);
	void (*stop)(struct _gfx__ParticleGenerator *);
	void (*addConstantForce)(struct _gfx__ParticleGenerator *, struct _math__Vector3d *);
	void (*applyForces)(struct _gfx__ParticleGenerator *);
};


void _gfx_ParticleGenerator_load();

#endif // ___gfx_ParticleGenerator__

