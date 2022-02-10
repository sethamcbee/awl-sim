/**
 * @file random.cc
 */

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

FRand GetRand(time(NULL));
