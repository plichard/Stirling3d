import gfx.Drawable
import loop.Scheduler
import loop.Timeout
import math.Vector3d

main: func {
	
	d1 := new Drawable
	d1 draw()
	d1 show
	d1 pos
	
	v1 = d1 pos : Vector3d
	v1 print()
	/* Cannot write
	 * d1 pos print()
	 * must use workarround above
	 * (Calling member function print() in an 
	 * expression MemberAccess which type hasn't been resolved yet!)
	 */
}
