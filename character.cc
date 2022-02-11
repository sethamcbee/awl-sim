/**
 * @file character.cc
 */

#include <cassert>

#include "character.h"

FCharacterParams DefaultCharacterParams;
TVector<FCharacter> Characters;

FCharacter::FCharacter()
{
	// Do nothing.
};

FCharacter::FCharacter(FRand& Rng)
{
	Generate(Rng);
}

void FCharacter::Generate(FRand& Rng, const FCharacterParams& Params)
{
	Log("\tGenerating character...");

	if (Params.Gender.has_value())
	{
		Gender = Params.Gender.value();
	}
	else
	{
		Gender = Rng(0, 1);
	}

	if (Params.Name.has_value())
	{
		Name = Params.Name.value();
	}
	else
	{
		// Generate name.
		if (Gender == GENDER_MALE)
		{
			Name = GenerateMaleName(Rng);
		}
		else
		{
			Name = GenerateFemaleName(Rng);
		}
	}

	if (Gender == GENDER_MALE)
	{
		Log("\t\tGender: Male");
	}
	else
	{
		Log("\t\tGender: Female");
	}
	Log("\t\tName: " + Names[Name]);

	if (Params.AgeYears.has_value())
	{
		AgeYears = Params.AgeYears.value();
	}
	else
	{
		AgeYears = Rng(0, DeathAgeYears - 1);
	}
	Log("\t\tAge: " + AgeToString(AgeYears));

	Birthday = RandBirthday(Rng);
	Log("\t\tBirthday: " + BirthdayToString(Birthday));
}

FId GenerateCharacter(FRand& Rng, const FCharacterParams& Params)
{
	Characters.push_back(FCharacter());
	auto& Character = Characters.back();
	Character.Generate(Rng, Params);
	return Characters.size() - 1;
}

FId GenerateSpouse(FRand& Rng, FId CharacterId)
{
	// Later we'll check compatibility.
	const auto& Character = Characters[CharacterId];
	auto Age = Character.AgeYears;

	assert(Age >= AdultAgeYears);

	auto DiffRangeYears = 6;
	auto DiffPrecision = 3;
	auto Min = Age - DiffRangeYears;
	auto Max = Age + DiffRangeYears;
	if (Max > DeathAgeYears - 1)
	{
		Max = DeathAgeYears - 1;
	}
	auto SpouseAge = Rng.Avg(Min, Max, DiffPrecision);
	if (SpouseAge < AdultAgeYears)
	{
		SpouseAge = AdultAgeYears;
	}

	FCharacterParams Params;
	Params.AgeYears = SpouseAge;

	// Determine whether couple is gay.
	if (Rng.Try(0.2))
	{
		Params.Gender = Character.Gender;
	}
	else
	{
		// Straight.
		Params.Gender = !Character.Gender;
	}

	return GenerateCharacter(Rng, Params);
}

FId GenerateAdult(FRand& Rng)
{
	FCharacterParams Params;
	Params.AgeYears = RandAdultAge(Rng);
	return GenerateCharacter(Rng, Params);
}

FId GenerateOffspring(FRand& Rng, FId Parent0Id, FId Parent1Id)
{
	// Get age of younger parent.
	const auto& Parent0 = Characters[Parent0Id];
	const auto& Parent1 = Characters[Parent1Id];
	auto ParentAge = Parent0.AgeYears;
	if (Parent1.AgeYears < ParentAge)
	{
		ParentAge = Parent1.AgeYears;
	}

	assert(ParentAge >= AdultAgeYears);

	// Later, we'll inherit traits. For now, we just ensure the age
	// of the offspring is logical.
	auto Min = BabyAgeYears;
	auto Max = ParentAge - AdultAgeYears;
	FCharacterParams Params;
	Params.AgeYears = Rng.Avg(Min, Max, 2);
	return GenerateCharacter(Rng, Params);
}

FId GenerateMaleName(FRand& Rng)
{
	assert(MaleNames.size() != 0);

	auto NameInd = Rng(0, MaleNames.size() - 1);
	auto NameIt = MaleNames.begin();
	std::advance(NameIt, NameInd);
	auto TmpName = *NameIt;
	MaleNames.erase(NameIt);
	auto NameId = Names.size();
	Names.push_back(TmpName);
	return NameId;
}

FId GenerateFemaleName(FRand& Rng)
{
	assert(FemaleNames.size() != 0);

	auto NameInd = Rng(0, FemaleNames.size() - 1);
	auto NameIt = FemaleNames.begin();
	std::advance(NameIt, NameInd);
	auto TmpName = *NameIt;
	FemaleNames.erase(NameIt);
	auto NameId = Names.size();
	Names.push_back(TmpName);
	return NameId;
}

FString AgeToString(int AgeYears)
{
	FString AgeString = std::to_string(AgeYears) + " years old ";

	// Get stage in life.
	FString Stage = "(Baby)";
	if (AgeYears >= ToddlerAgeYears)
	{
		Stage = "(Toddler)";
	}
	if (AgeYears >= ChildAgeYears)
	{
		Stage = "(Child)";
	}
	if (AgeYears >= TeenAgeYears)
	{
		Stage = "(Teen)";
	}
	if (AgeYears >= AdultAgeYears)
	{
		Stage = "(Adult)";
	}
	if (AgeYears >= SeniorAgeYears)
	{
		Stage = "(Senior)";
	}

	return AgeString + Stage;
}
