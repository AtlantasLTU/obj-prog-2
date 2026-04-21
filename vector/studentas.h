#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <istream>
#include <ostream>
static constexpr int maxNdKiekis = 10;

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
    Studentas() : vardas(""), pavarde(""), nd(), rez(0){};
    Studentas(std::istream& is) { readStudentConsole(is); };
    Studentas(std::istream& is, int ndKiekis) { readStudentFile(is, ndKiekis); };

    // copy constructor
    Studentas(const Studentas &kitas);

    // copy assignment operator
    Studentas& operator=(const Studentas&);

    // move constructor
    Studentas(Studentas&&) noexcept;

    // move assignment operator
    Studentas& operator=(Studentas&&) noexcept;

    // getters
    const std::string &getVardas() const { return vardas; };
    const std::string &getPavarde() const { return pavarde; };
    const std::vector<int> &getNd() const { return nd; };
    int getRez() const { return rez; };

    // setters
    void setVardas(std::string v) { vardas = std::move(v); } // to remove
    void setPavarde(std::string p) { pavarde = std::move(p); } // to remove
    void setNd(std::vector<int> n) { nd = std::move(n);}
    void setRez(int r) { rez = r; }

    std::istream& readStudentFile(std::istream& is, int ndKiekis);  // set'eriai
    std::istream& readStudentConsole(std::istream& is);  // set'eriai
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
