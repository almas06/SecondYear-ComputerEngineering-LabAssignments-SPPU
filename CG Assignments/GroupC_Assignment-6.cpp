/*Write OpenGL program to draw Sun Rise and Sunset..*/

#include <iostream>
#include <GL/glut.h>
#include <math.h>

float sx = 0, sy = 0, r = 0.9, g = 0.8, b = 0.2;
float r1 = 0.4, g1 = 0.8, b1 = 0.8;
float btx = 0, bty = 0;
void sunsettimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, sunsettimer, 0);
    r = 0.9, g = 0.6, b = 0.2;
    sy = sy - 0.06;
    r1 = 0.4, g1 = 0.5, b1 = 0.5;
    sx += 0.00001;

}
void sunrisetimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, sunrisetimer, 0);
    if (sy <= 11)
    {
        sy += 0.03;
        sx += 0.025;
    }
    else if (sy >= 11)
    {
        sunsettimer(0);
    }
}

void birdstimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, birdstimer, 0);
    if(btx<10){
        btx-=0.03;
        bty-=0.001;
    }
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //resets projection matrix
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON); //sky
    glColor3f(r1, g1, b1);
    glVertex2f(-10, -10);
    glVertex2f(-10, 10);
    glVertex2f(10, 10);
    glVertex2f(10, -10);
    glEnd();

    float theta;

    glBegin(GL_POLYGON); //sun
    for (int j = 0; j < 360; j++)
    {
        glColor3f(r, g, b);
        theta = j * 3.14 / 180;
        glVertex2f(-9 + sx + 0.9 * cos(theta), (-2 + sy + 0.9 * sin(theta)));
    }
    glEnd();

    //Mountains
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex2f(-2, -10);
    glVertex2f(-7, -7);
    glVertex2f(-2, 1);
    glVertex2f(4, -7);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.06);
    glVertex2f(-10, -1);
    glVertex2f(-10, -10);
    glVertex2f(-2, -10);

    glVertex2f(-2.5, -10);
    glVertex2f(6, 0);
    glVertex2f(11, -10);
    glEnd();

    //birds
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex2f(5 + btx, 9 + bty);
    glVertex2f(5.5 + btx, 8.5 + bty);
    glVertex2f(5.7 + btx, 8.7 + bty);

    glVertex2f(5.7 + btx, 8.7 + bty);
    glVertex2f(5.5 + btx, 8.8 + bty);
    glVertex2f(6.2 + btx, 9.7 + bty);

    glVertex2f(6 + btx, 9 + bty);
    glVertex2f(6.5 + btx, 8.5 + bty);
    glVertex2f(6.7 + btx, 8.7 + bty);

    glVertex2f(6.7 + btx, 8.7 + bty);
    glVertex2f(6.5 + btx, 8.8 + bty);
    glVertex2f(7.2 + btx, 9.7 + bty);
    glEnd();

    glFlush();
}
int main(int argc, char **argv)

{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Sunrise and Sunset");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, sunrisetimer, 0);
    glutTimerFunc(0, birdstimer, 0);
    glutMainLoop();
}


