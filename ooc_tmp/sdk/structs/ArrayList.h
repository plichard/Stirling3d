/* structs.ArrayList header file, generated with ooc */
#ifndef ___structs_ArrayList__
#define ___structs_ArrayList__


#include "ArrayList-fwd.h"


struct _structs__ArrayList{
	struct _structs__List __super__;
	uint8_t *data;
	int capacity;
	int size;
};


struct _structs__ArrayListClass{
	struct _structs__ListClass __super__;
	struct _structs__ArrayList * (*new)(struct _lang__Class *);
	void (*init)(struct _structs__ArrayList *);
	struct _structs__ArrayList * (*new_withCapacity)(struct _lang__Class *, int);
	void (*init_withCapacity)(struct _structs__ArrayList *, int);
	struct _structs__ArrayList * (*new_withData)(struct _lang__Class *, uint8_t *, int);
	void (*init_withData)(struct _structs__ArrayList *, uint8_t *, int);
	void (*ensureCapacity)(struct _structs__ArrayList *, int);
	void (*grow)(struct _structs__ArrayList *);
	void (*checkIndex)(struct _structs__ArrayList *, int);
};


struct _structs__ArrayListIterator{
	struct _lang__Iterator __super__;
	struct _structs__ArrayList *list;
	int index;
};


struct _structs__ArrayListIteratorClass{
	struct _lang__IteratorClass __super__;
	struct _structs__ArrayListIterator * (*new)(struct _lang__Class *, struct _structs__ArrayList *);
	void (*init)(struct _structs__ArrayListIterator *, struct _structs__ArrayList *);
};


void _structs_ArrayList_load();

#endif // ___structs_ArrayList__

