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

    for (int I = 0; I < YearLengthDays * 10; ++I)
    {
		World.SimulateDay();
		if (I % YearLengthDays == 0)
		{
			Log("==========");
		}
	}

	Log("All-time population: " + std::to_string(AllTimePopulation));

    return 0;
}
