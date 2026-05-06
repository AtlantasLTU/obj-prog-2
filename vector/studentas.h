#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include <string>
#include <vector>
#include <istream>
#include <ostream>

constexpr int maxNdKiekis = 10;   ///< Maksimalus namų darbų kiekis (naudojamas jei nenurodyta kitaip).

/**
 * @class Studentas
 * @brief Klasė, sukurianti studento objektą su pažymiais.
 * 
 * Paveldi iš klasės Zmogus. Saugo namų darbų pažymius ir egzamino rezultatą.
 * Leidžia skaičiuoti galutinį pažymį (pagal vidurkį arba medianą).
 */
class Studentas : public Zmogus {
    std::vector<int> nd;   ///< Namų darbų pažymių vektorius.
    int rez;               ///< Egzamino pažymys.

    /**
     * @brief Nuskaito vardą ir pavardę iš eilutės.
     * @param eilute Eilutė, kurioje tikimasi dviejų žodžių.
     * @return true jei nuskaitymas sėkmingas, false jei formatas neteisingas.
     */
    bool studentoVardoPavardesIvestis(const std::string& eilute);
    
    /** @brief Nuskaito namų darbų rezultatus iš terminalo. */
    void namuDarbuRezultatuIvestis();
    
    /** @brief Nuskaito egzamino rezultatą iš terminalo. */
    void egzaminoRezultatoIvestis();
    
    /** @brief Atsitiktinai sugeneruoja vardą ir pavardę. */
    void genVardaPavarde();
    
    /**
     * @brief Atsitiktinai sugeneruoja namų darbų rezultatus.
     * @param ndKiekis Kiek rezultatų generuoti.
     */
    void ndRandom(int ndKiekis);
    
    /** @brief Atsitiktinai sugeneruoja egzamino rezultatą. */
    void egzRandom();
    
public:
    // constructors
    /** @brief Default konstruktorius. */
    Studentas() : Zmogus(), nd(), rez(0){};
    
    /**
     * @brief Konstruktorius su visais parametrais.
     * @param v Vardas.
     * @param p Pavardė.
     * @param n Namų darbų pažymių vektorius.
     * @param r Egzamino rezultatas.
     */
    Studentas(std::string v, std::string p, std::vector<int> n, int r) 
        : Zmogus(std::move(v), std::move(p)), nd(std::move(n)), rez(r) {};
    
    /**
     * @brief Konstruktorius, nuskaitantis studentą iš srauto.
     * @param is Įvesties srautas.
     * @param ndKiekis Namų darbų skaičius (jei 0, tai nustatoma iš duomenų).
     */
    Studentas(std::istream& is, int ndKiekis = 0){ read(is, ndKiekis); };

    /** @brief Kopijavimo konstruktorius. */
    Studentas(const Studentas &kitas);

    /** @brief Kopijavimo priskyrimo operatorius. */
    Studentas& operator=(const Studentas&);

    /** @brief Perkėlimo konstruktorius. */
    Studentas(Studentas&&) noexcept;

    /** @brief Perkėlimo priskyrimo operatorius. */
    Studentas& operator=(Studentas&&) noexcept;

    // getters
    /** @return Namų darbų pažymių vektoriaus konstantinė nuoroda. */
    const std::vector<int> &getNd() const { return nd; };
    
    /** @return Egzamino rezultatas. */
    int getRez() const { return rez; };

    // setters
    /**
     * @brief Nustato namų darbų pažymius.
     * @param n Naujas pažymių vektorius.
     */
    void setNd(std::vector<int> n) { nd = std::move(n);}
    
    /**
     * @brief Nustato egzamino rezultatą.
     * @param r Naujas egzamino pažymys.
     */
    void setRez(int r) { rez = r; }

    /**
     * @brief Nuskaito studentą iš failo srauto.
     * @param is Įvesties srautas.
     * @param ndKiekis Jei >0, skaitoma būtent tiek nd rezultatų, kitaip skaitoma iki failo galo ir egzamino rezultatas nustatomas automatiškai.
     * @return Srauto nuoroda.
     */
    std::istream& readStudentStream(std::istream& is, int ndKiekis);
    
    /**
     * @brief Nuskaito studentą iš terminalo.
     * @param is Įvesties srautas (paprastai std::cin).
     * @return Srauto nuoroda.
     */
    std::istream& readStudentConsole(std::istream& is);
    
    /**
     * @brief Nuskaito studentą iš srauto (automatiškai parenka readStudentConsole arba readStudentStream).
     * @param is Įvesties srautas.
     * @param ndKiekis Namų darbų skaičius (naudojamas tik failo skaitymui).
     */
    void read(std::istream& is, int ndKiekis = 0);
    
    /**
     * @brief Dalinai atsitiktinis įvedimas: vardas/pavardė ranka, pažymiai atsitiktiniai.
     * @return true jei vartotojas įvedė ne tuščią eilutę, false jei įveda ENTER - užbaigia įvedimą.
     */
    bool readSemiRandom();
    
    /**
     * @brief Visiškai atsitiktinis studento ir jo rezultatų sugeneravimas.
     * @param ndKiekis Kiek namų darbų pažymių sugeneruoti.
     */
    void readRandom(int ndKiekis);
    
    /**
     * @brief Prideda vieną namų darbų pažymį.
     * @param paz Pažymys (1-10).
     */
    void addNd(int paz);
    
    /**
     * @brief Resize'ina namų darbų vektorių ir užpildo naujas vietas nurodyta reikšme.
     * @param n Naujas dydis.
     * @param skaicius Reikšmė naujiems elementams (numatyta 0).
     */
    void resizeNd(int n, int skaicius = 0);

    /**
     * @brief Apskaičiuoja galutinį pažymį.
     * @param medianos Jei true – naudoja medianą, kitu atveju – vidurkį.
     * @param ndKiekis Jei >0 – naudoja šį ND skaičių, kitu atveju – maxNdKiekis.
     * @return Galutinis pažymys (0.4 * ND + 0.6 * egz.).
     */
    double galutinis(bool medianos, int ndKiekis = 0) const;

    /** @brief Destruktorius. */
    ~Studentas();

    /** @brief Įvesties operatorius (>>). */
    friend std::istream& operator>>(std::istream& in, Studentas &A);
    
    /** @brief Išvesties operatorius (<<). */
    friend std::ostream& operator<<(std::ostream& out, const Studentas &A);
};

#endif // STUDENTAS_H