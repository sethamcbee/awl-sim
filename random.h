/**
 * @file random.h
 */

#pragma once

#include <random>

// std::minstd_rand wrapper
class FRand
{
public:

    FRand(int S);

    int operator()();

    int operator()(int Min, int Max);

private:

    std::minstd_rand State;
};

// General purpose rand for when results do not need to be preserved
// per seed. State is global.
extern FRand GetRand;
