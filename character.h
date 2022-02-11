/**
 * @file character.h
 */

#pragma once

#include "date.h"
#include "id.h"
#include "log.h"
#include "names.h"
#include "optional.h"
#include "random.h"
#include "string.h"
#include "vector.h"

const int GENDER_MALE = 0;
const int GENDER_FEMALE = 1;
const int HOME_HOMELESS = 0;

class FCharacterParams
{
public:

	TOptional<int> Gender;
	TOptional<FId> Name;
	TOptional<FId> Home;
	TOptional<int> AgeYears;
	TOptional<int> Birthday;
};

extern FCharacterParams DefaultCharacterParams;

class FCharacter
{
public:

    FCharacter();

    FCharacter(FRand& Rng);

	void Generate(FRand& Rng, const FCharacterParams& Params = DefaultCharacterParams);

    int Gender;
    FId Name;
    FId Home = HOME_HOMELESS;
    int AgeYears;
    int Birthday;
};

extern TVector<FCharacter> Characters;

FId GenerateCharacter(
	FRand& Rng,
	const FCharacterParams& Params = DefaultCharacterParams);
FId GenerateSpouse(FRand& Rng, FId CharacterId);
FId GenerateAdult(FRand& Rng);
FId GenerateOffspring(FRand& Rng, FId Parent0Id, FId Parent1Id);

// Helpers.
FId GenerateMaleName(FRand& Rng);
FId GenerateFemaleName(FRand& Rng);
FString AgeToString(int AgeYears);
