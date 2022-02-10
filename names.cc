/**
 * @file names.cc
 */

#include <fstream>

#include "names.h"

TVector<FString> Names;
TSet<FString> MaleNames;
TSet<FString> FemaleNames;

void LoadNames()
{
    std::ifstream MaleFile("data/male_names.txt");
    FString TmpName;
    while (MaleFile >> TmpName)
    {
        MaleNames.insert(TmpName);
    }

    std::ifstream FemaleFile("data/female_names.txt");
    while (FemaleFile >> TmpName)
    {
        FemaleNames.insert(TmpName);
    }
}
