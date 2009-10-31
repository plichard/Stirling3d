/* sdl.Sdl header file, generated with ooc */
#ifndef ___sdl_Sdl__fwd__
#define ___sdl_Sdl__fwd__


#include <SDL/SDL.h>
typedef SDL_Surface sdl__Surface;
typedef struct _sdl__SDL sdl__SDL;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
lang__Class *Surface_class();
lang__Class *SDL_class();
#ifndef SDL_init
#define SDL_init SDL_Init
#endif

#ifndef SDL_initSubSystem
#define SDL_initSubSystem SDL_InitSubSystem
#endif

#ifndef SDL_quitSubSystem
#define SDL_quitSubSystem SDL_QuitSubSystem
#endif

#ifndef SDL_quit
#define SDL_quit SDL_Quit
#endif

#ifndef SDL_wasInit
#define SDL_wasInit SDL_WasInit
#endif

#ifndef SDL_getError
#define SDL_getError SDL_GetError
#endif

#ifndef SDL_setError
#define SDL_setError SDL_SetError
#endif

#ifndef SDL_clearError
#define SDL_clearError SDL_ClearError
#endif

#ifndef SDL_loadObject
#define SDL_loadObject SDL_LoadObject
#endif

#ifndef SDL_loadFunction
#define SDL_loadFunction SDL_LoadFunction
#endif

#ifndef SDL_unloadObject
#define SDL_unloadObject SDL_UnloadObject
#endif

#ifndef SDL_getTicks
#define SDL_getTicks SDL_GetTicks
#endif


#endif // ___sdl_Sdl__fwd__

