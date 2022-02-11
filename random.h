/**
 * @file random.h
 */

#pragma once

#include <random>

extern const int RandMax;

// std::minstd_rand wrapper
class FRand
{
public:

    FRand(int S);

    int operator()();

    int operator()(int Min, int Max);

	// Generate number whose probability of being near the middle
	// of the range increases as N increases.
    int Avg(int Min, int Max, int N);

    bool Try(float Chance);

private:

    std::minstd_rand State;
};

// General purpose rand for when results do not need to be preserved
// per seed. State is global.
extern FRand GetRand;
