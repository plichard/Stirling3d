use glew
import glew

Font: class {
	
	base: static GLuint   /* Base Display List For The Font Set */
	cnt1: static GLfloat  /* 1st Counter Used To Move Text & For Coloring */
	cnt2: static GLfloat  /* 2nd Counter Used To Move Text & For Coloring */
	
	
	killFont: func {
		glDeleteLists( base, 96 )
	}
	
	
	buildFont: func() {
		Display *dpy;          /* Our current X display */
		XFontStruct *fontInfo; /* Our font info */

		/* Sotrage for 96 characters */
		base = glGenLists( 96 );

		/* Get our current display long enough to get the fonts */
		dpy = XOpenDisplay( NULL );

		/* Get the font information */
		fontInfo = XLoadQueryFont( dpy, "-adobe-helvetica-medium-r-normal--18-*-*-*-p-*-iso8859-1" );

		/* If the above font didn't exist try one that should */
		if ( fontInfo == NULL )
		{
			fontInfo = XLoadQueryFont( dpy, "fixed" );
			/* If that font doesn't exist, something is wrong */
			if ( fontInfo == NULL )
			{
				fprintf( stderr, "no X font available?\n" );
				Quit( 1 );
			}
		}

		/* generate the list */
		glXUseXFont( fontInfo->fid, 32, 96, base );

		/* Recover some memory */
		XFreeFont( dpy, fontInfo );

		/* close the display now that we're done with it */
		XCloseDisplay( dpy );

		return;
	}

	
	
	
	
}
