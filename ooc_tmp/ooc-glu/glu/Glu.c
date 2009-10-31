/* glu.Glu source file, generated with ooc */
#include "Glu.h"
lang__Class *Quadric_class() {
	#line 3 "/usr/lib/ooc/ooc-glu/./glu/Glu.ooc"
	static lang__Class *_class = NULL;
	#line 3 "/usr/lib/ooc/ooc-glu/./glu/Glu.ooc"
	if (_class == NULL){
		#line 3 "/usr/lib/ooc/ooc-glu/./glu/Glu.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 3 "/usr/lib/ooc/ooc-glu/./glu/Glu.ooc"
		_class->size = sizeof(lang__Pointer);
		#line 3 "/usr/lib/ooc/ooc-glu/./glu/Glu.ooc"
		_class->instanceSize = sizeof(lang__Pointer);
		#line 3 "/usr/lib/ooc/ooc-glu/./glu/Glu.ooc"
		_class->name = "Quadric";
	}
	#line 3 "/usr/lib/ooc/ooc-glu/./glu/Glu.ooc"
	return _class;
}



void _glu_Glu_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
	}
}

