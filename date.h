/**
 * @file date.h
 */

#pragma once

#include "random.h"
#include "string.h"

// Time and date rates.
extern int HourLengthMinutes;
extern int DayLengthHours;
extern int SeasonLengthDays;
extern int YearLengthSeasons;

extern int MinuteLengthTicks;
extern int HourLengthTicks;
extern int DayLengthTicks;
extern int SeasonLengthTicks;
extern int YearLengthTicks;

extern int YearLengthDays;

// Aging.
extern int BabyLengthYears;
extern int ToddlerLengthYears;
extern int ChildLengthYears;
extern int TeenLengthYears;
extern int YoungAdultLengthYears;
extern int AdultLengthYears;
extern int SeniorLengthYears;

extern int BabyAgeYears;
extern int ToddlerAgeYears;
extern int ChildAgeYears;
extern int TeenAgeYears;
extern int YoungAdultAgeYears;
extern int AdultAgeYears;
extern int SeniorAgeYears;
extern int DeathAgeYears;

// Time and date conversions.
int TicksToMinutes(int Ticks);
int TicksToHours(int Ticks);
int TicksToDays(int Ticks);
int TicksToSeasons(int Ticks);
int TicksToYears(int Ticks);

int MinutesToTicks(int Minutes);
int HoursToTicks(int Hours);
int DaysToTicks(int Days);
int SeasonsToTicks(int Seasons);
int YearsToTicks(int Years);

int YearsToDays(int Years);

// Character generation.
int RandBabyAge(FRand& Rng);
int RandToddlerAge(FRand& Rng);
int RandChildAge(FRand& Rng);
int RandTeenAge(FRand& Rng);
int RandYoungAdultAge(FRand& Rng);
int RandAdultAge(FRand& Rng);
int RandSeniorAge(FRand& Rng);

int RandBirthday(FRand& Rng);
FString BirthdayToString(int Birthday);
