/* sdl.Video source file, generated with ooc */
#include "Video.h"
#include <Stirling3d/sdl/Sdl.h>
lang__Class *SDLVideo_class() {
	#line 4 "./sdl/Video.ooc"
	static lang__Class *_class = NULL;
	#line 4 "./sdl/Video.ooc"
	if (_class == NULL){
		#line 4 "./sdl/Video.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 4 "./sdl/Video.ooc"
		_class->size = sizeof(sdl__SDLVideo);
		#line 4 "./sdl/Video.ooc"
		_class->instanceSize = sizeof(sdl__SDLVideo);
		#line 4 "./sdl/Video.ooc"
		_class->name = "SDLVideo";
	}
	#line 4 "./sdl/Video.ooc"
	return _class;
}



void _sdl_Video_load(){
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

