/**
 * @file world.h
 */

#pragma once

#include <vector>

#include "id.h"
#include "log.h"
#include "lot.h"
#include "random.h"

namespace AWL
{

const int LOT_COUNT = 30;
const int LOTS_OCCUPIED = 10;

class World
{
public:

    World() : WorldSeed(GetRand()), WorldRand(WorldSeed) {}

    World(int S) : WorldSeed(S), WorldRand(WorldSeed) {}

    void Generate()
    {
        Log("Beginning world generation...");
        Lots.resize(LOT_COUNT);

        // Fill random lots with singles.
        Log("Beginning lot generation...");
        for (size_t i = LOTS_OCCUPIED; i > 0; --i)
        {
            auto LotId = RandRange(WorldRand, 0, LOT_COUNT-1);
            auto& Lot = Lots[LotId];

            // Check if lot is occupied already.
            if (Lot.Occupants.size() == 0)
            {
                Lot.Generate(WorldRand());
            }
            else
            {
                // Lot occupied; pick another lot.
                Log("Lot already occupied, picking again.");
                ++i;
            }
        }
    }

private:

    int WorldSeed;
    Rand WorldRand;
};

}
