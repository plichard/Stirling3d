/* lang.memory header file, generated with ooc */
#ifndef ___lang_memory__fwd__
#define ___lang_memory__fwd__


#if defined(__OOC_USE_GC__)

#include <gc/gc.h>
#endif

#include <sdk/lang/BasicTypes-fwd.h>
#include <sdk/lang/memory-fwd.h>
#include <sdk/lang/ooclib-fwd.h>
#include <sdk/lang/stdio-fwd.h>
#if defined(__OOC_USE_GC__)

#ifndef gc_malloc
#define gc_malloc GC_MALLOC
#endif
#endif
#if defined(__OOC_USE_GC__)

#ifndef gc_malloc_atomic
#define gc_malloc_atomic GC_MALLOC_ATOMIC
#endif
#endif
#if defined(__OOC_USE_GC__)

#ifndef gc_realloc
#define gc_realloc GC_REALLOC
#endif
#endif
#if defined(__OOC_USE_GC__)

void *gc_calloc(size_t nmemb, size_t size);
#endif
#if !defined(__OOC_USE_GC__)

void *gc_malloc(size_t size);
#endif
#if !defined(__OOC_USE_GC__)

#ifndef gc_malloc_atomic
#define gc_malloc_atomic malloc
#endif
#endif
#if !defined(__OOC_USE_GC__)

#ifndef gc_realloc
#define gc_realloc realloc
#endif
#endif
#if !defined(__OOC_USE_GC__)

#ifndef gc_calloc
#define gc_calloc calloc
#endif
#endif

#endif // ___lang_memory__fwd__

