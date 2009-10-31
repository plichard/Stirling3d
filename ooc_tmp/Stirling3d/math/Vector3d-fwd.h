/* math.Vector3d header file, generated with ooc */
#ifndef ___math_Vector3d__fwd__
#define ___math_Vector3d__fwd__


struct _math__Vector3d;
typedef struct _math__Vector3d math__Vector3d;
struct _math__Vector3dClass;
typedef struct _math__Vector3dClass math__Vector3dClass;

#include <sdk/lang/BasicTypes.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>
lang__Class *Vector3d_class();

void Vector3d___load__();
void Vector3d___defaults__(struct _math__Vector3d *this);
void Vector3d___defaults___impl(struct _math__Vector3d *this);
void Vector3d___destroy__(struct _math__Vector3d *this);
void Vector3d___destroy___impl(struct _math__Vector3d *this);
struct _math__Vector3d *Vector3d_new_withParams(double x, double y, double z);
void Vector3d_init_withParams(struct _math__Vector3d *this, double x, double y, double z);
void Vector3d_init_withParams_impl(struct _math__Vector3d *this, double x, double y, double z);
struct _math__Vector3d *Vector3d_new();
void Vector3d_init(struct _math__Vector3d *this);
void Vector3d_init_impl(struct _math__Vector3d *this);
bool Vector3d_isNull(struct _math__Vector3d *this);
bool Vector3d_isNull_impl(struct _math__Vector3d *this);
void Vector3d_set(struct _math__Vector3d *this, double x, double y, double z);
void Vector3d_set_impl(struct _math__Vector3d *this, double x, double y, double z);
void Vector3d_print(struct _math__Vector3d *this);
void Vector3d_print_impl(struct _math__Vector3d *this);
struct _math__Vector3d *Vector3d_clone(struct _math__Vector3d *this);
struct _math__Vector3d *Vector3d_clone_impl(struct _math__Vector3d *this);

math__Vector3d *__OP_ADD_Vector3d_Vector3d__Vector3d(math__Vector3d *a, math__Vector3d *b);
math__Vector3d *__OP_SUB_Vector3d_Vector3d__Vector3d(math__Vector3d *a, math__Vector3d *b);
math__Vector3d *__OP_DIV_Vector3d_Double__Vector3d(math__Vector3d *v, double n);

#endif // ___math_Vector3d__fwd__

