#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
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
    Studentas(std::istream& is, int ndKiekis = 0) { readStudent(is, ndKiekis); };

    // copy constructor
    Studentas(const Studentas& kitas);

    // copy assignment operator
    Studentas& operator=(const Studentas&);

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

    std::istream& readStudent(std::istream& is, int ndKiekis = 0);  // set'eriai
    bool readSemiRandom(); // galbut kaip konstruktoriu irig naudot
    void readRandom(int ndKiekis); // galbut kaip konstruktoriu irgi naudot
    void addNd(int paz);
    void resizeNd(int n, int skaicius = 0);

    double galutinis(bool medianos, int ndKiekis = 0) const;


    ~Studentas();
};
#endif // STUDENTAS_H
