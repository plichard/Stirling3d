/* gfx.Drawable source file, generated with ooc */
#include "Drawable.h"
#include <out/glew.h>
#include <Stirling3d/math/Vector3d.h>

void Drawable___defaults___impl(struct _gfx__Drawable *this){
	Object___defaults___impl((lang__Object *) this);
	#line 8 "./gfx/Drawable.ooc"
	this->show = true;
	#line 13 "./gfx/Drawable.ooc"
	this->pos = Vector3d_new_withParams(0, 0, 0);
	#line 14 "./gfx/Drawable.ooc"
	this->rot = Vector3d_new_withParams(0, 0, 0);
	#line 15 "./gfx/Drawable.ooc"
	this->scl = Vector3d_new_withParams(1, 1, 1);
}

void Drawable___destroy___impl(struct _gfx__Drawable *this){
}

void Drawable_init_drawableAbstract_impl(struct _gfx__Drawable *this){
}

void Drawable_draw_impl(struct _gfx__Drawable *this){
	#line 23 "./gfx/Drawable.ooc"
	if (this->show){
		#line 24 "./gfx/Drawable.ooc"
		glPushMatrix();
		#line 26 "./gfx/Drawable.ooc"
		glTranslated(this->pos->x, this->pos->y, this->pos->z);
		#line 28 "./gfx/Drawable.ooc"
		Drawable__draw(this);
		#line 29 "./gfx/Drawable.ooc"
		if (((gfx__DrawableClass*) Drawable_class())->axes){
			#line 30 "./gfx/Drawable.ooc"
			Drawable__drawAxes(this);
		}
		#line 32 "./gfx/Drawable.ooc"
		glPopMatrix();
	}
}

void Drawable__draw_impl(struct _gfx__Drawable *this){
	#line 40 "./gfx/Drawable.ooc"
	printf("Empty drawable trying to display itself, strange...\n");
}

void Drawable__drawAxes_impl(struct _gfx__Drawable *this){
	#line 47 "./gfx/Drawable.ooc"
	glBegin(GL_LINES);
	#line 48 "./gfx/Drawable.ooc"
	glColor3d(((double) (1)), ((double) (0)), ((double) (0)));
	#line 49 "./gfx/Drawable.ooc"
	glVertex3d(((double) (0)), ((double) (0)), ((double) (0)));
	#line 49 "./gfx/Drawable.ooc"
	glVertex3d(((double) (1)), ((double) (0)), ((double) (0)));
	#line 50 "./gfx/Drawable.ooc"
	glColor3d(((double) (0)), ((double) (1)), ((double) (0)));
	#line 51 "./gfx/Drawable.ooc"
	glVertex3d(((double) (0)), ((double) (0)), ((double) (0)));
	#line 51 "./gfx/Drawable.ooc"
	glVertex3d(((double) (0)), ((double) (2)), ((double) (0)));
	#line 52 "./gfx/Drawable.ooc"
	glColor3d(((double) (0)), ((double) (0)), ((double) (1)));
	#line 53 "./gfx/Drawable.ooc"
	glVertex3d(((double) (0)), ((double) (0)), ((double) (0)));
	#line 53 "./gfx/Drawable.ooc"
	glVertex3d(((double) (0)), ((double) (0)), ((double) (3)));
	#line 54 "./gfx/Drawable.ooc"
	glEnd();
}

void Drawable_update_impl(struct _gfx__Drawable *this, int t){
}

lang__Class *Drawable_class(){
	static bool __done__ = false;
	static gfx__DrawableClass class = {{{
				.instanceSize = sizeof(gfx__Drawable),
				.size = sizeof(void*),
				.name = "Drawable",
			},
			.__load__ = (void (*)()) Drawable___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Drawable___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Drawable___destroy___impl,
		},
		.new_drawableAbstract = Drawable_new_drawableAbstract,
		.init_drawableAbstract = Drawable_init_drawableAbstract_impl,
		.draw = Drawable_draw_impl,
		._draw = Drawable__draw_impl,
		._drawAxes = Drawable__drawAxes_impl,
		.update = Drawable_update_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Drawable___defaults__(struct _gfx__Drawable *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Drawable___destroy__(struct _gfx__Drawable *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Drawable_init_drawableAbstract(struct _gfx__Drawable *this){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->init_drawableAbstract((struct _gfx__Drawable *) this);
}


void Drawable_draw(struct _gfx__Drawable *this){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->draw((struct _gfx__Drawable *) this);
}


void Drawable__draw(struct _gfx__Drawable *this){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->_draw((struct _gfx__Drawable *) this);
}


void Drawable__drawAxes(struct _gfx__Drawable *this){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->_drawAxes((struct _gfx__Drawable *) this);
}


void Drawable_update(struct _gfx__Drawable *this, int t){
	((gfx__DrawableClass *)((lang__Object *)this)->class)->update((struct _gfx__Drawable *) this, t);
}


void Drawable___load__(){
	#line 11 "./gfx/Drawable.ooc"
	((gfx__DrawableClass*) Drawable_class())->axes = false;
}


struct _gfx__Drawable *Drawable_new_drawableAbstract(){
	#line 17 "./gfx/Drawable.ooc"
	struct _gfx__Drawable *this = ((struct _gfx__Drawable *) (Class_alloc(Drawable_class())));
	#line 17 "./gfx/Drawable.ooc"
	Drawable_init_drawableAbstract(this);
	#line 17 "./gfx/Drawable.ooc"
	return this;
}



void _gfx_Drawable_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		Drawable___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_glew_load();
		_math_Vector3d_load();
	}
}

