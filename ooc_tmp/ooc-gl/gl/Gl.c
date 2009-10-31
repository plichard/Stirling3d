/* gl.Gl source file, generated with ooc */
#include "Gl.h"
lang__Class *GL_class() {
	#line 9 "/usr/lib/ooc/ooc-gl/./gl/Gl.ooc"
	static lang__Class *_class = NULL;
	#line 9 "/usr/lib/ooc/ooc-gl/./gl/Gl.ooc"
	if (_class == NULL){
		#line 9 "/usr/lib/ooc/ooc-gl/./gl/Gl.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 9 "/usr/lib/ooc/ooc-gl/./gl/Gl.ooc"
		_class->size = sizeof(gl__GL);
		#line 9 "/usr/lib/ooc/ooc-gl/./gl/Gl.ooc"
		_class->instanceSize = sizeof(gl__GL);
		#line 9 "/usr/lib/ooc/ooc-gl/./gl/Gl.ooc"
		_class->name = "GL";
	}
	#line 9 "/usr/lib/ooc/ooc-gl/./gl/Gl.ooc"
	return _class;
}



void _gl_Gl_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
	}
}

