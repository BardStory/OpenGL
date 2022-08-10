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
char window[50] = "Athabasca University - Comp390 TME 1 Program 1";

//Variables (Must be in order or will not work with for loops)

//Top Triangle points 
float TopTriangle[3][2] = { {-2.5,1.5},{0.5,4.5},{-2,4} };

//variable for the points of the house square
float TopSquare[4][2] = { {0,0},{2,2},{0,4},{-2,2} };

//Bottom Triangle points
float BotTriangle[3][2] = { {2.5,-3.5},{5.5,-0.5},{3,-1} };

//variables for the points of the house bottom
float BotSquare[4][2] = { {5,-5},{7,-3},{5,-1},{3,-3} };

//Routines
void initialize();
void render();
void display();
void reshape(int w, int h);



#endif