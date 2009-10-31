/* os.Terminal source file, generated with ooc */
#include "Terminal.h"

void Attr___defaults___impl(struct _os__Attr *this){
	Object___defaults___impl((lang__Object *) this);
}

void Attr___destroy___impl(struct _os__Attr *this){
}

void Attr_init_impl(struct _os__Attr *this){
}

lang__Class *Attr_class(){
	static bool __done__ = false;
	static os__AttrClass class = {{{
				.instanceSize = sizeof(os__Attr),
				.size = sizeof(void*),
				.name = "Attr",
			},
			.__load__ = (void (*)()) Attr___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Attr___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Attr___destroy___impl,
		},
		.new = Attr_new,
		.init = Attr_init_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Attr___defaults__(struct _os__Attr *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Attr___destroy__(struct _os__Attr *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Attr_init(struct _os__Attr *this){
	((os__AttrClass *)((lang__Object *)this)->class)->init((struct _os__Attr *) this);
}


void Attr___load__(){
	#line 10 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__AttrClass*) Attr_class())->reset = 0;
	#line 12 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__AttrClass*) Attr_class())->bright = 1;
	#line 14 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__AttrClass*) Attr_class())->dim = 2;
	#line 16 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__AttrClass*) Attr_class())->under = 3;
	#line 18 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__AttrClass*) Attr_class())->blink = 5;
	#line 20 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__AttrClass*) Attr_class())->reverse = 7;
	#line 22 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__AttrClass*) Attr_class())->hidden = 8;
}


struct _os__Attr *Attr_new(){
	#line 7 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	struct _os__Attr *this = ((struct _os__Attr *) (Class_alloc(Attr_class())));
	#line 7 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	Attr_init(this);
	#line 7 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	return this;
}



void Color___defaults___impl(struct _os__Color *this){
	Object___defaults___impl((lang__Object *) this);
}

void Color___destroy___impl(struct _os__Color *this){
}

void Color_init_impl(struct _os__Color *this){
}

lang__Class *Color_class(){
	static bool __done__ = false;
	static os__ColorClass class = {{{
				.instanceSize = sizeof(os__Color),
				.size = sizeof(void*),
				.name = "Color",
			},
			.__load__ = (void (*)()) Color___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Color___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Color___destroy___impl,
		},
		.new = Color_new,
		.init = Color_init_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Color___defaults__(struct _os__Color *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Color___destroy__(struct _os__Color *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Color_init(struct _os__Color *this){
	((os__ColorClass *)((lang__Object *)this)->class)->init((struct _os__Color *) this);
}


void Color___load__(){
	#line 28 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__ColorClass*) Color_class())->black = 30;
	#line 29 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__ColorClass*) Color_class())->red = 31;
	#line 30 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__ColorClass*) Color_class())->green = 32;
	#line 31 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__ColorClass*) Color_class())->yellow = 33;
	#line 32 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__ColorClass*) Color_class())->blue = 34;
	#line 33 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__ColorClass*) Color_class())->magenta = 35;
	#line 34 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__ColorClass*) Color_class())->cyan = 36;
	#line 35 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	((os__ColorClass*) Color_class())->white = 37;
}


struct _os__Color *Color_new(){
	#line 26 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	struct _os__Color *this = ((struct _os__Color *) (Class_alloc(Color_class())));
	#line 26 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	Color_init(this);
	#line 26 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	return this;
}



void Terminal___defaults___impl(struct _os__Terminal *this){
	Object___defaults___impl((lang__Object *) this);
}

void Terminal___destroy___impl(struct _os__Terminal *this){
}

void Terminal_init_impl(struct _os__Terminal *this){
}

lang__Class *Terminal_class(){
	static bool __done__ = false;
	static os__TerminalClass class = {{{
				.instanceSize = sizeof(os__Terminal),
				.size = sizeof(void*),
				.name = "Terminal",
			},
			.__load__ = (void (*)()) Terminal___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Terminal___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Terminal___destroy___impl,
		},
		.new = Terminal_new,
		.init = Terminal_init_impl,
		.setColor = Terminal_setColor,
		.setFgColor = Terminal_setFgColor,
		.setBgColor = Terminal_setBgColor,
		.setAttr = Terminal_setAttr,
		.reset = Terminal_reset,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Terminal___defaults__(struct _os__Terminal *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Terminal___destroy__(struct _os__Terminal *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Terminal_init(struct _os__Terminal *this){
	((os__TerminalClass *)((lang__Object *)this)->class)->init((struct _os__Terminal *) this);
}


void Terminal___load__(){
}


struct _os__Terminal *Terminal_new(){
	#line 38 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	struct _os__Terminal *this = ((struct _os__Terminal *) (Class_alloc(Terminal_class())));
	#line 38 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	Terminal_init(this);
	#line 38 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	return this;
}


void Terminal_setColor(int f, int b){
	#line 46 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	Terminal_setFgColor(f);
	#line 47 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	Terminal_setBgColor(b);
}


void Terminal_setFgColor(int c){
	#line 52 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	if (c >= 30 && c <= 37){
		#line 53 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
		printf("\033[%dm", c);
	}
}


void Terminal_setBgColor(int c){
	#line 59 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	if (c >= 30 && c <= 37){
		#line 60 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
		printf("\033[%dm", c + 10);
	}
}


void Terminal_setAttr(int att){
	#line 66 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	if (att >= 0 && att <= 8){
		#line 67 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
		printf("\033[%dm", att);
	}
}


void Terminal_reset(){
	#line 74 "/media/shared/dev/ooc/sdk/os/Terminal.ooc"
	Terminal_setAttr(((os__AttrClass*) Attr_class())->reset);
}



void _os_Terminal_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		Attr___load__();
		Color___load__();
		Terminal___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
	}
}

