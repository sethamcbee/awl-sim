/**
 * @file random.cc
 */

#include <cassert>
#include <cstdlib>

#include "log.h"
#include "random.h"

FRand GetRand(time(NULL));
const int RandMax = std::minstd_rand::max();

FRand::FRand(int S) : State(S)
{
	// Do nothing.
}

int FRand::operator()()
{
	return State();
}

int FRand::operator()(int Min, int Max)
{
	auto Range = Max - Min + 1;
	auto R = State();
	return R / (RandMax / Range + 1) + Min;
}

int FRand::Avg(int Min, int Max, int N)
{
	assert(N >= 0);
	assert(N < 11);

	auto& Self = *this;
	int Sum = Self(Min, Max);
	for (size_t I = 0; I < N; ++I)
	{
		Sum += Self(Min, Max);
	}
	return Sum / (N + 1);
}

bool FRand::Try(float Chance)
{
	const int SCALE = 1000000;
	auto& Self = *this;
	assert(SCALE < (int)State.max());

	int ScaledChance = (int)(Chance * (float)SCALE);
	int N = Self(0, SCALE);
	return N < ScaledChance;
}

