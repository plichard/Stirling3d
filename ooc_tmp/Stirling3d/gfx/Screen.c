/* gfx.Screen source file, generated with ooc */
#include "Screen.h"
#include <Stirling3d/sdl/Sdl.h>
#include <Stirling3d/sdl/Video.h>
#include <out/glew.h>
#include <ooc-glu/glu/Glu.h>

void Screen___defaults___impl(struct _gfx__Screen *this){
	Object___defaults___impl((lang__Object *) this);
	#line 8 "./gfx/Screen.ooc"
	this->title = "Unnamed";
}

void Screen___destroy___impl(struct _gfx__Screen *this){
}

void Screen_init_impl(struct _gfx__Screen *this, int x, int y, int bpp){
	#line 9 "./gfx/Screen.ooc"
	this->bpp = bpp;
	#line 9 "./gfx/Screen.ooc"
	this->y = y;
	#line 9 "./gfx/Screen.ooc"
	this->x = x;
	#line 10 "./gfx/Screen.ooc"
	SDL_init(((uint32_t) (SDL_INIT_EVERYTHING)));
	#line 11 "./gfx/Screen.ooc"
	Screen_setRes(this, x, y, bpp);
}

void Screen_setRes_impl(struct _gfx__Screen *this, int x, int y, int bpp){
	#line 14 "./gfx/Screen.ooc"
	this->bpp = bpp;
	#line 14 "./gfx/Screen.ooc"
	this->y = y;
	#line 14 "./gfx/Screen.ooc"
	this->x = x;
	#line 15 "./gfx/Screen.ooc"
	SDLVideo_setMode(x, y, bpp, ((uint32_t) (SDL_OPENGL)));
	#line 16 "./gfx/Screen.ooc"
	glMatrixMode(GL_PROJECTION);
	#line 17 "./gfx/Screen.ooc"
	glLoadIdentity();
	#line 18 "./gfx/Screen.ooc"
	gluPerspective(((double) (70)), ((double) (x / ((double) (y)))), ((double) (0.0010)), ((double) (1000)));
	#line 19 "./gfx/Screen.ooc"
	glViewport(0, 0, x, y);
	#line 20 "./gfx/Screen.ooc"
	glEnable(GL_DEPTH_TEST);
}

void Screen_title_impl(struct _gfx__Screen *this, char *title){
	#line 24 "./gfx/Screen.ooc"
	this->title = title;
	#line 25 "./gfx/Screen.ooc"
	SDLVideo_wmSetCaption(title, ((const char *) (NULL)));
}

void Screen_close_impl(struct _gfx__Screen *this){
	#line 29 "./gfx/Screen.ooc"
	SDL_quit();
}

lang__Class *Screen_class(){
	static bool __done__ = false;
	static gfx__ScreenClass class = {{{
				.instanceSize = sizeof(gfx__Screen),
				.size = sizeof(void*),
				.name = "Screen",
			},
			.__load__ = (void (*)()) Screen___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Screen___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Screen___destroy___impl,
		},
		.new = Screen_new,
		.init = Screen_init_impl,
		.setRes = Screen_setRes_impl,
		.title = Screen_title_impl,
		.close = Screen_close_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Screen___defaults__(struct _gfx__Screen *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Screen___destroy__(struct _gfx__Screen *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Screen_init(struct _gfx__Screen *this, int x, int y, int bpp){
	((gfx__ScreenClass *)((lang__Object *)this)->class)->init((struct _gfx__Screen *) this, x, y, bpp);
}


void Screen_setRes(struct _gfx__Screen *this, int x, int y, int bpp){
	((gfx__ScreenClass *)((lang__Object *)this)->class)->setRes((struct _gfx__Screen *) this, x, y, bpp);
}


void Screen_title(struct _gfx__Screen *this, char *title){
	((gfx__ScreenClass *)((lang__Object *)this)->class)->title((struct _gfx__Screen *) this, title);
}


void Screen_close(struct _gfx__Screen *this){
	((gfx__ScreenClass *)((lang__Object *)this)->class)->close((struct _gfx__Screen *) this);
}


void Screen___load__(){
}


struct _gfx__Screen *Screen_new(int x, int y, int bpp){
	#line 9 "./gfx/Screen.ooc"
	struct _gfx__Screen *this = ((struct _gfx__Screen *) (Class_alloc(Screen_class())));
	#line 9 "./gfx/Screen.ooc"
	Screen_init(this, x, y, bpp);
	#line 9 "./gfx/Screen.ooc"
	return this;
}



void _gfx_Screen_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		Screen___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_sdl_Sdl_load();
		_sdl_Video_load();
		_glew_load();
		_glu_Glu_load();
	}
}

