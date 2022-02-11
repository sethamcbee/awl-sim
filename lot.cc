/**
 * @file lot.cc
 */

#include "lot.h"

FLot::FLot()
{
	// Do nothing.
}

FLot::FLot(FRand& Rng)
{
	Generate(Rng);
}

void FLot::Generate(FRand& Rng)
{
	Log("Generating lot...");

	auto LotPopulationType = Rng(0, 2);
	if (LotPopulationType == 0)
	{
		// Generate single.
		Log("Generating single person.");
		auto CharacterId = GenerateAdult(Rng);
		Occupants.push_back(CharacterId);
	}
	else if (LotPopulationType == 1)
	{
		// Generate couple.
		Log("Generating couple.");
		auto CharacterId0 = GenerateAdult(Rng);
		Occupants.push_back(CharacterId0);
		auto CharacterId1 = GenerateSpouse(Rng, CharacterId0);
		Occupants.push_back(CharacterId1);
	}
	else if (LotPopulationType == 2)
	{
		// Generate family.
		Log("Generating family.");
		auto CharacterId0 = GenerateAdult(Rng);
		Occupants.push_back(CharacterId0);
		auto CharacterId1 = GenerateSpouse(Rng, CharacterId0);
		Occupants.push_back(CharacterId1);
		auto CharacterId2 = GenerateOffspring(Rng, CharacterId0, CharacterId1);
		Occupants.push_back(CharacterId2);
	}
}

TVector<FLot> Lots;
