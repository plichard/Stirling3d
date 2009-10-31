/* sdl.Event source file, generated with ooc */
#include "Event.h"
#include <Stirling3d/sdl/Sdl.h>
lang__Class *Event_class() {
	#line 4 "./sdl/Event.ooc"
	static lang__Class *_class = NULL;
	#line 4 "./sdl/Event.ooc"
	if (_class == NULL){
		#line 4 "./sdl/Event.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 4 "./sdl/Event.ooc"
		_class->size = sizeof(sdl__Event);
		#line 4 "./sdl/Event.ooc"
		_class->instanceSize = sizeof(sdl__Event);
		#line 4 "./sdl/Event.ooc"
		_class->name = "Event";
	}
	#line 4 "./sdl/Event.ooc"
	return _class;
}


lang__Class *SDLEvent_class() {
	#line 7 "./sdl/Event.ooc"
	static lang__Class *_class = NULL;
	#line 7 "./sdl/Event.ooc"
	if (_class == NULL){
		#line 7 "./sdl/Event.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 7 "./sdl/Event.ooc"
		_class->size = sizeof(sdl__SDLEvent);
		#line 7 "./sdl/Event.ooc"
		_class->instanceSize = sizeof(sdl__SDLEvent);
		#line 7 "./sdl/Event.ooc"
		_class->name = "SDLEvent";
	}
	#line 7 "./sdl/Event.ooc"
	return _class;
}



void _sdl_Event_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_sdl_Sdl_load();
	}
}

