#include "calc.h"
#include <algorithm>
#include <numeric>
#include <iostream>

double galutinisVid(const Studentas &A){
    if(A.getNd().empty()) return 0.6*A.getRez();

    int sum = std::accumulate(A.getNd().begin(), A.getNd().end(), 0);

    double vid = (double)sum / maxNdKiekis;
    return 0.4 * vid + 0.6 * A.getRez();
}


double galutinisMed(/* const  */Studentas &A){ // uzkomentuotas kodas toks pat kaip ir F sitos funkcijos versijoje, kuri aprasyta zemiau
    if(A.getNd().empty()) return 0.6*A.getRez();

    /* std::vector<int> nd = A.nd; */
    A.resizeNd(maxNdKiekis, 0);
    std::sort(A.getNd().begin(), A.getNd().end());

    double med =
        (maxNdKiekis % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (A.getNd().at(maxNdKiekis/2) + A.getNd().at(maxNdKiekis/2 - 1)) / 2.0
        : A.getNd().at(maxNdKiekis/2);

    return 0.4 * med + 0.6 * A.getRez();
}

double galutinisVidF(Studentas &A, int ndKiekis){ // perduodam ndKieki, jis naudojamas kaip maxNDKiekis, tik cia jis gautas is failo.
    if(A.getNd().empty()) return 0.6*A.getRez();

    int sum = std::accumulate(A.getNd().begin(), A.getNd().end(), 0);
    
    double vid = (double)sum / ndKiekis;
    return 0.4 * vid + 0.6 * A.getRez();
}


double galutinisMedF(/* const atkomentuoti, jei griztam prie nd vektoriaus kopijavimo */Studentas &A, int ndKiekis){
    if(A.getNd().empty()) return 0.6*A.getRez();
    //geriau kopijuot, bet kadangi veliau nenaudosim A.nd vektoriaus niekur, tai kopija nebutina
    /* std::vector<int> nd = A.nd;
    while(nd.size() < maxNdKiekis){
        nd.push_back(0);
    } */
    A.resizeNd(ndKiekis, 0);
    std::sort(A.getNd().begin(), A.getNd().end());

    double med =
        (ndKiekis % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
        ? (A.getNd().at(ndKiekis/2) + A.getNd().at(ndKiekis/2 - 1)) / 2.0
        : A.getNd().at(ndKiekis/2);

    return 0.4 * med + 0.6 * A.getRez();
}