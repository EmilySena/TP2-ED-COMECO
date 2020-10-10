#include <string>
#ifndef CIVILIZACAO_H
#define CIVILIZACAO_H

class Civilizacao{
private:
    std::string Nome;
    int Distancia;
    int Populacao;

public:
    Civilizacao();
    virtual ~Civilizacao();
    std::string GetNome();
    int GetDistancia();
    int GetPopulacao();
    void SetNome(std::string nome);
    void SetDistancia(int distancia);
    void SetPopulacao(int populacao);
    void Imprimir();

};

#endif // CIVILIZACAO_H