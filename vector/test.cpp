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
    testoRezultatas("Įvesties operatorius", testas);
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