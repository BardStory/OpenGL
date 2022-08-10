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
char window[50] = "Athabasca University - Comp390 TME 1 Program 2";

//Variables

//variable for number of houses to left and right of center
int houses = 2;
//amount each house rotates
float rotateright = -30;
float rotateleft = 30;

//moves houses on x axis to not collide
float distanceleft = -3.0;
float distanceright = 3.0;
float distancedown = -1;
//sets scale to be 1 to 1
float scale = 1.0;

//Array that will hold each point
typedef float array2D[2];
// pts for bottom square of house (Must be in oder)
array2D square[4] = { {0,0}, {2,0}, {2,2}, {0,2} };
// points for triangle top of house (Must be in order)
array2D triangle[3] = { {-0.5, 2}, {2.5, 2}, {1, 3} };

//Routines
void draw(array2D* tempsquare, array2D* temptriangle);
void initialize();
void render();
void display();
void reshape(int w, int h);

#endif