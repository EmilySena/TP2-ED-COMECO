#include <iostream>
#include <string>
#include <vector>
#include "Civilizacao.h"

using namespace std;
void swap(Civilizacao *a, Civilizacao *b);
void selectionSort(vector<Civilizacao>&c, int num);
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

    selectionSort(civilizacoes, num);

    for (auto c : civilizacoes){
        c.Imprimir();
    }
    return 0;
}
void swap(Civilizacao *a, Civilizacao *b){ //função para trocar a posição de duas civilizacoes no vector
    Civilizacao tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(vector<Civilizacao> &c, int n) {
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        // achar o minimo elemento no vector desordenado
        min = i;
        for (j = i+1; j < n; j++) {
          if(c[j].GetDistancia()==c[min].GetDistancia()){ //se a distancia for igual verificar a segunda chave
              if(c[j].GetPopulacao()>c[min].GetPopulacao()) //colocando o que tiver a maior populacao antes
                swap(&c[min],&c[j]);
          }
          if (c[j].GetDistancia() < c[min].GetDistancia())
            min = j;
        }
        // Troca o elemento minimo que foi achado pelo primeiro elemento do array
        swap(&c[min], &c[i]);
    }
}
