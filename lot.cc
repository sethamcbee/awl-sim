/**
 * @file lot.cc
 */

#include "lot.h"
#include "world.h"

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

	bool bDone = false;
	while (!bDone)
	{
		bDone = true;

		if (Rng.Try(0.3))
		{
			// Generate single.
			Log("Generating single person.");
			auto CharacterId = GenerateAdult(Rng);
			Occupants.push_back(CharacterId);
			AllTimePopulation += 1;
		}
		else if (Rng.Try(0.35))
		{
			// Generate couple.
			Log("Generating couple.");
			auto CharacterId0 = GenerateAdult(Rng);
			Occupants.push_back(CharacterId0);
			auto CharacterId1 = GenerateSpouse(Rng, CharacterId0);
			Occupants.push_back(CharacterId1);
			AllTimePopulation += 2;
		}
		else if (Rng.Try(0.35))
		{
			// Generate family.
			Log("Generating family.");
			auto CharacterId0 = GenerateAdult(Rng);
			Occupants.push_back(CharacterId0);
			auto CharacterId1 = GenerateSpouse(Rng, CharacterId0);
			Occupants.push_back(CharacterId1);
			auto CharacterId2 = GenerateOffspring(Rng, CharacterId0, CharacterId1);
			Occupants.push_back(CharacterId2);
			AllTimePopulation += 3;
		}
		else
		{
			bDone = false;
		}
	}
}

TVector<FLot> Lots;
