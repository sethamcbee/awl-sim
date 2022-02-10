/**
 * @file character.h
 */

#pragma once

#include "id.h"
#include "log.h"
#include "names.h"
#include "random.h"
#include "string.h"
#include "vector.h"

const int GENDER_MALE = 0;
const int GENDER_FEMALE = 1;

class FCharacter
{
public:

    FCharacter() {}

    FCharacter(int S)
    {
        Generate(S);
    }

    void Generate(int S)
    {
        Log("\tGenerating character...");
        FRand Rng(S);

        // Assign gender.
        Gender = Rng(0, 1);

        // Pick random name.
        TSet<FString>* NameSet;
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
        auto NameInd = Rng(0, NameSet->size());
        std::advance(NameIt, NameInd);
        auto TmpName = *NameIt;
        Log("\t\tName: " + TmpName);
        NameSet->erase(NameIt);
        Name = Names.size();
        Names.push_back(TmpName);
    }

private:

    int Gender;
    FId Name;
    FId Home;
};

extern TVector<FCharacter> Characters;

FCharacter& GenerateCharacter(FRand& Rng);
