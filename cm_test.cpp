#include <unistd.h>
#include <stdio.h>

#include "cm_update.h"
#include "gfx.h"
#include "world.h"

int tThen = 0;

int main(int argc, char * argv[]) {

    init_world();

    cm_init();

    init_gfx(argc, argv, "Chipmunk Test");

    init_callbacks();

    run_gfx();

    return 0;
}

