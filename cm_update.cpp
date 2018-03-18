#include "cm_update.h"

#include <stdio.h>
#include <unistd.h>

#include <chipmunk/chipmunk.h>

#include "gfx.h"
#include "world.h"

void update() {

    double time_step = get_delta_time();

    cm_update(time_step);
    // p->angle += 30.0 * time_step;

    usleep(10000);
}

cpSpace * world;
cpBody * pentagon_body;

void cm_init() {

    world = cpSpaceNew();
    cpSpaceSetGravity(world, cpv(0.0, -10.0));

    // Add Ground
    // : body
    cpBody * ground_body = cpSpaceAddBody(world, cpBodyNewKinematic());
    cpBodySetPosition(ground_body, cpv(g->c.x, g->c.y));
    // : shape
    cpShape * ground_shape = cpSpaceAddShape(world, cpSegmentShapeNew(ground_body, cpv(g->p1.x, g->p1.y), cpv(g->p2.x, g->p2.y), 0.0));
    cpShapeSetElasticity(ground_shape, 1.0);
    cpShapeSetFriction(ground_shape, 1.0);
   
    // Add Pentagon
    // : body
    cpVect p_verts[5];
    for (int i=0; i<5; ++i) {
        p_verts[i].x = p->p[i].x;
        p_verts[i].y = p->p[i].y;
    }
    pentagon_body = cpSpaceAddBody(world, cpBodyNew(p->mass, cpMomentForPoly(p->mass, 5, p_verts, cpvzero, 0.0)));
    cpBodySetPosition(pentagon_body, cpv(p->c.x, p->c.y));
    cpBodySetAngle(pentagon_body, p->angle);
    // : shape
    cpShape * pentagon_shape = cpSpaceAddShape(world, cpPolyShapeNew(pentagon_body, 5, p_verts, cpTransformIdentity, 0.0));
    cpShapeSetElasticity(pentagon_shape, 0.5);
    cpShapeSetFriction(pentagon_shape, 0.7);
}

void cm_update(double time_step) {

    cpSpaceStep(world, time_step);

    cpVect pos = cpBodyGetPosition(pentagon_body);
    double angle = cpBodyGetAngle(pentagon_body);

    p->c.x = pos.x;
    p->c.y = pos.y;
    p->angle = angle * 180.0 / M_PI;
}

