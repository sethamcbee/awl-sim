/**
 * @file lot.h
 */

#pragma once

#include "character.h"
#include "id.h"
#include "log.h"
#include "vector.h"

class FLot
{
public:

    // Default initialize with no occupants.
    FLot() {}

    // Initialize with seed.
    FLot(int S)
    {
        Generate(S);
    }

    void Generate(int S)
    {
        Log("Generating lot...");
        FRand Rng(S);

        auto& FCharacter = GenerateCharacter(Rng);
    }

    TVector<FId> Occupants;

private:
};

extern TVector<FLot> Lots;
