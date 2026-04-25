#include "zmogus.h"

//copy constructor
Zmogus::Zmogus(const Zmogus &kitas)
    : vardas(kitas.vardas),
    pavarde(kitas.pavarde)
{}

// copy assignment operator
Zmogus& Zmogus::operator=(const Zmogus& kitas)
{
    if(this != &kitas)
    {
        vardas = kitas.vardas;
        pavarde = kitas.vardas;
    }
    return *this;
}

// move constructor
Zmogus::Zmogus(Zmogus&& kitas) noexcept
    : vardas(std::move(kitas.vardas)),
    pavarde(std::move(kitas.pavarde))
{}

// move assignment operator
Zmogus& Zmogus::operator=(Zmogus&& kitas) noexcept
{
    if(this != &kitas)
    {
        vardas = std::move(kitas.vardas);
        pavarde = std::move(kitas.vardas);
    }
    return *this;
}