#include "apdorojimas.h"
#include "studVPGen.h"
#include "random.h"
#include <fstream>

void skaiciavimas(std::vector<Studentas> &A, bool medianos, int ndKiekis){
    if(medianos)
    {
        for(Studentas &X : A){
            X.setGalutinis(galutinisMedF(X, ndKiekis));
        }
    }
    else
    {
        for(Studentas &X : A){
            X.setGalutinis(galutinisVidF(X, ndKiekis));
        }
    }
}

void skaiciavimas(std::vector<Studentas> &A, bool medianos){
    if(medianos)
    {
        for(Studentas &X : A){
            X.setGalutinis(galutinisMed(X));
        }
    }
    else
    {
        for(Studentas &X : A){
            X.setGalutinis(galutinisVid(X));
        }
    }
}

void failoGeneravimas(int studentuKiekis, int ndKiekis)
{
    std::string out;
    out.reserve(studentuKiekis*100/* 46+(ndKiekis*10)+studentuKiekis*(43+ndKiekis*10) */);
    setw("Vardas", 20, out);
    setw("Pavardė", 21, out);
    for(int i = 1; i <= ndKiekis; i++){
        setw(std::format("ND{}", i), 10, out);
    }
    out += "Egz.\n";
    for(int i = 0; i < studentuKiekis; i++){
        Studentas A;
        gen_map(A);
        namuDarbuRezultataiRandom(A, ndKiekis);
        egzaminoRezultatasRandom(A);
        setw(A.getVardas(), 20, out);
        setw(A.getPavarde(), 20, out);
        for(int j = 0; j < ndKiekis; j++){
            setw(std::to_string(A.getNd().at(j)), 10, out);
        }
        out += std::to_string(A.getRez())+"\n";
    }
    std::string failoPavadinimas = std::string("studentai") + std::to_string(studentuKiekis) + ".txt";
    std::ofstream fout(failoPavadinimas);
    fout << out;
    fout.close();
}

void setw(const std::string &tekstas, int plotis, std::string& out) {
    out += tekstas;
    if (tekstas.size() < plotis)
        out.append(plotis - tekstas.size(), ' ');
};