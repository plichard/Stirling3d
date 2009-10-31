/* sdl.Event header file, generated with ooc */
#ifndef ___sdl_Event__fwd__
#define ___sdl_Event__fwd__


#include <SDL/SDL.h>
typedef SDL_Event sdl__Event;
typedef struct _sdl__SDLEvent sdl__SDLEvent;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
#include <Stirling3d/sdl/Sdl-fwd.h>
lang__Class *Event_class();
lang__Class *SDLEvent_class();
#ifndef SDLEvent_wait
#define SDLEvent_wait SDL_WaitEvent
#endif

#ifndef SDLEvent_poll
#define SDLEvent_poll SDL_PollEvent
#endif


#endif // ___sdl_Event__fwd__

