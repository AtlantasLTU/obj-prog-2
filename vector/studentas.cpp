#include "studentas.h"
#include "ivestis.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>

void Studentas::addNd(int paz)
{
    nd.push_back(paz);
}

void Studentas::resizeNd(int n, int skaicius)
{
    if(nd.size() < n)
        nd.resize(n, skaicius);
};

double Studentas::galutinis(bool medianos, int ndKiekis) const
{
    int max;
    if(ndKiekis != 0)
    {
        max = ndKiekis;
    }
    else
    {
        max = maxNdKiekis;
    }
    if(medianos)
    {
        if(nd.empty()) return 0.6*rez;

        std::vector<int> ND = nd;
        ND.resize(max, 0);
        std::sort(ND.begin(), ND.end());

        double med =
            (max % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
            ? (ND.at(max/2) + ND.at(max/2 - 1)) / 2.0
            : ND.at(max/2);

        return 0.4 * med + 0.6 * rez;
    }
    else
    {
        if(nd.empty()) return 0.6*rez;

        int sum = std::accumulate(nd.begin(), nd.end(), 0);

        double vid = (double)sum / max;
        return 0.4 * vid + 0.6 * rez;
    }
}

std::istream& Studentas::readStudent(std::istream& is, int ndKiekis)
{
    if(&is != &std::cin)
    {
        if(!(is >> vardas >> pavarde)) return is;
        int paz;
        for(int i = 0; i < ndKiekis; i++)
        {
            if(!(is >> paz)) throw std::runtime_error("Klaida: netinkami pažymiai faile.");
                nd.push_back(paz);
        }
        if(!(is >> rez)) throw std::runtime_error("Klaida: netinkamas egzamino rezultatas faile.");
    }
    else
    {
        std::string eilute;
        std::cout << "Įveskite studento vardą bei pavardę (ENTER - nutraukti įvedimą): ";

            // perskaito eilute ir jei perskaitymas nesekmingas, tai ziuri ar std::cin.eof, jei taip, tai programa uzbaigiama, jei ne, tai isvalo ivesties stream'o veliaveles ir vel prasoma ivesti
        if (!std::getline(std::cin, eilute))
        {
            cinEOFgaudymas();
            return is;
        } // jei enter - iseina
        if(eilute.empty())
        {
            return is;
        }
        while(!studentoVardoPavardesIvestis(eilute))
        {
            std::cout << "Įveskite studento vardą bei pavardę (ENTER - baigti): ";
            if(!std::getline(std::cin, eilute) || eilute.empty()) return is;
        }
        namuDarbuRezultatuIvestis();
        egzaminoRezultatoIvestis();
    }
    return is;
}

bool Studentas::studentoVardoPavardesIvestis(const std::string& eilute)
{
    std::istringstream iss(eilute);
    if (!(iss >> vardas >> pavarde))
    {
        std::cout << "Įveskite vardą ir pavardę (du žodžiai)!\n";
        return false;
    }
    // tikriname ar po vardo ir pavardės yra dar žodžių
    std::string ekstra;
    if (iss >> ekstra)
    {
        std::cout << "Įvesta per daug žodžių — reikia tik vardo ir pavardės!\n";
        return false;
    }
    return true;
}

void Studentas::namuDarbuRezultatuIvestis()
{
    std::cout << "Įveskite " << maxNdKiekis << " namų darbų rezultatų." << std::endl;
    while (nd.size()<maxNdKiekis)
    {
        int balas = gautiSkaiciu("Įveskite namų darbų rezultatą nuo 1 iki 10 (ENTER - baigti): ", 1, 10, true);
        if (balas == -1) break; 
        nd.push_back(balas);
    }

    if(nd.size()==maxNdKiekis)
    {
        std::cout << "Įvestas didžiausias namų darbų rezultatų kiekis" << std::endl;
    }
}

void Studentas::egzaminoRezultatoIvestis()
{
    rez = gautiSkaiciu("Įveskite egzamino rezultatą (1-10): ", 1, 10);
}

bool Studentas::readSemiRandom()
{
    std::string eilute;
    std::cout << "Įveskite studento vardą bei pavardę (ENTER - nutraukti įvedimą): ";

        // perskaito eilute ir jei perskaitymas nesekmingas, tai ziuri ar std::cin.eof, jei taip, tai programa uzbaigiama, jei ne, tai isvalo ivesties stream'o veliaveles ir vel prasoma ivesti
    if (!std::getline(std::cin, eilute))
    {
        cinEOFgaudymas();
        return false;
    } // jei enter - iseina
    if(eilute.empty())
    {
        return false;
    }
    while(!studentoVardoPavardesIvestis(eilute))
    {
        std::cout << "Įveskite studento vardą bei pavardę (ENTER - baigti): ";
        if(!std::getline(std::cin, eilute) || eilute.empty()) return false;
    }
    ndRandom(gautiSkaiciu("Įveskite norimą generuoti namų darbų rezultatų kiekį: ", 0, 100));
    egzRandom();
    return true;
}

void Studentas::readRandom(int ndKiekis)
{
    genVardaPavarde();
    ndRandom(ndKiekis);
    egzRandom();
}

void Studentas::genVardaPavarde()
{
    static std::mt19937 mt(static_cast<long unsigned int>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(0, 9);

    static const std::vector<std::string> vardai = {
        "Irma","Alma","Irena","Egle","Jolanta",
        "Petras","Jonas","Ignas","Darius","Simas"
    };
    static const std::vector<std::string> pavardes_m = {
        "Pavardaite1","Pavardaite2","Pavardaite3","Pavardaite4","Pavardaite5",
        "Pavardaite6","Pavardaite7","Pavardaite8","Pavardaite9","Pavardaite10"
    };
    static const std::vector<std::string> pavardes_v = {
        "Pavardenis1","Pavardenis2","Pavardenis3","Pavardenis4","Pavardenis5",
        "Pavardenis6","Pavardenis7","Pavardenis8","Pavardenis9","Pavardenis10"
    };

    vardas = vardai[dist(mt)];
    // paskutinis simbolis 's' = vyras
    pavarde = (*vardas.rbegin() == 's') ? pavardes_v[dist(mt)] : pavardes_m[dist(mt)];
}

void Studentas::ndRandom(int ndKiekis)
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 10);
    for (int i = 0; i < ndKiekis; i++)
        nd.push_back(dist(rng));
}

void Studentas::egzRandom()
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 10);
    rez = dist(rng);
}