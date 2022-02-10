/**
 * @file character.cc
 */

#include "character.h"

FCharacter::FCharacter()
{
	// Do nothing.
};

FCharacter::FCharacter(FRand& Rng)
{
	Generate(Rng);
}

void FCharacter::Generate(FRand& Rng)
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

////////

TVector<FCharacter> Characters;

FId GenerateCharacter(FRand& Rng)
{
    Characters.push_back(FCharacter());
    auto& Character = Characters.back();
    Character.Generate(Rng);
    return Characters.size() - 1;
}
