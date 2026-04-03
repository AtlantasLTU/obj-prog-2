# Programos naudojimas:
  ## Reikalavimai:
    C++ kompiliatorius su C++20 palaikymu.
    Unix OS (Linux arba MacOS) arba WSL (Windows Subsystem for Linux)
    git

  ## Programos diegimas:
    git clone https://github.com/AtlantasLTU/obj-prog-1.git
    cd ./obj-prog-1
    make
    ./main
    
  ## Programos naudojimas:
    Funkcijos:
      Pasirinktina išvestis į failą arba į terminalą.
      Pasirinktinas galutinio rezultato skaičiavimas, remiantis vidurkiu arba mediana.
      Direktorijoje esančių .txt failų pasirinkimas.
      Rūšiavimas pasirinktu būdu.
      
    1 parinktis - rankinis duomenų įvedimas, studento vardo, pavardės, namų darbų rezultatų, egzamino rezultato, jų apdorojimas ir išvedimas.
    2 parinktis - pusiau rankinis duomenų įvedimas, studento vardo, pavardės, rezultatų generavimas, duomenų apdorojimas ir išvedimas.
    3 parinktis - automatinis studentų vardų, pavardžių, rezultatų generavimas, jų apdorojimas ir išvedimas.
    4 parinktis - skaitymas iš pasirinktino failo, rūšiavimas pasirinktinu būdu, duomenų apdorojimas ir išvedimas.
    5 parinktis - testavimas su failais, pasirenkamas failas, konteinerio tipas, strategija, testų skaičius, failai apdorojami (nuskaitymas, skaičiavimas, rūšiavimas, skirstymas) ir išvedami testo rezultatai į terminalą.
    6 parinktis - studentų failų generavimas, studentų, namų darbų kiekio pasirinkimas ir išvedimas į studentai*.txt failą.
    7 parinktis - programos nutraukimas.

# Testavimas:

- Kompiuterio, su kuriuo testuota parametrai:
<img width="1000" height="606" alt="image" src="https://github.com/user-attachments/assets/76e93716-e1de-4997-9bfb-c176b49e5e1e" />

#### Skirstymo strategijos:
- 0 - pradiniame relize naudota strategija. Dviejų konteinerių "vargšiukų" ir "kietiakų" sukūrimas, duomenys perkeliami iš "studentai" konteinerio su std::move.
- 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Dviejų konteinerių "vargšiukų" ir "kietiakų" sukūrimas, duomenys kopijuojami iš "studentai" konteinerio.
- 2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Studentai konteineris išrūšiuotas, randamas iteratorius rodantis į pirmąjį galvočių, viskas iki iteratoriaus perkeliama į vargšiukų konteinerį ir ištrinama iš studentai konteinerio. Iteratoriui rasti naudojamas lower_bound metodas
- 3 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant greičiausiai veikianti 1 arba 2 strategiją  įtraukiant į ją "efektyvius" darbo su konteineriais metodus. Šioje strategijoje naudojamas partition metodas.

#### Atlikta programos veikimo greičio (spartos) analizė:
- lyginamas v1.0 struct tipas su v1.1 realizuota klasė.
- lyginamas vienas konteinerius - vektorius, su pačia greičiausia dalijimo strategija - 2.
- 100000 ir 1000000 studentų failai.
- lyginamos kompiliatoriaus optimizavimo vėliavėlės (-Ofast, -O1, -O2, -O3).

Testuota tik naudojant terminalą, visos kitos pašalinės programos testavimo metu buvo išjungtos bei įrenginys "performance" režime.
Visi testavimo atvejai testuoti 10 kartų, su medianų skaičiavimu.

## Spartos palyginimas:
#### 100000 studentų:
|Tipas|Optimizavimo vėliavėlė|Bendras veikimo laikas (s)|Failo dydis (KB)|
|---------|---------------------------|------------------------------|-------------------------------|
|struct|-Ofast|1.65366 s|349.3 KB|
|class|-Ofast|4.66815 s|332.7 KB|
|struct|-O1|2.43243 s|300.6 KB|
|class|-O1|7.11753 s|293.2 KB|
|struct|-O2|2.24629 s|314.2 KB|
|class|-O2|6.3197 s|308.2 KB|
|struct|-O3|2.1662 s|349.5 KB|
|class|-O3|5.94076 s|332.7 KB|
#### 1000000 studentų:
|Tipas|Optimizavimo vėliavėlė|Bendras veikimo laikas (s)|Failo dydis (KB)|
|---------|---------------------------|------------------------------|-------------------------------|
|struct|-Ofast|18.4434 s|349.3 KB|
|class|-Ofast|66.1051 s|332.7 KB|
|struct|-O1|20.5588 s|300.6 KB|
|class|-O1|79.2437 s|293.2 KB|
|struct|-O2|18.8914 s|314.2 KB|
|class|-O2|72.3371 s|308.2 KB|
|struct|-O3|18.0112 s|349.5 KB|
|class|-O3|55.4038 s|332.7 KB|

# Relizų aprašas

v1.0

    Padidintas template naudojimas, siekiant ištestuoti vector, deque ir list konteinerius.
    Pridėtos trys studentų skirstymo į „vargšiukus“ (vidurkis < 5.0) ir „kietiakus“ strategijos:
        1 strategija: Bendro konteinerio skaidymas į du naujus, kopijuojant į vargsiukai ir galvočiai konteinerius.
        2 strategija: „Vargšiukų“ perkėlimas į naują konteinerį, juos ištrinant iš studentų konteinerio.
        3 strategija: Optimizuotas skirstymas naudojant efektyvius algoritmus (std::partition).

    Paruoštas pilnas README.md su tyrimo rezultatais, lentelėmis ir naudojimo instrukcija.
    Pridėtas Makefile lengvam programos kompiliavimui.

v0.4
    
    Patobulinta išvestis.
    Pridėtas skirstymas į "galvočius" ir "vargšiukus".
    Pridėtas failų generavimas.
    Pridėtas failų pasirinkimas.

v0.3

    Kodas išskirstytas į daugiau dalių (.h ir .cpp failus).
    Įterptas try-catch blokas failų egzistavimo tikrinimui, kitų klaidų gaudymui.
    Panaudotas template rūšiavimo funkcijoje, kodo skaitomumui pagerinti.
    Refaktoriaus metu apšvarintas main.cpp failas.

v0.2

    Pridėtas duomenų nuskaitymas iš išorinių failų.
    Pridėti testavimo atvejai.

v0.1

    Pridėtas automatinis pažymių generavimas.
    Įdiegtas „sąžiningas“ vidurkio skaičiavimas (atsižvelgiant į trūkstamus namų darbus).
    Patobulintas įvesties valdymas (apsauga nuo neteisingos įvesties).

V.pradinė

    Sukurta studento struktūra.
    Realizuotas vidurkio ir medianos skaičiavimas.
    Pradinė įvesties apsauga.
    Hardcoded reikšmės testavimui.
