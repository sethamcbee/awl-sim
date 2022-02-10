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

    FCharacter();

    FCharacter(FRand& Rng);

	void Generate(FRand& Rng);

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
