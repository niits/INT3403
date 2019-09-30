#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

const GLfloat PI = 3.1415;
int K = 10;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -15, 15);
}
void drawCircle(GLfloat centerX, GLfloat centerY, GLfloat radius)
{
    for (float i = 0; i <= 2; i += 0.01)
    {
        glVertex2f(centerX + radius * cos(PI * i), centerY + radius * sin(PI * i));
    }
}
void display(void)
{
    GLfloat x = 0;
    GLfloat y = 0;
    GLfloat theta = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 2 * PI; theta += 0.02 * PI)
    {
        GLfloat radius = K * (1 + cos(theta)) / 2;
        drawCircle(radius * cos(theta), radius * sin(theta), radius);
    }
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
