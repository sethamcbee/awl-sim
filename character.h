/**
 * @file character.h
 */

#pragma once

#include "id.h"
#include "log.h"
#include "names.h"
#include "string.h"
#include "vector.h"

namespace AWL
{

const int GENDER_MALE = 0;
const int GENDER_FEMALE = 1;

class Character
{
public:

    Character() {}

    Character(int S)
    {
        Generate(S);
    }

    void Generate(int S)
    {
        Log("\tGenerating character...");
        Rand Rng(S);

        // Assign gender.
        Gender = RandRange(Rng, 0, 1);

        // Pick random name.
        Set<String>* NameSet;
        if (Gender == GENDER_MALE)
        {
            Log("\t\tGender: Male");
            NameSet = &MaleNames;
        }
        else
        {
            Log("\t\tGender: Female");
            NameSet = &FemaleNames;
        }
        auto NameIt = NameSet->begin();
        auto NameInd = RandRange(Rng, 0, NameSet->size());
        std::advance(NameIt, NameInd);
        auto TmpName = *NameIt;
        Log("\t\tName: " + TmpName);
        NameSet->erase(NameIt);
        Name = Names.size();
        Names.push_back(TmpName);
    }

private:

    int Gender;
    Id Name;
};

Vector<Character> Characters;

}
