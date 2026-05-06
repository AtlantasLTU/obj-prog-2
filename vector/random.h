#ifndef RANDOM_H
#define RANDOM_H
#include "studentas.h"
#include <random>

/**
 * @brief Generuoja studentų sąrašą su atsitiktiniais duomenimis.
 * @param pasirinkimas 2 – generuoti tik pažymius (vardai/pavardės įvedami ranka),
 *                      3 – generuoti viską.
 * @return Vektorius su sugeneruotais studentais.
 */
std::vector<Studentas> ivestiStudentusRandom(int pasirinkimas);

/**
 * @brief Grąžina statinį Mersenne Twister atsitiktinių skaičių generatorių.
 * @return Nuoroda į generatorių.
 */
std::mt19937& rng();

#endif