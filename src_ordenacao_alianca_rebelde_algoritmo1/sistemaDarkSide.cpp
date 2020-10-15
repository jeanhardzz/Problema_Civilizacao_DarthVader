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
    //save = save + c.GetPlaneta() + " " + std::to_string(c.GetDistancia()) + " " + std::to_string(c.GetPopulacao()) +"\n";
  }
}

void SistemaDarkSide::Ordena(){
  RecursivoDistancia(0,num_civilizacoes-1);  
  //RecursivoPopulacao(0,num_civilizacoes-1);
}

void SistemaDarkSide::RecursivoDistancia(int esq,int dir){
    int i, j;
    ParticaoDistancia(esq,dir,&i,&j);
    if(esq<j){
        RecursivoDistancia(esq,j);
    }
    if(i<dir){
        RecursivoDistancia(i,dir);
    }
}

void SistemaDarkSide::ParticaoDistancia(int esq,int dir, int *i,int *j){
    Civilizacao x, w;
    *i = esq; *j = dir;
    x = civilizacoes[(*i + *j)/2]; /* obtem o pivo x */
    //x.distancia > A[*i].distancia || (x.distancia == A[*i].distancia && x.populacao < A[*i].populacao)
    do{
        //std::cout<<"i: "<<*i<<" j:"<< *j<<std::endl;
        while ((x.GetDistancia() > civilizacoes[*i].GetDistancia()) || ((x.GetDistancia() == civilizacoes[*i].GetDistancia()) && (x.GetPopulacao() < civilizacoes[*i].GetPopulacao())) ){        
          (*i)++;          
        } 
        while ((x.GetDistancia() < civilizacoes[*j].GetDistancia()) || ((x.GetDistancia() == civilizacoes[*j].GetDistancia()) && (x.GetPopulacao() > civilizacoes[*j].GetPopulacao())) ){          
          (*j)--;          
        }
        /*
        while (x.GetDistancia() > civilizacoes[*i].GetDistancia()) (*i)++;
        while (x.GetDistancia() < civilizacoes[*j].GetDistancia()) (*j)--;
        */
        if (*i <= *j){  
          /*
          if(civilizacoes[*i].GetDistancia() == civilizacoes[*j].GetDistancia()){
            if(civilizacoes[*i].GetPopulacao() < civilizacoes[*j].GetPopulacao()){
              w = civilizacoes[*i];
              civilizacoes[*i] = civilizacoes[*j];
              civilizacoes[*j] = w;
              (*i)++;
              (*j)--;
            }else{
              (*i)++;
              (*j)--;
            }
          }else{
            w = civilizacoes[*i];
            civilizacoes[*i] = civilizacoes[*j];
            civilizacoes[*j] = w;
            (*i)++;
            (*j)--;
          }
        */
        w = civilizacoes[*i];
        civilizacoes[*i] = civilizacoes[*j];
        civilizacoes[*j] = w;
        (*i)++;
        (*j)--;       
          
      }
    }
    while (*i <= *j);
}

void SistemaDarkSide::RecursivoPopulacao(int esq,int dir){
    int i, j;
    ParticaoPopulacao(esq,dir,&i,&j);
    if(esq<j){
        RecursivoPopulacao(esq,j);
    }
    if(i<dir){
        RecursivoPopulacao(i,dir);
    }
}

void SistemaDarkSide::ParticaoPopulacao(int esq,int dir, int *i,int *j){
    Civilizacao x, w;
    *i = esq; *j = dir;
    x = civilizacoes[(*i + *j)/2]; /* obtem o pivo x */        
    do{
        while (x.GetPopulacao() < civilizacoes[*i].GetPopulacao()) (*i)++;
        while (x.GetPopulacao() > civilizacoes[*j].GetPopulacao()) (*j)--;
        if (*i <= *j){
            if(civilizacoes[*i].GetDistancia() == civilizacoes[*j].GetDistancia()){
              w = civilizacoes[*i];
              civilizacoes[*i] = civilizacoes[*j];
              civilizacoes[*j] = w;
            }            
            (*i)++;
            (*j)--;
        }
    }
    while (*i <= *j);
}

