//
//  CMSC405_HW2.cpp
//
//  Created by Yuji Shimojo on 11/4/12.

// Include section
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#define PART 200
#define M_PI 3.1415926535897932384626433832795

// Window display size
GLsizei winWidth = 800, winHeight = 600;   

// Initialize method
void init (void)
{
    // Get and display your OpenGL version
	const GLubyte *Vstr;
	Vstr = glGetString (GL_VERSION);
	fprintf(stderr, "Your OpenGL version is %s\n", Vstr);
    
	// White color window
   	glClearColor (0.0, 0.0, 0.5, 0.0);
    // Projection on World Coordinates 
   	glMatrixMode (GL_PROJECTION);
   	gluOrtho2D (0.0,(GLdouble) winWidth , 0.0,(GLdouble) winHeight);
}

// Method for creating a circle
void drawCircle (int x_intercept, int y_intercept)
{
    int i, n = PART;
    float x, y, r = 11;
    double rate;
    
    // Set pink color
    glColor3f (1.0, 0.6, 0.7);
    glBegin (GL_POLYGON);
    for (i = 0; i < n; i++) {
        rate = (double)i / n;
        x = r * cos(2.0 * M_PI * rate);
        y = r * sin(2.0 * M_PI * rate);
        glVertex2f(x_intercept+x, y_intercept+y);
    }
    glEnd();
}

void displayFcn (void)
{
    // Clear display window.
    glClear (GL_COLOR_BUFFER_BIT);
    
    // Create a trapezoid
    // Set brown color
    glColor3f (0.7, 0.6, 0);
    glBegin (GL_QUADS);
        glVertex2i (460, 15);
        glVertex2i (485, 75);
        glVertex2i (310, 75);
        glVertex2i (335, 15);   
    glEnd();
    
    // Trunk of the tree
    // Set dark brown color
    glColor3f (0.8, 0.3, 0.1);
    glRecti (420, 75, 375, 150);

    // Create triangles
    // Set dark green
    glColor3f (0.0, 0.5, 0.0);
    glBegin (GL_TRIANGLES);
    // 1st
    glVertex2i (397, 225);
    glVertex2i (247, 125);
    glVertex2i (547, 125);    
    // 2nd
    glVertex2i (397, 305);
    glVertex2i (267, 205);
    glVertex2i (527, 205);
    // 3rd
    glVertex2i (397, 385);
    glVertex2i (287, 285);
    glVertex2i (507, 285);
    // 4th
    glVertex2i (397, 465);
    glVertex2i (307, 365);
    glVertex2i (487, 365);
    // 5th
    glVertex2i (397, 545);
    glVertex2i (327, 445);
    glVertex2i (467, 445);
    glEnd ( );    
 
    // Draw circles
    drawCircle(375, 490);
    drawCircle(425, 395);
    drawCircle(365, 335);    
    drawCircle(395, 250);
    drawCircle(460, 155);

    // Draw the star on top of the tree
    // Set yellow color
    glColor3f (1.0, 1.0, 0.0);
    glBegin (GL_LINE_LOOP);
    glVertex2i(397, 583); // = X, Y
    glVertex2i(376, 533); // X-21, Y-50
    glVertex2i(427, 563); // X+30, Y-20
    glVertex2i(367, 563); // X-30, Y-20
    glVertex2i(418, 533); // X+21, Y-50
    glEnd();    
    
    // Draw stars
    glBegin (GL_LINE_LOOP);
    glVertex2i(415, 490); // = X, Y
    glVertex2i(405, 465); // X-10, Y-25
    glVertex2i(430, 480); // X+15, Y-10
    glVertex2i(400, 480); // X-15, Y-10
    glVertex2i(425, 465); // X+10, Y-25
    glEnd();

    glBegin (GL_LINE_LOOP);
    glVertex2i(365, 415); // = X, Y
    glVertex2i(355, 390); // X-10, Y-25
    glVertex2i(380, 405); // X+15, Y-10
    glVertex2i(350, 405); // X-15, Y-10
    glVertex2i(375, 390); // X+10, Y-25
    glEnd();    

    glBegin (GL_LINE_LOOP);
    glVertex2i(435, 345); // = X, Y
    glVertex2i(425, 320); // X-10, Y-25
    glVertex2i(450, 335); // X+15, Y-10
    glVertex2i(420, 335); // X-15, Y-10
    glVertex2i(445, 320); // X+10, Y-25
    glEnd();

    glBegin (GL_LINE_LOOP);
    glVertex2i(345, 255); // = X, Y
    glVertex2i(335, 230); // X-10, Y-25
    glVertex2i(360, 245); // X+15, Y-10
    glVertex2i(330, 245); // X-15, Y-10
    glVertex2i(355, 230); // X+10, Y-25
    glEnd();

    glBegin (GL_LINE_LOOP);
    glVertex2i(450, 250); // = X, Y
    glVertex2i(440, 225); // X-10, Y-25
    glVertex2i(465, 240); // X+15, Y-10
    glVertex2i(435, 240); // X-15, Y-10
    glVertex2i(460, 225); // X+10, Y-25
    glEnd();
    
    glBegin (GL_LINE_LOOP);
    glVertex2i(395, 190); // = X, Y
    glVertex2i(385, 165); // X-10, Y-25
    glVertex2i(410, 180); // X+15, Y-10
    glVertex2i(380, 180); // X-15, Y-10
    glVertex2i(405, 165); // X+10, Y-25
    glEnd();    

    glBegin (GL_LINE_LOOP);
    glVertex2i(330, 170); // = X, Y
    glVertex2i(320, 145); // X-10, Y-25
    glVertex2i(345, 160); // X+15, Y-10
    glVertex2i(315, 160); // X-15, Y-10
    glVertex2i(340, 145); // X+10, Y-25
    glEnd();
        
    // Set characters
    glColor3f(1, 0, 0);
    glRasterPos2i(310,300);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'M'); 
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e'); 
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'r');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'r'); 
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'y');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'C');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'h');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'r');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'i');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'s');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'m');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'a');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'s');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'!');
    
    // Execute OpenGL functions
    glFlush ( );
}

// Windows redraw function
void winReshapeFcn (GLint newWidth, GLint newHeight)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ( );
    gluOrtho2D (0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
    glClear (GL_COLOR_BUFFER_BIT);  
}

// Main function
int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    // Set initial Window position
    glutInitWindowPosition (100, 100);
    // Set Window Size
    glutInitWindowSize (winWidth, winHeight);
    // Set Window Title
    glutCreateWindow ("Merry Chistmas!");
    // Initialize
    init ( );
    // Display function call
    glutDisplayFunc (displayFcn);
    // Window reshape call
    glutReshapeFunc (winReshapeFcn);
    glutMainLoop ( );
	return 0;
}