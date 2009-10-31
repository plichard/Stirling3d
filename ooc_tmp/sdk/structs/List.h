/* structs.List header file, generated with ooc */
#ifndef ___structs_List__
#define ___structs_List__


#include "List-fwd.h"


struct _structs__List{
	struct _lang__Iterable __super__;
};


struct _structs__ListClass{
	struct _lang__IterableClass __super__;
	void (*add)(struct _structs__List *, uint8_t *);
	void (*add_withIndex)(struct _structs__List *, int, uint8_t *);
	void (*addAll)(struct _structs__List *, struct _lang__Iterable *);
	void (*addAll_atStart)(struct _structs__List *, int, struct _lang__Iterable *);
	void (*clear)(struct _structs__List *);
	bool (*removeLast)(struct _structs__List *);
	bool (*contains)(struct _structs__List *, uint8_t *);
	void (*get)(struct _structs__List *, void *, int);
	int (*indexOf)(struct _structs__List *, uint8_t *);
	bool (*isEmpty)(struct _structs__List *);
	int (*lastIndexOf)(struct _structs__List *, uint8_t *);
	void (*removeAt)(struct _structs__List *, void *, int);
	bool (*remove)(struct _structs__List *, uint8_t *);
	void (*set)(struct _structs__List *, int, uint8_t *);
	int (*size)(struct _structs__List *);
	struct _structs__List * (*clone)(struct _structs__List *);
	void (*last)(struct _structs__List *, void *);
	size_t (*lastIndex)(struct _structs__List *);
	void * (*toArray)(struct _structs__List *);
};


void _structs_List_load();

#endif // ___structs_List__

