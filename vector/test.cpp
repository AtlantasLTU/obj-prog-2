#include "test.h"

void testas()
{
    std::cout << "Studento klasės testas\n\n";
    testDefaultKonstruktorius();
    testStreamKonstruktorius();
    testCopyKonstruktorius();
    testCopyAssignmentOperator();
    testMoveKonstruktorius();
    testMoveAssignmentOperator();
    testDestructor();
    testInputOperator();
    testOutputOperator();
}

void testDefaultKonstruktorius()
{
    Studentas A;
    bool testas = (A.getVardas().empty() && A.getPavarde().empty() && A.getNd().empty() && A.getRez() == 0);
    testoRezultatas("Default konstruktorius", testas);
}

void testStreamKonstruktorius()
{
    std::istringstream iss("Jonas Jonaitis 1 2 10");
    Studentas C(iss, 2);
    bool testas = (C.getVardas()=="Jonas" && C.getPavarde()=="Jonaitis" && C.getNd().at(0) == 1 && C.getNd().at(1) == 2 && C.getRez() == 10);
    std:: cout << "Turėtų išvesti 'Jonas Jonaitis 1 2 10':\n" << C << std::endl;
    testoRezultatas("Stream įvesties konstruktorius", testas);
}

void testCopyKonstruktorius()
{
    Studentas A;
    A.setVardas("A");
    A.setPavarde("AAA");
    A.setNd({1,2});
    A.setRez(10);
    Studentas B(A);
    bool testas = (B.getVardas()=="A" && B.getPavarde()=="AAA" && B.getNd().at(0) == 1 && B.getNd().at(1) == 2 && B.getRez() == 10);
    testoRezultatas("Copy konstruktorius", testas);
}

void testCopyAssignmentOperator()
{
    Studentas A;
    A.setVardas("A");
    A.setPavarde("AAA");
    A.setNd({1,2});
    A.setRez(10);
    Studentas B;
    B = A;
    bool testas = (B.getVardas()=="A" && B.getPavarde()=="AAA" && B.getNd().at(0) == 1 && B.getNd().at(1) == 2 && B.getRez() == 10);
    testoRezultatas("Copy assignment operatorius", testas);
}

void testMoveKonstruktorius()
{
    Studentas A;
    A.setVardas("A");
    A.setPavarde("AAA");
    A.setNd({1,2});
    A.setRez(10);
    Studentas B(std::move(A));
    bool testas = ((B.getVardas()=="A" && B.getPavarde()=="AAA" && B.getNd().at(0) == 1 && B.getNd().at(1) == 2 && B.getRez() == 10) && (A.getVardas().empty() && A.getPavarde().empty() && A.getNd().empty() && A.getRez() == 0));
    testoRezultatas("Move konstruktorius", testas);
}

void testMoveAssignmentOperator()
{
    Studentas A;
    A.setVardas("A");
    A.setPavarde("AAA");
    A.setNd({1,2});
    A.setRez(10);
    Studentas B;
    B = std::move(A);
    bool testas = ((B.getVardas()=="A" && B.getPavarde()=="AAA" && B.getNd().at(0) == 1 && B.getNd().at(1) == 2 && B.getRez() == 10) && (A.getVardas().empty() && A.getPavarde().empty() && A.getNd().empty() && A.getRez() == 0));
    testoRezultatas("Move assignment operatorius", testas);
}

void testDestructor()
{
    {
        Studentas A;
        A.setVardas("A");
        A.setPavarde("AAA");
        A.setNd({1,2});
        A.setRez(10);
    }
    testoRezultatas("Destruktorius", true);
}

void testInputOperator()
{
    Studentas A;
    std::istringstream iss("Jonas Jonaitis 1 2 10");
    iss >> A;
    std::cout << "Turėtų išvesti 'Jonas Jonaitis 1 2 10':\n" << A << std::endl;
    bool testas = (A.getVardas()=="Jonas" && A.getPavarde()=="Jonaitis" && A.getNd().at(0) == 1 && A.getNd().at(1) == 2 && A.getRez() == 10);
    testoRezultatas("Input operatorius", testas);
}

void testOutputOperator()
{
    Studentas A;
    A.setVardas("A");
    A.setPavarde("AAA");
    A.setNd({1,2});
    A.setRez(10);
    std::ostringstream out;
    out << A;
    std::string isvestis = out.str();
    bool testas = (isvestis.find("A") != std::string::npos && isvestis.find("AAA") != std::string::npos && isvestis.find("1") != std::string::npos && isvestis.find("2") != std::string::npos && isvestis.find("10") != std::string::npos);
    testoRezultatas("Išvesties operatorius", testas);
}

void testoRezultatas(const std::string& testoPavadinimas, bool passed)
{
    std::cout << (passed ? "PASS " : "FAIL ") << testoPavadinimas << "\n";
}

/* template<class Konteineris>
Konteineris skaitymasIsFailo(const std::string &failoPavadinimas, int &ndKiekis, int rezervas){
    Konteineris studentai;
    if constexpr(requires(Konteineris konteineris){konteineris.reserve(0);})
        studentai.reserve(rezervas);
    std::string eil, t;

    std::ifstream open_f(failoPavadinimas);
    if (!open_f.is_open()) throw std::runtime_error("Klaida: failas \"" + failoPavadinimas + "\" nerastas.");

    if(!std::getline(open_f, eil)) throw std::runtime_error("Klaida: failas tuščias arba netinkantis");
    std::istringstream antraste(eil);
    antraste >> t >> t;
    while(antraste >> t){
        if(t == "Egz." || t == "Egzaminas") break;
        ndKiekis++;
    }

    std::string vardas, pavarde;
    int paz;
    
    while (true) {
        Studentas studentas;
        if(!(studentas.readStudentStream(open_f, ndKiekis))) break;
        studentai.push_back(std::move(studentas));
    }

    open_f.close();
    return studentai;
} */