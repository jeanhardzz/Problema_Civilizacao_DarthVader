/*
References
http://www.cplusplus.com/doc/tutorial/files/
https://pt.stackoverflow.com/questions/33032/quero-gravar-as-informa%C3%A7%C3%B5es-em-um-txt-em-c
https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
*/

#include <iostream>
#include <time.h> //medir o tempo 
#include <iomanip> // std::setprecision
#include <fstream> // file 
#include "headers/civilizacao.h"
#include "headers/sistemaDarkSide.h"


int main(){  
  /*
    *Inicializando as civilizacoes pela stdin
  */ 
  int num_civilizacoes;

  std::cin>>num_civilizacoes;
  SistemaDarkSide Vader(num_civilizacoes);
    
  char planeta[11];
  int  distancia, populacao;
  while(std::cin>>planeta>>distancia>>populacao){         
    Vader.AdicionaCivilizacao(planeta,distancia,populacao);    
    
  }

  /*
    *Medindo o tempo de execucao do programa para ordenar
  */
    clock_t start, end;     
    start = clock();   //iniciando contagem       

    Vader.Ordena(); //ordenando

    end = clock(); //fechando contagem
 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); // Calculando tempo.
    
    /*
      *Salvando em um arquivo para posterior analise.
    */
   
    std::fstream file;   
    file.open("tempo.txt",std::ios::app);         
    file << std::fixed << time_taken << std::setprecision(5) << " sec " << std::endl; 
    file.close();
    


    /*
      *Imprimindo saida.
    */
    Vader.ImprimeCivilizacoes();
  return 0;
}
