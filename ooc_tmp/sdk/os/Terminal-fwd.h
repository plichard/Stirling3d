/* os.Terminal header file, generated with ooc */
#ifndef ___os_Terminal__fwd__
#define ___os_Terminal__fwd__


struct _os__Attr;
typedef struct _os__Attr os__Attr;
struct _os__AttrClass;
typedef struct _os__AttrClass os__AttrClass;
struct _os__Color;
typedef struct _os__Color os__Color;
struct _os__ColorClass;
typedef struct _os__ColorClass os__ColorClass;
struct _os__Terminal;
typedef struct _os__Terminal os__Terminal;
struct _os__TerminalClass;
typedef struct _os__TerminalClass os__TerminalClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
lang__Class *Attr_class();

void Attr___load__();
void Attr___defaults__(struct _os__Attr *this);
void Attr___defaults___impl(struct _os__Attr *this);
void Attr___destroy__(struct _os__Attr *this);
void Attr___destroy___impl(struct _os__Attr *this);
struct _os__Attr *Attr_new();
void Attr_init(struct _os__Attr *this);
void Attr_init_impl(struct _os__Attr *this);

lang__Class *Color_class();

void Color___load__();
void Color___defaults__(struct _os__Color *this);
void Color___defaults___impl(struct _os__Color *this);
void Color___destroy__(struct _os__Color *this);
void Color___destroy___impl(struct _os__Color *this);
struct _os__Color *Color_new();
void Color_init(struct _os__Color *this);
void Color_init_impl(struct _os__Color *this);

lang__Class *Terminal_class();

void Terminal___load__();
void Terminal___defaults__(struct _os__Terminal *this);
void Terminal___defaults___impl(struct _os__Terminal *this);
void Terminal___destroy__(struct _os__Terminal *this);
void Terminal___destroy___impl(struct _os__Terminal *this);
struct _os__Terminal *Terminal_new();
void Terminal_init(struct _os__Terminal *this);
void Terminal_init_impl(struct _os__Terminal *this);
void Terminal_setColor(int f, int b);
void Terminal_setFgColor(int c);
void Terminal_setBgColor(int c);
void Terminal_setAttr(int att);
void Terminal_reset();


#endif // ___os_Terminal__fwd__

