#ifndef CIVILIZACAO
#define CIVILIZACAO

#include <string>

class Civilizacao{
    private:
        char planeta[11];
        int distancia;
        int populacao;
    public:
        Civilizacao();
        Civilizacao(char planeta[],int distancia,int populacao);
        char* GetPlaneta();
        int GetDistancia();
        int GetPopulacao();
        void Imprime();   
};

#endif