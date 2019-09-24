#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

const GLfloat PI = 3.1415;
int K = 1;
int n = 8;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
}

void display(void)
{
    GLfloat x = 0;
    GLfloat y = 0;
    GLfloat theta = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 2 * PI; theta += 0.01 * PI)
    {
        x = K * (1 + cos(theta * n)) * cos(theta);
        y = K * (1 + cos(theta * n)) * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    scanf("%d", &K);
    scanf("%d", &n);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Lab 04");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
