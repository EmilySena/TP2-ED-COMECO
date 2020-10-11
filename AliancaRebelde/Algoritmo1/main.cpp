#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
#include "Civilizacao.h"

using namespace std;
void swap(Civilizacao *a, Civilizacao *b);
void quickSort(vector<Civilizacao>&c, int low, int high);
int partition (vector<Civilizacao>&c, int low, int high);
int main() {

   // clock_t start, end; 
    
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
    
    //start = clock();
    quickSort(civilizacoes, 0,num-1);
    //end = clock(); 
    for (auto c : civilizacoes){
        c.Imprimir();
    }
   // double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
   /* cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; */

    return 0;
}
void swap(Civilizacao *a, Civilizacao *b){
    Civilizacao tmp = *a;
    *a = *b;
    *b = tmp;
}
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (vector<Civilizacao>&c, int low, int high)  
{  
    Civilizacao pivot = c[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (c[j].GetDistancia() < pivot.GetDistancia())  
        {  
            i++; // increment index of smaller element  
            swap(&c[i], &c[j]);  
        }  
    }  
    swap(&c[i + 1], &c[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(vector<Civilizacao>&c, int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(c, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(c, low, pi - 1);  
        quickSort(c, pi + 1, high);  
    }  
}  
  
