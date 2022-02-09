/**
 * @file names.h
 */

#pragma once

#include "id.h"
#include "set.h"
#include "string.h"
#include "vector.h"

namespace AWL
{

extern Vector<String> Names;
extern Set<String> MaleNames;
extern Set<String> FemaleNames;

void LoadNames();
    
}
