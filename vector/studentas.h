#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#define maxNdKiekis 10

class Studentas{
    std::string vardas, pavarde;
public:
    const std::string &getVardas() const { return vardas; };
    const std::string &getPavarde() const { return pavarde; };

    void setVardas(const std::string &v) { vardas = v; }
    void setPavarde(const std::string &p) { pavarde = p; }
    std::vector<int> nd;
    int rez;
    double galutinis = 0;
};
#endif // STUDENTAS_H
