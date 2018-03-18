#include "b2_update.h"

#include <stdio.h>
#include <unistd.h>

#include "gfx.h"
#include "world.h"

void update() {

    double time_step = get_delta_time();

    p->angle -= 30.0 * time_step;

    usleep(10000);
}

