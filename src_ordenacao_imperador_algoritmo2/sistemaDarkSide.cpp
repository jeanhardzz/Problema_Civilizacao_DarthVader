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
  
  int i,j;
  Civilizacao aux;
    for (i = 1; i < num_civilizacoes; i++) {
        aux = civilizacoes[i];
        j = i - 1;
        while (( j >= 0 ) && (aux.GetDistancia() < civilizacoes[j].GetDistancia())) {            
              civilizacoes[j + 1] = civilizacoes[j];
              j--;                        
        }        
        civilizacoes[j + 1] = aux;
    }
    for (i = 1; i < num_civilizacoes; i++) {
        aux = civilizacoes[i];
        j = i - 1;
        while (( j >= 0 ) && (aux.GetDistancia() == civilizacoes[j].GetDistancia()) && (aux.GetPopulacao() > civilizacoes[j].GetPopulacao())) {                          
                civilizacoes[j + 1] = civilizacoes[j];
                j--;              
        }        
        civilizacoes[j + 1] = aux;
    }
}


