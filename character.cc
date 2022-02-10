/**
 * @file character.cc
 */

#include "character.h"

TVector<FCharacter> Characters;

FCharacter& GenerateCharacter(FRand& Rng)
{
    Characters.push_back(FCharacter());
    auto& Character = Characters.back();
    Character.Generate(Rng());
    return Character;
}
