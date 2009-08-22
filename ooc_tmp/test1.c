/* test1 source file, generated with ooc */
#include "test1.h"
Int main()
{
	_test1_load();
	Drawable *d1 = Drawable_new();
	Drawable_draw(d1);
	return 0;
}


void _test1_load()
{
	static bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		_ooclib_load();
		_gfx_Drawable_load();
	}
}

