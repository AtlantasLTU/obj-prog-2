#ifndef RANDOM_H
#define RANDOM_H
#include "studentas.h"
#include <random>

std::vector<Studentas> ivestiStudentusRandom(int pasirinkimas);

std::mt19937& rng();

#endif