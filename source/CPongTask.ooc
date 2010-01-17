use sdl,glew,glu
import glew,ITask,sdl/Event,CGlobalTimer,CInputTask,CKernel,glu/Glu

abs: extern func(...) -> Int

CPongTask:class extends ITask {
	p1pos, p2pos: Float
	paddleWidth, paddleHeight: Float
	ballX, ballY, ballVX, ballVY: Float
	ballSize: Float
	
	init: func ~cpongtask {
		super()
	}

	start: func -> Bool {
		//initRandomNumbers()
		glViewport(0,0,1280,800)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()
	    glOrtho(0.0, 1.0, 1.0, 0.0, -1.0, 1.0)
	    glMatrixMode(GL_MODELVIEW)
	    glLoadIdentity()

		glClearColor(0.0, 0.0, 0.0, 1.0)
		glShadeModel(GL_SMOOTH)
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL)
		glEnable(GL_BLEND)
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA)

		paddleWidth = 0.1 ; paddleHeight = 0.01
		p1pos = 0.5 ; p2pos = 0.5
		ballX = 0.5 ;  ballY=0.5
		ballVX = (rand() % 20 - 10)/20.0
		ballVY = (rand() % 20 - 10)/20.0
		ballSize = 0.01

		return true
	}
	
	update: func {
		glClear(GL_COLOR_BUFFER_BIT)
	    glMatrixMode(GL_MODELVIEW)
	    glLoadIdentity()
		
		if(CInputTask get() mouseDown(SDL_BUTTON_LEFT))CKernel get() killAllTasks()
		glPushMatrix()
		glBegin(GL_QUADS)
		{
			glColor4f(1.0,1.0,1.0,1.0)
			//draw the ball
			glVertex2f(ballX-ballSize, ballY-ballSize)
			glVertex2f(ballX+ballSize, ballY-ballSize)
			glVertex2f(ballX+ballSize, ballY+ballSize)
			glVertex2f(ballX-ballSize, ballY+ballSize)
			
			
			//paddles
			glVertex2f(p2pos-paddleWidth, 0)
			glVertex2f(p2pos+paddleWidth, 0)
			glVertex2f(p2pos+paddleWidth, paddleHeight)
			glVertex2f(p2pos-paddleWidth, paddleHeight)

			glVertex2f(p1pos-paddleWidth, 1-paddleHeight)
			glVertex2f(p1pos+paddleWidth, 1-paddleHeight)
			glVertex2f(p1pos+paddleWidth, 1)
			glVertex2f(p1pos-paddleWidth, 1)
		}
		glEnd()
		glPopMatrix()

		p1pos += (CInputTask get() dX)  / 200.0
		if( p1pos < paddleWidth ) p1pos = paddleWidth
		if( p1pos > 1 - paddleWidth) p1pos = 1 - paddleWidth

		ballX += ballVX * CGlobalTimer get() dT; ballY += ballVY * CGlobalTimer get() dT
		if( ballX < ballSize ) ballVX = qAbs(ballVX)//-ballVX
		if( ballX > 1 - ballSize ) ballVX =  -qAbs(ballVX)//-ballVX
		if(ballY < ballSize + paddleHeight ) {
			if((ballX > p2pos - paddleWidth ) && (ballX < p2pos + paddleWidth)) {
				ballVY = -ballVY
			}else{
				CKernel get() killAllTasks()
			}
		}
		if(ballY > 1 - ballSize - paddleHeight) {
			if((ballX > p1pos - paddleWidth ) && (ballX < p1pos + paddleWidth)) {
				ballVY = -ballVY
			}else{
				CKernel get() killAllTasks()
			}
		}

		if(ballX > p2pos) p2pos += 0.6*CGlobalTimer get() dT
		if(ballX<p2pos) p2pos-=0.6*CGlobalTimer get() dT
		if(p2pos<paddleWidth) p2pos = paddleWidth
		if(p2pos>1-paddleWidth) p2pos = 1 - paddleWidth
	}
	stop: func {
	}
	
	handleEvent: func(event: Event) {
	}
	
	qAbs: func(f: Float) -> Float {
		return (f > 0)?f:-f
	}
}
