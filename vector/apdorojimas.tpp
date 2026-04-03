#include "apdorojimas.h"
#include "studVPGen.h"
#include "random.h"
#include <fstream>
#include <list>

/* template<class Konteineris>
void skaiciavimas(Konteineris &A, bool medianos, int ndKiekis){

    auto funkcija = medianos ? galutinisMedF : galutinisVidF;

    for(Studentas &X : A)
        X.setGalutinis(funkcija(X, ndKiekis));
} */

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
            return didejanciai ? lambdaFunkcija(A) < lambdaFunkcija(B) : lambdaFunkcija(A) > lambdaFunkcija(B); // lambdaFunkcija(A) prilygsta kad i funkcija [](const Studentas &studentas){return studentas.vardas;} perduotas studentas A ir na, tas pats su B
        }
        );
    }
    
}

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

/* template<class Konteineris> // jeigu neisrusiuotas konteineris pries tai
void skirstymasStrat2(Konteineris &studentai, Konteineris &vargsiukai){
    for(auto it = studentai.begin(); it != studentai.end();)
    {
        if(it->galutinis < 5)
        {
            vargsiukai.push_back(std::move(*it));
            it = studentai.erase(it);
        }
        else
        {
            ++it;
        }
    }
} */

template<class Konteineris> // jeigu isrusiuotas konteineris pries tai
void skirstymasStrat2(Konteineris &studentai, Konteineris &vargsiukai, bool medianos, int ndKiekis = 0){
    auto it = std::lower_bound(studentai.begin(), studentai.end(), 5, [medianos, ndKiekis](const Studentas &A, int skaic)
        {
            return A.galutinis(medianos, ndKiekis) < skaic;
        }
    );
    vargsiukai.insert(vargsiukai.end(), std::make_move_iterator(studentai.begin()), std::make_move_iterator(it));
    studentai.erase(studentai.begin(), it);
}

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