/* gfx.Drawable header file, generated with ooc */
#ifndef ___gfx_Drawable__
#define ___gfx_Drawable__


#include "Drawable-fwd.h"


struct _gfx__Drawable{
	struct _lang__Object __super__;
	bool show;
	struct _math__Vector3d *pos;
	struct _math__Vector3d *rot;
	struct _math__Vector3d *scl;
};


struct _gfx__DrawableClass{
	struct _lang__ObjectClass __super__;
	struct _gfx__Drawable * (*new_drawableAbstract)();
	void (*init_drawableAbstract)(struct _gfx__Drawable *);
	void (*draw)(struct _gfx__Drawable *);
	void (*_draw)(struct _gfx__Drawable *);
	void (*_drawAxes)(struct _gfx__Drawable *);
	void (*update)(struct _gfx__Drawable *, int);
	bool axes;
};


void _gfx_Drawable_load();

#endif // ___gfx_Drawable__

