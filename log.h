/**
 * @file log.h
 */

#pragma once

#include <fstream>
#include <iostream>

#include "string.h"

namespace AWL
{

void LogImpl(const String& l)
{
    static std::ofstream LogFile("run/log.txt");
    LogFile << l << std::endl;
}

#ifndef NDEBUG
#define Log(x) LogImpl((x))
#endif

#ifdef NDEBUG
#define Log(x) (void)((x));
#endif

}
