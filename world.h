/**
 * @file world.h
 */

#pragma once

#include <vector>

#include "id.h"
#include "log.h"
#include "lot.h"
#include "random.h"

const int LOT_COUNT = 30;
const int LOTS_OCCUPIED = 15;

class FWorld
{
public:

    FWorld() : WorldSeed(GetRand()), WorldRand(WorldSeed) {}

    FWorld(int S) : WorldSeed(S), WorldRand(WorldSeed) {}

	void Generate();

	void SimulateDay();

private:

    int WorldSeed;
    FRand WorldRand;
};

extern int AllTimePopulation;
