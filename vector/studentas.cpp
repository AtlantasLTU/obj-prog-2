#include "studentas.h"

void Studentas::addNd(int paz)
{
    nd.push_back(paz);
}

void Studentas::resizeNd(int n, int skaicius)
{
    if(nd.size() < n)
        nd.resize(n, skaicius);
};