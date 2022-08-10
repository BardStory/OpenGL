/*
Author: Joshua Bard
Athabasca ID: 3453236
Assignment: COMP 390 TME1 Program 3 2D Graphics

The editor used was Microsoft Visual 2022

This Program adds color to the screen by putting 4 different vertices in each corner.

Headers:
-Render Sets the vertices to the right color and puts them on proper points. Also draws them on screen
-Display creates the display buffer to view the images
-Reshape creates teh reshape buffer for view on the perspective of images
-Initialise sets the background colour to white
-Main runs and call everything

Problems or Errors. No problems except for aligning the vertex based on the view to not have one colour overpower others.

References:
Below is the test file given to test openGL. The functions initialize, display, reshape, render and main were based on the test file.
https://scis.lms.athabascau.ca/file.php/400/studyguide/code/U1S2O3.cpp
*/


#include "GL/glut.h"
#include "header.h"

void render() {
	glBegin(GL_QUADS);
	//Bottom Right red
	glColor3f(red, 0.0, 0.0);
	glVertex2f(-8, -7.0);
	//Top left green
	glColor3f(0.0, green, 0.0);
	glVertex2f(-8, 7.0);
	//top right blue
	glColor3f(0.0, 0.0, blue);
	glVertex2f(8, 7.0);
	//bottom left yellow
	glColor3f(red, green, 0.0);
	glVertex2f(8, -7.0);
	glEnd();
}

//reshape registry (FROM TEST FILE)
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


//display registry (FROM TEST FILE)
void display(void) {

	//glClear will clear buffers of any preset values.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//replaces current matrix with the identity matrix
	glLoadIdentity();

	//creates the viewing matrix need to make slight adjustments to properly view 
	gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//calls render
	render();

	//buffer swap
	glutSwapBuffers();
}

//initialize 
void initialize() {
	//sets the background colour to white.
	glClearColor(WHITE, WHITE, WHITE, WHITE);
}

//main program (From Test File)
int main(int argc, char** argv) {
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