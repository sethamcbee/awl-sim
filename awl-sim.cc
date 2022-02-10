/**
 * @file awl-sim.cc
 */

#include <iostream>

#include "names.h"
#include "random.h"
#include "world.h"

int main(int argc, char* argv[])
{
    LoadNames();

    FWorld World;
    World.Generate();

    return 0;
}
