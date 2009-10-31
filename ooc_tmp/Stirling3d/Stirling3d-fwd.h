/* Stirling3d header file, generated with ooc */
#ifndef ___Stirling3d__fwd__
#define ___Stirling3d__fwd__


struct _Stirling3d;
typedef struct _Stirling3d Stirling3d;
struct _Stirling3dClass;
typedef struct _Stirling3dClass Stirling3dClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <Stirling3d/gfx/Scene-fwd.h>
#include <Stirling3d/gfx/Screen-fwd.h>
#include <Stirling3d/gfx/Drawable-fwd.h>
#include <Stirling3d/sdl/Event-fwd.h>
#include <Stirling3d/sdl/Sdl-fwd.h>
lang__Class *Stirling3d_class();

void Stirling3d___load__();
void Stirling3d___defaults__(struct _Stirling3d *this);
void Stirling3d___defaults___impl(struct _Stirling3d *this);
void Stirling3d___destroy__(struct _Stirling3d *this);
void Stirling3d___destroy___impl(struct _Stirling3d *this);
struct _Stirling3d *Stirling3d_new();
void Stirling3d_init(struct _Stirling3d *this);
void Stirling3d_init_impl(struct _Stirling3d *this);
void Stirling3d_window(struct _Stirling3d *this, int x, int y);
void Stirling3d_window_impl(struct _Stirling3d *this, int x, int y);
void Stirling3d_newScene(struct _Stirling3d *this);
void Stirling3d_newScene_impl(struct _Stirling3d *this);
void Stirling3d_drawAxes(struct _Stirling3d *this, bool b);
void Stirling3d_drawAxes_impl(struct _Stirling3d *this, bool b);
void Stirling3d_handleInput(struct _Stirling3d *this);
void Stirling3d_handleInput_impl(struct _Stirling3d *this);
void Stirling3d_mainLoop(struct _Stirling3d *this);
void Stirling3d_mainLoop_impl(struct _Stirling3d *this);

extern void usleep(unsigned int);

#endif // ___Stirling3d__fwd__

