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
    FLot();

    // Initialize with seed.
    FLot(FRand& Rng);

    void Generate(FRand& Rng);

    TVector<FId> Occupants;

private:
};

extern TVector<FLot> Lots;
