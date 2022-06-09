#ifndef USTAWIENIA_H
#define USTAWIENIA_H
#include <iostream>
#include <vector>
#include "komputer.h"
using namespace std;
/*
 1 -> okret
 2 -> otoczenie okretu
 3 -> trafienie na widoku trafien
 4 -> pudło na widoku trafien
 5 -> trafienie na planszy z statkami
 6 -> pudlo na planszy z statkami
 */

struct dane{
    int wiersze=10;
    int kolumny=10;
    int jednomasztowiec=2;
    int dwumasztowiec=2;
    int trzymasztowiec=1;
    int trzymasztowiec_po_przekatnej=1;
    int licznik1=0;
    int licznik2=0;
};

class ustawienia
{
private:
    int wiersze;
    int kolumny;
public:
    vector < vector<int> > tab;
    
    ustawienia(vector < vector<int> > & t, dane *ust):tab(t),kolumny(ust->kolumny),wiersze(ust->wiersze){stworzPole();};
    ustawienia(const ustawienia &ust):wiersze(ust.wiersze),kolumny(ust.kolumny),tab(ust.tab){};
    void stworzPole();
    void wyswietl();
    void wyswietl2();
};

class strzaly
{
public:
    void strzal(vector < vector<int> > & tab, vector < vector<int> > & tab_strzaly, int w, int k,int &counter,int w_max,int k_max);
    static bool koniecGry(dane *obj)
    {
        int max = obj->jednomasztowiec+ obj->dwumasztowiec+obj->trzymasztowiec+obj->trzymasztowiec_po_przekatnej;
        bool var = 0; if (obj->licznik1 == max || obj->licznik2 == max) var = 1; return var;
        
    };
    bool czyStrzal(vector < vector<int> > & tab_strzaly, int w, int k,int w_max, int k_max);
};
#endif // USTAWIENIA_H

