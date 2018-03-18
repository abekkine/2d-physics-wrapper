#ifndef WORLD_H_
#define WORLD_H_

#include <math.h>

struct Point {
    Point() {}
    Point(double xv, double yv) : x(xv), y(yv) {}
    double x, y;
};

struct Ground {
    Ground(double size);
    float color[3];
    Point c;
    double angle;
    Point p1, p2;
};

struct Pentagon {
    Pentagon(double size);
    float color[3];
    Point c;
    double angle;
    Point p[5];
};
 
void init_world();
void render_world();

extern Pentagon *p;
extern Ground *g;

#endif // WORLD_H_

