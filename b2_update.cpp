#include "b2_update.h"

#include <stdio.h>
#include <unistd.h>

#include <Box2D/Box2D.h>

#include "gfx.h"
#include "world.h"

void update() {

    double time_step = get_delta_time();

    b2_update(time_step);
    // p->angle -= 30.0 * time_step;

    usleep(10000);
}

b2World * world;
b2Body * pentagon_body;

void b2_init() {

    b2Vec2 gravity(0.0f, -10.0f);
    world = new b2World(gravity);

    // Add Ground
    // : definition
    b2BodyDef ground_def;
    ground_def.type = b2_kinematicBody;
    ground_def.position.Set(g->c.x, g->c.y);
    // : body
    b2Body * ground_body = world->CreateBody(&ground_def);
    // : shape
    b2EdgeShape ground_shape;
    ground_shape.Set(b2Vec2(g->p1.x, g->p1.y), b2Vec2(g->p2.x, g->p2.y));
    // : fixture
    b2FixtureDef ground_fixture;
    ground_fixture.shape = &ground_shape;
    ground_fixture.density = 1.0;
    ground_fixture.friction = 0.7;
    ground_body->CreateFixture(&ground_fixture);    

    // Add Pentagon
    // : definition
    b2BodyDef pentagon_def;
    pentagon_def.type = b2_dynamicBody;
    pentagon_def.position.Set(p->c.x, p->c.y);
    pentagon_def.angle = p->angle;
    // : body
    pentagon_body = world->CreateBody(&pentagon_def);
    // : shape
    b2Vec2 p_verts[5];
    for (int i=0; i<5; ++i) {
        p_verts[i].Set(p->p[i].x, p->p[i].y);
    }
    b2PolygonShape pentagon_shape;
    pentagon_shape.Set(p_verts, 5);
    // : fixture
    b2FixtureDef pentagon_fixture;
    pentagon_fixture.shape = &pentagon_shape;
    pentagon_fixture.density = 1.0;
    pentagon_fixture.friction = 0.7;
    pentagon_body->CreateFixture(&pentagon_fixture);
}

void b2_update(double time_step) {

    world->Step(time_step, 6, 2);

    b2Vec2 pos = pentagon_body->GetPosition();
    double angle = pentagon_body->GetAngle();

    p->c.x = pos.x;
    p->c.y = pos.y;
    p->angle = angle * 180.0 / M_PI;
}

