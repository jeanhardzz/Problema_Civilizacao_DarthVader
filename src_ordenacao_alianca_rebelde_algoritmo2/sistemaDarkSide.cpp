#include <iostream>
#include "headers/sistemaDarkSide.h"


SistemaDarkSide::SistemaDarkSide(int num_civilizacoes){
  this->num_civilizacoes = num_civilizacoes;  
}

void SistemaDarkSide::AdicionaCivilizacao(char planeta[], int distancia, int populacao){  
  Civilizacao c(planeta,distancia,populacao);  
  civilizacoes.push_back(c);    
}

void SistemaDarkSide::ImprimeCivilizacoes(){
  for (Civilizacao c : civilizacoes){    
    c.Imprime();    
  }
}

void SistemaDarkSide::Ordena(){  
    int esq, dir;
    Civilizacao x;
    Constroi(); /* constroi o heap */    
    esq = 1; dir = num_civilizacoes;
    while (dir > 1){ /* ordena o vetor */        
        x = civilizacoes[0];
        civilizacoes[0] = civilizacoes[dir-1];
        civilizacoes[dir-1] = x;
        dir--;
        Refaz(esq, dir);
    }      
}

void SistemaDarkSide::Constroi(){
  int Esq;    
  Esq = num_civilizacoes / 2 + 1;
  while (Esq > 1) {
      Esq--;
      Refaz(Esq, num_civilizacoes);
  }

}
void SistemaDarkSide::Refaz(int esq, int dir){
  int i, j;
  Civilizacao x;
  i = esq;  
  j = i * 2;
  x = civilizacoes[i-1];
  while (j <= dir){
      if (j < dir){      
          if ((civilizacoes[j-1].GetDistancia() < civilizacoes[j+1-1].GetDistancia()) || ((civilizacoes[j-1].GetDistancia() == civilizacoes[j+1-1].GetDistancia()) && (civilizacoes[j-1].GetPopulacao() > civilizacoes[j+1-1].GetPopulacao()))){
              j++;
          } 
      }      
      if ((x.GetDistancia() > civilizacoes[j-1].GetDistancia()) || ((x.GetDistancia() == civilizacoes[j-1].GetDistancia()) && (x.GetPopulacao() < civilizacoes[j-1].GetPopulacao()))){          
          break;
      }
     
      
      civilizacoes[i-1] = civilizacoes[j-1];
      i = j;
      j = i *2;
  }
  civilizacoes[i-1] = x;  
}

