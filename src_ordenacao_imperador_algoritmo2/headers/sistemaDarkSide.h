#ifndef SISTEMA_DARKSIDE
#define SISTEMA_DARKSIDE

#include "civilizacao.h"
#include <string>
#include <vector>

class SistemaDarkSide{
    private:
        int num_civilizacoes=0;
        std::vector<Civilizacao> civilizacoes;
    public:
        SistemaDarkSide(int num_civilizacoes);
        void AdicionaCivilizacao(char planeta[], int distancia, int populacao); 
        void ImprimeCivilizacoes();
        void Ordena();
};

#endif