/* math.Vector3d source file, generated with ooc */
#include "Vector3d.h"

void Vector3d___defaults___impl(struct _math__Vector3d *this){
	Object___defaults___impl((lang__Object *) this);
	#line 5 "./math/Vector3d.ooc"
	this->x = 0;
	#line 5 "./math/Vector3d.ooc"
	this->y = 0;
	#line 5 "./math/Vector3d.ooc"
	this->z = 0;
}

void Vector3d___destroy___impl(struct _math__Vector3d *this){
}

void Vector3d_init_withParams_impl(struct _math__Vector3d *this, double x, double y, double z){
	#line 7 "./math/Vector3d.ooc"
	this->z = z;
	#line 7 "./math/Vector3d.ooc"
	this->y = y;
	#line 7 "./math/Vector3d.ooc"
	this->x = x;
}

void Vector3d_init_impl(struct _math__Vector3d *this){
}

bool Vector3d_isNull_impl(struct _math__Vector3d *this){
	#line 14 "./math/Vector3d.ooc"
	if (this->x && this->y && this->z){
		#line 15 "./math/Vector3d.ooc"
		return true;
	}
	#line 16 "./math/Vector3d.ooc"
	else {
		#line 17 "./math/Vector3d.ooc"
		return false;
	}
}

void Vector3d_set_impl(struct _math__Vector3d *this, double x, double y, double z){
	#line 20 "./math/Vector3d.ooc"
	this->z = z;
	#line 20 "./math/Vector3d.ooc"
	this->y = y;
	#line 20 "./math/Vector3d.ooc"
	this->x = x;
}

void Vector3d_print_impl(struct _math__Vector3d *this){
	#line 23 "./math/Vector3d.ooc"
	printf("(%0.2f , %0.2f , %0.2f)\n", this->x, this->y, this->z);
}

struct _math__Vector3d *Vector3d_clone_impl(struct _math__Vector3d *this){
	#line 27 "./math/Vector3d.ooc"
	return Vector3d_new_withParams(this->x, this->y, this->z);
}

lang__Class *Vector3d_class(){
	static bool __done__ = false;
	static math__Vector3dClass class = {{{
				.instanceSize = sizeof(math__Vector3d),
				.size = sizeof(void*),
				.name = "Vector3d",
			},
			.__load__ = (void (*)()) Vector3d___load__,
			.__defaults__ = (void (*)(struct _lang__Object *)) Vector3d___defaults___impl,
			.__destroy__ = (void (*)(struct _lang__Object *)) Vector3d___destroy___impl,
		},
		.new_withParams = Vector3d_new_withParams,
		.init_withParams = Vector3d_init_withParams_impl,
		.new = Vector3d_new,
		.init = Vector3d_init_impl,
		.isNull = Vector3d_isNull_impl,
		.set = Vector3d_set_impl,
		.print = Vector3d_print_impl,
		.clone = Vector3d_clone_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__){
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


void Vector3d___defaults__(struct _math__Vector3d *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((struct _lang__Object *) this);
}


void Vector3d___destroy__(struct _math__Vector3d *this){
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((struct _lang__Object *) this);
}


void Vector3d_init_withParams(struct _math__Vector3d *this, double x, double y, double z){
	((math__Vector3dClass *)((lang__Object *)this)->class)->init_withParams((struct _math__Vector3d *) this, x, y, z);
}


void Vector3d_init(struct _math__Vector3d *this){
	((math__Vector3dClass *)((lang__Object *)this)->class)->init((struct _math__Vector3d *) this);
}


bool Vector3d_isNull(struct _math__Vector3d *this){
	return (bool)((math__Vector3dClass *)((lang__Object *)this)->class)->isNull((struct _math__Vector3d *) this);
}


void Vector3d_set(struct _math__Vector3d *this, double x, double y, double z){
	((math__Vector3dClass *)((lang__Object *)this)->class)->set((struct _math__Vector3d *) this, x, y, z);
}


void Vector3d_print(struct _math__Vector3d *this){
	((math__Vector3dClass *)((lang__Object *)this)->class)->print((struct _math__Vector3d *) this);
}


struct _math__Vector3d *Vector3d_clone(struct _math__Vector3d *this){
	return (struct _math__Vector3d *)((math__Vector3dClass *)((lang__Object *)this)->class)->clone((struct _math__Vector3d *) this);
}


void Vector3d___load__(){
}


struct _math__Vector3d *Vector3d_new_withParams(double x, double y, double z){
	#line 7 "./math/Vector3d.ooc"
	struct _math__Vector3d *this = ((struct _math__Vector3d *) (Class_alloc(Vector3d_class())));
	#line 7 "./math/Vector3d.ooc"
	Vector3d_init_withParams(this, x, y, z);
	#line 7 "./math/Vector3d.ooc"
	return this;
}


struct _math__Vector3d *Vector3d_new(){
	#line 11 "./math/Vector3d.ooc"
	struct _math__Vector3d *this = ((struct _math__Vector3d *) (Class_alloc(Vector3d_class())));
	#line 11 "./math/Vector3d.ooc"
	Vector3d_init(this);
	#line 11 "./math/Vector3d.ooc"
	return this;
}


math__Vector3d *__OP_ADD_Vector3d_Vector3d__Vector3d(math__Vector3d *a, math__Vector3d *b) {
	#line 32 "./math/Vector3d.ooc"
	return Vector3d_new_withParams(a->x + b->x, a->y + b->y, a->z + b->z);
}

math__Vector3d *__OP_SUB_Vector3d_Vector3d__Vector3d(math__Vector3d *a, math__Vector3d *b) {
	#line 36 "./math/Vector3d.ooc"
	return Vector3d_new_withParams(a->x - b->x, a->y - b->y, a->z - b->z);
}

math__Vector3d *__OP_DIV_Vector3d_Double__Vector3d(math__Vector3d *v, double n) {
	#line 40 "./math/Vector3d.ooc"
	return Vector3d_new_withParams(v->x / n, v->y / n, v->z / n);
}


void _math_Vector3d_load(){
	static bool __done__ = false;
	if (!__done__){
		__done__ = true;
		Vector3d___load__();
		_lang_BasicTypes_load();
		_lang_memory_load();
		_lang_ooclib_load();
		_lang_stdio_load();
	}
}

