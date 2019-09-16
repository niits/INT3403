/* -- INCLUDE FILES ------------------------------------------------------ */
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <stdio.h>
/* ----------------------------------------------------------------------- */

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0, 0);
  glPointSize(3.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

/* ----------------------------------------------------------------------- */

/* ----------------------------------------------------------------------- */
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  glBegin(GL_POLYGON);
  glVertex2f(0.25, 0.25);
  glVertex2f(0.75, 0.25);
  glVertex2f(0.75, 0.75);
  glVertex2f(0.25, 0.75);
  glEnd();
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}
void listenMouseClicked(int button, int state, int x, int y)
{
  if (state == GLUT_DOWN)
  {
    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
    glutPostRedisplay();
  }
}
/* ----------------------------------------------------------------------- */

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Lab02");
  init();
  glutDisplayFunc(display);
  glutMouseFunc(listenMouseClicked);
  glutMainLoop();
}

/* ----------------------------------------------------------------------- */
