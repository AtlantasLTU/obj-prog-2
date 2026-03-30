#include "studentas.h"
#include <algorithm>
#include <numeric>

void Studentas::addNd(int paz)
{
    nd.push_back(paz);
}

void Studentas::resizeNd(int n, int skaicius)
{
    if(nd.size() < n)
        nd.resize(n, skaicius);
};

double Studentas::galutinis(bool medianos, int ndKiekis) const
{
    int max;
    if(ndKiekis != 0)
    {
        max = ndKiekis;
    }
    else
    {
        max = maxNdKiekis;
    }
    if(medianos)
    {
        if(nd.empty()) return 0.6*rez;

        std::vector<int> ND = nd;
        ND.resize(max, 0);
        std::sort(ND.begin(), ND.end());

        double med =
            (max % 2 == 0) // jei lyginis, tai dvieju viduriniu nd vektoriaus nariu mediana paskaiciuoja
            ? (ND.at(max/2) + ND.at(max/2 - 1)) / 2.0
            : ND.at(max/2);

        return 0.4 * med + 0.6 * rez;
    }
    else
    {
        if(nd.empty()) return 0.6*rez;

        int sum = std::accumulate(nd.begin(), nd.end(), 0);

        double vid = (double)sum / max;
        return 0.4 * vid + 0.6 * rez;
    }
}