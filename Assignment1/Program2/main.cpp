/*
Author: Joshua Bard
Athabasca ID: 3453236
Assignment: COMP 390 TME1 Program 2 2D Graphics

The editor used was Microsoft Visual 2022

This Program draws a house in OpenGL and then uses Transformation and Rotation to add 4 additional houses. 

Headers:
-Initialise sets the background colour to white
-Render sets the point colors and allows for the points to connect through lines
-Display creates the display buffer to view the images
-Reshape creates teh reshape buffer for view on the perspective of images
-Main runs and call everything

Problems or Errors: Because the houses transform from an angle like a pivot point. It is difficult to make them symmetrical.

References:
Below is the test file given to test openGL. The functions initialize, display, reshape, render and main were based on the test file.
https://scis.lms.athabascau.ca/file.php/400/studyguide/code/U1S2O3.cpp
*/



#include "GL/glut.h"
#include "header.h"


void draw(array2D* tempsquare, array2D* temptriangle){

	//draws the square 
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(tempsquare[i]);
	}
	glEnd();

	//draw the triangle 
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 4; i++) {
		glVertex2fv(temptriangle[i]);
	}
	glEnd();
}

void render() {
	//set color to black
	glColor3f(BLACK, BLACK, BLACK);

	//makes sure antialiasing is on
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// set mode to draw polygons without fill
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// set the matrix mode for transforming the houses
	glMatrixMode(GL_MODELVIEW);

	//Draws the original house
	draw(square, triangle);
	
	//push matrix, do translations and rotates then pop matrix
	glPushMatrix();
	for (int i = 0; i < houses; i++){
		glTranslatef(distanceright, 0.0, 0.0);
		glRotatef(rotateright, 0.0, 0.0, scale);
		draw(square, triangle);
	}
	glPopMatrix();

	//returns matrix to original point to work on left side
	glPushMatrix();
	for (int i = 0; i < houses; i++) {
		glTranslatef(distanceleft, distancedown, 0.0);
		glRotatef(rotateleft, 0.0, 0.0, scale);
		draw(square, triangle);
	}
	glPopMatrix();
	
}


//reshape registry(FROM TEST FILE)
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


//display registry(FROM TEST FILE)
void display(void) {

	//glClear will clear buffers of any preset values.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//replaces current matrix with the identity matrix
	glLoadIdentity();

	//creates the viewing matrix need to make slight adjustments to properly view houses
	gluLookAt(0.0, 0.0, 15.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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

//main (FROM TEST FILE)
void main(int argc, char** argv) {
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