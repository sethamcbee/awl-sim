/**
 * @file log.cc
 */

#include "log.h"

void LogImpl(const FString& l)
{
    static std::ofstream LogFile("run/log.txt");
    LogFile << l << std::endl;
}
