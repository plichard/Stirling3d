/* gfx.Scene header file, generated with ooc */
#ifndef ___gfx_Scene__fwd__
#define ___gfx_Scene__fwd__


#include <GL/glew.h>
#include <GL/glu.h>
struct _gfx__Scene;
typedef struct _gfx__Scene gfx__Scene;
struct _gfx__SceneClass;
typedef struct _gfx__SceneClass gfx__SceneClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <out/glew-fwd.h>
#include <ooc-glu/glu/Glu-fwd.h>
#include <Stirling3d/gfx/Drawable-fwd.h>
#include <Stirling3d/gfx/Particle-fwd.h>
#include <Stirling3d/sdl/Sdl-fwd.h>
#include <Stirling3d/sdl/Video-fwd.h>
#include <sdk/structs/LinkedList-fwd.h>
lang__Class *Scene_class();

void Scene___load__();
void Scene___defaults__(struct _gfx__Scene *this);
void Scene___defaults___impl(struct _gfx__Scene *this);
void Scene___destroy__(struct _gfx__Scene *this);
void Scene___destroy___impl(struct _gfx__Scene *this);
struct _gfx__Scene *Scene_new();
void Scene_init(struct _gfx__Scene *this);
void Scene_init_impl(struct _gfx__Scene *this);
void Scene_clear(struct _gfx__Scene *this);
void Scene_clear_impl(struct _gfx__Scene *this);
void Scene_draw(struct _gfx__Scene *this);
void Scene_draw_impl(struct _gfx__Scene *this);
void Scene_update(struct _gfx__Scene *this);
void Scene_update_impl(struct _gfx__Scene *this);
void Scene_add(struct _gfx__Scene *this, struct _gfx__Drawable *d);
void Scene_add_impl(struct _gfx__Scene *this, struct _gfx__Drawable *d);

extern void usleep(unsigned int);

#endif // ___gfx_Scene__fwd__

