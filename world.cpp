#include "world.h"

#include <GL/glut.h>

Ground::Ground(double size)
: color{1.0, 1.0, 1.0}
, c(Point(0.0, 0.0))
, angle(0.0)
{
    double tilt = 5.0 * M_PI / 180.0;
    p1.x = 0.5 * size * cos(tilt);
    p1.y = 0.5 * size * sin(tilt);
    p2.x = -0.5 * size * cos(tilt); 
    p2.y = -0.5 * size * sin(tilt); 
}

Pentagon::Pentagon(double size)
: color{1.0, 0.0, 0.0}
, c(Point(0.0, 0.0))
, angle(0.0)
, mass(10.0)
{
    for (int i=0; i<5; ++i) {
        p[i].x = size * cos(0.4 * (double)i * M_PI);
        p[i].y = size * sin(0.4 * (double)i * M_PI);
    }
}

Pentagon *p;
Ground *g;

void init_world() {

    p = new Pentagon(10.0);
    g = new Ground(200.0);
    g->c.y -= 80.0;
}

void render_world() {

    glPushMatrix();

    // Ground
    glLoadIdentity();
    glTranslated(g->c.x, g->c.y, 0.0);
    glRotated(g->angle, 0.0, 0.0, 1.0);

    glColor3fv(g->color);

    glBegin(GL_LINES);
        glVertex2d(g->p1.x, g->p1.y);
        glVertex2d(g->p2.x, g->p2.y);
    glEnd();
 
    // Pentagon  
    glLoadIdentity();
    glTranslated(p->c.x, p->c.y, 0.0);
    glRotated(p->angle, 0.0, 0.0, 1.0);

    glColor3fv(p->color);

    glBegin(GL_LINE_LOOP);
    for(int i=0; i<5; ++i) {
        glVertex2d(p->p[i].x, p->p[i].y);
    }
    glEnd();

    glPopMatrix();
}


