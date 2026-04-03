#include "random.h"
#include "ivestis.h"

std::vector<Studentas> ivestiStudentusRandom(int pasirinkimas)
{
    std::vector<Studentas> studentai;
    switch(pasirinkimas)
    {
        case 2:
        {
            Studentas A;
            while(A.readSemiRandom())
            {
                studentai.push_back(std::move(A));
                A = Studentas{};
            }
            break;
        }
        case 3:
        {
            int studKiekis = gautiSkaiciu("Įveskite norimą generuoti studentų kiekį: ", 0, 100);
            studentai.reserve(studKiekis);
            for (int i = 0; i < studKiekis; i++)
            {
                Studentas A;
                int ndKiekis = gautiSkaiciu("Įveskite norimą generuoti namų darbų rezultatų kiekį: ", 0, 100);
                A.readRandom(ndKiekis);
                studentai.push_back(std::move(A));
            }
            break;
        }
        default:
        {
            std::cout << "ivestiStudentusRandom default atvejis" << std::endl;
        }
    }
    return studentai;
} 

std::mt19937& rng() {
    static std::mt19937 rng(std::random_device{}());
    return rng;
}