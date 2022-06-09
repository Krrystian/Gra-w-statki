#include "komputer.h"


std::random_device GeneratorLosowy::device;
int GeneratorLosowy::losujOdZeraDo(int max)
{
    std::uniform_int_distribution<int> dist(0, max);
    return dist(GeneratorLosowy::device);
}

komputer::komputer(dane *obj,vector < vector<int> > & tab)
{
    {
        int w,k,orientacja,statek=0;
        //int licznik1=0, licznik2=0, licznik3=0, licznik4=0;
        const int jedno = obj->jednomasztowiec;
        const int dwu = jedno+obj->dwumasztowiec;
        const int trzy = dwu+obj->trzymasztowiec;
        const int trzy_pp = trzy+obj->trzymasztowiec_po_przekatnej;
        statki a;
        trzymasztowiec_po_przekatnej tpp;
        jednomasztowiec j;
        for (int i=0; i<trzy_pp;i++)
        {
            if (i==jedno) statek = 1;
            if (i==dwu) statek = 2;
            if (i==trzy) statek = 3;
            
            w = GEN::losujOdZeraDo(obj->wiersze-1);
            k = GEN::losujOdZeraDo(obj->kolumny-1);
            orientacja = GEN::losujOdZeraDo(1);
            
            
            switch(statek)
            {
                case 0:{
                    j.jedenmaszt(tab, w, k, 1, obj->wiersze-1, obj->kolumny-1);
                    //licznik1++;
                    break;}
                case 1:{
                    a.wielomasztowiec(tab, w, k, orientacja, 2, 0, obj->wiersze-1,obj->kolumny-1);
                    //licznik2++;
                    break;}
                case 2:{
                    a.wielomasztowiec(tab, w, k, orientacja, 3, 0, obj->wiersze-1,obj->kolumny-1);
                    //licznik3++;
                    break;}
                case 3:{
                    tpp.wielomasztowiec(tab, w, k, orientacja, 3, 0, obj->wiersze-1,obj->kolumny-1);
                    //licznik4++;
                    break;}
            }
        }
        //cout<<endl;
        //cout << "Jedno: " << licznik1 <<" Dwu: "<<licznik2 <<" Trzy: "<<licznik3 << " TrzyPP: "<<licznik4<<endl;
    }


}
