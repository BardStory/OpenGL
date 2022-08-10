/*
Author: Joshua Bard
Athabasca ID: 3453236
Assignment: COMP 390 TME1 Program 1 2D Graphics

The editor used was Microsoft Visual 2022

This Program draws two houses in openGL. The one on top does not use Anti-aliasing and the bottom one does.

Routines:
-Initialise sets the background colour to white
-Render sets the point colors and allows for the points to connect through lines
-Display creates the display buffer to view the images
-Reshape creates teh reshape buffer for view on the perspective of images
-Main runs and call everything

Problems or Errors. The question states I must have 1 routine to render each house. So I just made both houses in the render routine. 
If they were suppose to be called in seperate routines I would have just called them from the render method.

References:
Below is the test file given to test openGL. The functions initialize, display, reshape, render and main were based on the test file.
https://scis.lms.athabascau.ca/file.php/400/studyguide/code/U1S2O3.cpp
*/


#include "GL/glut.h"
#include "header.h"



//renders both houses
void render() {

	//sets the point colors to be black
	glColor3f(BLACK, BLACK, BLACK);
	
	//select polygon. For the face must be front and back facing polygons and we want 
	//the boundry edges to be drawn in line segments hence GL_Line
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//makes sure antialiasing is off for the first house
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_BLEND);

	//Draw The TopHouseTriangle
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(TopTriangle[i][0], TopTriangle[i][1]);
	}
	glEnd();

	//draw the TopHouseSquare
	glBegin(GL_QUADS);
	
	//We can use a for loop only because the points are in order for cleanliness
	//glvertex2f are paring the point/line/vertices together. Point order is important to work properly
	for (int i = 0; i < 4; i++) {
		glVertex2f(TopSquare[i][0], TopSquare[i][1]);
	}
	glEnd();
	
	//makes sure antialiasing is on
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	//blends the lines to be cleaner
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Draw The TopHouseTriangle
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(BotTriangle[i][0], BotTriangle[i][1]);
	}
	glEnd();

	//draw the TopHouseSquare we need to use floats for antialiasing to make it cleaner
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++) {
		glVertex2f(BotSquare[i][0], BotSquare[i][1]);
	}
	glEnd();

}

// reshape registry (FROM TEST FILE)
void reshape(int w, int h) {

	//specifies the affline transformation of x and y from the normalized coordinates
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	//sets the current matrix mode
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//multiplys current matrix by perspective matrix
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 50.0);
	glMatrixMode(GL_MODELVIEW);
}
//initialize (FROM TEST FILE)
void initialize() {
	//sets the background colour to white.
	glClearColor(WHITE, WHITE, WHITE, WHITE);
}

//display registry (FROM TEST FILE)
void display(void) {
	
	//glClear will clear buffers of any preset values.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//replaces current matrix with the identity matrix
	glLoadIdentity();
	
	//creates the viewing matrix need to make slight adjustments to properly view houses based on points
	gluLookAt(0.0, 0.0, 12.0, 2.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	//calls render
	render();

	//buffer swap
	glutSwapBuffers();
}



// main program (From Test File)
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	//sets the window size and position
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitWindowPosition(WindowPositionWidth, WindowPositionHeight);
	
	//sets the title for the windowhandle and adds it
	int windowHandle = glutCreateWindow(window);
	glutSetWindow(windowHandle);
	
	//calls the display and reshape function
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	//initializes the background color
	initialize();
	glutMainLoop();
}