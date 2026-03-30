#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#define maxNdKiekis 10

class Studentas{
    std::string vardas, pavarde;
    std::vector<int> nd;
    int rez;

    bool studentoVardoPavardesIvestis(const std::string& eilute);
    void namuDarbuRezultatuIvestis();
    void egzaminoRezultatoIvestis();

    void genVardaPavarde();
    void ndRandom(int ndKiekis);
    void egzRandom();
public:
    // constructors
    Studentas() = default;
    Studentas(std::string v, std::string p) : vardas(std::move(v)), pavarde(std::move(p)) {};
    Studentas(std::istream& is, int ndKiekis = 0) { readStudent(is, ndKiekis); };

    // getters
    const std::string &getVardas() const { return vardas; };
    const std::string &getPavarde() const { return pavarde; };
    const std::vector<int> &getNd() const { return nd; };
    std::vector<int> &getNd() { return nd; };
    int getRez() const { return rez; };

    // setters
    void setVardas(std::string v) { vardas = std::move(v); }
    void setPavarde(std::string p) { pavarde = std::move(p); }

    void setNd(const std::vector<int> n) { nd = std::move(n);}
    void setRez(int r) { rez = r; }

    std::istream& readStudent(std::istream& is, int ndKiekis = 0);  // set'eriai
    bool readSemiRandom();
    void readRandom(int ndKiekis);
    void addNd(int paz);
    void resizeNd(int n, int skaicius = 0);

    double galutinis(bool medianos, int ndKiekis = 0) const;

};
#endif // STUDENTAS_H
