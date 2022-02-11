/**
 * @file random.cc
 */

#include <cassert>
#include <cstdlib>

#include "random.h"

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
	return State() % Range + Min;
}

int FRand::Avg(int Min, int Max, int N)
{
	assert(N >= 0);

	auto& Self = *this;
	int Sum = Self(Min, Max);
	for (size_t I = 0; I < N; ++I)
	{
		Sum += Self(Min, Max);
	}
	return Sum / (N + 1);
}

FRand GetRand(time(NULL));
