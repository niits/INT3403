#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>
#include <fstream>
#include <cstdio>

void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 1000.0, 0.0, 750.0);
}

void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  std::ifstream fi;
  fi.open("dinosaur.dat");
  int numOfSector = 0;
  fi >> numOfSector;
  for (int i = 0; i < numOfSector; i++)
  {
    int numOfPoint = 0;
    fi >> numOfPoint;
    glBegin(GL_LINE_STRIP);
    for (int j = 0; j < numOfPoint; j++)
    {
      double x, y;
      fi >> x >> y;
      glVertex2d(x, y);
    }
    glEnd();
  }
  glFlush();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Lab5");
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();
}