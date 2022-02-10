/**
 * @file character.cc
 */

#include "character.h"

TVector<FCharacter> Characters;

FId GenerateCharacter(FRand& Rng)
{
    Characters.push_back(FCharacter());
    auto& Character = Characters.back();
    Character.Generate(Rng);
    return Characters.size() - 1;
}
