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
    // constructors
    Studentas() = default;
    Studentas(std::string v, std::string p) : vardas(std::move(v)), pavarde(std::move(p)) {};

    // getters
    const std::string &getVardas() const { return vardas; };
    const std::string &getPavarde() const { return pavarde; };
    const std::vector<int> &getNd() const { return nd; };
    std::vector<int> &getNd() { return nd; };
    int getRez() const { return rez; };

    // setters
    void setVardas(const std::string v) { vardas = std::move(v); }
    void setPavarde(const std::string p) { pavarde = std::move(p); }

    void setNd(const std::vector<int> n) { nd = std::move(n);}
    void setRez(int r) { rez = r; }

    void addNd(int paz);
    void resizeNd(int n, int skaicius = 0);

    double galutinis(bool medianos, int ndKiekis = 0) const;
};
#endif // STUDENTAS_H
