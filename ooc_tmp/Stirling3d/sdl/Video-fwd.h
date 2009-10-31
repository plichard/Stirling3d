/* sdl.Video header file, generated with ooc */
#ifndef ___sdl_Video__fwd__
#define ___sdl_Video__fwd__


#include <SDL/SDL.h>
typedef struct _sdl__SDLVideo sdl__SDLVideo;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <Stirling3d/sdl/Sdl-fwd.h>
lang__Class *SDLVideo_class();
#ifndef SDLVideo_getVideoSurface
#define SDLVideo_getVideoSurface SDL_GetVideoSurface
#endif

#ifndef SDLVideo_setMode
#define SDLVideo_setMode SDL_SetVideoMode
#endif

#ifndef SDLVideo_wmSetCaption
#define SDLVideo_wmSetCaption SDL_WM_SetCaption
#endif

#ifndef SDLVideo_glSwapBuffers
#define SDLVideo_glSwapBuffers SDL_GL_SwapBuffers
#endif


#endif // ___sdl_Video__fwd__

