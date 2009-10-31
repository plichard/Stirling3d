/* gfx.ParticleGenerator source file, generated with ooc */
#include "ParticleGenerator.h"
#include <sdk/structs/LinkedList.h>
#include <sdk/structs/ArrayList.h>
#include <Stirling3d/gfx/Particle.h>
#include <Stirling3d/sdl/Sdl.h>
#include <Stirling3d/math/Vector3d.h>

void ParticleGenerator___defaults___impl(struct _gfx__ParticleGenerator *this){
	Drawable___defaults___impl((gfx__Drawable *) this);
	#line 20 "./gfx/ParticleGenerator.ooc"
	this->particles = LinkedList_new(Pointer_class());
	#line 21 "./gfx/ParticleGenerator.ooc"
	this->constantForces = LinkedList_new(Pointer_class());
}

void ParticleGenerator___destroy___impl(struct _gfx__ParticleGenerator *this){
}

void ParticleGenerator_init_impl(struct _gfx__ParticleGenerator *this){
	#line 24 "./gfx/ParticleGenerator.ooc"
	ParticleGenerator_setTime(this, 1000, 0);
	#line 25 "./gfx/ParticleGenerator.ooc"
	this->life = 2000;
	#line 26 "./gfx/ParticleGenerator.ooc"
	ParticleGenerator_setVel(this, Vector3d_new_withParams(0, 0, 1), Vector3d_new_withParams(0, 0, 0));
	#line 27 "./gfx/ParticleGenerator.ooc"
	this->pTime = this->cTime = 0;
}

void ParticleGenerator_init_withParams_impl(struct _gfx__ParticleGenerator *this, int life, int dlife, int dt, int ddt, struct _math__Vector3d *vel, struct _math__Vector3d *dv){
	#line 32 "./gfx/ParticleGenerator.ooc"
	this->dv = dv;
	#line 32 "./gfx/ParticleGenerator.ooc"
	this->vel = vel;
	#line 32 "./gfx/ParticleGenerator.ooc"
	this->ddt = ddt;
	#line 32 "./gfx/ParticleGenerator.ooc"
	this->dt = dt;
	#line 32 "./gfx/ParticleGenerator.ooc"
	this->dlife = dlife;
	#line 32 "./gfx/ParticleGenerator.ooc"
	this->life = life;
	#line 33 "./gfx/ParticleGenerator.ooc"
	ParticleGenerator_print(this);
}

void ParticleGenerator_print_impl(struct _gfx__ParticleGenerator *this){
	#line 37 "./gfx/ParticleGenerator.ooc"
	printf("\nParticleGenerator params: \n");
	#line 38 "./gfx/ParticleGenerator.ooc"
	printf("life: %d\n", this->life);
	#line 39 "./gfx/ParticleGenerator.ooc"
	printf(" vel: (%f,%f,%f)\n", this->vel->x, this->vel->y, this->vel->z);
	#line 40 "./gfx/ParticleGenerator.ooc"
	printf("dvel: (%f,%f,%f)\n", this->dv->x, this->dv->y, this->dv->z);
}

void ParticleGenerator_setTime_impl(struct _gfx__ParticleGenerator *this, int dt, int ddt){
	#line 42 "./gfx/ParticleGenerator.ooc"
	this->ddt = ddt;
	#line 42 "./gfx/ParticleGenerator.ooc"
	this->dt = dt;
}

void ParticleGenerator_setVel_impl(struct _gfx__ParticleGenerator *this, struct _math__Vector3d *vel, struct _math__Vector3d *dv){
	#line 44 "./gfx/ParticleGenerator.ooc"
	this->dv = dv;
	#line 44 "./gfx/ParticleGenerator.ooc"
	this->vel = vel;
}

void ParticleGenerator_update_impl(struct _gfx__ParticleGenerator *this, int t){
	#line 48 "./gfx/ParticleGenerator.ooc"
	this->cTime = (int) SDL_getTicks();
	#line 49 "./gfx/ParticleGenerator.ooc"
	ParticleGenerator_applyForces(this);
	#line 50 "./gfx/ParticleGenerator.ooc"
	if (this->cTime - this->pTime > this->dt + rand() % this->ddt - 2 * this->ddt){
		#line 51 "./gfx/ParticleGenerator.ooc"
		struct _math__Vector3d *nvel = Vector3d_clone(this->vel);
		#line 52 "./gfx/ParticleGenerator.ooc"
		int nlife = this->life;
		#line 53 "./gfx/ParticleGenerator.ooc"
		if (this->dv->x){
			#line 54 "./gfx/ParticleGenerator.ooc"
			nvel->x = this->vel->x + rand() % (((int) (this->dv->x))) - 2 * this->dv->x;
		}
		#line 56 "./gfx/ParticleGenerator.ooc"
		if (this->dv->y){
			#line 57 "./gfx/ParticleGenerator.ooc"
			nvel->y = this->vel->y + rand() % (((int) (this->dv->y))) - 2 * this->dv->y;
		}
		#line 59 "./gfx/ParticleGenerator.ooc"
		if (this->dv->z){
			#line 60 "./gfx/ParticleGenerator.ooc"
			nvel->z = this->vel->z + rand() % (((int) (this->dv->z))) - 2 * this->dv->z;
		}
		#line 63 "./gfx/ParticleGenerator.ooc"
		if (this->dlife){
			#line 64 "./gfx/ParticleGenerator.ooc"
			nlife += rand() % this->dlife - 2 * this->dlife;
		}
		#line 68 "./gfx/ParticleGenerator.ooc"
		
		{
			#line 68 "./gfx/ParticleGenerator.ooc"
			struct _gfx__Particle *tparam = Particle_new_lifePosVal(nlife, ((gfx__Drawable*) this)->pos, nvel);
			#line 68 "./gfx/ParticleGenerator.ooc"
			LinkedList_add(this->particles, (uint8_t*) &tparam);
		};
	}
	#line 72 "./gfx/ParticleGenerator.ooc"
	struct _structs__LinkedListIterator *iter = LinkedList_iterator(this->particles);
	#line 73 "./gfx/ParticleGenerator.ooc"
	while (LinkedListIterator_hasNext(iter)){
		#line 74 "./gfx/ParticleGenerator.ooc"
		struct _structs__Node *p = LinkedListIterator_nextNode(iter);
		#line 75 "./gfx/ParticleGenerator.ooc"
		Particle_update(*((struct _gfx__Particle **)(p->data)), this->cTime - this->pTime);
		#line 76 "./gfx/ParticleGenerator.ooc"
		if (!(Particle_isAlive(*((struct _gfx__Particle **)(p->data))))){
			#line 76 "./gfx/ParticleGenerator.ooc"
			LinkedList_removeNode(this->particles, p);
		}
	}
	#line 78 "./gfx/ParticleGenerator.ooc"
	this->pTime = this->cTime;
}

void ParticleGenerator_stop_impl(struct _gfx__ParticleGenerator *this){
}

void ParticleGenerator__draw_impl(struct _gfx__ParticleGenerator *this){
	#line 86 "./gfx/ParticleGenerator.ooc"
	struct _structs__LinkedListIterator *iter = LinkedList_iterator(this->particles);
	#line 87 "./gfx/ParticleGenerator.ooc"
	while (LinkedListIterator_hasNext(iter)){
		#line 88 "./gfx/ParticleGenerator.ooc"
		
		{
			#line 88 "./gfx/ParticleGenerator.ooc"
			void *gcall;
			#line 88 "./gfx/ParticleGenerator.ooc"
			LinkedListIterator_next(iter, &gcall);
			#line 88 "./gfx/ParticleGenerator.ooc"
			Drawable_draw((struct _gfx__Drawable *) ((struct _gfx__Particle *) (gcall)));
		};
	}
}

void ParticleGenerator_addConstantForce_impl(struct _gfx__ParticleGenerator *this, struct _math__Vector3d *f){
	#line 93 "./gfx/ParticleGenerator.ooc"
	LinkedList_add(this->constantForces, (uint8_t*) &f);
}

void ParticleGenerator_applyForces_impl(struct _gfx__ParticleGenerator *this){
	#line 97 "./gfx/ParticleGenerator.ooc"
	
	{
		#line 97 "./gfx/ParticleGenerator.ooc"
		void *f;
		#line 97 "./gfx/ParticleGenerator.ooc"
		struct _structs__LinkedListIterator *iter = LinkedList_iterator(this->constantForces);
		#line 97 "./gfx/ParticleGenerator.ooc"
		while (LinkedListIterator_hasNext(iter)){
			#line 97 "./gfx/ParticleGenerator.ooc"
			LinkedListIterator_next(iter, &f);
			#line 98 "./gfx/ParticleGenerator.ooc"
			
			{
				#line 98 "./gfx/ParticleGenerator.ooc"
				void *p;
				#line 98 "./gfx/ParticleGenerator.ooc"
				struct _structs__LinkedListIterator *iter = LinkedList_iterator(this->particles);
				#line 98 "./gfx/ParticleGenerator.ooc"
				while (LinkedListIterator_hasNext(iter)){
					#line 98 "./gfx/ParticleGenerator.ooc"
					LinkedListIterator_next(iter, &p);
					#line 99 "./gfx/ParticleGenerator.ooc"
					Particle_addForce(((struct _gfx__Particle *) (p)), f);
				}
			};
		}
	};
}

lang__Class *ParticleGenerator_class(){
	static bool __done__ = false;
	static gfx__ParticleGeneratorClass class = {{{{
					.instanceSize = sizeof(gfx__ParticleGenerator),
					.size = sizeof(void*),
					.name = "ParticleGenerator",
				},
				.__load__ = (void (*)()) ParticleGenerator___load__,
				.__defaults__ = (void (*)(struct _lang__Object *)) ParticleGenerator___defaults___impl,
				.__destroy__ = (void (*)(struct _lang__Object *)) ParticleGenerator___destroy___impl,
			},
			.new_drawableAbstract = (struct _gfx__Drawable * (*)()) Drawable_new_drawableAbstract,
			.init_drawableAbstract = Drawable_init_drawableAbstract_impl,
			.draw = (void (*)(struct _gfx__Drawable *)) Drawable_draw_impl,
			._draw = (void (*)(struct _gfx__Drawable *)) ParticleGenerator__draw_impl,
			._drawAxes = (void (*)(struct _gfx__Drawable *)) Drawable__drawAxes_impl,
			.update = (void (*)(struct _gfx__Drawable *, int)) ParticleGenerator_update_impl,
		},
		.new = ParticleGenerator_new,
		.init = ParticleGenerator_init_impl,
		.new_withParams = ParticleGenerator_new_withParams,
		.init_withParams = ParticleGenerator_init_withParams_impl,
		.print = ParticleGenerator_print_impl,
		.setTime = ParticleGenerator_setTime_impl,
		.setVel = ParticleGenerator_setVel_impl,
		.stop = ParticleGenerator_stop_impl,
		.addConstantForce = ParticleGenerator_addConstantForce_impl,
		.applyForces = ParticleGenerator_applyForces_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Drawable_class();
	}
	return classPtr;
}


void ParticleGenerator___defaults__(struct _gfx__ParticleGenerator *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void ParticleGenerator___destroy__(struct _gfx__ParticleGenerator *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void ParticleGenerator_init(struct _gfx__ParticleGenerator *this){
	((gfx__ParticleGeneratorClass *)((lang__Object *)this)->class)->init((struct _gfx__ParticleGenerator *) this);
}


void ParticleGenerator_init_withParams(struct _gfx__ParticleGenerator *this, int life, int dlife, int dt, int ddt, struct _math__Vector3d *vel, struct _math__Vector3d *dv){
	((gfx__ParticleGeneratorClass *)((lang__Object *)this)->class)->init_withParams((struct _gfx__ParticleGenerator *) this, life, dlife, dt, ddt, vel, dv);
}


void ParticleGenerator_print(struct _gfx__ParticleGenerator *this){
	((gfx__ParticleGeneratorClass *)((lang__Object *)this)->class)->print((struct _gfx__ParticleGenerator *) this);
}


void ParticleGenerator_setTime(struct _gfx__ParticleGenerator *this, int dt, int ddt){
	((gfx__ParticleGeneratorClass *)((lang__Object *)this)->class)->setTime((struct _gfx__ParticleGenerator *) this, dt, ddt);
}


void ParticleGenerator_setVel(struct _gfx__ParticleGenerator *this, struct _math__Vector3d *vel, struct _math__Vector3d *dv){
	((gfx__ParticleGeneratorClass *)((lang__Object *)this)->class)->setVel((struct _gfx__ParticleGenerator *) this, vel, dv);
}


void ParticleGenerator_update(struct _gfx__ParticleGenerator *this, int t){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->update((struct _gfx__Drawable *) this, t);
}


void ParticleGenerator_stop(struct _gfx__ParticleGenerator *this){
	((gfx__ParticleGeneratorClass *)((lang__Object *)this)->class)->stop((struct _gfx__ParticleGenerator *) this);
}


void ParticleGenerator__draw(struct _gfx__ParticleGenerator *this){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->_draw((struct _gfx__Drawable *) this);
}


void ParticleGenerator_addConstantForce(struct _gfx__ParticleGenerator *this, struct _math__Vector3d *f){
	((gfx__ParticleGeneratorClass *)((lang__Object *)this)->class)->addConstantForce((struct _gfx__ParticleGenerator *) this, f);
}


void ParticleGenerator_applyForces(struct _gfx__ParticleGenerator *this){
	((gfx__ParticleGeneratorClass *)((lang__Object *)this)->class)->applyForces((struct _gfx__ParticleGenerator *) this);
}


void ParticleGenerator___load__(){
}


struct _gfx__ParticleGenerator *ParticleGenerator_new(){
	#line 23 "./gfx/ParticleGenerator.ooc"
	struct _gfx__ParticleGenerator *this = ((struct _gfx__ParticleGenerator *) (Class_alloc(ParticleGenerator_class())));
	#line 23 "./gfx/ParticleGenerator.ooc"
	ParticleGenerator_init(this);
	#line 23 "./gfx/ParticleGenerator.ooc"
	return this;
}


struct _gfx__ParticleGenerator *ParticleGenerator_new_withParams(int life, int dlife, int dt, int ddt, struct _math__Vector3d *vel, struct _math__Vector3d *dv){
	#line 32 "./gfx/ParticleGenerator.ooc"
	struct _gfx__ParticleGenerator *this = ((struct _gfx__ParticleGenerator *) (Class_alloc(ParticleGenerator_class())));
	#line 32 "./gfx/ParticleGenerator.ooc"
	ParticleGenerator_init_withParams(this, life, dlife, dt, ddt, vel, dv);
	#line 32 "./gfx/ParticleGenerator.ooc"
	return this;
}



void _gfx_ParticleGenerator_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		ParticleGenerator___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_structs_LinkedList_load();
		_structs_ArrayList_load();
		_gfx_Particle_load();
		_sdl_Sdl_load();
		_gfx_Drawable_load();
		_math_Vector3d_load();
	}
}

