#include <iostream>
#include <string>
#include <vector>
#include "Civilizacao.h"

using namespace std;
int main() {
  
    string n; //n->nome da civilizacao
    int d; //distancia da civilizacao
    int p; //populacao da civilizacao
    vector <Civilizacao> civilizacoes;
    int num{};
    cin>>num;
    for(int i=0; i<num; ++i){
        Civilizacao c1;
        cin>>n>>d>>p;
        c1.SetNome(n);
        c1.SetDistancia(d);
        c1.SetPopulacao(p);
        civilizacoes.push_back(c1);
    }
    cout<<"----------"<<endl;
    for (auto c : civilizacoes){
        c.Imprimir();
    }
    return 0;
}