#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#define maxNdKiekis 10

class Studentas{
    std::string vardas, pavarde;
    std::vector<int> nd;
    int rez;
public:
    const std::string &getVardas() const { return vardas; };
    const std::string &getPavarde() const { return pavarde; };
    const std::vector<int> &getNd() const { return nd; };
    int getRez() const { return rez; };
    std::vector<int> &getNd() { return nd; };

    void setVardas(const std::string &v) { vardas = v; }
    void setPavarde(const std::string &p) { pavarde = p; }
    void setNd(const std::vector<int> &n) { nd = n;}
    void addNd(int paz) {nd.push_back(paz);}
    void setRez(int r) { rez = r; }
    double galutinis = 0;
};
#endif // STUDENTAS_H
