/* gfx.Drawable header file, generated with ooc */
#ifndef ___gfx_Drawable__fwd__
#define ___gfx_Drawable__fwd__


#include <GL/glew.h>
struct _gfx__Drawable;
typedef struct _gfx__Drawable gfx__Drawable;
struct _gfx__DrawableClass;
typedef struct _gfx__DrawableClass gfx__DrawableClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <out/glew-fwd.h>
#include <Stirling3d/math/Vector3d-fwd.h>
lang__Class *Drawable_class();

void Drawable___load__();
void Drawable___defaults__(struct _gfx__Drawable *this);
void Drawable___defaults___impl(struct _gfx__Drawable *this);
void Drawable___destroy__(struct _gfx__Drawable *this);
void Drawable___destroy___impl(struct _gfx__Drawable *this);
struct _gfx__Drawable *Drawable_new_drawableAbstract();
void Drawable_init_drawableAbstract(struct _gfx__Drawable *this);
void Drawable_init_drawableAbstract_impl(struct _gfx__Drawable *this);
void Drawable_draw(struct _gfx__Drawable *this);
void Drawable_draw_impl(struct _gfx__Drawable *this);
void Drawable__draw(struct _gfx__Drawable *this);
void Drawable__draw_impl(struct _gfx__Drawable *this);
void Drawable__drawAxes(struct _gfx__Drawable *this);
void Drawable__drawAxes_impl(struct _gfx__Drawable *this);
void Drawable_update(struct _gfx__Drawable *this, int t);
void Drawable_update_impl(struct _gfx__Drawable *this, int t);


#endif // ___gfx_Drawable__fwd__

