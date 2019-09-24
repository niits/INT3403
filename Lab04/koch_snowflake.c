#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
const GLfloat PI = 3.1415;

GLfloat currentX = 0;
GLfloat currentY = 0;

void drawEdgeFromPoint(GLfloat angleMeasure, GLfloat length, GLfloat step)
{
    if (step == 0)
    {
        GLfloat nextX = currentX + length * cos(angleMeasure);
        GLfloat nextY = currentY + length * sin(angleMeasure);

        glVertex2f(currentX, currentY);
        glVertex2f(nextX, nextY);
        currentX = nextX;
        currentY = nextY;
    }
    else
    {
        step--;
        length /= 3;
        drawEdgeFromPoint(angleMeasure, length, step);
        drawEdgeFromPoint(angleMeasure - PI / 3, length, step);
        drawEdgeFromPoint(angleMeasure + PI / 3, length, step);
        drawEdgeFromPoint(angleMeasure, length, step);
    }
}
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-8, 8, -8, 8);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    GLfloat angleMeasure = 0;
    currentX = -5.2;
    currentY = -3;
    drawEdgeFromPoint(0, 10.4, 1);
    currentX = 5.2;
    currentY = -3;
    drawEdgeFromPoint(2*PI/3, 10.4, 1);
    currentX = 0;
    currentY = 6;
    drawEdgeFromPoint(4*PI/3, 10.4, 1);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Lab 04");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
