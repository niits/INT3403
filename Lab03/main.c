#include <gl/glut.h>
#include <windows.h>

float StartShape[18] = {
    0, 10,
    -25, 10,
    -25, 0,
    -5, 0,
    -5, -20,
    5, -20,
    5, 0,
    25, 0,
    25, 10};
float EndShape[18] = {
    -25, 10,
    -25, -20,
    -5, -20,
    -5, -10,
    5, -10,
    5, -20,
    25, -20,
    25, 10,
    0, 20};

void init();
void listenMouseClicked(int button, int state, int x, int y);
void displayWithoutTranform();
void displayWithTranform();
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 480);
    glutInitWindowPosition(150, 100);
    glutCreateWindow("LAB 3");
    init();
    glutDisplayFunc(displayWithoutTranform);
    glutMouseFunc(listenMouseClicked);
    glutMainLoop();
    return 0;
}
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glLoadIdentity();
    gluOrtho2D(-30, 30, -30, 30);
}
void listenMouseClicked(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        glutDisplayFunc(displayWithTranform);
        glutPostRedisplay();
    }
}
void displayWithoutTranform()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, StartShape);
    glDrawArrays(GL_LINE_LOOP, 0, 9);
    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}
void displayWithTranform()
{
    static float t = 0;
    static float d = 1;
    glClear(GL_COLOR_BUFFER_BIT);
    float intermediateShape[18];
    for (int i = 0; i < 9; i++)
    {
        intermediateShape[i * 2] = (1 - t) * StartShape[i * 2] + t * EndShape[i * 2];
        intermediateShape[i * 2 + 1] = (1 - t) * StartShape[i * 2 + 1] + t * EndShape[i * 2 + 1];
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, intermediateShape);
    glDrawArrays(GL_LINE_LOOP, 0, 9);
    glDisableClientState(GL_VERTEX_ARRAY);
    t += 0.0001 * d;
    if (t >= 1 && d >= 1)
    {
        d = -1;
    }
    if (t <= 0 && d <= -1)
    {
        d = 1;
    }
    glutSwapBuffers();
    glutPostRedisplay();
}