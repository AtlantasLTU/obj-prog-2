#include "studentas.h"
#include "ivestis.h"
#include "random.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <utility>

void Studentas::addNd(int paz)
{
    nd.push_back(paz);
}

void Studentas::resizeNd(int n, int skaicius)
{
    nd.resize(n, skaicius);
};

double Studentas::galutinis(bool medianos, int ndKiekis) const
{
    const int max = (ndKiekis != 0) ? ndKiekis : maxNdKiekis;
    if(nd.empty()) return 0.6*rez;
    if(medianos)
    {
        std::vector<int> ND = nd;
        if(ND.size() < max) ND.resize(max, 0);
        std::sort(ND.begin(), ND.end());
        const int vidurys = max / 2;
        std::nth_element(ND.begin(), ND.begin() + vidurys, ND.end());
        double med;
        for(int X : ND){
            std::cout << X << std::endl;
        }
        if(max % 2 == 0)
        {
            med = (*std::max_element(ND.begin(), ND.begin() + vidurys) + ND[vidurys]) / 2.0;
        }
        else
        {
            med = ND[vidurys];
        }
        return 0.4 * med + 0.6 * rez;
    }
    else
    {
        int sum = std::accumulate(nd.begin(), nd.end(), 0);

        double vid = (double)sum / max;
        return 0.4 * vid + 0.6 * rez;
    }
}

std::istream& Studentas::readStudentStream(std::istream& is, int ndKiekis)
{
    if(!(is >> vardas >> pavarde)) return is;
    int paz;
    if(ndKiekis == 0)
    {
        std::vector<int> skaiciai;
        while(is >> paz)
        {
            skaiciai.push_back(paz);
        }
        if(skaiciai.empty()){
            throw std::runtime_error("Klaida: įvesty nerasta nei namų darbų, nei egzamino pažymių");
        }
        rez = skaiciai.back();
        skaiciai.pop_back();
        nd = skaiciai;
    }
    else
    {
        nd.clear();
        nd.reserve(ndKiekis);
        for(int i = 0; i < ndKiekis; i++)
        {
            if(!(is >> paz)) throw std::runtime_error("Klaida: netinkami pažymiai faile.");
                nd.push_back(paz);
        }
        if(!(is >> rez)) throw std::runtime_error("Klaida: netinkamas egzamino rezultatas faile.");
    }
    return is;
}

std::istream& Studentas::readStudentConsole(std::istream& is){
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
        is.setstate(std::ios::failbit);
        return is;
    }
    while(!studentoVardoPavardesIvestis(eilute))
    {
        std::cout << "Įveskite studento vardą bei pavardę (ENTER - baigti): ";
        if(!std::getline(std::cin, eilute) || eilute.empty()) return is;
    }
    namuDarbuRezultatuIvestis();
    egzaminoRezultatoIvestis();
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

    vardas = vardai[dist(rng())];
    // paskutinis simbolis 's' = vyras
    pavarde = (*vardas.rbegin() == 's') ? pavardes_v[dist(rng())] : pavardes_m[dist(rng())];
}

void Studentas::ndRandom(int ndKiekis)
{
    std::uniform_int_distribution<int> dist(1, 10);
    for (int i = 0; i < ndKiekis; i++)
        nd.push_back(dist(rng()));
}

void Studentas::egzRandom()
{
    std::uniform_int_distribution<int> dist(1, 10);
    rez = dist(rng());
}

Studentas::~Studentas()
{
    nd.clear();
    rez = 0;
}

Studentas::Studentas(const Studentas& kitas)
    : Zmogus(kitas),
    nd(kitas.nd),
    rez(kitas.rez)
{}

Studentas& Studentas::operator=(const Studentas& kitas)
{
    if(this != &kitas)
    {
        Zmogus::operator=(kitas);
        nd = kitas.nd;
        rez = kitas.rez;
    }
    return *this;
}

Studentas::Studentas(Studentas&& kitas) noexcept
    : Zmogus(std::move(kitas)),
    nd(std::move(kitas.nd)),
    rez(std::exchange(kitas.rez, 0))
{}

Studentas& Studentas::operator=(Studentas&& kitas) noexcept
{
    if(this != &kitas){
        Zmogus::operator=(std::move(kitas));
        nd = std::move(kitas.nd);
        rez = std::exchange(kitas.rez, 0);
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Studentas &A)
{
    A.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& out, const Studentas &A){
    out << A.getVardas() << " " << A.getPavarde() << " ";
    for(int X : A.getNd()) out << X << " ";
    out << A.getRez();
    return out; 
}

void Studentas::read(std::istream& is, int ndKiekis){
    if(&is == &std::cin)
    {
        readStudentConsole(is);
    }
    else
    {
        readStudentStream(is, ndKiekis);
    }
}