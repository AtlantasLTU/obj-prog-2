#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
    protected:
        std::string vardas, pavarde;
    public:
        Zmogus() : vardas(""), pavarde("") {};
        Zmogus(const std::string v,const std::string p) : vardas(std::move(v)), pavarde(std::move(p)) {};

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

        void setVardas(std::string v) { vardas = std::move(v); }
        void setPavarde( std::string p) { pavarde = std::move(p); }

        virtual ~Zmogus() = 0; // destruktorius, kuris abstraktuoja visa zmogaus klase.
};

#endif