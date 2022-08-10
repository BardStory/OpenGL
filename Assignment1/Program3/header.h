#ifndef HEADER_FILE
#define HEADER_FILE

//variables for colors
float WHITE = 1.0;
float BLACK = 0.0;

//Variables for initial window
int WindowWidth = 700;
int WindowHeight = 700;
int WindowPositionWidth = 200;
int WindowPositionHeight = 200;

//windowhandle
char window[50] = "Athabasca University - Comp390 TME 1 Program 3";

//variables
float blue = 1.0;
float green = 1.0;
float red = 1.0;
//red + green = yellow

//Routines
void initialize();
void render();
void display();
void reshape(int w, int h);

#endif