/**
 * @file log.h
 */

#pragma once

#include <fstream>
#include <iostream>

#include "string.h"

void LogImpl(const FString& l);

#ifndef NDEBUG
#define Log(x) LogImpl((x))
#endif

#ifdef NDEBUG
#define Log(x) (void)((x));
#endif
