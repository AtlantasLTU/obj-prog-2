#ifndef APDOROJIMAS_H
#define APDOROJIMAS_H

#include <algorithm>
#include <format>
#include "studentas.h"
#include "random.h"
#include <fstream>
#include <list>

/**
 * @brief Generuoja failą su studentų duomenimis.
 * @param studentuKiekis Kiek studentų generuoti.
 * @param ndKiekis Kiek namų darbų rezultatų generuoti kiekvienam studentui.
 */
void failoGeneravimas(int studentuKiekis, int ndKiekis);

/**
 * @brief Prideda tekstą prie išvesties eilutės, sulygiuodama jį nurodytu pločiu.
 * @param tekstas Tekstas
 * @param plotis Minimalus eilutės plotis.
 * @param out Nuoroda į išvesties eilutę.
 */
void setw(const std::string &tekstas, int plotis, std::string& out);

#endif