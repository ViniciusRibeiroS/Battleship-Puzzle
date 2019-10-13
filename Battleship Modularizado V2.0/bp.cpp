#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include "bp.h"

int main(int argc, char** argv)
{
  int linhas = std::stoi( argv[2]);
  int colunas= std::stoi( argv[3]);
  int dimensoes = linhas * colunas;
  char map_gabarito[dimensoes];

  linha_colunas_qntpuzzles( argc, argv);

  preenchercopia(map_gabarito, dimensoes);
  
  if (linhas < 10)
  jogar_menor10(dimensoes, colunas, map_gabarito);

  if (linhas >=10)
  jogar_maior10( dimensoes, colunas, map_gabarito);
   
  return 0;   
}
