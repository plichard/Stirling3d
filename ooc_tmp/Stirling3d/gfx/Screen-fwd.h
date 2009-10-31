/* gfx.Screen header file, generated with ooc */
#ifndef ___gfx_Screen__fwd__
#define ___gfx_Screen__fwd__


#include <SDL/SDL.h>
#include <GL/glew.h>
#include <GL/glu.h>
struct _gfx__Screen;
typedef struct _gfx__Screen gfx__Screen;
struct _gfx__ScreenClass;
typedef struct _gfx__ScreenClass gfx__ScreenClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <Stirling3d/sdl/Sdl-fwd.h>
#include <Stirling3d/sdl/Video-fwd.h>
#include <out/glew-fwd.h>
#include <ooc-glu/glu/Glu-fwd.h>
lang__Class *Screen_class();

void Screen___load__();
void Screen___defaults__(struct _gfx__Screen *this);
void Screen___defaults___impl(struct _gfx__Screen *this);
void Screen___destroy__(struct _gfx__Screen *this);
void Screen___destroy___impl(struct _gfx__Screen *this);
struct _gfx__Screen *Screen_new(int x, int y, int bpp);
void Screen_init(struct _gfx__Screen *this, int x, int y, int bpp);
void Screen_init_impl(struct _gfx__Screen *this, int x, int y, int bpp);
void Screen_setRes(struct _gfx__Screen *this, int x, int y, int bpp);
void Screen_setRes_impl(struct _gfx__Screen *this, int x, int y, int bpp);
void Screen_title(struct _gfx__Screen *this, char *title);
void Screen_title_impl(struct _gfx__Screen *this, char *title);
void Screen_close(struct _gfx__Screen *this);
void Screen_close_impl(struct _gfx__Screen *this);


#endif // ___gfx_Screen__fwd__

