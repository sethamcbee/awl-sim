/**
 * @file names.cc
 */

#include <fstream>

#include "names.h"

namespace AWL
{

Vector<String> Names;
Set<String> MaleNames;
Set<String> FemaleNames;

void LoadNames()
{
    std::ifstream MFile("data/male_names.txt");
    String TmpName;
    while (MFile >> TmpName)
    {
        MaleNames.insert(TmpName);
    }

    std::ifstream FFile("data/female_names.txt");
    while (FFile >> TmpName)
    {
        FemaleNames.insert(TmpName);
    }
}

}
