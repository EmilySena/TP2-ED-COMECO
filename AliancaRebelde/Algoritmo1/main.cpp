#include <iostream>
#include <string>
#include <vector>
#include "Civilizacao.h"

using namespace std;
void swap(Civilizacao *a, Civilizacao *b);
void quickSort(vector<Civilizacao>&c, int low, int high);
int partition (vector<Civilizacao>&c, int low, int high);
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
    quickSort(civilizacoes, 0,num-1);
    for (auto c : civilizacoes){
        c.Imprimir();
    }
    return 0;
}
void swap(Civilizacao *a, Civilizacao *b){ //função de troca
    Civilizacao tmp = *a;
    *a = *b;
    *b = tmp;
}
/* A função partition (partição) pega o ultimo elemento como pivot, coloca
coloca o pivot na sua posição correta no vector ordenado, e coloca o elemento menor
(menor que o pivot) à esquerda do pivot, e todos os elementos maiores ficam à
direita do pivot */
int partition (vector<Civilizacao>&c, int low, int high) {
    Civilizacao pivot = c[high]; // pivot
    int i = (low - 1); // index do menor elemento

    for (int j = low; j <= high - 1; j++){
        // se o elemento atual é menor que o pivot
        if (c[j].GetDistancia() < pivot.GetDistancia()||(c[j].GetDistancia() == pivot.GetDistancia() && c[j].GetPopulacao()>pivot.GetPopulacao())){
          //if para verificar a primeira chave(distancia), e no caso de ser igual, verificar a segunda(populacao)
            i++; // incrementa o index do menor elemento
            swap(&c[i], &c[j]);
        }
    }
    swap(&c[i + 1], &c[high]);
    return (i + 1);
}

/*low -->  index inicial,
high --> index final */
void quickSort(vector<Civilizacao>&c, int low, int high) {
    if (low < high) {
        /* pi é um index particional */
        int pi = partition(c, low, high);

        // chamando o quickSort recursivamente
        // partição(partition) depois de partição
        quickSort(c, low, pi - 1);
        quickSort(c, pi + 1, high);
    }
}
