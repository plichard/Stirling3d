/* ooclib source file, generated with ooc */
#include "ooclib.h"
Int Char_toInt(Char this)
{
	if((this >= 48) && (this <= 57))
	{
		return (this - 48);
	}
	return 0 - 1;
}


Int String_length(String this)
{
	return strlen(this);
}


void println(String str)
{
	printf("%s\n", str);
}

void println_empty()
{
	printf("\n");
}

Pointer gc_calloc(SizeT nmemb, SizeT size)
{
	return GC_malloc(nmemb * size);
}


void _ooclib_load()
{
	static bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
	}
}

