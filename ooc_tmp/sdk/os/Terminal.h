/* os.Terminal header file, generated with ooc */
#ifndef ___os_Terminal__
#define ___os_Terminal__


#include "Terminal-fwd.h"


struct _os__Attr{
	struct _lang__Object __super__;
};


struct _os__AttrClass{
	struct _lang__ObjectClass __super__;
	struct _os__Attr * (*new)();
	void (*init)(struct _os__Attr *);
	int reset, bright, dim, under, blink, reverse, hidden;
};


struct _os__Color{
	struct _lang__Object __super__;
};


struct _os__ColorClass{
	struct _lang__ObjectClass __super__;
	struct _os__Color * (*new)();
	void (*init)(struct _os__Color *);
	int black, red, green, yellow, blue, magenta, cyan, white;
};


struct _os__Terminal{
	struct _lang__Object __super__;
};


struct _os__TerminalClass{
	struct _lang__ObjectClass __super__;
	struct _os__Terminal * (*new)();
	void (*init)(struct _os__Terminal *);
	void (*setColor)(int, int);
	void (*setFgColor)(int);
	void (*setBgColor)(int);
	void (*setAttr)(int);
	void (*reset)();
};


void _os_Terminal_load();

#endif // ___os_Terminal__

