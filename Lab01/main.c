
/* -- INCLUDE FILES ------------------------------------------------------ */
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

/* ----------------------------------------------------------------------- */

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0f, 0.0f, 0.0f);
  glPointSize(3.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/* ----------------------------------------------------------------------- */

/* ----------------------------------------------------------------------- */
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex3f(0.25, 0.25, 0.0);
  glVertex3f(0.75, 0.25, 0.0);
  glVertex3f(0.75, 0.75, 0.0);
  glVertex3f(0.25, 0.75, 0.0);
  glEnd();
  glFlush();
  glutSwapBuffers();
}

/* ----------------------------------------------------------------------- */

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Lab01");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
}

/* ----------------------------------------------------------------------- */
