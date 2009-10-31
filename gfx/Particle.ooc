use glew,glu
import glew,glu/Glu
import math/Vector3d
import gfx/Drawable

Particle: class extends Drawable{
	
	params = null : static Quadric
	godlike = false : static Bool
	dlist : GLuint
	pshow := true  //show this particle?
	
	life = 1000 : Double
	vel := Vector3d new(0,0,1) as Vector3d
	force := Vector3d new(0,0,0)
	
	isAlive: func -> Bool {
		if(godlike) {
			return true
		}
		
		if(life > 0){
			return true
		}
		
		life = 0
		return false	
	}
	
	init: func ~lifePosVal (=life, .pos, .vel) {
		this pos = pos clone()
		this vel = vel clone() 
		if(!params){
			params = gluNewQuadric()
		}
		dlist = glGenLists(1)
		glNewList(dlist, GL_COMPILE)
			drawfunc()
		glEndList()
	}
	
	update: func(t: Double) {
		vel += force * t / 1000
		dpos := vel * t / 1000
		pos += dpos
		life -= t / 1000
		force set(0,0,0)
	}
	
	addForce: func(f: Vector3d) {
		force = force + f
		//printf("Adding force: (%f,%f,%f)\n",force x, force y, force z)
	}
	
	print: func {
		println()
		printf("life: %d\n",life)
		printf("pos: (%f,%f,%f)\n",pos x, pos y, pos z)
		printf("vel: (%f,%f,%f)\n",vel x, vel y, vel z)
	}
	
	_draw: func {
		//printf("Drawing da sphere!!!")
		//glColor4ub((pos x * 1.3) as Int % 255  + 128,(pos y * 1.3) as Int %  255 + 128,(pos z * 1.3) as Int % 255 + 128,255)
		//glColor4d(1.0,1.0,1.0,1.0)
		//glColor4ub(color r,color g,color b,color a)
		if(pshow)
			glCallList(dlist)
		//vel glPrint()
	}
	
	drawfunc: func {
		gluSphere(params,0.1,10,10)
	}
	
	drawCube: func {
		glBegin( GL_QUADS )                 /* Draw A Quad                      */
      glColor3f(   0.0,  1.0,  0.0) /* Set The Color To Green           */
      glVertex3f(  1.0,  1.0, -1.0) /* Top Right OThe Quad (Top)      */
      glVertex3f( -1.0,  1.0, -1.0) /* Top Left OThe Quad (Top)       */
      glVertex3f( -1.0,  1.0,  1.0) /* Bottom Left OThe Quad (Top)    */
      glVertex3f(  1.0,  1.0,  1.0) /* Bottom Right OThe Quad (Top)   */

      glColor3f(   1.0,  0.5,  0.0) /* Set The Color To Orange          */
      glVertex3f(  1.0, -1.0,  1.0) /* Top Right OThe Quad (Botm)     */
      glVertex3f( -1.0, -1.0,  1.0) /* Top Left OThe Quad (Botm)      */
      glVertex3f( -1.0, -1.0, -1.0) /* Bottom Left OThe Quad (Botm)   */
      glVertex3f(  1.0, -1.0, -1.0) /* Bottom Right OThe Quad (Botm)  */

      glColor3f(   1.0,  0.0,  0.0) /* Set The Color To Red             */
      glVertex3f(  1.0,  1.0,  1.0) /* Top Right OThe Quad (Front)    */
      glVertex3f( -1.0,  1.0,  1.0) /* Top Left OThe Quad (Front)     */
      glVertex3f( -1.0, -1.0,  1.0) /* Bottom Left OThe Quad (Front)  */
      glVertex3f(  1.0, -1.0,  1.0) /* Bottom Right OThe Quad (Front) */

      glColor3f(   1.0,  1.0,  0.0) /* Set The Color To Yellow          */
      glVertex3f(  1.0, -1.0, -1.0) /* Bottom Left OThe Quad (Back)   */
      glVertex3f( -1.0, -1.0, -1.0) /* Bottom Right OThe Quad (Back)  */
      glVertex3f( -1.0,  1.0, -1.0) /* Top Right OThe Quad (Back)     */
      glVertex3f(  1.0,  1.0, -1.0) /* Top Left OThe Quad (Back)      */

      glColor3f(   0.0,  0.0,  1.0) /* Set The Color To Blue            */
      glVertex3f( -1.0,  1.0,  1.0) /* Top Right OThe Quad (Left)     */
      glVertex3f( -1.0,  1.0, -1.0) /* Top Left OThe Quad (Left)      */
      glVertex3f( -1.0, -1.0, -1.0) /* Bottom Left OThe Quad (Left)   */
      glVertex3f( -1.0, -1.0,  1.0) /* Bottom Right OThe Quad (Left)  */

      glColor3f(   1.0,  0.0,  1.0) /* Set The Color To Violet          */
      glVertex3f(  1.0,  1.0, -1.0) /* Top Right OThe Quad (Right)    */
      glVertex3f(  1.0,  1.0,  1.0) /* Top Left OThe Quad (Right)     */
      glVertex3f(  1.0, -1.0,  1.0) /* Bottom Left OThe Quad (Right)  */
      glVertex3f(  1.0, -1.0, -1.0) /* Bottom Right OThe Quad (Right) */
    glEnd( )                            /* Done Drawing The Quad            */
	}
}
