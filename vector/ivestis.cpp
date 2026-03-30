#include "ivestis.h"

bool gautiPatvirtinima(const std::string &pranesimas)
{
    std::string ivestis;
    while (true) {
        std::cout << pranesimas << " (y/n): ";
        
        if (!std::getline(std::cin, ivestis)) {
            cinEOFgaudymas();
            continue;
        }

        ivestis.erase(0, ivestis.find_first_not_of(" \t")); // randa pirma simboli kuris nera tarpas arba tabuliacija, tada trina nuo 0-inio indekso iki rasto simbolio.
        ivestis.erase(ivestis.find_last_not_of(" \t") + 1); // randa pirma simboli kuris nera tarpas arba tabuliacija nuo galo ir istrina viska po to

        // ivesties ilgio patikrinimas ir konvertavimas
        if (ivestis.length() == 1) {
            // ivesti vercia i mazaja | to lower tikisi unsigned char arba EOF pagal standarta, static_cast keicia char interpretavima i unsigned char.
            if (std::tolower(static_cast<unsigned char>(ivestis[0])) == 'y') return true;
            if (std::tolower(static_cast<unsigned char>(ivestis[0])) == 'n') return false;
        }

        // jei ivestis neteisinga, t.y. nieko nebuvo returninta, tai prompt'ina vartotoja vel ivesti y ar n!
        std::cout << "Neteisinga įvestis! Prašome įvesti tik 'y' arba 'n'.\n";
    }
}

std::vector<Studentas> ivestiStudentus()
{
    std::vector<Studentas> studentai;
    while(true)
    {
        Studentas A(std::cin);
        if(!std::cin) break;
        studentai.push_back(std::move(A));
    }
    return studentai;
}

/* bool skaitymas(Studentas &A)
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
    while(!studentoVardoPavardesIvestis(A, eilute))
    {
        std::cout << "Įveskite studento vardą bei pavardę (ENTER - baigti): ";
        if(!std::getline(std::cin, eilute) || eilute.empty()) return false;
    }
    namuDarbuRezultatuIvestis(A);
    egzaminoRezultatoIvestis(A);
    return true;
}

bool studentoVardoPavardesIvestis(Studentas &A, const std::string& eilute)
{
    std::istringstream iss(eilute);
    std::string vardas, pavarde;
    // įvestį skaidome į du žodžius
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
    // Jei viskas gerai — saugom
    A.setVardas(vardas);
    A.setPavarde(pavarde);
    return true;
}

void namuDarbuRezultatuIvestis(Studentas &A)
{
    std::cout << "Įveskite " << maxNdKiekis << " namų darbų rezultatų." << std::endl;
    auto &nd = A.getNd();
    while (nd.size()<maxNdKiekis)
    {
        int balas = gautiSkaiciu("Įveskite namų darbų rezultatą nuo 1 iki 10 (ENTER - baigti): ", 1, 10, true);
        if (balas == -1) break; 
        A.addNd(balas);
    }

    if(nd.size()==maxNdKiekis)
    {
        std::cout << "Įvestas didžiausias namų darbų rezultatų kiekis" << std::endl;
    }
}

void egzaminoRezultatoIvestis(Studentas &A)
{
    int balas = gautiSkaiciu("Įveskite egzamino rezultatą (1-10): ", 1, 10);
    A.setRez(balas);
} */

int gautiSkaiciu(const std::string &pranešimas, int min, int max, bool galiButiTuscia /* = false */)
{
    std::string ivestis;
    while (true) {
        std::cout << pranešimas;

        if (!std::getline(std::cin, ivestis)) {
            if (std::cin.eof()) 
                cinEOFgaudymas();
            continue;
        }

        // ivesties nutraukimas su ENTER
        if (galiButiTuscia && ivestis.empty()) return -1;

        try {
            // 
            if (!arTikSkaicius(ivestis)) throw std::invalid_argument("Ne skaičius");

            int skaicius = std::stoi(ivestis);

            //tikriname ar ivestas skaicius atitinka nuo maziausio leistino iki didziausio leistino
            if (skaicius >= min && skaicius <= max) {
                return skaicius;
            } else {
                std::cout << "Klaida, skaičius turi būti tarp " << min << " ir " << max << "!\n";
            }
        } catch (...) {
            std::cout << "Klaida, įveskite sveikąjį skaičių!\n";
        }
    }
}

bool arTikSkaicius(const std::string& eilute)
{ // jei eilute tuscia grazinama false, std::all_of pereina nuo eilutes.begin() pradzios iki galo eilutes.end() per kiekviena simboli, kiekvienam simboliui jei jis skaicius ar tarpas grazina true, jei tai tiesiog raide - grazinama false ir toliau eilute nebetikrinama
    return !eilute.empty() && 
    std::all_of(eilute.begin(), eilute.end(), [](unsigned char simbolis) 
    {
        return std::isdigit(simbolis) || std::isspace(simbolis);
    });
}

void cinEOFgaudymas()
{
    if (std::cin.eof())
    { // apsauga nuo CTRL+D (linux), CTRL+Z (windows)
        throw std::runtime_error("Įvesties pabaiga (EOF). Darbas su programa baigtas");
    }
    std::cin.clear(); // atstatome std::cin fail flag'a
}