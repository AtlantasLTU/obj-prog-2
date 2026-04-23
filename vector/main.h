#ifndef MAIN_H
#define MAIN_H

//Header file includes
#include "ivestis.h"
#include "isvestis.h"
#include "apdorojimas.h"
#include "random.h"
#include "Timer.h"
#include "test.h"
#include "main.tpp"
#include <deque>
#include <list>

#ifdef _WIN32 // naudojame preprocesorių, kad kompiliatorius, naudojant Windows, pridėtų windows.h antraščių failą, kad vėliau galėtume pakeistį terminalo išvesties ir įvesties užkodavimą į UTF-8
#include <windows.h> // windows antraščių failas
#endif

void failoApdorojimas(const std::string &failoPavadinimas, int rezervas, int &ndKiekis, bool medianos, int rPasirinkimas, bool failas);

#endif