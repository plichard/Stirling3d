/* lang.ooclib source file, generated with ooc */
#include "ooclib.h"
lang__Class *VaList_class() {
	#line 5 "/media/shared/dev/ooc/sdk/lang/ooclib.ooc"
	static lang__Class *_class = NULL;
	#line 5 "/media/shared/dev/ooc/sdk/lang/ooclib.ooc"
	if (_class == NULL){
		#line 5 "/media/shared/dev/ooc/sdk/lang/ooclib.ooc"
		_class = (void *) gc_malloc(sizeof(lang__Class));
		#line 5 "/media/shared/dev/ooc/sdk/lang/ooclib.ooc"
		_class->size = sizeof(lang__VaList);
		#line 5 "/media/shared/dev/ooc/sdk/lang/ooclib.ooc"
		_class->instanceSize = sizeof(lang__VaList);
		#line 5 "/media/shared/dev/ooc/sdk/lang/ooclib.ooc"
		_class->name = "VaList";
	}
	#line 5 "/media/shared/dev/ooc/sdk/lang/ooclib.ooc"
	return _class;
}



void _lang_ooclib_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_lang_BasicTypes_load();
	}
}

