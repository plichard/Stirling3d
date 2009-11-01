use glew,glu,sdl
import sdl/[Sdl]
import glew,glu/Glu
import math/Vector3d
import Drawable
import Billboard

Particle: class extends Drawable{
	
	params = null : static Quadric
	textLoaded = false : static Bool
	dlistCreated = false : static Bool
	godlike = false : static Bool
	dlist : static GLuint
	pshow := true  //show this particle?
	
	life = 10 : Double
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
		if(!dlistCreated) {
			dlist = glGenLists(1)
			glNewList(dlist, GL_COMPILE)
				drawfunc()
			glEndList()
			dlistCreated = true
		}
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
		glColor4d(0.1,0.1,1,0.1)
		//billboardCheatSphericalBegin()
		if(pshow)
			glCallList(dlist)
		//vel glPrint()
		//billboardEnd()
	}
	
	drawSquare: func {
		filter : GLuint  /* Which Filter To Use...not used in fact */
		texture : GLuint[3] /* Storage for 3 textures */
		glEnable(GL_TEXTURE_2D)
		if(!textLoaded) {
			
			textureImage := SDL loadBMP("Star.bmp")
			glGenTextures( 3, texture[0]&)
			
			glBindTexture( GL_TEXTURE_2D, texture[0] )
			
			glTexImage2D( GL_TEXTURE_2D, 0, 3, textureImage[0] w,
							textureImage[0] h, 0, GL_BGR,
							GL_UNSIGNED_BYTE, textureImage[0] pixels )
			  
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
							GL_NEAREST )
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
							GL_NEAREST )
		}
		glBegin( GL_QUADS );
		  /* Front Face */
		  /* Normal Pointing Towards Viewer */
		  glNormal3f( 0.0, 0.0, 1.0);
		  /* Point 1 (Front) */
		  glTexCoord2f( 1.0, 0.0); glVertex3f( -1.0, -1.0,  1.0)
		  /* Point 2 (Front) */
		  glTexCoord2f( 0.0, 0.0); glVertex3f(  1.0, -1.0,  1.0)
		  /* Point 3 (Front) */
		  glTexCoord2f( 0.0, 1.0); glVertex3f(  1.0,  1.0,  1.0)
		  /* Point 4 (Front) */
		  glTexCoord2f( 1.0, 1.0); glVertex3f( -1.0,  1.0,  1.0)
		glEnd()
	}	
	
	drawfunc: func {
		gluSphere(params,0.1,10,10)
		//drawSquare()
		//drawCube()
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
