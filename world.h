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
const int LOTS_OCCUPIED = 10;

class FWorld
{
public:

    FWorld() : WorldSeed(GetRand()), WorldRand(WorldSeed) {}

    FWorld(int S) : WorldSeed(S), WorldRand(WorldSeed) {}

    void Generate()
    {
        Log("Beginning world generation...");
        Lots.resize(LOT_COUNT);

        // Fill random lots.
        Log("Beginning lot generation...");
        for (size_t I = LOTS_OCCUPIED; I > 0; --I)
        {
            auto LotId = WorldRand(0, LOT_COUNT-1);
            auto& Lot = Lots[LotId];

            // Check if lot is occupied already.
            if (Lot.Occupants.size() == 0)
            {
                Lot.Generate(WorldRand);
            }
            else
            {
                // Lot occupied; pick another lot.
                Log("Lot already occupied, picking again.");
                ++I;
            }
        }
    }

private:

    int WorldSeed;
    FRand WorldRand;
};
