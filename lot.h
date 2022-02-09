/**
 * @file lot.h
 */

#pragma once

#include "character.h"
#include "id.h"
#include "log.h"
#include "vector.h"

namespace AWL
{

class Lot
{
public:

    // Default initialize with no occupants.
    Lot() {}

    // Initialize with seed.
    Lot(int S)
    {
        Generate(S);
    }

    void Generate(int S)
    {
        Log("Generating lot...");
        Rand Rng(S);

        // Generate one character.
        Characters.push_back(Character());
        auto& Character = Characters.back();
        Character.Generate(Rng());
    }
    
    Vector<Id> Occupants;

private:
};

Vector<Lot> Lots;

}
