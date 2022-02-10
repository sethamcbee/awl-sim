/**
 * @file names.h
 */

#pragma once

#include "id.h"
#include "set.h"
#include "string.h"
#include "vector.h"

extern TVector<FString> Names;
extern TSet<FString> MaleNames;
extern TSet<FString> FemaleNames;

void LoadNames();
