
#include "ustawienia.h"
#include "statki.h"
#include "rozgrywka.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int> > tab;
    dane *dane_gry = new dane;
    char wyb;
    
    cout << "CZY CHCESZ UZYC DOMYSLNYCH USTAWIEN [y/n]: ";
    cin >> wyb;
    wyb = tolower(wyb);
    if(wyb=='n'){
        int j,d,t,tpp,w,k;
        cout << "PODAJ WIELKOSC POLA [w,k]: ";
        cin >> w;
        cin >> k;
        cout << "ILE STATKOW JEDNOMASZTOWYCH: ";
        cin >> j;
        cout << "ILE STATKOW DWUMASZTOWYCH: ";
        cin >> d;
        cout << "ILE STATKOW TRZYMASZTOWYCH: ";
        cin >> t;
        cout << "ILE STATKOW TRZYMASZTOWYCH PO PRZEKATNEJ: ";
        cin >> tpp;
        rozgrywka n_def(dane_gry, w, k, j, d, t, tpp);
        n_def.gra(dane_gry, tab);
    }
    else
    {
        cout <<"WCZYTANIE STANDARDOWYCH DANYCH"<<endl;
        rozgrywka def;
        def.gra(dane_gry, tab);
    }
}
