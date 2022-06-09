#ifndef STATKI_H
#define STATKI_H
#include <iostream>
#include "komputer.h"
#include "ustawienia.h"
using namespace std;
struct dane;

class statki
{
public:
    bool czyOtoczenie(vector < vector<int> > tab,int w, int k,int w_max, int k_max);
    virtual bool czyNaPolu(vector < vector<int> > & tab,int w, int k,int w_max, int k_max) final;
    virtual void umiesc(vector < vector<int> > & tab,int w, int k,int w_max, int k_max) final;
    virtual void wielomasztowiec(vector < vector<int> > & tab,int w,int k,int orientacja,int ilosc,bool osoba,int w_max, int k_max);
};

class jednomasztowiec: public statki{
public:
    
    void jedenmaszt(vector < vector<int> > & tab,int w,int k,bool osoba,int w_max, int k_max);
};
/*
class dwumasztowiec:public statki{
public:
    dwumasztowiec(vector < vector<int> > & tab,int w,int k,int orientacja,bool osoba,int w_max, int k_max)
        {
        wielomasztowiec(tab,w,k,orientacja,2,osoba,w_max,k_max);
        };
    ~dwumasztowiec(){};
};

class trzymasztowiec:public statki{
public:
    trzymasztowiec(vector < vector<int> > & tab,int w,int k,int orientacja,bool osoba,int w_max, int k_max)
    {
        wielomasztowiec(tab,w,k,orientacja,3,osoba,w_max, k_max);
    };
    ~trzymasztowiec(){};
};
 */
class trzymasztowiec_po_przekatnej : public statki{
public:
    trzymasztowiec_po_przekatnej() = default;
    void wielomasztowiec(vector < vector<int> > & tab,int w, int k,int orientacja,int ilosc,bool osoba,int w_max, int k_max);
};

#endif // STATKI_H
