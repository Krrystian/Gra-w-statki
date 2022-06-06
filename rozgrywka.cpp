#include "rozgrywka.h"

void rozgrywka::gra(dane *ust, vector < vector<int> > & tab)
{
    ustawienia gracz1(tab,ust);
    ustawienia gracz1_strzaly(gracz1);
    ustawienia pc(gracz1);
    komputer komp(ust,pc.tab);
    statkiGracza(ust, gracz1);
    while (!strzaly::koniecGry(ust))
        przebiegGry(ust, gracz1, pc, gracz1_strzaly);
    cout << "Gra dobiegla konca"<<endl;
}
void rozgrywka::statkiGracza(dane *obj, ustawienia &player)
{
    int w,orientacja,statek=0;
    char k;
    const int jedno = obj->jednomasztowiec;
    const int dwu = jedno+obj->dwumasztowiec;
    const int trzy = dwu+obj->trzymasztowiec;
    const int trzy_pp = trzy+obj->trzymasztowiec_po_przekatnej;
    
    for (int i=0; i<trzy_pp;i++)
    {
        if (i==jedno) statek = 1;
        if (i==dwu) statek = 2;
        if (i==trzy) statek = 3;
        
        switch(statek)
        {
            case 0:{
                cout << "Jednomasztowiec "<<i+1<<" [k,w]: ";
                cin>>k;
                cin>>w;
                k = toupper(k);
                jednomasztowiec j(player.tab,w-1,(int)k-65,1,obj->wiersze-1,obj->kolumny-1);
                j.~jednomasztowiec();
                player.wyswietl2();
                break;}
            case 1:{
                cout << "Dwumasztowiec "<<i+1-jedno<<" [k,w,o {1-POZ,0-PION}]: ";
                cin>>k;
                cin>>w;
                cin>>orientacja;
                k = toupper(k);
                dwumasztowiec d(player.tab,w-1,(int)k-65,orientacja,1,obj->wiersze-1,obj->kolumny-1);
                d.~dwumasztowiec();
                player.wyswietl2();
                break;}
            case 2:{
                cout << "Trzymasztowiec "<<i+1-dwu<<" [k,w,o {1-POZ,0-PION}]: ";
                cin>>k;
                cin>>w;
                cin>>orientacja;
                k = toupper(k);
                trzymasztowiec t(player.tab,w-1,(int)k-65,orientacja,1,obj->wiersze-1,obj->kolumny-1);
                t.~trzymasztowiec();
                player.wyswietl2();
                break;}
            case 3:{
                cout << "Trzymasztowiec po przekatnej "<<i+1-trzy<<" [k,w,o {1-LEWO,0-PRAWO}]: ";
                cin>>k;
                cin>>w;
                cin>>orientacja;
                trzymasztowiec_po_przekatnej tpp(player.tab,w-1,(int)k-65,orientacja,1,obj->wiersze-1,obj->kolumny-1);
                tpp.~trzymasztowiec_po_przekatnej();
                player.wyswietl2();
                break;}
        }
    }
    
}

void rozgrywka::przebiegGry(dane *obj, ustawienia &player, ustawienia &pc, ustawienia &gracz_strzaly){
    strzaly s;
    int w;
    char k;
    int z = 0;
    cout << "Podaj wspolrzedne do strzalu [k,w]: ";
    cin >> k;
    cin >> w;
    k = toupper(k);
    while(!s.czyStrzal(gracz_strzaly.tab, w-1, (int)k-65,obj->wiersze-1,obj->kolumny-1))
    {
        cout << "Podaj poprawne wspolrzedne do strzalu [k,w]: ";
        cin >> k;
        cin >> w;
        k = toupper(k);
    }
    s.strzal(pc.tab, gracz_strzaly.tab, w-1, (int)k-65,obj->licznik1,obj->wiersze-1,obj->kolumny-1);
    
    w = GEN::losujOdZeraDo(obj->wiersze-1);
    z = GEN::losujOdZeraDo(obj->kolumny-1);
    while (!s.czyStrzal(pc.tab, w, z,obj->wiersze-1,obj->kolumny-1))
    {
        w = GEN::losujOdZeraDo(obj->wiersze-1);
        z = GEN::losujOdZeraDo(obj->kolumny-1);
    }
    s.strzal(player.tab, pc.tab, w, z,obj->licznik2,obj->wiersze-1,obj->kolumny-1);
    cout << "TWOJE STRZALY: "<<endl;
    gracz_strzaly.wyswietl2();
    
    cout << endl;
    cout << "Przeciwnik strzelil w pole: " << (char)(z+65) <<" "<<w+1<<endl;
    cout <<endl;
    cout << "TWOJA TABLICA:" <<endl;
    player.wyswietl2();
    cout << endl;
    
    
    cout << "Zniszczone okrety wroga: " <<obj->licznik1<<endl;
    cout << "Moje zniszczone okrety: " <<obj->licznik2<<endl;
    cout <<"TABLICA WROGA:"<<endl;
    pc.wyswietl2();
}
