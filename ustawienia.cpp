#include "ustawienia.h"
#include <stdlib.h>
void ustawienia::stworzPole()
{
    vector <int> num(kolumny,0);
    for(int i=0; i<wiersze;i++)
    {
        tab.push_back(num);
    }
}

void ustawienia::wyswietl2(){
    cout << "-  ";
    
    for(int i=0;i<tab[0].size();i++)
    {
        cout << char(65+i)<< " ";
    }
    cout << std::endl;
    for(int i=0;i<tab.size();i++){
        if (i+1>=10) cout <<1+i <<" ";
        else cout <<1+i <<"  ";
        for (int j=0;j<tab[0].size();j++){
            switch(tab[i][j]){
                case 1:
                    cout << "S ";
                    break;
                case 2:
                    cout << "+ ";
                    break;
                case 3:
                    cout << "X ";
                    break;
                case 4:
                    cout << "- ";
                    break;
                case 5:
                    cout << "X ";
                    break;
                case 6:
                    cout << "- ";
                    break;
                default:
                    cout <<"0 ";
                    break;
            }
            
        }
        cout << std::endl;
    }
}

#include "statki.h"
void strzaly::strzal(vector < vector<int> > & tab, vector < vector<int> > & tab_strzaly, int w, int k, int &counter,int w_max,int k_max)
{
    statki s;
    if(tab[w][k]==1){
        tab_strzaly[w][k] = 3;
        tab[w][k]=5;
        bool var = s.czyOtoczenie(tab,w,k,w_max,k_max);
        if(var == 0){ cout << "Zniszczono statek!" <<endl;
                    counter++;}
    }
    else{
        tab_strzaly[w][k] = 4;
        tab[w][k]=6;}
}
bool strzaly::czyStrzal(vector < vector<int> > & tab_strzaly, int w, int k,int w_max, int k_max){
    bool var = 1;
    if (w<0 || k<0 || w>w_max || k>k_max) var = 0;
    else if (tab_strzaly[w][k] == 3 || tab_strzaly[w][k] == 4) var = 0;
    return var;
}


