/* Stirling3d source file, generated with ooc */
#include "Stirling3d.h"
#include <Stirling3d/gfx/Scene.h>
#include <Stirling3d/gfx/Screen.h>
#include <Stirling3d/gfx/Drawable.h>
#include <Stirling3d/sdl/Event.h>
#include <Stirling3d/sdl/Sdl.h>

void Stirling3d___defaults___impl(struct _Stirling3d *this){
	Object___defaults___impl((lang__Object *) this);
	#line 10 "./Stirling3d.ooc"
	this->isRunning = false;
}

void Stirling3d___destroy___impl(struct _Stirling3d *this){
}

void Stirling3d_init_impl(struct _Stirling3d *this){
}

void Stirling3d_window_impl(struct _Stirling3d *this, int x, int y){
	#line 15 "./Stirling3d.ooc"
	this->screen = Screen_new(x, y, 32);
}

void Stirling3d_newScene_impl(struct _Stirling3d *this){
	#line 19 "./Stirling3d.ooc"
	this->scene = Scene_new();
}

void Stirling3d_drawAxes_impl(struct _Stirling3d *this, bool b){
	#line 23 "./Stirling3d.ooc"
	((gfx__DrawableClass*) Drawable_class())->axes = b;
}

void Stirling3d_handleInput_impl(struct _Stirling3d *this){
	#line 27 "./Stirling3d.ooc"
	SDL_Event event;
	#line 28 "./Stirling3d.ooc"
	while ((int) SDLEvent_poll(&event)){
		#line 29 "./Stirling3d.ooc"
		if (((event.type)) == (SDL_QUIT)){
			exit(0);
		};
	}
}

void Stirling3d_mainLoop_impl(struct _Stirling3d *this){
	#line 39 "./Stirling3d.ooc"
	this->isRunning = true;
	#line 40 "./Stirling3d.ooc"
	while (this->isRunning){
		#line 41 "./Stirling3d.ooc"
		Stirling3d_handleInput(this);
		#line 42 "./Stirling3d.ooc"
		Scene_update(this->scene);
		#line 43 "./Stirling3d.ooc"
		Scene_draw(this->scene);
		#line 44 "./Stirling3d.ooc"
		usleep(((unsigned int) (30000)));
	}
}

lang__Class *Stirling3d_class(){
	static bool __done__ = false;
	static Stirling3dClass class = {{{
				.instanceSize = sizeof(Stirling3d),
				.size = sizeof(void*),
				.name = "Stirling3d",
			},
			.__load__ = (void (*)()) Stirling3d___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Stirling3d___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Stirling3d___destroy___impl,
		},
		.new = Stirling3d_new,
		.init = Stirling3d_init_impl,
		.window = Stirling3d_window_impl,
		.newScene = Stirling3d_newScene_impl,
		.drawAxes = Stirling3d_drawAxes_impl,
		.handleInput = Stirling3d_handleInput_impl,
		.mainLoop = Stirling3d_mainLoop_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Stirling3d___defaults__(struct _Stirling3d *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Stirling3d___destroy__(struct _Stirling3d *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Stirling3d_init(struct _Stirling3d *this){
	((Stirling3dClass *)((lang__Object *)this)->class)->init((struct _Stirling3d *) this);
}


void Stirling3d_window(struct _Stirling3d *this, int x, int y){
	((Stirling3dClass *)((lang__Object *)this)->class)->window((struct _Stirling3d *) this, x, y);
}


void Stirling3d_newScene(struct _Stirling3d *this){
	((Stirling3dClass *)((lang__Object *)this)->class)->newScene((struct _Stirling3d *) this);
}


void Stirling3d_drawAxes(struct _Stirling3d *this, bool b){
	((Stirling3dClass *)((lang__Object *)this)->class)->drawAxes((struct _Stirling3d *) this, b);
}


void Stirling3d_handleInput(struct _Stirling3d *this){
	((Stirling3dClass *)((lang__Object *)this)->class)->handleInput((struct _Stirling3d *) this);
}


void Stirling3d_mainLoop(struct _Stirling3d *this){
	((Stirling3dClass *)((lang__Object *)this)->class)->mainLoop((struct _Stirling3d *) this);
}


void Stirling3d___load__(){
}


struct _Stirling3d *Stirling3d_new(){
	#line 12 "./Stirling3d.ooc"
	struct _Stirling3d *this = ((struct _Stirling3d *) (Class_alloc(Stirling3d_class())));
	#line 12 "./Stirling3d.ooc"
	Stirling3d_init(this);
	#line 12 "./Stirling3d.ooc"
	return this;
}



void _Stirling3d_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		Stirling3d___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_gfx_Scene_load();
		_gfx_Screen_load();
		_gfx_Drawable_load();
		_sdl_Event_load();
		_sdl_Sdl_load();
	}
}

