#include "Civilizacao.h"
#include <iostream>


Civilizacao::Civilizacao()
{
    Nome="";
    Populacao = 0;
    Distancia = 0;
    
}

Civilizacao::~Civilizacao()
{
}
 std::string Civilizacao::GetNome(){
    return Nome;
    
}
void Civilizacao::SetNome(std::string nome){
    Nome=nome;
}
int Civilizacao::GetDistancia(){
    return Distancia;
}
void Civilizacao::SetDistancia(int distancia){
    Distancia = distancia;
}
int Civilizacao::GetPopulacao(){
    return Populacao;
}
void Civilizacao::SetPopulacao(int populacao){
    Populacao=populacao;
}
void Civilizacao::Imprimir(){
    std::cout<<Nome<<" "<<Distancia<<" "<<Populacao<<std::endl;
}