use glew
import glew

billboardCheatSphericalBegin: func  {
	
	modelview: Float[16]
	i,j: Int

	// save the current modelview matrix
	glPushMatrix()

	// get the current modelview matrix
	glGetFloatv(GL_MODELVIEW_MATRIX , modelview)

	// undo all rotations
	// beware all scaling is lost as well 
	for( i=0; i<3; i+=1 ) 
	    for( j=0; j<3; j+=1 ) {
		if ( i==j )
		    modelview[i*4+j] = 1.0
		else
		    modelview[i*4+j] = 0.0
	    }

	// set the modelview with no rotations
	glLoadMatrixf(modelview)
}

billboardEnd: func {

	// restore the previously 
	// stored modelview matrix
	glPopMatrix()
}
