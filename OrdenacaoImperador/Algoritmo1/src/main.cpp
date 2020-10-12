#include <iostream>
#include <string>
#include <vector>
#include "Civilizacao.h"

using namespace std;
void swap(Civilizacao *a, Civilizacao *b);
void bubblesort(vector<Civilizacao>&c, int num);
int main() {
  
    string n; //n->nome da civilizacao
    int d; //distancia da civilizacao
    int p; //populacao da civilizacao
    vector <Civilizacao> civilizacoes;
    int num{}; //num-> numero de civilizacoes
    cin>>num;
    //lendo cada civilizacao e adicionando no vector 
    for(int i=0; i<num; ++i){
        Civilizacao c1;
        cin>>n>>d>>p;
        c1.SetNome(n);
        c1.SetDistancia(d);
        c1.SetPopulacao(p);
        civilizacoes.push_back(c1);
    }
    
    bubblesort(civilizacoes, num);
    for (auto c : civilizacoes){
        c.Imprimir();
    }
    return 0;
}
void swap(Civilizacao *a, Civilizacao *b){
    Civilizacao tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubblesort(vector<Civilizacao> &c, int num){
    int i, j;
    for(i=0; i<num-1; i++){
        for(j=0; j<num-i-1; j++){
            if(c[j].GetDistancia()==c[j+1].GetDistancia()){
                if(c[j].GetPopulacao()<c[j+1].GetPopulacao()){
                   swap(&c[j], &c[j+1]);
                }
            }
            if(c[j].GetDistancia() > c[j+1].GetDistancia()){
                swap(&c[j],&c[j+1]);
            }
        }
    }
}