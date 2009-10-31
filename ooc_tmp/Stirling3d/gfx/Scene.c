/* gfx.Scene source file, generated with ooc */
#include "Scene.h"
#include <out/glew.h>
#include <ooc-glu/glu/Glu.h>
#include <Stirling3d/gfx/Drawable.h>
#include <Stirling3d/gfx/Particle.h>
#include <Stirling3d/sdl/Sdl.h>
#include <Stirling3d/sdl/Video.h>
#include <sdk/structs/LinkedList.h>

void Scene___defaults___impl(struct _gfx__Scene *this){
	Object___defaults___impl((lang__Object *) this);
	#line 10 "./gfx/Scene.ooc"
	this->drawables = LinkedList_new(Pointer_class());
}

void Scene___destroy___impl(struct _gfx__Scene *this){
}

void Scene_init_impl(struct _gfx__Scene *this){
}

void Scene_clear_impl(struct _gfx__Scene *this){
}

void Scene_draw_impl(struct _gfx__Scene *this){
	#line 19 "./gfx/Scene.ooc"
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	#line 20 "./gfx/Scene.ooc"
	glMatrixMode(GL_MODELVIEW);
	#line 21 "./gfx/Scene.ooc"
	glLoadIdentity();
	#line 22 "./gfx/Scene.ooc"
	gluLookAt(((double) (100)), ((double) (0)), ((double) (0)), ((double) (0)), ((double) (0)), ((double) (0)), ((double) (0)), ((double) (0)), ((double) (1)));
	#line 24 "./gfx/Scene.ooc"
	
	{
		#line 24 "./gfx/Scene.ooc"
		void *d;
		#line 24 "./gfx/Scene.ooc"
		struct _structs__LinkedListIterator *iter = LinkedList_iterator(this->drawables);
		#line 24 "./gfx/Scene.ooc"
		while (LinkedListIterator_hasNext(iter)){
			#line 24 "./gfx/Scene.ooc"
			LinkedListIterator_next(iter, &d);
			#line 25 "./gfx/Scene.ooc"
			Drawable_draw(((struct _gfx__Drawable *) (d)));
		}
	};
	#line 29 "./gfx/Scene.ooc"
	glFlush();
	#line 30 "./gfx/Scene.ooc"
	SDLVideo_glSwapBuffers();
}

void Scene_update_impl(struct _gfx__Scene *this){
	#line 35 "./gfx/Scene.ooc"
	struct _structs__LinkedListIterator *iter = LinkedList_iterator(this->drawables);
	#line 36 "./gfx/Scene.ooc"
	while (LinkedListIterator_hasNext(iter)){
		#line 37 "./gfx/Scene.ooc"
		
		{
			#line 37 "./gfx/Scene.ooc"
			void *gcall;
			#line 37 "./gfx/Scene.ooc"
			LinkedListIterator_next(iter, &gcall);
			#line 37 "./gfx/Scene.ooc"
			Drawable_update(((struct _gfx__Drawable *) (gcall)), 1);
		};
	}
}

void Scene_add_impl(struct _gfx__Scene *this, struct _gfx__Drawable *d){
	#line 42 "./gfx/Scene.ooc"
	LinkedList_add(this->drawables, (uint8_t*) &d);
}

lang__Class *Scene_class(){
	static bool __done__ = false;
	static gfx__SceneClass class = {{{
				.instanceSize = sizeof(gfx__Scene),
				.size = sizeof(void*),
				.name = "Scene",
			},
			.__load__ = (void (*)()) Scene___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Scene___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Scene___destroy___impl,
		},
		.new = Scene_new,
		.init = Scene_init_impl,
		.clear = Scene_clear_impl,
		.draw = Scene_draw_impl,
		.update = Scene_update_impl,
		.add = Scene_add_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Scene___defaults__(struct _gfx__Scene *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Scene___destroy__(struct _gfx__Scene *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Scene_init(struct _gfx__Scene *this){
	((gfx__SceneClass *)((lang__Object *)this)->class)->init((struct _gfx__Scene *) this);
}


void Scene_clear(struct _gfx__Scene *this){
	((gfx__SceneClass *)((lang__Object *)this)->class)->clear((struct _gfx__Scene *) this);
}


void Scene_draw(struct _gfx__Scene *this){
	((gfx__SceneClass *)((lang__Object *)this)->class)->draw((struct _gfx__Scene *) this);
}


void Scene_update(struct _gfx__Scene *this){
	((gfx__SceneClass *)((lang__Object *)this)->class)->update((struct _gfx__Scene *) this);
}


void Scene_add(struct _gfx__Scene *this, struct _gfx__Drawable *d){
	((gfx__SceneClass *)((lang__Object *)this)->class)->add((struct _gfx__Scene *) this, d);
}


void Scene___load__(){
}


struct _gfx__Scene *Scene_new(){
	#line 12 "./gfx/Scene.ooc"
	struct _gfx__Scene *this = ((struct _gfx__Scene *) (Class_alloc(Scene_class())));
	#line 12 "./gfx/Scene.ooc"
	Scene_init(this);
	#line 12 "./gfx/Scene.ooc"
	return this;
}



void _gfx_Scene_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		Scene___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_glew_load();
		_glu_Glu_load();
		_gfx_Drawable_load();
		_gfx_Particle_load();
		_sdl_Sdl_load();
		_sdl_Video_load();
		_structs_LinkedList_load();
	}
}

