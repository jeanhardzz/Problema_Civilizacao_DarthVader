#include <iostream>
#include "headers/sistemaDarkSide.h"


SistemaDarkSide::SistemaDarkSide(int num_civilizacoes){
  this->num_civilizacoes = num_civilizacoes;  
}

void SistemaDarkSide::AdicionaCivilizacao(char planeta[], int distancia, int populacao){  
  Civilizacao c(planeta,distancia,populacao);  
  civilizacoes.push_back(c);
  
  //c.Imprime();
}

void SistemaDarkSide::ImprimeCivilizacoes(){
  for (Civilizacao c : civilizacoes){    
    c.Imprime();
  }
}

void SistemaDarkSide::Ordena(){
  
  int i, j, min;
    for (i = 0; i < num_civilizacoes - 1; i++){
        min = i;
        for (j = i + 1 ; j < num_civilizacoes; j++){
            if (civilizacoes[j].GetDistancia() < civilizacoes[min].GetDistancia()){
              min = j;
            }else if (civilizacoes[j].GetDistancia() == civilizacoes[min].GetDistancia()){
                if (civilizacoes[j].GetPopulacao() > civilizacoes[min].GetPopulacao()){
                  min = j;
                }
              }
            
        }
        //Troca(v[i], v[Min]);
        Civilizacao aux = civilizacoes[i];
        civilizacoes[i]=civilizacoes[min];
        civilizacoes[min]=aux;
    }
    
    
}


