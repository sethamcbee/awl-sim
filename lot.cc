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
		auto CharacterId = GenerateCharacter(Rng);
		Occupants.push_back(CharacterId);
	}
	else if (LotPopulationType == 1)
	{
		// Generate couple.
		auto CharacterId0 = GenerateCharacter(Rng);
		Occupants.push_back(CharacterId0);
		auto CharacterId1 = GenerateCharacter(Rng);
		Occupants.push_back(CharacterId1);
	}
	else if (LotPopulationType == 2)
	{
		// STUB.
		auto CharacterId = GenerateCharacter(Rng);
		Occupants.push_back(CharacterId);
	}
}

TVector<FLot> Lots;
