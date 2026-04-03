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
    std::cin.clear();
    return studentai;
}

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