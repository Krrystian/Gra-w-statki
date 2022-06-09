#ifndef komputer_h
#define komputer_h
#include <stdio.h>
#include "statki.h"
#include <random>
#include <iostream>
#include <ctime>
#include "ustawienia.h"
struct dane;

class komputer{
public:
    komputer(dane *obj,vector < vector<int> > & tab);
};

class GeneratorLosowy
{
private:
    static std::random_device device;
    GeneratorLosowy(){}
public:
    static int losujOdZeraDo(int max);
};
typedef GeneratorLosowy GEN;

#endif /* komputer_hpp */
