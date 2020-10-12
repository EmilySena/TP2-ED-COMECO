#include <iostream>
#include <string>
#include <vector>
#include "Civilizacao.h"

using namespace std;
void swap(Civilizacao *a, Civilizacao *b);
void heapSort(vector<Civilizacao>&c, int num);
void heapify (vector<Civilizacao>&c, int n, int i);
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
    heapSort(civilizacoes, num);
    for (auto c : civilizacoes){
        c.Imprimir();
    }

    return 0;
}
void swap(Civilizacao *a, Civilizacao *b){ //funçao para trocar as posições das civilizações no vector
    Civilizacao tmp = *a;
    *a = *b;
    *b = tmp;
}
//heapify uma sub-árvore enraizada no node i
// n é o tamanho do heap
void heapify( vector<Civilizacao>&c, int n, int i)
{
    int largest = i; // Inicializa o maior (largest) como a raiz
    int l = 2*i + 1; // Esquerda -> l de left = 2*i + 1
    int r = 2*i + 2; //Direita -> r de right = 2*i + 2

    // Se o filho da esquerda (left) é maior que a raiz
    if (l < n && c[l].GetDistancia() > c[largest].GetDistancia())
        largest = l;
        else if(l<n && c[l].GetDistancia()==c[largest].GetDistancia()){ //verificando a segunda chave, caso as distancias sejam iguais
              if(c[l].GetPopulacao()<c[largest].GetPopulacao()){
                  largest = l;
              }
          }
    // Se o filho da direita é maior que o maior (largest) até agora
    if (r < n && c[r].GetDistancia() > c[largest].GetDistancia())
        largest = r; //maior = direita
        else if(r<n && c[r].GetDistancia()==c[largest].GetDistancia()){ //verificando a segunda chave, caso as distancias sejam iguais
              if(c[r].GetPopulacao()<c[largest].GetPopulacao()){
                  largest = r; //maior = direita
              }
          }
    // Se o maior (largest) não é a raiz
    if (largest != i) {
        swap(&c[i], &c[largest]);
        // Recursivamente chamando heapify para a sub-árvore afetada
        heapify(c, n, largest);
    }
}
void heapSort(vector<Civilizacao>&c, int n) {
    // Construir o heap (vector reorganizado)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(c, n, i);

    // Extraindo um a um, um elemento do heap
    for (int i=n-1; i>0; i--) {
        // Move a raiz atual para o final
        swap(&c[0], &c[i]);

        // chama max heapify no heap reduzido
        heapify(c, i, 0);

    }
}
