/* gfx.Screen header file, generated with ooc */
#ifndef ___gfx_Screen__
#define ___gfx_Screen__


#include "Screen-fwd.h"


struct _gfx__Screen{
	struct _lang__Object __super__;
	int x, y, bpp;
	char *title;
};


struct _gfx__ScreenClass{
	struct _lang__ObjectClass __super__;
	struct _gfx__Screen * (*new)(int, int, int);
	void (*init)(struct _gfx__Screen *, int, int, int);
	void (*setRes)(struct _gfx__Screen *, int, int, int);
	void (*title)(struct _gfx__Screen *, char *);
	void (*close)(struct _gfx__Screen *);
};


void _gfx_Screen_load();

#endif // ___gfx_Screen__

