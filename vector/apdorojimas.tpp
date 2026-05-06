#include "apdorojimas.h"

/**
 * @brief Rūšiuoja konteinerio studentus pagal nurodytą lambda funkciją.
 * @tparam T lambda funkcijos tipas.
 * @tparam Konteineris (list, vector, deque).
 * @param studentai Studentų konteineris.
 * @param lambdaFunkcija Funkcija, grąžinanti rūšiavimo būdą.
 * @param didejanciai Jei true – rūšiuoti didėjančiai, kitu atveju – mažėjančiai.
 */
template<class T, class Konteineris>
void rusiavimasPagal(Konteineris &studentai, T lambdaFunkcija, bool didejanciai = true)
{
    if constexpr(std::is_same_v<Konteineris, std::list<Studentas>>){
        if(didejanciai){
            studentai.sort([lambdaFunkcija](const Studentas &A, const Studentas &B){
                return lambdaFunkcija(A) < lambdaFunkcija(B);
            });
        } else {
            studentai.sort([lambdaFunkcija](const Studentas &A, const Studentas &B){
                return lambdaFunkcija(A) > lambdaFunkcija(B);
            });
        }
    } else {
        std::sort(studentai.begin(), studentai.end(),
        [didejanciai, lambdaFunkcija](const Studentas &A, const Studentas &B)
        {
            return didejanciai ? lambdaFunkcija(A) < lambdaFunkcija(B) : lambdaFunkcija(A) > lambdaFunkcija(B);
        }
        );
    }
}

/**
 * @brief Rūšiuoja studentus pagal vartotojo pasirinkimą (vardą, pavardę, galutinį pažymį).
 * @tparam Konteineris (list, vector, deque).
 * @param studentai Studentų konteineris.
 * @param rPasirinkimas Rūšiavimo būdas (1-6).
 * @param medianos Ar naudoti medianą galutiniam pažymiui.
 * @param ndKiekis Namų darbų kiekis (jei žinomas).
 */
template<class Konteineris>
void rusiavimasSkirstymas(Konteineris &studentai, int rPasirinkimas, bool medianos, int ndKiekis = 0){
    switch(rPasirinkimas){
        case 1: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.getVardas();}); break;
        case 2: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.getVardas();}, false); break;
        case 3: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.getPavarde();}); break;
        case 4: rusiavimasPagal(studentai, [](const Studentas &studentas){return studentas.getPavarde();}, false); break;
        case 5: rusiavimasPagal(studentai, [medianos, ndKiekis](const Studentas &studentas){return studentas.galutinis(medianos, ndKiekis);}); break;
        case 6: rusiavimasPagal(studentai, [medianos, ndKiekis](const Studentas &studentas){return studentas.galutinis(medianos, ndKiekis);}, false); break;
        default:
        {
            break;
        }
    }
}

/**
 * @brief Skirsto studentus į "galvočius" (≥5) ir "vargšiukus" (<5) naudojant judinimą (move).
 * @tparam Konteineris (list, vector, deque).
 * @param studentai Studentų konteineris (ištuštinamas).
 * @param galvociai Konteineris studentams, kurių galutinis >=5.
 * @param vargsiukai Konteineris studentams, kurių galutinis <5.
 * @param medianos Ar naudoti medianą galutiniam pažymiui.
 * @param ndKiekis Namų darbų skaičius.
 */
template<class Konteineris>
void skirstymas(Konteineris &studentai, Konteineris &galvociai, Konteineris &vargsiukai, bool medianos, int ndKiekis = 0)
{
    for(Studentas &A : studentai)
    {
        if(A.galutinis(medianos, ndKiekis)<5){
            vargsiukai.push_back(std::move(A));
        } else {
            galvociai.push_back(std::move(A));
        }
    }
    studentai.clear();
    if constexpr(!(std::is_same_v<Konteineris, std::list<Studentas>>)){
        vargsiukai.shrink_to_fit();
        galvociai.shrink_to_fit();
    }
}

/**
 * @brief 1 strategija: skirstymas be perkėlimo (kopijavimas).
 * @tparam Konteineris (list, vector, deque).
 * @param studentai Studentų konteineris (ištuštinamas).
 * @param galvociai Konteineris studentams, kurių galutinis >=5.
 * @param vargsiukai Konteineris studentams, kurių galutinis <5.
 * @param medianos Ar naudoti medianą galutiniam pažymiui.
 * @param ndKiekis Namų darbų skaičius.
 */
template<class Konteineris>
void skirstymasStrat1(Konteineris &studentai, Konteineris &galvociai, Konteineris &vargsiukai, bool medianos, int ndKiekis = 0)
{
    for(Studentas &A : studentai)
    {
        if(A.galutinis(medianos, ndKiekis)<5){
            vargsiukai.push_back(A);
        } else {
            galvociai.push_back(A);
        }
    }
    studentai.clear();
    if constexpr(!(std::is_same_v<Konteineris, std::list<Studentas>>)){
        vargsiukai.shrink_to_fit();
        galvociai.shrink_to_fit();
    }
}

/**
 * @brief 2 strategija: naudoja std::lower_bound, kai konteineris jau surūšiuotas.
 * @tparam Konteineris (list, vector, deque).
 * @param studentai Surūšiuotas studentų konteineris (išsaugomi "galvočiai", kurių galutinis >=5).
 * @param vargsiukai Konteineris studentams, kurių galutinis <5.
 * @param medianos Ar naudoti medianą galutiniam pažymiui.
 * @param ndKiekis Namų darbų skaičius.
 */
template<class Konteineris>
void skirstymasStrat2(Konteineris &studentai, Konteineris &vargsiukai, bool medianos, int ndKiekis = 0){
    auto it = std::lower_bound(studentai.begin(), studentai.end(), 5, [medianos, ndKiekis](const Studentas &A, int skaic)
        {
            return A.galutinis(medianos, ndKiekis) < skaic;
        }
    );
    vargsiukai.insert(vargsiukai.end(), std::make_move_iterator(studentai.begin()), std::make_move_iterator(it));
    studentai.erase(studentai.begin(), it);
}

/**
 * @brief 3 strategija: naudoja std::partition.
 * @tparam Konteineris (list, vector, deque).
 * @param studentai Surūšiuotas studentų konteineris (išsaugomi "galvočiai", kurių galutinis >=5).
 * @param vargsiukai Konteineris studentams, kurių galutinis <5.
 * @param medianos Ar naudoti medianą galutiniam pažymiui.
 * @param ndKiekis Namų darbų skaičius.
 */
template<class Konteineris>
void skirstymasStrat3(Konteineris &studentai, Konteineris &vargsiukai, bool medianos, int ndKiekis = 0){
    auto it = std::partition(studentai.begin(), studentai.end(),
        [medianos, ndKiekis](const Studentas& A){
            return A.galutinis(medianos, ndKiekis) >= 5;
        }
    );
    vargsiukai.insert(vargsiukai.end(), std::make_move_iterator(it), std::make_move_iterator(studentai.end()));
    studentai.erase(it, studentai.end());
}