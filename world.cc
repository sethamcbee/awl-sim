/**
 * @file world.cc
 */

#include "world.h"

void FWorld::Generate()
{
	Log("Beginning world generation...");
	Lots.resize(LOT_COUNT);

	// Fill random lots.
	Log("Beginning lot generation...");
	for (size_t I = LOTS_OCCUPIED; I > 0; --I)
	{
		auto LotId = WorldRand(0, LOT_COUNT-1);
		auto& Lot = Lots[LotId];

		// Check if lot is occupied already.
		if (Lot.Occupants.size() == 0)
		{
			Lot.Generate(WorldRand);
		}
		else
		{
			// Lot occupied; pick another lot.
			Log("Lot already occupied, picking again.");
			++I;
		}
	}
}
