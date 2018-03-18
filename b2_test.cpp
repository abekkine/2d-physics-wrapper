#include <unistd.h>
#include <stdio.h>

#include "b2_update.h"
#include "gfx.h"
#include "world.h"

int tThen = 0;

int main(int argc, char * argv[]) {

    init_world();

    b2_init();

    init_gfx(argc, argv, "Box2D Test");

    init_callbacks();

    run_gfx();

    return 0;
}

