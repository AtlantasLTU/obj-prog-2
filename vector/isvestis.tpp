#include "isvestis.h"

/**
 * @brief Išveda studentų sąrašą į failą arba ekraną.
 * @tparam Konteineris (list, vector, deque).
 * @param A Studentų konteineris.
 * @param medianos Ar naudoti medianą galutiniam pažymiui.
 * @param failas Jei true – išvesti į failą "rezultatai.txt", kitu atveju – į std::cout.
 * @param failoPavadinimas Išvesties failo pavadinimas (numatyta "rezultatai.txt").
 * @param ndKiekis Namų darbų skaičius.
 */
template<class Konteineris>
void isvestis(Konteineris &A, bool medianos, bool failas, const std::string &failoPavadinimas = "rezultatai.txt", int ndKiekis = 0)
{
    std::string out;

    setw("Vardas", 20, out);
    setw("Pavardė", 21, out);
    out += "Galutinis (Vid.) / Galutinis (Med.)\n";
    out += std::string(75, '-') + "\n";
    for(const Studentas &X : A)
    {
        int vardoPlotis = 20 + lietuviskosRaides(X.getVardas());
        int pavardesPlotis = 20 + lietuviskosRaides(X.getPavarde());
        
        setw(X.getVardas(), vardoPlotis, out);
        setw(X.getPavarde(), pavardesPlotis, out);
        if (medianos)
        {
            setw("x.xx", 19, out);
            out += std::format("{:.2f}", X.galutinis(medianos, ndKiekis));
            out += '\n';
        }
        else
        {
            setw(std::format("{:.2f}", X.galutinis(medianos, ndKiekis)), 19, out);
            out += "y.yy\n";
        }
    }
    if(failas){
        std::ofstream fout(failoPavadinimas);
        fout << out;
        fout.close();
    } else {
        std::cout << out;
    }
}