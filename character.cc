/**
 * @file character.cc
 */

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

#if 0
void FCharacter::Generate(FRand& Rng)
{
	Log("\tGenerating character...");

	// Assign gender.
	Gender = Rng(0, 1);

	// Pick random name.
	if (Gender == GENDER_MALE)
	{
		Log("\t\tGender: Male");
		Name = GenerateMaleName(Rng);
	}
	else
	{
		Log("\t\tGender: Female");
		Name = GenerateFemaleName(Rng);
	}
	Log("\t\tName: " + Names[Name]);

	// Pick age.
	AgeTicks = YearsToTicks(AdultAgeYears);
	auto AgeYears = TicksToYears(AgeTicks);
	Log("\t\tAge: " + std::to_string(AgeYears) + " years");

	// Pick birthday.
	Birthday = RandBirthday(Rng);
	Log("\t\tBirthday: " + BirthdayToString(Birthday));
}
#endif

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

	if (Params.AgeTicks.has_value())
	{
		AgeTicks = Params.AgeTicks.value();
	}
	else
	{
		AgeTicks = Rng(0, DeathAgeTicks - 1);
	}
	Log("\t\tAge: " + AgeToString(AgeTicks));

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

FId GenerateMaleName(FRand& Rng)
{
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
	auto NameInd = Rng(0, FemaleNames.size() - 1);
	auto NameIt = FemaleNames.begin();
	std::advance(NameIt, NameInd);
	auto TmpName = *NameIt;
	FemaleNames.erase(NameIt);
	auto NameId = Names.size();
	Names.push_back(TmpName);
	return NameId;
}

FString AgeToString(int AgeTicks)
{
	int Years = TicksToYears(AgeTicks);
	int LeftoverTicks = AgeTicks - Years * YearLengthTicks;
	int LeftoverDays = TicksToDays(LeftoverTicks);
	FString AgeString = std::to_string(Years) + " years and ";
	AgeString += std::to_string(LeftoverDays) + " days ";

	// Get stage in life.
	FString Stage = "(Baby)";
	if (AgeTicks >= ToddlerAgeTicks)
	{
		Stage = "(Toddler)";
	}
	if (AgeTicks >= ChildAgeTicks)
	{
		Stage = "(Child)";
	}
	if (AgeTicks >= TeenAgeTicks)
	{
		Stage = "(Teen)";
	}
	if (AgeTicks >= AdultAgeTicks)
	{
		Stage = "(Adult)";
	}
	if (AgeTicks >= SeniorAgeTicks)
	{
		Stage = "(Senior)";
	}

	return AgeString + Stage;
}
