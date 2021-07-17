#include<GL/glut.h>   
#include<stdio.h>
int lflag = 0, dflag = 0, m = 0;
int sx = 1.0, sy = 1.0, sz = 1.0;
int dcx = 1.0;
int dcy = 0.0;
int dcz = 1.0;
int fishm = 0;
int my = 0;
int mx = 0;
int fishtranslate = 0;
int fishrot = 0;
int  nightflag = 0;
float skycolors[3] = { 0.0, 0.7, 1.0 };
float suncolors[3] = { 1.0,1.0, 0.0 };
float grasscolors[3] = { 0.3, 0.8, 0.0 };
float pondcolors[3] = { 0.0, 0.7, 1.0 };
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}
void draw_pixel(GLint cx, GLint cy)
{

    glBegin(GL_POINTS);
    glVertex2i(cx, cy);
    glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
    draw_pixel(x + h, y + k);
    draw_pixel(-x + h, y + k);
    draw_pixel(x + h, -y + k);
    draw_pixel(-x + h, -y + k);
    draw_pixel(y + h, x + k);
    draw_pixel(-y + h, x + k);
    draw_pixel(y + h, -x + k);
    draw_pixel(-y + h, -x + k);
}
void draw_circle(GLint h, GLint k, GLint r)
{
    GLint d = 1 - r, x = 0, y = r;
    while (y > x)
    {
        plotpixels(h, k, x, y);
        if (d < 0) d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            --y;
        }
        ++x;
    }
    plotpixels(h, k, x, y);
}
void sky()
{
    glColor3f(skycolors[0], skycolors[1], skycolors[2]);
    glBegin(GL_POLYGON);
    glVertex2i(-500, 500);
    glVertex2i(500, 500);
    glVertex2i(500, 200);
    glVertex2i(-500, 200);
    glEnd();
}
void cloud()

{
    int l;

    for (l = 0; l <= 35; l++)
    {
        glColor3f(1.0, 1.0, 1.0);
        draw_circle(-400 + m, 420, l);
        draw_circle(-450 + m, 420, l);
    }

    for (l = 0; l <= 20; l++)
    {
        glColor3f(1.0, 1.0, 1.0);
        draw_circle(-350 + m, 420, l);

    }
    for (l = 0; l <= 35; l++)
    {
        glColor3f(1.0, 1.0, 1.0);
        draw_circle(-250 + m, 400, l);
        draw_circle(-200 + m, 400, l);
    }

    for (l = 0; l <= 20; l++)
    {
        glColor3f(1.0, 1.0, 1.0);
        draw_circle(-160 + m, 400, l);
    }

    for (l = 0; l <= 35; l++)
    {
        glColor3f(1.0, 1.0, 1.0);
        draw_circle(50 + m, 350, l);
        draw_circle(90 + m, 350, l);

    }

    for (l = 0; l <= 20; l++)
    {
        glColor3f(1.0, 1.0, 1.0);
        draw_circle(130 + m, 350, l);
    }

}
void sidewall(int x, int y)
{
    glColor3f(sx, sy, sz);
    glBegin(GL_POLYGON);
    glVertex2i(-350 + x, 112 + y);
    glVertex2i(-300 + x, 112 + y);
    glVertex2i(-300 + x, 55 + y);
    glVertex2i(-350 + x, 55 + y);
    glEnd();
    //glFlush();
}

void windowline(int x, int y)
{
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(-325 + x, 112 + y);
    glVertex2i(-325 + x, 55 + y);
    glVertex2i(-350 + x, 81 + y);
    glVertex2i(-300 + x, 81 + y);
    glEnd();
    //glFlush();
}
void tree(int x, int y)
{
    int l;
    glColor3f(0.5, 0.35, 0.05);
    glBegin(GL_POLYGON);
    glVertex2i(200 + x, 200 + y);
    glVertex2i(250 + x, 200 + y);
    glVertex2i(250 + x, 50 + y);
    glVertex2i(200 + x, 50 + y);
    glEnd();
    for (l = 0; l <= 35; l++)
    {
        glColor3f(0.0, 0.7, 0.0);
        draw_circle(170 + x, 200 + y, l);
        draw_circle(220 + x, 220 + y, l);
        draw_circle(270 + x, 200 + y, l);
        draw_circle(180 + x, 270 + y, l);
        draw_circle(255 + x, 270 + y, l);
        draw_circle(220 + x, 290 + y, l);
    }
}
void sun()
{
    int l;
    for (l = 0; l <= 35; l++)
    {
        glColor3f(suncolors[0], suncolors[1], suncolors[2]);
        draw_circle(0, 450, l);
    }
}
void door(int x, int y)
{
    glColor3f(dcx, dcy, dcz);
    glBegin(GL_POLYGON);
    glVertex2i(-470 + x, 100 + y);
    glVertex2i(-440 + x, 100 + y);
    glVertex2i(-440 + x, 60 + y);
    glVertex2i(-470 + x, 60 + y);
    glEnd();
    //glFlush();
}

void grass()
{
    glColor3f(grasscolors[0], grasscolors[1], grasscolors[2]);
    glBegin(GL_POLYGON);
    glVertex2i(-500, 200);
    glVertex2i(500, 200);
    glVertex2i(500, -500);
    glVertex2i(-500, -500);
    glEnd();
}
void home(int x, int y)
{
    glColor3f(1.0, 0.6, 1.0);
    //roof
    glBegin(GL_POLYGON);
    glVertex2i(-450 + x, 300 + y);
    glVertex2i(-300 + x, 300 + y);
    glVertex2i(-250 + x, 200 + y);
    glVertex2i(-400 + x, 200 + y);
    glEnd();

    //triangle
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(-450 + x, 300 + y);
    glVertex2i(-500 + x, 200 + y);
    glVertex2i(-400 + x, 200 + y);
    glEnd();

    //below traingle
    glColor3f(0.5, 0.35, 0.05);
    glBegin(GL_POLYGON);
    glVertex2i(-500 + x, 200 + y);
    glVertex2i(-400 + x, 200 + y);
    glVertex2i(-400 + x, 50 + y);
    glVertex2i(-500 + x, 50 + y);
    glEnd();

    // Front Door
    glColor3f(0.8, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(-400 + x, 200 + y);
    glVertex2i(-250 + x, 200 + y);
    glVertex2i(-250 + x, 50 + y);
    glVertex2i(-400 + x, 50 + y);
    glEnd();

    // Front Door Lock
    door(x, y);

    //side Wall
    sidewall(x, y);

    // line of window one
    windowline(x, y);

}

void pond()
{
    glColor3f(pondcolors[0], pondcolors[1], pondcolors[2]);
    glBegin(GL_POLYGON);
    glVertex2i(-500, -500);
    glVertex2i(-500, 10);
    glVertex2i(-450, -10);
    glVertex2i(-350, -20);
    glVertex2i(-250, -30);
    glVertex2i(-100, -150);
    glVertex2i(-90, -200);
    glVertex2i(-50, -500);
    glEnd();
}

void dooropen(int x, int y)
{
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(-470 + x, 100 + y);
    glVertex2i(-493 + x, 95 + y);
    glVertex2i(-493 + x, 55 + y);
    glVertex2i(-470 + x, 60 + y);
    glEnd();

}
void fish(int x, int y, int fcx, int fcy, int fcz)
{
    glColor3f(fcx, fcy, fcz);
    glBegin(GL_TRIANGLES);
    glVertex2i(-350 + x + mx, -30 + y + my);
    glVertex2i(-360 + x + mx, -40 + y + my);
    glVertex2i(-360 + x + mx, -30 + y + my);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2i(-350 + x + mx, -30 + y + my);
    glVertex2i(-360 + x + mx, -40 + y + my);
    glVertex2i(-340 + x + mx, -60 + y + my);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2i(-345 + x + mx, -80 + y + my);
    glVertex2i(-340 + x + mx, -60 + y + my);
    glVertex2i(-325 + x + mx, -70 + y + my);
    glEnd();
}
void pole()
{
    int l = 0;
    glColor3f(0.5, 0.35, 0.05);
    glBegin(GL_POLYGON);
    glVertex2i(450.0, -150.0);
    glVertex2i(450.0, 250.0);
    glVertex2i(460.0, 250.0);
    glVertex2i(460.0, -150.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(300.0, 150.0);
    glVertex2i(450.0, 150.0);
    glVertex2i(450.0, 140.0);
    glVertex2i(300.0, 165.0);
    glEnd();
    for (l = 0; l <= 25; l++)
    {
        glColor3f(1.0, 1.0, 1.0);
        draw_circle(300, 140, l);
    }
}
void stars()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(-400, 400);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2i(-300, 450);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2i(-350, 300);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2i(20, 350);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2i(60, 430);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2i(400, 250);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2i(40, 220);
    glEnd();

}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    cloud();
    sun();
    grass();
    home(0, 0);
    home(750, -450);
    pond();
    tree(-50, 0);
    tree(150, 100);
    tree(-400, 100);
    if (nightflag != 1)
    {

        glPushMatrix();

        if (fishrot == 1)
        {

            glTranslatef(-300, -300, 0.0);
            glRotatef(180.0, 0.0, 0.0, 1.0);
            glTranslatef(300, 300, 0.0);
        }
        fish(-40, -300, 1.0, 1.0, 0.0);
        fish(-90, -100, 0.8, 0.5, 0.8);
        fish(-60, -450, 1.0, 0.8, 0.6);
        fish(20, -200, 0.5, 0.2, 1.0);
        fish(100, -200, 0.0, 0.0, 0.0);
        glPopMatrix();
    }
    if (nightflag == 1)
    {
        stars();
        pole();
    }
    if (dflag == 1)
    {
        dooropen(0, 0);
        dooropen(750, -450);
    }


    glFlush();
}

void idle()
{
    m += 1;

    if (m > 500)
        m = -500.0;
    display();
}
void select(int c)
{
    switch (c) {
    case 1:
        dflag = 1;
        if (lflag == 1) {
            dcx = 1.0;
            dcy = 1.0;
            dcz = 0.0;
        }
        else {
            dcx = 0.3;
            dcy = 0.5;
            dcz = 0.5;
        }
        glutPostRedisplay();
        break;
    case 2:
        lflag = 1;
        if (dflag == 1)
        {
            dcx = 1.0;
            dcy = 1.0;
            dcz = 0.0;
        }
        sx = 1.0;
        sy = 1.0;
        sz = 0.0;
        glutPostRedisplay();

    }
}
void keys(unsigned char key)
{
    if (key == 'x' || key == 'X')
    {
        if (mx < 110)
            mx += 5;

    }
    if (key == 'y' || key == 'Y')
    {
        if (my <= 100)
            my += 5;

    }
    if (key == 'r' || key == 'R')
        fishrot = 1;

    if (key == 'n' || key == 'N')
    {
        nightflag = 1;
        skycolors[0] = 0.0;
        skycolors[1] = 0.0;
        skycolors[2] = 0.0;
        suncolors[0] = 1.0;
        suncolors[1] = 1.0;
        suncolors[2] = 1.0;
        grasscolors[0] = 0.2;
        grasscolors[1] = 0.6;
        grasscolors[2] = 0.3;
        pondcolors[0] = 0;
        pondcolors[1] = 0;
        pondcolors[2] = 1;


    }
}
int main(int argc, char** argv)
{
    printf("---------------------------------------\n");
    printf("-----------1. Press x and y for movement of fishes-------------\n");
    printf("-----------2. Press r for rotation of fishes-----------\n");
    printf("-----------3. Press n for night mode----------------------\n");
    printf("-----------4. Right click to view menu-----------\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800.0, 700.0);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Simple Village Animation");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutCreateMenu(select);
    glutAddMenuEntry("Open Doors", 1);
    glutAddMenuEntry("Turn Lights ON", 2);
    glutKeyboardFunc(keys);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}