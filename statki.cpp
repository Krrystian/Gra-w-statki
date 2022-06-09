#include "statki.h"


bool statki::czyNaPolu(vector < vector<int> > & tab,int w, int k,int w_max, int k_max)
{
    bool var = 0;
    if(w<=w_max && w>=0 && k<=k_max && k>=0)
        if (tab[w][k]==0)
            if(!czyOtoczenie(tab,w,k,w_max,k_max))
                var = 1;
    return var;
}
bool statki::czyOtoczenie(vector < vector<int> > tab,int w, int k,int w_max, int k_max)
{
    bool var = 0;
    if(w==0 && k==0){
        if(tab[w][k+1]==1) var = 1;
        else if(tab[w+1][k]==1) var = 1;
        else if(tab[w+1][k+1]==1) var = 1;
    }
    else if (w==0){
        if(tab[w][k-1]==1) var = 1;
        else if(tab[w][k+1]==1) var = 1;
        else if(tab[w+1][k-1]==1) var = 1;
        else if(tab[w+1][k]==1) var = 1;
        else if(tab[w+1][k+1]==1) var = 1;
    }
    else if (w==w_max){
        if(tab[w-1][k-1]==1) var = 1;
        else if(tab[w-1][k]==1) var = 1;
        else if(tab[w-1][k+1]==1) var = 1;
        else if(tab[w][k-1]==1) var = 1;
        else if(tab[w][k+1]==1) var = 1;
    }
    else if (k==0){
        if(tab[w-1][k]==1) var = 1;
        else if(tab[w-1][k+1]==1) var = 1;
        else if(tab[w][k+1]==1) var = 1;
        else if(tab[w+1][k]==1) var = 1;
        else if(tab[w+1][k+1]==1) var = 1;
    }
    else if (k==k_max){
        if(tab[w-1][k-1]==1) var = 1;
        else if(tab[w-1][k]==1) var = 1;
        else if(tab[w][k-1]==1) var = 1;
        else if(tab[w+1][k-1]==1) var = 1;
        else if(tab[w+1][k]==1) var = 1;
    }
    else {
        if(tab[w-1][k-1]==1) var = 1;
        else if(tab[w-1][k]==1) var = 1;
        else if(tab[w-1][k+1]==1) var = 1;
        else if(tab[w][k-1]==1) var = 1;
        else if(tab[w][k+1]==1) var = 1;
        else if(tab[w+1][k-1]==1) var = 1;
        else if(tab[w+1][k]==1) var = 1;
        else if(tab[w+1][k+1]==1) var = 1;
    }
    return var;
}

void statki::umiesc(vector < vector<int> > & tab,int w, int k,int w_max, int k_max)
{
    tab[w][k]=1;
    if(w==0){
        if(tab[w][k-1]==0) tab[w][k-1]=2;
        if(tab[w][k+1]==0) tab[w][k+1]=2;
        if(tab[w+1][k-1]==0) tab[w+1][k-1]=2;
        if(tab[w+1][k]==0) tab[w+1][k]=2;
        if(tab[w+1][k+1]==0) tab[w+1][k+1]=2;
    }
    else if (w==w_max){
        if(tab[w-1][k-1]==0) tab[w-1][k-1]=2;
        if(tab[w-1][k]==0) tab[w-1][k]=2;
        if(tab[w-1][k+1]==0) tab[w-1][k+1]=2;
        if(tab[w][k-1]==0) tab[w][k-1]=2;
        if(tab[w][k+1]==0) tab[w][k+1]=2;
    }
    else if(k==0){
        if(tab[w-1][k]==0) tab[w-1][k]=2;
        if(tab[w-1][k+1]==0) tab[w-1][k+1]=2;
        if(tab[w][k+1]==0) tab[w][k+1]=2;
        if(tab[w+1][k]==0) tab[w+1][k]=2;
        if(tab[w+1][k+1]==0) tab[w+1][k+1]=2;
    }
    else if(k==k_max){
        if(tab[w-1][k-1]==0) tab[w-1][k-1]=2;
        if(tab[w-1][k]==0) tab[w-1][k]=2;
        if(tab[w][k-1]==0) tab[w][k-1]=2;
        if(tab[w+1][k-1]==0) tab[w+1][k-1]=2;
        if(tab[w+1][k]==0) tab[w+1][k]=2;
    }
    else {
        if(tab[w-1][k-1]==0) tab[w-1][k-1]=2;
        if(tab[w-1][k]==0) tab[w-1][k]=2;
        if(tab[w-1][k+1]==0) tab[w-1][k+1]=2;
        if(tab[w][k-1]==0) tab[w][k-1]=2;
        if(tab[w][k+1]==0) tab[w][k+1]=2;
        if(tab[w+1][k-1]==0) tab[w+1][k-1]=2;
        if(tab[w+1][k]==0) tab[w+1][k]=2;
        if(tab[w+1][k+1]==0) tab[w+1][k+1]=2;
    }
}

void jednomasztowiec::jedenmaszt(vector < vector<int> > & tab,int w,int k,bool osoba,int w_max, int k_max){
    char d;
    int starczy=0;
    while(!czyNaPolu(tab,w,k,w_max,k_max)){
        if (osoba == 1){
            std::cout <<"wprowadz k i w jeszcze raz: ";
            std::cin.ignore();
            std::cin >> d;
            std::cin >> w;
            d = toupper(d);
            w--;
            k=static_cast<char>(d)-65;
        }
        if (osoba == 0){
            w = GEN::losujOdZeraDo(w_max);
            k = GEN::losujOdZeraDo(k_max);
            starczy++;
            if(starczy==100) {exit(0);}
        }
    }
    umiesc(tab,w,k,w_max,k_max);
}
void statki::wielomasztowiec(vector < vector<int> > & tab,int w, int k,int orientacja,int ilosc,bool osoba,int w_max, int k_max){
    bool var = 1;
    bool zlaPozycja=0;
    int starczy=0;
    if (orientacja ==0)
    { //PIONOWO

        int w_temp = w;
        for(int i=0;i<ilosc;i++)
        {
            var = czyNaPolu(tab,w_temp,k,w_max,k_max);
            if(var==0) zlaPozycja=1;
            w_temp++;
        }

        while(zlaPozycja){
            if (osoba == 1){
                char d;
                std::cout <<"wprowadz k i w jeszcze raz: ";
                std::cin.ignore();
                std::cin >> d;
                std::cin >> w;
                d = toupper(d);
                w--;;
                k = static_cast<char>(d)-65;}
            if (osoba == 0){
                w = GEN::losujOdZeraDo(w_max);
                k = GEN::losujOdZeraDo(k_max);
                starczy++;
            }
            w_temp = w;
            zlaPozycja=0;
            if(starczy==100) {exit(0);}
            for(int i=0;i<ilosc;i++){
                var = czyNaPolu(tab,w_temp,k,w_max,k_max);
                if(var==0) zlaPozycja=1;
                w_temp++;}
        }
        for(int i=0;i<ilosc;i++){
            umiesc(tab,w,k,w_max,k_max);
            w++;
        }
    }
    if (orientacja ==1)
    { //POZIOMO
        int k_temp = k;
        for(int i=0;i<ilosc;i++)
        {
            var = czyNaPolu(tab,w,k_temp,w_max,k_max);
            if(var==0) zlaPozycja=1;
            k_temp++;
        }

        while(zlaPozycja){
            if (osoba == 1){
                char d;
                std::cout <<"wprowadz k i w jeszcze raz: ";
                std::cin.ignore();
                std::cin >> d;
                std::cin >> w;
                d = toupper(d);
                w--;
                k = static_cast<char>(d)-65;}
            if (osoba == 0){
                w = GEN::losujOdZeraDo(w_max);
                k = GEN::losujOdZeraDo(k_max);
                starczy++;
            }
            k_temp = k;
            zlaPozycja=0;
            if(starczy==100){exit(0);}
            for(int i=0;i<ilosc;i++)
            {
                var = czyNaPolu(tab,w,k_temp,w_max,k_max);
                if(var==0) zlaPozycja=1;
                else zlaPozycja=0;
                k_temp++;
            }

        }
        for(int i=0;i<ilosc;i++){
            umiesc(tab,w,k,w_max,k_max);
            k++;
        }
    }
}

void trzymasztowiec_po_przekatnej::wielomasztowiec(vector < vector<int> > & tab,int w, int k,int orientacja,int ilosc,bool osoba,int w_max, int k_max){
    bool var = 1;
    bool zlaPozycja=0;
    int starczy=0;
    if (orientacja ==0)
    { //W PRAWO

        int w_temp = w;
        int k_temp = k;
        for(int i=0;i<ilosc;i++)
        {
            var = czyNaPolu(tab,w_temp,k_temp,w_max,k_max);
            if(var==0) zlaPozycja=1;
            w_temp++;
            k_temp++;
        }

        while(zlaPozycja){
            if (osoba == 1){
                char d;
                std::cout <<"wprowadz k i w jeszcze raz: ";
                std::cin.ignore();
                std::cin >> d;
                std::cin >> w;
                d = toupper(d);
                w--;
                k = static_cast<char>(d)-65;
            }
            if (osoba == 0){
                w = GEN::losujOdZeraDo(w_max);
                k = GEN::losujOdZeraDo(k_max);
                starczy++;
            }
            w_temp = w;
            k_temp = k;
            zlaPozycja=0;
            if(starczy==100) exit(0);
            for(int i=0;i<ilosc;i++){
                var = czyNaPolu(tab,w_temp,k_temp,w_max,k_max);
                if(var==0) zlaPozycja=1;
                w_temp++;
                k_temp++;
            }
        }
        for(int i=0;i<ilosc;i++){
            umiesc(tab,w,k,w_max,k_max);
            w++;
            k++;
        }
    }
    if (orientacja ==1)
    { //W LEWO
        int w_temp = w;
        int k_temp = k;
        for(int i=0;i<ilosc;i++)
        {
            var = czyNaPolu(tab,w_temp,k_temp,w_max,k_max);
            if(var==0) zlaPozycja=1;
            k_temp--;
            w_temp++;
        }

        while(zlaPozycja){
            if (osoba == 1){
                char d;
                std::cout <<"wprowadz k i w jeszcze raz: ";
                std::cin.ignore();
                std::cin >> d;
                std::cin >> w;
                d = toupper(d);
                w--;
                k = static_cast<char>(d)-65;}
            if (osoba == 0){
                w = GEN::losujOdZeraDo(w_max);
                k = GEN::losujOdZeraDo(k_max);
                starczy++;
            }
            k_temp = k;
            w_temp = w;
            zlaPozycja=0;
            if(starczy==100) { exit(0);}
            for(int i=0;i<ilosc;i++)
            {
                var = czyNaPolu(tab,w_temp,k_temp,w_max,k_max);
                if(var==0) zlaPozycja=1;
                k_temp--;
                w_temp++;
            }
        }
        for(int i=0;i<ilosc;i++){
            umiesc(tab,w,k,w_max,k_max);
            k--;
            w++;
        }
    }
}


