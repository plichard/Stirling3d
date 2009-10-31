/* Stirling3d header file, generated with ooc */
#ifndef ___Stirling3d__
#define ___Stirling3d__


#include "Stirling3d-fwd.h"


struct _Stirling3d{
	struct _lang__Object __super__;
	struct _gfx__Scene *scene;
	struct _gfx__Screen *screen;
	bool isRunning;
};


struct _Stirling3dClass{
	struct _lang__ObjectClass __super__;
	struct _Stirling3d * (*new)();
	void (*init)(struct _Stirling3d *);
	void (*window)(struct _Stirling3d *, int, int);
	void (*newScene)(struct _Stirling3d *);
	void (*drawAxes)(struct _Stirling3d *, bool);
	void (*handleInput)(struct _Stirling3d *);
	void (*mainLoop)(struct _Stirling3d *);
};


void _Stirling3d_load();

#endif // ___Stirling3d__

