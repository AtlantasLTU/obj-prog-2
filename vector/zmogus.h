#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

/**
 * @class Zmogus
 * @brief Abstrakti bazinė klasė, turinti vardą ir pavardę.
 * 
 * Klasė yra abstrakti dėl virtualaus destruktoriaus.
 * Skirta paveldėjimui (pvz., Studentas).
 */
class Zmogus {
    protected:
        std::string vardas;   ///< Zmogaus vardas.
        std::string pavarde;  ///< Zmogaus pavardė.
        
    public:
        /** @brief Numatytasis konstruktorius – tuščias vardas ir pavardė. */
        Zmogus() : vardas(""), pavarde("") {};
        
        /**
         * @brief Konstruktorius su vardu ir pavarde.
         * @param v Vardas.
         * @param p Pavardė.
         */
        Zmogus(const std::string v, const std::string p) 
            : vardas(std::move(v)), pavarde(std::move(p)) {};

        /** @brief Kopijavimo konstruktorius. */
        Zmogus(const Zmogus &kitas);

        /** @brief Kopijavimo priskyrimo operatorius. */
        Zmogus& operator=(const Zmogus&);

        /** @brief Perkėlimo konstruktorius. */
        Zmogus(Zmogus&&) noexcept;

        /** @brief Perkėlimo priskyrimo operatorius. */
        Zmogus& operator=(Zmogus&&) noexcept;

        /** @return Vardą (konstantinė nuoroda). */
        const std::string& getVardas() const { return vardas; }
        
        /** @return Pavardę (konstantinė nuoroda). */
        const std::string& getPavarde() const { return pavarde; }

        /**
         * @brief Nustato vardą.
         * @param v Naujas vardas.
         */
        void setVardas(std::string v) { vardas = std::move(v); }
        
        /**
         * @brief Nustato pavardę.
         * @param p Nauja pavardė.
         */
        void setPavarde(std::string p) { pavarde = std::move(p); }

        /**
         * @brief Virtualus destruktorius – padaro klasę abstrakčia.
         */
        virtual ~Zmogus() = 0;
};

#endif