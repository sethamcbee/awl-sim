/**
 * @file random.h
 */

#pragma once

#include <random>

// std::minstd_rand wrapper
class FRand
{
public:

    FRand(int S) : State(S) {}

    auto operator()()
    {
        return State();
    }

    auto operator()(int Min, int Max)
    {
        auto Range = Max - Min + 1;
        return State() % Range + Min;
    }

private:

    std::minstd_rand State;
};

// General purpose rand for when results do not need to be preserved
// per seed. State is global.
extern FRand GetRand;

static inline auto GetRandRange(int Min, int Max)
{
    auto Range = Max - Min + 1;
    return GetRand() % Range + Min;
}
