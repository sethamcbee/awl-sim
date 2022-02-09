/**
 * @file awl-sim.cc
 */

#include <iostream>

#include "names.h"
#include "random.h"
#include "world.h"

using namespace AWL;

int main(int argc, char* argv[])
{
    // Load name list.
    LoadNames();
    
    // Generate world.
    World world;
    world.Generate();
    
    return 0;
}
