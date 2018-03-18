#include "cm_update.h"

#include <stdio.h>
#include <unistd.h>

#include "gfx.h"

void update() {

    usleep(10000);

    printf("cm time_step(%f)\n", get_delta_time());
}


