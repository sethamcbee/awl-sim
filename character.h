/**
 * @file character.h
 */

#pragma once

#include "date.h"
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

    FCharacter(FRand& Rng)
    {
        Generate(Rng);
    }

    void Generate(FRand& Rng)
    {
        Log("\tGenerating character...");

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
        auto NameInd = Rng(0, NameSet->size() - 1);
        auto NameIt = NameSet->begin();
        std::advance(NameIt, NameInd);
        auto TmpName = *NameIt;
        Log("\t\tName: " + TmpName);
        NameSet->erase(NameIt);
        Name = Names.size();
        Names.push_back(TmpName);

        // Pick age.
        AgeYears = YoungAdultAgeYears;

        // Pick birthday.
        Birthday = RandBirthday(Rng);
        Log("\t\tBirthday: " + BirthdayToString(Birthday));
    }

private:

    int Gender;
    FId Name;
    FId Home;
    int AgeYears;
    int Birthday;
};

extern TVector<FCharacter> Characters;

FId GenerateCharacter(FRand& Rng);
FId GenerateSpouse(FRand& Rng, const FCharacter&);
