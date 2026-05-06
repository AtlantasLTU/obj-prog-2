#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include <string>
#include <vector>
#include <istream>
#include <ostream>
constexpr int maxNdKiekis = 10;

class Studentas : public Zmogus {
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
    Studentas() : Zmogus(), nd(), rez(0){};
    Studentas(std::string v, std::string p, std::vector<int> n, int r) : Zmogus(std::move(v), std::move(p)), nd(std::move(n)), rez(r) {};
    Studentas(std::istream& is, int ndKiekis = 0){ read(is, ndKiekis); };

    // copy constructor
    Studentas(const Studentas &kitas);

    // copy assignment operator
    Studentas& operator=(const Studentas&);

    // move constructor
    Studentas(Studentas&&) noexcept;

    // move assignment operator
    Studentas& operator=(Studentas&&) noexcept;

    // getters
    const std::vector<int> &getNd() const { return nd; };
    int getRez() const { return rez; };

    // setters
    void setNd(std::vector<int> n) { nd = std::move(n);}
    void setRez(int r) { rez = r; }

    std::istream& readStudentStream(std::istream& is, int ndKiekis);  // set'eriai
    std::istream& readStudentConsole(std::istream& is);  // set'eriai
    void read(std::istream& is, int ndKiekis = 0);
    bool readSemiRandom();
    void readRandom(int ndKiekis);
    void addNd(int paz);
    void resizeNd(int n, int skaicius = 0);

    double galutinis(bool medianos, int ndKiekis = 0) const;

    ~Studentas();

    friend std::istream& operator>>(std::istream& in, Studentas &A);
    friend std::ostream& operator<<(std::ostream& out, const Studentas &A);
};
#endif // STUDENTAS_H
