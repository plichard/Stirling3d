/* lang.memory source file, generated with ooc */
#include "memory.h"
#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>

#if defined(__OOC_USE_GC__)
void *gc_calloc(size_t nmemb, size_t size) {
	#line 8 "/media/shared/dev/ooc/sdk/lang/memory.ooc"
	return (void *) gc_malloc(nmemb * size);
}


#endif
#if !defined(__OOC_USE_GC__)
void *gc_malloc(size_t size) {
	#line 15 "/media/shared/dev/ooc/sdk/lang/memory.ooc"
	return gc_calloc(1, size);
}


#endif
void _lang_memory_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		#line 1 "/media/shared/dev/ooc/sdk/lang/memory.ooc"
		
#if defined(__OOC_USE_GC__)
		
		{
		}
#endif
		#line 12 "/media/shared/dev/ooc/sdk/lang/memory.ooc"
		
#if !defined(__OOC_USE_GC__)
		
		{
		}
#endif
	}
}

