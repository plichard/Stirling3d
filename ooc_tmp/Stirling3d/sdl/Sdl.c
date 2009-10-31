/* sdl.Sdl source file, generated with ooc */
#include "Sdl.h"
lang__Class *Surface_class() {
	#line 36 "./sdl/Sdl.ooc"
	static lang__Class *_class = NULL;
	#line 36 "./sdl/Sdl.ooc"
	if (_class == NULL){
		#line 36 "./sdl/Sdl.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 36 "./sdl/Sdl.ooc"
		_class->size = sizeof(sdl__Surface);
		#line 36 "./sdl/Sdl.ooc"
		_class->instanceSize = sizeof(sdl__Surface);
		#line 36 "./sdl/Sdl.ooc"
		_class->name = "Surface";
	}
	#line 36 "./sdl/Sdl.ooc"
	return _class;
}


lang__Class *SDL_class() {
	#line 40 "./sdl/Sdl.ooc"
	static lang__Class *_class = NULL;
	#line 40 "./sdl/Sdl.ooc"
	if (_class == NULL){
		#line 40 "./sdl/Sdl.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 40 "./sdl/Sdl.ooc"
		_class->size = sizeof(sdl__SDL);
		#line 40 "./sdl/Sdl.ooc"
		_class->instanceSize = sizeof(sdl__SDL);
		#line 40 "./sdl/Sdl.ooc"
		_class->name = "SDL";
	}
	#line 40 "./sdl/Sdl.ooc"
	return _class;
}



void _sdl_Sdl_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
	}
}

