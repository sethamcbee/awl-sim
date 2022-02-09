/**
 * @file random.h
 */

#pragma once

#include <cstdlib>
#include <random>

namespace AWL
{

// std::minstd_rand wrapper
class Rand
{
public:

    Rand(int S) : State(S) {}

    auto operator()()
    {
        return State();
    }

private:

    std::minstd_rand State;
};

// General purpose rand for when results do not need to be preserved
// per seed. State is global.
Rand GetRand(time(NULL));

class RandRange
{
public:

    RandRange(int S, int MinP, int MaxP) : State(S)
    {
        Range = MaxP - MinP + 1;
    }

    auto operator()()
    {
        return State() % Range + Min;
    }

private:

    Rand State;
    int Min;
    int Range;
};

auto GetRandRange(int Min, int Max)
{
    auto Range = Max - Min + 1;
    return GetRand() % Range + Min;
}

}
