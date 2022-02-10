/**
 * @file awl-sim.cc
 */

#include <filesystem>
#include <iostream>

#include "names.h"
#include "random.h"
#include "world.h"

int main(int argc, char* argv[])
{
    std::filesystem::create_directory("run");

    LoadNames();

    FWorld World;
    World.Generate();

    return 0;
}
