#include "b2_update.h"

#include <stdio.h>
#include <unistd.h>

#include "gfx.h"

void update() {

    usleep(10000);

    printf("b2 time_step(%f)\n", get_delta_time());
}

