#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
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
void swap(Civilizacao *a, Civilizacao *b){
    Civilizacao tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(vector<Civilizacao> &c, int n) { 
    int i, j, min; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) { 
        // Find the minimum element in unsorted array 
        min = i; 
        for (j = i+1; j < n; j++) {
          if(c[j].GetDistancia()==c[min].GetDistancia()){
              if(c[j].GetPopulacao()>c[min].GetPopulacao())
                swap(&c[min],&c[j]);
          }
          if (c[j].GetDistancia() < c[min].GetDistancia()) 
            min = j; 
        }
        // Swap the found minimum element with the first element 
        swap(&c[min], &c[i]); 
    } 
}
