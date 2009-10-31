/* gfx.Particle source file, generated with ooc */
#include "Particle.h"
#include <out/glew.h>
#include <ooc-glu/glu/Glu.h>
#include <Stirling3d/math/Vector3d.h>

void Particle___defaults___impl(struct _gfx__Particle *this){
	Drawable___defaults___impl((gfx__Drawable *) this);
	#line 10 "./gfx/Particle.ooc"
	this->life = 1000;
	#line 11 "./gfx/Particle.ooc"
	this->vel = Vector3d_new_withParams(0, 0, 1);
	#line 12 "./gfx/Particle.ooc"
	this->force = Vector3d_new_withParams(0, 0, 0);
}

void Particle___destroy___impl(struct _gfx__Particle *this){
}

bool Particle_isAlive_impl(struct _gfx__Particle *this){
	#line 15 "./gfx/Particle.ooc"
	if (this->life > 0){
		#line 16 "./gfx/Particle.ooc"
		return true;
	}
	#line 19 "./gfx/Particle.ooc"
	this->life = 0;
	#line 20 "./gfx/Particle.ooc"
	return false;
}

void Particle_init_lifePosVal_impl(struct _gfx__Particle *this, int life, struct _math__Vector3d *pos, struct _math__Vector3d *vel){
	#line 23 "./gfx/Particle.ooc"
	this->life = life;
	#line 24 "./gfx/Particle.ooc"
	((gfx__Drawable*) this)->pos = Vector3d_clone(pos);
	#line 25 "./gfx/Particle.ooc"
	this->vel = Vector3d_clone(vel);
	#line 26 "./gfx/Particle.ooc"
	if (!((gfx__ParticleClass*) Particle_class())->params){
		#line 27 "./gfx/Particle.ooc"
		((gfx__ParticleClass*) Particle_class())->params = (GLUquadric *) gluNewQuadric();
	}
}

void Particle_update_impl(struct _gfx__Particle *this, int t){
	#line 33 "./gfx/Particle.ooc"
	this->vel = __OP_ADD_Vector3d_Vector3d__Vector3d(this->vel, __OP_DIV_Vector3d_Double__Vector3d(this->force, ((double) (t))));
	#line 34 "./gfx/Particle.ooc"
	struct _math__Vector3d *dpos = __OP_DIV_Vector3d_Double__Vector3d(this->vel, ((double) (t)));
	#line 35 "./gfx/Particle.ooc"
	((gfx__Drawable*) this)->pos = __OP_ADD_Vector3d_Vector3d__Vector3d(((gfx__Drawable*) this)->pos, dpos);
	#line 36 "./gfx/Particle.ooc"
	this->life -= 1;
	#line 37 "./gfx/Particle.ooc"
	Vector3d_set(this->force, 0, 0, 0);
}

void Particle_addForce_impl(struct _gfx__Particle *this, struct _math__Vector3d *f){
	#line 41 "./gfx/Particle.ooc"
	this->force = __OP_ADD_Vector3d_Vector3d__Vector3d(this->force, f);
}

void Particle_print_impl(struct _gfx__Particle *this){
	#line 46 "./gfx/Particle.ooc"
	println();
	#line 47 "./gfx/Particle.ooc"
	printf("life: %d\n", this->life);
	#line 48 "./gfx/Particle.ooc"
	printf("pos: (%f,%f,%f)\n", ((gfx__Drawable*) this)->pos->x, ((gfx__Drawable*) this)->pos->y, ((gfx__Drawable*) this)->pos->z);
	#line 49 "./gfx/Particle.ooc"
	printf("vel: (%f,%f,%f)\n", this->vel->x, this->vel->y, this->vel->z);
}

void Particle__draw_impl(struct _gfx__Particle *this){
	#line 54 "./gfx/Particle.ooc"
	gluSphere(((gfx__ParticleClass*) Particle_class())->params, ((double) (5)), 10, 10);
}

lang__Class *Particle_class(){
	static bool __done__ = false;
	static gfx__ParticleClass class = {{{{
					.instanceSize = sizeof(gfx__Particle),
					.size = sizeof(void*),
					.name = "Particle",
				},
				.__load__ = (void (*)()) Particle___load__,
				.__defaults__ = (void (*)(struct _lang__Object *)) Particle___defaults___impl,
				.__destroy__ = (void (*)(struct _lang__Object *)) Particle___destroy___impl,
			},
			.new_drawableAbstract = (struct _gfx__Drawable * (*)()) Drawable_new_drawableAbstract,
			.init_drawableAbstract = Drawable_init_drawableAbstract_impl,
			.draw = (void (*)(struct _gfx__Drawable *)) Drawable_draw_impl,
			._draw = (void (*)(struct _gfx__Drawable *)) Particle__draw_impl,
			._drawAxes = (void (*)(struct _gfx__Drawable *)) Drawable__drawAxes_impl,
			.update = (void (*)(struct _gfx__Drawable *, int)) Particle_update_impl,
		},
		.isAlive = Particle_isAlive_impl,
		.new_lifePosVal = Particle_new_lifePosVal,
		.init_lifePosVal = Particle_init_lifePosVal_impl,
		.addForce = Particle_addForce_impl,
		.print = Particle_print_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Drawable_class();
	}
	return classPtr;
}


void Particle___defaults__(struct _gfx__Particle *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Particle___destroy__(struct _gfx__Particle *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


bool Particle_isAlive(struct _gfx__Particle *this){
	return (bool)((gfx__ParticleClass *)((lang__Object *)this)->class)->isAlive((struct _gfx__Particle *) this);
}


void Particle_init_lifePosVal(struct _gfx__Particle *this, int life, struct _math__Vector3d *pos, struct _math__Vector3d *vel){
	((gfx__ParticleClass *)((lang__Object *)this)->class)->init_lifePosVal((struct _gfx__Particle *) this, life, pos, vel);
}


void Particle_update(struct _gfx__Particle *this, int t){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->update((struct _gfx__Drawable *) this, t);
}


void Particle_addForce(struct _gfx__Particle *this, struct _math__Vector3d *f){
	((gfx__ParticleClass *)((lang__Object *)this)->class)->addForce((struct _gfx__Particle *) this, f);
}


void Particle_print(struct _gfx__Particle *this){
	((gfx__ParticleClass *)((lang__Object *)this)->class)->print((struct _gfx__Particle *) this);
}


void Particle__draw(struct _gfx__Particle *this){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->_draw((struct _gfx__Drawable *) this);
}


void Particle___load__(){
	#line 8 "./gfx/Particle.ooc"
	((gfx__ParticleClass*) Particle_class())->params = NULL;
}


struct _gfx__Particle *Particle_new_lifePosVal(int life, struct _math__Vector3d *pos, struct _math__Vector3d *vel){
	#line 23 "./gfx/Particle.ooc"
	struct _gfx__Particle *this = ((struct _gfx__Particle *) (Class_alloc(Particle_class())));
	#line 23 "./gfx/Particle.ooc"
	Particle_init_lifePosVal(this, life, pos, vel);
	#line 23 "./gfx/Particle.ooc"
	return this;
}



void _gfx_Particle_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		Particle___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_glew_load();
		_glu_Glu_load();
		_math_Vector3d_load();
		_gfx_Drawable_load();
	}
}

