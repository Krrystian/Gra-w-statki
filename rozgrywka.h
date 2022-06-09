#ifndef rozgrywka_h
#define rozgrywka_h
#include "ustawienia.h"
#include "komputer.h"
#include "statki.h"
#include <stdio.h>
#include <iostream>
#include <vector>

struct dane;

class rozgrywka{
public:
    rozgrywka(dane *ust,int wiersze,int kolumny,int jednomasztowce, int dwumasztowce, int trzymasztowce, int trzymasztowce_po_przekatnej)
    {
        ust->wiersze = wiersze;
        ust->kolumny = kolumny;
        ust->jednomasztowiec = jednomasztowce;
        ust->dwumasztowiec = dwumasztowce;
        ust->trzymasztowiec = trzymasztowce;
        ust->trzymasztowiec_po_przekatnej = trzymasztowce_po_przekatnej;
    }
    rozgrywka(){};
    void gra(dane *ust, vector < vector<int> > & tab);
private:
    void statkiGracza(dane *obj, ustawienia &player);
    void przebiegGry(dane *obj, ustawienia &ust, ustawienia &pc, ustawienia &gracz_strzaly);
};

#endif /* rozgrywka_hpp */
