#include <iostream>
#include "headers/sistemaDarkSide.h"

Civilizacao::Civilizacao(){
    //this->planeta="0000000000";
    this->distancia = 0;
    this->populacao = 0;

}

Civilizacao::Civilizacao(char planeta[],int distancia,int populacao){
    //planeta=_planeta;
    
    for(int i=0;i<11;i++){
        this->planeta[i]=planeta[i];
        //std::cout << planeta[i]<<" : "<<this->planeta[i] <<std::endl;
    }
    
    //std::cout <<" CABO "<<planeta<<" : "<<this->planeta<<std::endl;
    //this->planeta = planeta;
    this->distancia = distancia;
    this->populacao = populacao;
    

}

char* Civilizacao::GetPlaneta(){
    return this->planeta;
}

int Civilizacao::GetDistancia(){
    return this->distancia;
}

int Civilizacao::GetPopulacao(){
    return this->populacao;
}


void Civilizacao::Imprime(){    
    std::cout << this->planeta <<" "<< this->distancia <<" "<< this->populacao<<std::endl;
}



