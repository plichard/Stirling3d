/* gfx.Scene header file, generated with ooc */
#ifndef ___gfx_Scene__
#define ___gfx_Scene__


#include "Scene-fwd.h"


struct _gfx__Scene{
	struct _lang__Object __super__;
	struct _structs__LinkedList *drawables;
};


struct _gfx__SceneClass{
	struct _lang__ObjectClass __super__;
	struct _gfx__Scene * (*new)();
	void (*init)(struct _gfx__Scene *);
	void (*clear)(struct _gfx__Scene *);
	void (*draw)(struct _gfx__Scene *);
	void (*update)(struct _gfx__Scene *);
	void (*add)(struct _gfx__Scene *, struct _gfx__Drawable *);
};


void _gfx_Scene_load();

#endif // ___gfx_Scene__

