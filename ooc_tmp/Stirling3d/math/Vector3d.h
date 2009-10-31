/* math.Vector3d header file, generated with ooc */
#ifndef ___math_Vector3d__
#define ___math_Vector3d__


#include "Vector3d-fwd.h"


struct _math__Vector3d{
	struct _lang__Object __super__;
	double x, y, z;
};


struct _math__Vector3dClass{
	struct _lang__ObjectClass __super__;
	struct _math__Vector3d * (*new_withParams)(double, double, double);
	void (*init_withParams)(struct _math__Vector3d *, double, double, double);
	struct _math__Vector3d * (*new)();
	void (*init)(struct _math__Vector3d *);
	bool (*isNull)(struct _math__Vector3d *);
	void (*set)(struct _math__Vector3d *, double, double, double);
	void (*print)(struct _math__Vector3d *);
	struct _math__Vector3d * (*clone)(struct _math__Vector3d *);
};


void _math_Vector3d_load();

#endif // ___math_Vector3d__

