use sdl

import lang/String

	
	INIT_TIMER : extern(SDL_INIT_TIMER) const Int
	INIT_AUDIO : extern(SDL_INIT_AUDIO) const Int
	INIT_VIDEO : extern(SDL_INIT_VIDEO) const Int
	INIT_CDROM : extern(SDL_INIT_CDROM) const Int
	INIT_JOYSTICK : extern (SDL_INIT_JOYSTICK) const Int
	INIT_NOPARACHUTE : extern (SDL_INIT_NOPARACHUTE) const Int
	INIT_EVENTTHREAD : extern (SDL_INIT_EVENTTHREAD) const Int
	INIT_EVERYTHING  : extern (SDL_INIT_EVERYTHING) const Int
	
	SWSURFACE: extern(SDL_SWSURFACE)	const Int/* Surface is in system memory */
	HWSURFACE: extern(SDL_HWSURFACE)	const Int/* Surface is in video memory */
	ASYNCBLIT: extern(SDL_ASYNCBLIT)	const Int/* Use asynchronous blits if possible */
	
	/* Available for SDL_SetVideoMode() */
	ANYFORMAT: extern(SDL_ANYFORMAT)	const Int/* Allow any video depth/pixel-format */
	HWPALETTE: extern(SDL_HWPALETTE)	const Int/* Surface has exclusive palette */
	DOUBLEBUF: extern(SDL_DOUBLEBUF)	const Int/* Set up double-buffered video mode */
	FULLSCREEN: extern (SDL_FULLSCREEN)	const Int/* Surface is a full screen display */
	OPENGL: extern(SDL_OPENGL) 			const Int/* Create an OpenGL rendering context */
	sOPENGLBLIT: extern(SDL_OPENGLBLIT)	const Int/* Create an OpenGL rendering context and use it for blitting */
	RESIZABLE: extern(SDL_RESIZABLE)	const Int/* This video mode may be resized */
	NOFRAME: extern(SDL_NOFRAME)		const Int/* No window caption or edge frame */
	
	/* Used internally (read-only) */
	HWACCEL: extern(SDL_HWACCEL)		const Int/* Blit uses hardware acceleration */
	SRCCOLORKEY: extern(SDL_SRCCOLORKEY)const Int/* Blit uses a source color key */
	RLEACCELOK: extern(SDL_RLEACCELOK)	const Int/* Private flag */
	RLEACCEL: extern(SDL_RLEACCEL)		const Int/* Surface is RLE encoded */
	SRCALPHA: extern(SDL_SRCALPHA)		const Int/* Blit uses source alpha blending */
	PREALLOC: extern(SDL_PREALLOC)		const Int/* Surface uses preallocated memory */
	
	Surface: cover from SDL_Surface
 
SDL: cover {
	
	/* Some general methods for sdl */
	init: extern(SDL_Init) static func(UInt32) -> Int
	initSubSystem: extern(SDL_InitSubSystem) static func(UInt32) -> Int
	quitSubSystem: extern(SDL_QuitSubSystem) static func(UInt32)
	quit: extern(SDL_Quit) static func()
	wasInit: extern (SDL_WasInit) static func(UInt32) -> Int
	getError: extern(SDL_GetError) static func() -> String
	setError: extern(SDL_SetError) static func (const String, ...)
	//error: extern(SDL_Error) static func (extern(SDL_errorcode))
	clearError: extern(SDL_ClearError) static func()
	loadObject: extern(SDL_LoadObject) static func(const String) -> Void*
	loadFunction: extern(SDL_LoadFunction) static func(Void* , const String) -> Void*
	unloadObject: extern(SDL_UnloadObject) static func(Void*)
	//linkedVersion: extern(SDL_Linked_Version) static func() -> const SDL_version*
}
