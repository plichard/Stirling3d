/* lang.BasicTypes header file, generated with ooc */
#ifndef ___lang_BasicTypes__
#define ___lang_BasicTypes__


#include "BasicTypes-fwd.h"

struct _lang__Range {
	int min, max;
};

struct _lang__Class{
	lang__Class *class;
	size_t instanceSize;
	size_t size;
	char *name;
	struct _lang__Class *super;
};


struct _lang__ClassClass{
	struct _lang__Class __super__;
	struct _lang__Object * (*alloc)(struct _lang__Class *);
	bool (*instanceof)(struct _lang__Class *, struct _lang__Class *);
	void (*__defaults__)(struct _lang__Class *);
	void (*__destroy__)(struct _lang__Class *);
	void (*__load__)();
};


struct _lang__Object{
	
	struct _lang__Class *class;
};


struct _lang__ObjectClass{
	struct _lang__Class __super__;
	void (*__load__)();
	void (*__defaults__)(struct _lang__Object *);
	void (*__destroy__)(struct _lang__Object *);
};


struct _lang__Iterator{
	struct _lang__Object __super__;
	struct _lang__Class *T;
};


struct _lang__IteratorClass{
	struct _lang__ObjectClass __super__;
	bool (*hasNext)(struct _lang__Iterator *);
	void (*next)(struct _lang__Iterator *, void *);
};


struct _lang__Iterable{
	struct _lang__Object __super__;
	struct _lang__Class *T;
};


struct _lang__IterableClass{
	struct _lang__ObjectClass __super__;
	struct _lang__Iterator * (*iterator)(struct _lang__Iterable *);
};


struct _lang__Interface{
	struct _lang__Object __super__;
	struct _lang__Object *realThis;
	struct _lang__Object *funcs;
};


struct _lang__InterfaceClass{
	struct _lang__ObjectClass __super__;
	struct _lang__Interface * (*new)(struct _lang__Object *, struct _lang__Object *);
	void (*init)(struct _lang__Interface *, struct _lang__Object *, struct _lang__Object *);
};


struct _lang__Exception{
	struct _lang__Object __super__;
	struct _lang__Class *origin;
	char *msg;
};


struct _lang__ExceptionClass{
	struct _lang__ObjectClass __super__;
	struct _lang__Exception * (*new)(struct _lang__Class *, char *);
	void (*init)(struct _lang__Exception *, struct _lang__Class *, char *);
	struct _lang__Exception * (*new_noOrigin)(char *);
	void (*init_noOrigin)(struct _lang__Exception *, char *);
	void (*crash)(struct _lang__Exception *);
	char * (*getMessage)(struct _lang__Exception *);
	void (*print)(struct _lang__Exception *);
	void (*throw)(struct _lang__Exception *);
};


void _lang_BasicTypes_load();

#endif // ___lang_BasicTypes__

