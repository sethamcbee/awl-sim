/**
 * @file world.cc
 */

#include "world.h"

int AllTimePopulation = 0;

FId RandLot(FRand& Rng)
{
	return Rng(0, LOT_COUNT - 1);
}

FId RandFreeLot(FRand& Rng)
{
	auto LotId = RandLot(Rng);
	while (Lots[LotId].Occupants.size() != 0)
	{
		LotId = RandLot(Rng);
	}
	return LotId;
}

FId RandOccupiedLot(FRand& Rng)
{
	auto LotId = RandLot(Rng);
	while (Lots[LotId].Occupants.size() == 0)
	{
		LotId = RandLot(Rng);
	}
	return LotId;
}

int CountOccupiedLots()
{
	int LotCount = 0;
	for (size_t I = 0; I < LOT_COUNT; ++I)
	{
		if (Lots[I].Occupants.size() > 0)
		{
			++LotCount;
		}
	}
	return LotCount;
}

int CountWorldOccupants()
{
	int Occupants = 0;
	for (const auto& Lot : Lots)
	{
		Occupants += Lot.Occupants.size();
	}
	return Occupants;
}

void LogWorldPopulation()
{
	int Occupants = 0;
	int Singles = 0;
	int Couples = 0;
	int Families = 0;
	int Adults = 0;
	int Kids = 0;
	for (const auto& Lot : Lots)
	{
		auto LotPop = Lot.Occupants.size();
		Occupants += LotPop;
		if (LotPop == 1)
		{
			++Singles;
			++Adults;
		}
		else if (LotPop == 2)
		{
			++Couples;
			Adults += 2;
		}
		else if (LotPop == 3)
		{
			++Families;
			Adults += 2;
			++Kids;
		}
	}
	Log("Population: " + std::to_string(Occupants));
	Log("Singles: " + std::to_string(Singles));
	Log("Couples: " + std::to_string(Couples));
	Log("Famlilies: " + std::to_string(Families));
	Log("Adults: " + std::to_string(Adults));
	Log("Kids: " + std::to_string(Kids));
}

void FWorld::Generate()
{
	Log("Beginning world generation...");
	Lots.resize(LOT_COUNT);

	// Fill random lots.
	Log("Beginning lot generation...");
	for (size_t I = LOTS_OCCUPIED; I > 0; --I)
	{
		auto LotId = RandLot(WorldRand);
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

	Log("Done generating world.");
	LogWorldPopulation();
}

void FWorld::SimulateDay()
{
	static int Day = 0;
	++Day;
	auto DayString = std::to_string(Day);

	const float WorldEventChance{0.05};
	const float MoveOutChance{0.5};
	const float MoveInChance{MoveOutChance * 1.5};

	if (WorldRand.Try(WorldEventChance))
	{
		if (WorldRand.Try(MoveInChance))
		{
			if (CountOccupiedLots() < LOT_COUNT)
			{
				Log("Day " + DayString + ": Someone moved in.");
				auto LotId = RandFreeLot(WorldRand);
				auto& Lot = Lots[LotId];
				Lot.Generate(WorldRand);
				LogWorldPopulation();
			}
		}
		else if (WorldRand.Try(MoveOutChance))
		{
			if (CountOccupiedLots() > 0)
			{
				Log("Day " + DayString + ": Someone moved out.");
				auto LotId = RandOccupiedLot(WorldRand);
				auto& Lot = Lots[LotId];
				Lot.Occupants.clear();
				LogWorldPopulation();
			}
		}
	}
}
