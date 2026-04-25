#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
    protected:
        std::string vardas, pavarde;
    public:
        Zmogus() : vardas(""), pavarde("") {};

        // copy constructor
        Zmogus(const Zmogus &kitas);

        // copy assignment operator
        Zmogus& operator=(const Zmogus&);

        // move constructor
        Zmogus(Zmogus&&) noexcept;

        // move assignment operator
        Zmogus& operator=(Zmogus&&) noexcept;

        const std::string& getVardas() const { return vardas; }
        const std::string& getPavarde() const { return pavarde; }

        void setVardas(const std::string& v) { vardas = std::move(v); }
        void setPavarde(const std::string& p) { pavarde = std::move(p); }

        virtual ~Zmogus() {
            vardas.clear();
            pavarde.clear();
        };
};

#endif