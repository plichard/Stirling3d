/* structs.LinkedList header file, generated with ooc */
#ifndef ___structs_LinkedList__
#define ___structs_LinkedList__


#include "LinkedList-fwd.h"


struct _structs__LinkedList{
	struct _structs__List __super__;
	int size;
	struct _structs__Node *first;
	struct _structs__Node *last;
};


struct _structs__LinkedListClass{
	struct _structs__ListClass __super__;
	struct _structs__LinkedList * (*new)(struct _lang__Class *);
	void (*init)(struct _structs__LinkedList *);
	struct _structs__Node * (*getNode)(struct _structs__LinkedList *, int);
	void (*removeNode)(struct _structs__LinkedList *, struct _structs__Node *);
	void (*print)(struct _structs__LinkedList *);
};


struct _structs__Node{
	struct _lang__Object __super__;
	struct _lang__Class *T;
	struct _structs__Node *prev;
	struct _structs__Node *next;
	uint8_t * data;
};


struct _structs__NodeClass{
	struct _lang__ObjectClass __super__;
	struct _structs__Node * (*new)(struct _lang__Class *);
	void (*init)(struct _structs__Node *);
	struct _structs__Node * (*new_withParams)(struct _lang__Class *, struct _structs__Node *, struct _structs__Node *, uint8_t *);
	void (*init_withParams)(struct _structs__Node *, struct _structs__Node *, struct _structs__Node *, uint8_t *);
};


struct _structs__LinkedListIterator{
	struct _lang__Iterator __super__;
	struct _structs__Node *current;
	struct _structs__LinkedList *list;
};


struct _structs__LinkedListIteratorClass{
	struct _lang__IteratorClass __super__;
	struct _structs__LinkedListIterator * (*new)(struct _lang__Class *, struct _structs__LinkedList *);
	void (*init)(struct _structs__LinkedListIterator *, struct _structs__LinkedList *);
	struct _structs__Node * (*nextNode)(struct _structs__LinkedListIterator *);
};


void _structs_LinkedList_load();

#endif // ___structs_LinkedList__

