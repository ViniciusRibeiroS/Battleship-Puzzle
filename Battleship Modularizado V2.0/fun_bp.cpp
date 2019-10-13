#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <random>
#include <cstdio>
#include <string>
#include "bp.h"


/*Remove o arquivo onde armazeno as cordenadas para evitar sobreposição de puzzles*/
void Limpar_arq()
{
  remove("Gabarito.txt");
}

void Limpar_gabarito()
{
  remove("BSPgabarito.txt");
}

/*Recebo os argumentos da função para a criação dos puzzles*/
void linha_colunas_qntpuzzles(int argc, char** argv)
{

  int linhas;  //Quantidade de Linha
  int colunas; //Quantidade de Colunas
  int qtd_puzzles; //Quantidade de Puzzles
  
  
  /*Chegarem da entrada do usuário*/
  if(argc == 0)
  {
    std::cerr << "Infelizmente voce não passou a parametragem correta, por favor ler README.TXT\n";
  }
  
  if(argc == 1)
  {
    std::cerr << "Infelizmente voce não passou a parametragem correta, por favor ler README.TXT\n";
  }

  if(argc == 2)
  {
   qtd_puzzles = std::stoi( argv[1]);
   linhas = 10;//std::stoi( argv[2]);
   colunas = 10;//std::stoi( argv[3]);
   std::cerr << "Pelo Padrão os Puzzles serão de 10x10\n";
  }

  if(argc == 3)
  {
    std::cerr << "Nessa versão ainda não estamos trabalhando com matrizes não quadraticas\n";
  }
  
  /*Se tudo der certo ele chama a função de construir os puzzles*/
  if(argc == 4)
  {
    Limpar_arq();
    Limpar_gabarito();
    if(std::stoi( argv[2]) == std::stoi( argv[3]) && std::stoi( argv[2]) > 6 && std::stoi( argv[2]) < 16)
    { 
     qtd_puzzles = std::stoi( argv[1]);
     linhas = std::stoi( argv[2]);
     colunas = std::stoi( argv[3]);
     std::cout << "Parametragem correta, Executando Programa\n";
     Construcao(linhas, colunas, qtd_puzzles); 
    }

    else
      std::cerr << "Nessa versão ainda não estamos trabalhando com matrizes não quadraticas\n";
  }
}

/*Construção dos Puzzles*/
void Construcao(int linhas, int colunas, int qtd_puzzles)
{
  std::cout << std::endl;

  std::cout << " <<<<<<<<<<<<<<< Project  Batleship >>>>>>>>>>>>" << std::endl
  << "Instruções:" << std::endl
  << " - Só são aceitas matrizes quadraticas nessa versão 2.0" << std::endl
  << " - Minimo de 7 a 15" << std::endl << " - Divirta - se" << std::endl
  << std::endl
  <<"Vinicius Ribeiro & Thyall Dgreville " << std::endl;

  if(linhas != colunas)
    std::cerr << "Nao operamos com matrizes ão quadraticas nessa versão ainda";

  std::cout << std::endl;
  
  int sorteado = get_puzzle(qtd_puzzles);

  for(int i = 0; i < qtd_puzzles; ++i)
  {
   int dimensoes = linhas * colunas;
   
   char map_battle[linhas * colunas];

   Preencher(map_battle, dimensoes); 
   
   //Caso seja uma 10x10 até 15x15 serão colocados todos os barcos
   if(colunas >= 10)
   {
   run(map_battle, dimensoes, colunas, linhas);
   }
   
   //Caso seja menor que uma 10x10 serão colocados uma quantidade menor de barcos
   if(colunas < 10)
   {
   run_menor10(map_battle, dimensoes, colunas, linhas);
   }
   
   limpar(map_battle, dimensoes);

   //Printar_arq(map_battle, dimensoes,qtd_puzzles);

   if (i == sorteado)
   {
     armazenarpuzzle(map_battle, dimensoes, colunas);
   }
       
   std::cout << i << std::endl;
   Printar(map_battle, dimensoes, colunas);
   std::cout << std::endl;

  } 
}

/*Função onde ocorre a checagem de como serão dispostos os barcos, na horizontal ou vertical*/
void run(char *map_battle, int dimensoes, int colunas, int linhas)
{
   int lado[6];  

   for (int i = 0; i < 6; ++i) 
   {
     lado[i] = set_boat(dimensoes);
   }

   if(lado[0] % 2 == 0)
   {
   Battleship(map_battle, dimensoes, colunas);
   cond_battleship(map_battle, dimensoes, colunas);
   }

   else
   {
   Battleship_v(map_battle, dimensoes, colunas, linhas);
   cond_batttleship_V(map_battle, dimensoes, colunas, linhas);
   }

   if(lado[1] % 2 == 0)
   {
    Cruiser(map_battle, dimensoes, colunas);
    cond_cruiser(map_battle, dimensoes, colunas);
   }

   else 
   {
    Cruiser_V(map_battle, dimensoes, colunas, linhas);
    cond_cruiser_V(map_battle, dimensoes, colunas, linhas);
   } 
      if(lado[2] % 2 == 0)
   {
    Cruiser(map_battle, dimensoes, colunas);
    cond_cruiser(map_battle, dimensoes, colunas);
   }

   else 
   {
    Cruiser_V(map_battle, dimensoes, colunas, linhas);
    cond_cruiser_V(map_battle, dimensoes, colunas, linhas);
   }


  if(lado[3] % 2 == 0 )
  {      
    Destroyer(map_battle, dimensoes, colunas);
    cond_destroyer(map_battle, dimensoes, colunas);           
  }
  else
  {
    Destroyer_V(map_battle, dimensoes, colunas, linhas);
    cond_destroyer_V(map_battle, dimensoes, colunas, linhas); 
  }

  if(lado[4] % 2 == 0 )
  {     
    Destroyer(map_battle, dimensoes, colunas);
    cond_destroyer(map_battle, dimensoes, colunas);          
  }
  else
  {
    Destroyer_V(map_battle, dimensoes, colunas, linhas);
    cond_destroyer_V(map_battle, dimensoes, colunas, linhas); 
  }

    if(lado[5] % 2 == 0 )
  {     
    Destroyer(map_battle, dimensoes, colunas);
    cond_destroyer(map_battle, dimensoes, colunas);          
  }
  else
  {
    Destroyer_V(map_battle, dimensoes, colunas, linhas);
    cond_destroyer_V(map_battle, dimensoes, colunas, linhas); 
  }

  for(int i = 0; i < 4; ++i)
  {
  Submarino(map_battle, dimensoes);
  cond_submarino(map_battle, dimensoes, colunas, linhas);
  }
}

/*Disposição dos barcos na horizonal ou vertical em menor quantidade*/
void run_menor10(char *map_battle, int dimensoes, int colunas, int linhas)
{
   int lado[3];  

   for (int i = 0; i < 3; ++i) 
   {
     lado[i] = set_boat(dimensoes); 
   }

   if(lado[0] % 2 == 0)
   {
   Battleship(map_battle, dimensoes, colunas);
   cond_battleship(map_battle, dimensoes, colunas);
   }

   else
   {
   Battleship_v(map_battle, dimensoes, colunas, linhas);
   cond_batttleship_V(map_battle, dimensoes, colunas, linhas);
   }

   if(lado[1] % 2 == 0)
   {
    Cruiser(map_battle, dimensoes, colunas);
    cond_cruiser(map_battle, dimensoes, colunas);
   }

   else 
   {
    Cruiser_V(map_battle, dimensoes, colunas, linhas);
    cond_cruiser_V(map_battle, dimensoes, colunas, linhas);
   } 

  if(lado[2] % 2 == 0 )
  {      
    Destroyer(map_battle, dimensoes, colunas);
    cond_destroyer(map_battle, dimensoes, colunas);           
  }
  else
  {
    Destroyer_V(map_battle, dimensoes, colunas, linhas);
    cond_destroyer_V(map_battle, dimensoes, colunas, linhas); 
  }

  for(int i = 0; i < 2; ++i)
  {
  Submarino(map_battle, dimensoes);
  cond_submarino(map_battle, dimensoes, colunas, linhas);
  }
}

/*Função para chamar aleatoriamente a condicional do barco*/
int set_boat(int dimensoes)
{
 std::random_device rd;
 
 std::mt19937_64 gen(rd());

 std::uniform_int_distribution < unsigned long long > dis;

 return dis(gen) % dimensoes + 1;
}

/*Função para pegar uma posição aleatoria para o barco naquele puzzle*/
int get_posision(int dimensoes)
{
 std::random_device rd;
 
 std::mt19937_64 gen(rd());

 std::uniform_int_distribution < unsigned long long > dis;

 return dis(gen) % dimensoes + 1;
}

/*Pego uma posição para o submarino com a restrição que aquela posição não pode existir barco*/
void Submarino(char *tabuleiro, int dimensoes)
{
  int Submarino = get_posision(dimensoes);

  while(tabuleiro[Submarino] != '=')
    Submarino = get_posision(dimensoes);

  tabuleiro[Submarino] = 'S';
}

/*Bloqueio todas as posições ao redor daquele submarino com as devidas restrições para cada posição*/
void cond_submarino(char *tabuleiro, int dimensoes, int colunas, int linhas)
{
  int vdd = 0;

  int i = 1;

  while(vdd != 1)
  {
    for(i = 1; i < dimensoes + 1; ++i)
   {
      if(tabuleiro[i] == 'S')
      {
        //Primeira Posição
        if(i == 1)
        { 
          tabuleiro[i + 1] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
        
        //Meio da Primeira Linha
        if(i > 1 && i < colunas)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da Primeira Linha
        if(i == colunas)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + colunas] = '!';
          vdd = 1;
        }
        
        //Borda da Esquerda
        if(i > colunas && i % colunas == 1 && i < linhas * (colunas-1) + 1)
        { 
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
        
        //Borda da Direita
        if(i > colunas && i % colunas == 0 && i < linhas * (colunas-1) + 1)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da Esquerda
        if(i % colunas == 1 && i == linhas * (colunas-1) + 1)
        { 
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          vdd = 1;
        }

        //Meio da Ultima Linha
        if(i % colunas != 0 && i % colunas != 1 && i + colunas > dimensoes)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i - colunas] = '!';
          vdd = 1;
        }

        //Ultima Posição da Direita
        if(i % colunas == 0 && i == dimensoes && i + colunas > dimensoes)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          vdd = 1;
        }

        //Meio
        if(i > colunas && i != 1 && i != colunas && i % colunas != 1 && i % colunas != 0 && i < linhas *(colunas - 1) + 1)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
      }//Tabuleiro[i]
    }//Dimensões
  }//While
}

/*Pego uma posição para o Destroyer Horizontal garantindo que as duas casas não estarão ocupadas e com a restrição que ele nunca saia 'quebrado' em linhas diferentes*/
void Destroyer(char *tabuleiro, int dimensoes, int colunas)
{
  
  int Destroyer;

  int vdd = 0;

  while(vdd != 1)
  {
    Destroyer = get_posision(dimensoes);

    if((Destroyer % colunas) != 0)
    {
      if(tabuleiro[Destroyer] == '=' && tabuleiro[Destroyer + 1] == '=')
      {
       vdd = 1; 
      }
    }
    else
      vdd = 0;
  }

  tabuleiro[Destroyer] = 'D';
  tabuleiro[Destroyer+1] = 'D';  
}

/*Bloqueio todas as posições do destroyer na horizontal com suas devidas restrições para cada posição*/
void cond_destroyer(char *tabuleiro, int dimensoes, int colunas)
{
  int vdd = 0;

  int i = 1;

  while(vdd != 1)
  {
    for(i = 1; i < dimensoes + 1; ++i)
   {
      if(tabuleiro[i] == 'D' && tabuleiro[i+1] == 'D')
      {
        //Primeira Posição
        if(i == 1)
        { 
          tabuleiro[i + 2] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          vdd = 1;
        }
         
        //Meio da Primeira Linha
        if(i != 1 && (i + 1) < colunas)
        {
          tabuleiro[i + 2] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da 1 Linha
        if(i + 1 == colunas)
        {  
          tabuleiro[i - 1] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          vdd = 1;
        }
        
        //Borda da Esquerda
        if(i% colunas == 1 && i != 1 && i + colunas < dimensoes)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 2] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          vdd = 1;
        }
        
        //Borda da Direita
        if((i + 1) % colunas == 0 && i + 1 != colunas && i + colunas < dimensoes)
        {   
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da Borda da Esquerda
        if(i % colunas == 1 && i + colunas > dimensoes)
        {
          tabuleiro[i + 2] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          vdd = 1;
        }

        //Meio da Ultima Linha
        if(i % colunas != 1 && i + colunas > dimensoes && (i+1) % colunas != 0)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i + 2] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          vdd = 1;
        }

        //Ultima Posição da Borda da Direita
        if((i + 1) % colunas == 0 && i + colunas > dimensoes)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          vdd = 1;
        }

        if(i != 1 && i > colunas && i + 1 != colunas && i % colunas != 1 && (i+1) % colunas != 0 && i + colunas < dimensoes)
        {
          tabuleiro[i + 2] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          vdd = 1;
        }
      }//tabuleiro[i] = 'D'
    }//For
  }//VDD
    
}

/*Pego uma posição para o Cruiser Horizontal garantindo que as tres casas não estarão ocupadas e com a restrição que ele nunca saia 'quebrado' em linhas diferentes*/
void Cruiser(char *tabuleiro, int dimensoes, int colunas)
{
  int vdd = 0;
  int Cruiser;

  while(vdd != 1)
  {
    Cruiser = get_posision(dimensoes);

    if(Cruiser % colunas != 0 && (Cruiser + 1) % colunas != 0)
    {
      if(tabuleiro[Cruiser] == '=' && tabuleiro[Cruiser + 1] == '=' && tabuleiro[Cruiser + 2] == '=')
      {
       vdd = 1; 
      }
    }
    else
     vdd = 0;
  }

  tabuleiro[Cruiser] = 'C'; 
  tabuleiro[Cruiser + 1] = 'C';
  tabuleiro[Cruiser + 2] = 'C';

}

/*Bloqueio todas as posições do Cruiser na horizontal com suas devidas restrições para cada posição*/
void cond_cruiser(char *tabuleiro, int dimensoes, int colunas)
{
  int vdd = 0;

  int i = 1;

  while(vdd != 1)
  {
    for(i = 1; i < dimensoes + 1; ++i)
   {
      if(tabuleiro[i] == 'C' && tabuleiro[i+1] == 'C' && tabuleiro[i+2] == 'C')
      {
        //Primeira Posição
        if(i == 1)
        { 
          tabuleiro[i + 3] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          vdd = 1;
        }
         
        //Meio da Primeira Linha
        if(i != 1 && (i + 2) < colunas)
        {
          tabuleiro[i + 3] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da 1 Linha
        if(i + 2 == colunas)
        {  
          tabuleiro[i - 1] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          vdd = 1;
        }
        
        //Borda da Esquerda
        if(i %colunas == 1 && i != 1 && i + colunas < dimensoes)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          tabuleiro[i + 3] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          vdd = 1;
        }
        
        //Borda da Direita
        if((i + 2) % colunas == 0 && i + 2 != colunas && i + colunas < dimensoes)
        {   
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da Borda da Esquerda
        if(i % colunas == 1 && i + colunas > dimensoes)
        {
          tabuleiro[i + 3] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          vdd = 1;
        }

        //Meio da Ultima Linha
        if(i % colunas != 1 && i + colunas > dimensoes && (i+2) % colunas != 0)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i + 3] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          vdd = 1;
        }

        //Ultima Posição da Borda da Direita
        if((i + 2) % colunas == 0 && i + colunas > dimensoes)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          vdd = 1;
        }

        if(i != 1 && i > colunas && i + 2 != colunas && i % colunas != 1 && (i+2) % colunas != 0 && i + colunas < dimensoes)
        {
          tabuleiro[i + 3] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          vdd = 1;
        }
      }//tabuleiro[i] = 'D'
    }//For
  }//VDD
    
}
/*Pego uma posição para o Battleship Horizontal garantindo que as quatro casas não estarão ocupadas e com a restrição que ele nunca saia 'quebrado' em linhas diferentes*/
void Battleship(char *tabuleiro, int dimensoes, int colunas)
{
  int Battleship;
  int vdd;

  while(vdd != 1)
  {
    Battleship = get_posision(dimensoes);

    if(Battleship % colunas != 0 && (Battleship + 1) % colunas != 0 && (Battleship + 2) % colunas != 0)
    {
      if(tabuleiro[Battleship] == '=' && tabuleiro[Battleship + 1] == '=' && tabuleiro[Battleship + 2] == '='
      && tabuleiro[Battleship + 2])
      {
       vdd = 1; 
      }
    }
    else
     vdd = 0;
  }

  tabuleiro[Battleship] = 'B'; 
  tabuleiro[Battleship + 1] = 'B';
  tabuleiro[Battleship + 2] = 'B';
  tabuleiro[Battleship + 3] = 'B';

}
/*Bloqueio todas as posições do Cruiser na horizontal com suas devidas restrições para cada posição*/
void cond_battleship(char *tabuleiro, int dimensoes, int colunas)
{
  int vdd = 0;

  int i = 1;

  while(vdd != 1)
  {
    for(i = 1; i < dimensoes + 1; ++i)
   {
      if(tabuleiro[i] == 'B' && tabuleiro[i+1] == 'B' && tabuleiro[i+2] == 'B' && tabuleiro[i+3] == 'B')
      {
        //Primeira Posição
        if(i == 1)
        { 
          tabuleiro[i + 4] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          tabuleiro[i + 4 + colunas] = '!';
          vdd = 1;
        }
         
        //Meio da Primeira Linha
        if(i != 1 && (i + 3) < colunas)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + 4] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          tabuleiro[i + 4 + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da 1 Linha
        if(i + 3 == colunas)
        {  
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          vdd = 1;
        }
        
        //Borda da Esquerda
        if(i % colunas == 1 && i != 1 && i + colunas < dimensoes)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          tabuleiro[i + 4 - colunas] = '!';
          tabuleiro[i + 4] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          tabuleiro[i + 4 + colunas] = '!';
          vdd = 1;
        }
        
        //Borda da Direita
        if((i + 3) % colunas == 0 && i + 3 != colunas && i + colunas < dimensoes)
        {   
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da Borda da Esquerda
        if(i % colunas == 1 && i + colunas > dimensoes)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 4] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          tabuleiro[i + 4 - colunas] = '!';
          vdd = 1;
        }

        //Meio da Ultima Linha
        if(i % colunas != 1 && i + colunas > dimensoes && (i+3) % colunas != 0)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 4] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          tabuleiro[i + 4 - colunas] = '!';
          vdd = 1;
        }

        //Ultima Posição da Borda da Direita
        if((i + 3) % colunas == 0 && i + colunas > dimensoes)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          vdd = 1;
        }

        if(i != 1 && i > colunas && (i + 3) != colunas && i % colunas != 1 && (i+3) % colunas != 0 && i + colunas < dimensoes)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i + colunas] = '!';
          tabuleiro[i + 4] = '!';
          tabuleiro[i + 4 - colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 2 + colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 2 - colunas] = '!';
          tabuleiro[i + 3 - colunas] = '!';
          tabuleiro[i + 3 + colunas] = '!';
          tabuleiro[i + 4 + colunas] = '!';
          vdd = 1;
        }
      }//tabuleiro[i] = 'D'
    }//For
  }//VDD
    
}

/*Mesma função da função Destoyer feita para a vertical*/
void Destroyer_V(char *tabuleiro, int dimensoes, int colunas, int linhas)
{
  int Destroyer;
  int vdd = 0;

  while(vdd != 1)
  {
    Destroyer = get_posision(dimensoes);

    if(Destroyer < dimensoes && Destroyer + colunas <= dimensoes)
    {
      if(tabuleiro[Destroyer] == '=' && tabuleiro[Destroyer + colunas] == '=')
      {
       vdd = 1; 
      }
    }
    else
    vdd = 0;
  } 
  
  tabuleiro[Destroyer] = 'D';
  tabuleiro[Destroyer+colunas] = 'D';  

}

/*Mesma função da função cond_destoyer feita para a vertical*/
void cond_destroyer_V(char *tabuleiro, int dimensoes, int colunas, int linhas)
{
  int vdd = 0;
  int i = 1;

  while(vdd != 1)
  {
    for(i = 1; i < dimensoes + 1; ++i)
   {
      if(tabuleiro[i] == 'D' && tabuleiro[i+colunas] == 'D')
      {
        //Primeira Posição
        if(i == 1)
        { 
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + (2*colunas)] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
         
        //Meio da Primeira Linha
        if(i != 1 && i < colunas)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + (2*colunas)] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da 1 Linha
        if(i == colunas)
        {  
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i + (2*colunas)] = '!';
          vdd = 1;
        }
        
        //Borda da Esquerda
        if(i % colunas == 1 && i != 1 && i + colunas < dimensoes && i + colunas < linhas * (colunas-1))
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + 1 + colunas ] = '!';
          tabuleiro[i + (2*colunas)] = '!';
          vdd = 1;
        }
        
        //Borda da Direita
        if(i % colunas == 0 && i + colunas < dimensoes && i > colunas)
        {   
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i + (2*colunas)] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da Borda da Esquerda
        if(i % colunas == 1 && i + colunas == linhas * (colunas-1) + 1)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }

        //Meio da Ultima Linha
        if(i % colunas != 1 && i + (2*colunas) != dimensoes && i % colunas != 0 && i + colunas > linhas * (colunas-1) + 1)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1 + (colunas)] = '!';
          vdd = 1;
        }

        //Ultima Posição da Borda da Direita
        if(i + colunas == dimensoes && i % colunas == 0)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          vdd = 1;
        }

        if(i != 1 && i % colunas != 0 && i % colunas != 1 && i > colunas && i + colunas < linhas * (colunas-1))
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + (2*colunas)] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          vdd = 1;
        }
      }//tabuleiro[i] = 'D'
    }//For
  }//VDD
    
}

/*Mesma função da função Cruiser feita para a vertical*/
void Cruiser_V(char *tabuleiro, int dimensoes, int colunas, int linhas)
{
  int Cruiser;
  int vdd = 0;

  while(vdd != 1)
  {
    Cruiser = get_posision(dimensoes);
    if(Cruiser < dimensoes && (Cruiser + colunas) < dimensoes && (Cruiser + (2* colunas)) <= dimensoes )
     {
      if(tabuleiro[Cruiser] == '=' && tabuleiro[Cruiser + colunas] == '=' && tabuleiro[Cruiser + (2 * colunas)])
      {
       vdd = 1; 
      }
    }
    else
    vdd = 0;
  }
  tabuleiro[Cruiser] = 'C';
  tabuleiro[Cruiser + colunas] = 'C'; 
  tabuleiro[Cruiser + 2 * colunas] = 'C';
}

/*Mesma função da função cond_cruiser feita para a vertical*/
void cond_cruiser_V(char *tabuleiro, int dimensoes, int colunas, int linhas)
{
  int vdd = 0;
  int i = 1;

  while(vdd != 1)
  {
    for(i = 1; i < dimensoes + 1; ++i)
   {
      if(tabuleiro[i] == 'C' && tabuleiro[i+colunas] == 'C' && tabuleiro[i+(2*colunas)] == 'C')
      {
        //Primeira Posição
        if(i == 1)
        { 
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          tabuleiro[i + (3*colunas)] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
         
        //Meio da Primeira Linha
        if(i != 1 && i < colunas)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (3*colunas)] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + (3*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da 1 Linha
        if(i == colunas)
        {  
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + (3*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i + (3*colunas)] = '!';
          vdd = 1;
        }
        
        //Borda da Esquerda
        if(i % colunas == 1 && i != 1 && i + colunas < dimensoes && i + colunas < linhas * (colunas-1)
          && i + (2*colunas) != linhas * (colunas-1) + 1)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + 1 + colunas ] = '!';
          tabuleiro[i + (3*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          vdd = 1;
        }
        
        //Borda da Direita
        if(i % colunas == 0 && i + colunas < dimensoes && i > colunas && i + (2*colunas) != dimensoes)
        {   
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i - 1 + (3*colunas)] = '!';
          tabuleiro[i + (3*colunas)] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da Borda da Esquerda
        if(i % colunas == 1 && i + (2*colunas) == linhas * (colunas-1) + 1)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          vdd = 1;
        }

        //Meio da Ultima Linha
        if(i % colunas != 1 && i + (2*colunas) != dimensoes && i + (2*colunas) > linhas * (colunas-1) + 1)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1 + (colunas)] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          vdd = 1;
        }

        //Ultima Posição da Borda da Direita
        if(i + (2*colunas) == dimensoes && i % colunas == 0)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          vdd = 1;
        }

        if(i != 1 && i % colunas != 0 && i % colunas != 1 && i > colunas && i + colunas < linhas * (colunas-1)
           && i + (2*colunas) < linhas * (colunas -1) + 1)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 +(3*colunas)] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + (3*colunas)] = '!';
          tabuleiro[i + 1 +(3*colunas)] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          vdd = 1;
        }
      }//tabuleiro[i] = 'D'
    }//For
  }//VDD
    
}

/*Mesma função da função battleship feita para a vertical*/
void Battleship_v(char *tabuleiro, int dimensoes, int colunas, int linhas)
{
  
  int Battleship;
  int vdd = 0;

  while(vdd != 1)
  {
    Battleship = get_posision(dimensoes);

    if(Battleship < dimensoes && Battleship + colunas < dimensoes && Battleship + (2*colunas) < dimensoes && 
       Battleship + (3*colunas) <= dimensoes)
      {
        if(tabuleiro[Battleship] == '=' && tabuleiro[Battleship + colunas] == '=' && 
           tabuleiro[Battleship + (2*colunas)] == '=' && tabuleiro[Battleship + (3*colunas)] == '=')
        {
          vdd = 1; 
        }
      }
    else
    vdd = 0;
  }

  tabuleiro[Battleship] = 'B';
  tabuleiro[Battleship + 1 * colunas] = 'B'; 
  tabuleiro[Battleship + 2 * colunas] = 'B';
  tabuleiro[Battleship + 3 * colunas] = 'B'; 

}

/*Mesma função da função cond_battleship feita para a vertical*/
void cond_batttleship_V(char *tabuleiro, int dimensoes, int colunas, int linhas)
{
  int vdd = 0;
  int i = 1;

  while(vdd != 1)
  {
    for(i = 1; i < dimensoes + 1; ++i)
   {
      if(tabuleiro[i] == 'B' && tabuleiro[i+colunas] == 'B' && tabuleiro[i+(2*colunas)] == 'B'
         && tabuleiro[i+(3*colunas)] == 'B')
      {
        //Primeira Posição
        if(i == 1)
        { 
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          tabuleiro[i + 1 + (4*colunas)] = '!';
          tabuleiro[i + (4*colunas)] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
         
        //Meio da Primeira Linha
        if(i != 1 && i < colunas)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (3*colunas)] = '!';
          tabuleiro[i - 1 + (4*colunas)] = '!';
          tabuleiro[i + 1 + (4*colunas)] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + (4*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da 1 Linha
        if(i == colunas)
        {  
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + (3*colunas)] = '!';
          tabuleiro[i - 1 + (4*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i + (4*colunas)] = '!';
          vdd = 1;
        }
        
        //Borda da Esquerda
        if(i % colunas == 1 && i != 1 && i + colunas < dimensoes && i + colunas < linhas * (colunas-1)
          && i + (3*colunas) != linhas * (colunas-1) + 1)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + 1 + colunas ] = '!';
          tabuleiro[i + (4*colunas)] = '!';
          tabuleiro[i + 1 + (4*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          vdd = 1;
        }
        
        //Borda da Direita
        if(i % colunas == 0 && i + colunas < dimensoes && i > colunas && i + (3*colunas) != dimensoes)
        {   
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + colunas ] = '!';
          tabuleiro[i - 1 + (3*colunas)] = '!';
          tabuleiro[i - 1 + (4*colunas)] = '!';
          tabuleiro[i + (4*colunas)] = '!';
          vdd = 1;
        }
        
        //Ultima Posição da Borda da Esquerda
        if(i % colunas == 1 && i + (3*colunas) == linhas * (colunas-1) + 1)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          vdd = 1;
        }

        //Meio da Ultima Linha
        if(i % colunas != 1 && i + (3*colunas) != dimensoes && i + (3*colunas) > linhas * (colunas-1) + 1)
        {
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 + (3*colunas)] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1 + (colunas)] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          vdd = 1;
        }

        //Ultima Posição da Borda da Direita
        if(i + (3*colunas) == dimensoes && i % colunas == 0)
        { 
          tabuleiro[i - 1] = '!';
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 + (3*colunas)] = '!';
          vdd = 1;
        }

        if(i != 1 && i % colunas != 0 && i % colunas != 1 && i > colunas && i + colunas < linhas * (colunas-1)
          && i + (3*colunas) < linhas * (colunas -1) + 1)
        {
          tabuleiro[i - colunas] = '!';
          tabuleiro[i - 1] = '!';
          tabuleiro[i - 1 - colunas] = '!';
          tabuleiro[i - 1 + colunas] = '!';
          tabuleiro[i - 1 + (2*colunas)] = '!';
          tabuleiro[i - 1 +(3*colunas)] = '!';
          tabuleiro[i - 1 + (4*colunas)] = '!';
          tabuleiro[i + 1] = '!';
          tabuleiro[i + 1 - colunas] = '!';
          tabuleiro[i + 1 + colunas] = '!';
          tabuleiro[i + (4*colunas)] = '!';
          tabuleiro[i + 1 +(3*colunas)] = '!';
          tabuleiro[i + 1 + (2*colunas)] = '!';
          tabuleiro[i + 1 + (3*colunas)] = '!';
          tabuleiro[i + 1 + (4*colunas)] = '!';
          vdd = 1;
        }
      }//tabuleiro[i] = 'D'
    }//For
  }//VDD
    
}

/*Criação do Mapa onde o caractere '=' representa a agua*/
void Preencher(char *tabuleiro, int dimensoes)
{
  for (int i = 1; i < dimensoes + 1; ++i)
  tabuleiro[i] = '=';
}

/*Mostrar o Mapa pelo terminal*/
void Printar(char *tabuleiro, int dimensoes, int colunas)
{
  int cont_jump = 0;

  for (int i = 1; i < dimensoes + 1; ++i)
  {
    std::cout << tabuleiro[i] << " ";
    cont_jump ++;

    if (cont_jump == colunas)
    {
      std::cout << std::endl;
      cont_jump = 0;
    }
  }
}

/*Removo todas as 'minas' que são representadas por '!' onde marca o bloqueio daquela posição para tal barco*/
void limpar(char *tabuleiro, int dimensoes)
{
  for (int i = 1; i < dimensoes + 1; ++i)
  {
    if(tabuleiro[i] == '!')
      tabuleiro[i] = '=';
  }
}

/*Passo para o arquivo txt apenas as posições chaves onde tem o barco daquele puzzle*/
void Printar_arq(char *tabuleiro, int dimensoes, int quantidade)
{ 
 
  //int cont(1);

  std:: ofstream batle;
  batle.open("BSP.txt", std::  ofstream::app);

  //for (int i = 0; i < quantidade; ++i)
  //{
    //batle << cont << std:: endl;

    for (int j = 1; j < dimensoes; ++j)
    {
      if(tabuleiro[j] != '=')
        batle << j << " ";
    }

    //cont ++;
    batle << std:: endl;
  //} 

  batle.close();
}


//Escolho um puzzle aleatorio entre os possiveis//
int get_puzzle(int qtd_puzzles)
{
 std::random_device rd;
 
 std::mt19937_64 gen(rd());

 std::uniform_int_distribution < unsigned long long > dis;

 return dis(gen) % qtd_puzzles;
}

//armazeno esse puzzle em um arquivo de nome gabarito//
void armazenarpuzzle(char *tabuleiro, int dimensoes, int colunas)
{
  std:: ofstream batle;
  batle.open("Gabarito.txt", std::ofstream::app);


  for (int j = 1; j < dimensoes; ++j)
  {
    if(tabuleiro[j] != '=')
      batle << j << " ";
  } 
    
  batle << std:: endl; 
}


void jogar_menor10(int dimensoes, int colunas, char *tabuleiro)
{
  int qnt_barco = 0;

  char comando;
  
  int vet_entradas[11];
  
  while(qnt_barco != 11)
  {
    displaymapa(tabuleiro ,dimensoes, colunas);

    int entrada_coluna;

    char posic;

    std::cout << "Digite a coluna e a linha que servirão de coordenadas: ";
    
    std::cin >> entrada_coluna >> posic;
    
    if( checar_menor10(entrada_coluna, posic) == 1 )
    {
      int entrada_user = (convertposic(posic)*colunas) + entrada_coluna;

      tabuleiro[entrada_user] = 'X';

      displaymapa(tabuleiro ,dimensoes, colunas);

      std::cout << "Deseja confirmar posição? Y/N\n";
      std::cin >> comando;
    
      if (comando == 'Y' || comando == 'y')
      {
      vet_entradas[qnt_barco] = entrada_user;   
      qnt_barco++;
      }

      if (comando == 'N' || comando == 'n')
      {
      tabuleiro[entrada_user] = '=';
      }
    }
  }

  if(compare_menor10(vet_entradas) == 11)
  {
   std::cout << "Parabens voce terminou o puzzle";
   std::cout << std::endl;
  }
  
  else
  {
    std::cout << "Infelizmente voce não acertou o Battleship Puzzle\n";
    displaygabarito_menor10(dimensoes, colunas);
  }
}

void jogar_maior10(int dimensoes, int colunas, char *tabuleiro)
{
  int qnt_barco = 0;

  char comando;

  int vet_entradas[20];
  
  while(qnt_barco != 20)
  {

    displaymapa(tabuleiro ,dimensoes, colunas);

    int entrada_coluna;

    char posic;

    std::cout << "Digite a coluna e a linha que servirão de coordenadas: ";
    
    std::cin >> entrada_coluna >> posic;

    if( checar_maior10(entrada_coluna, posic) == 1 )
    {

      int entrada_user = (convertposic(posic)*colunas) + entrada_coluna;

      tabuleiro[entrada_user] = 'X';

      displaymapa(tabuleiro ,dimensoes, colunas);

      std::cout << "Deseja confirmar posição? Y/N\n";
      std::cin >> comando;
    
      if (comando == 'Y' || comando == 'y')
      {
      vet_entradas[qnt_barco] = entrada_user;   
      qnt_barco++;
      }

      if (comando == 'N' || comando == 'n')
      {
      tabuleiro[entrada_user] = '=';
      }
    }
  }

  if(compare_maior10(vet_entradas) == 11)
  {
   std::cout << "Parabens voce terminou o puzzle";
   std::cout << std::endl;
  }
  
  else
  {
    std::cout << "Infelizmente voce não acertou o Battleship Puzzle\n";
    displaygabarito_maior10(dimensoes, colunas);
  }

}


//Preencho o mapa copia para o user//
void preenchercopia(char *tabuleiro, int dimensoes)
{
  for (int i = 1; i < dimensoes + 1; ++i)
  tabuleiro[i] = '=';
}

//Mostro o para com as coordenadas//
void displaymapa(char *tabuleiro ,int dimensoes, int colunas)
{
  int cont_jump = 0;
  char coord = 'A';
  
  for (int i = 0; i < colunas; ++i)
    std::cout << i + 1 << " ";

  std::cout << std::endl;

  for (int i = 1; i < dimensoes + 1; ++i)
  {
    std::cout << tabuleiro[i] << " ";
    cont_jump++;
    if (cont_jump == colunas)
    { 
      std::cout << " " << coord;
      coord++;
      std::cout << std::endl;
      cont_jump = 0;
    }
  }
}

//Converto a entrada para o indice//
int convertposic(char posic)
{
  int coord;

  if(posic == 'A' || posic == 'a')
   coord = 0;

  if(posic == 'B' || posic == 'b')
   coord = 1;
  
  if(posic == 'C' || posic == 'c')
   coord = 2;
  
  if(posic == 'D' || posic == 'd')
   coord = 3;
  
  if(posic == 'E' || posic == 'e')
   coord = 4;
   
  if(posic == 'F' || posic == 'f')
   coord = 5;
   
  if(posic == 'G' || posic == 'g')
   coord = 6;
   
  if(posic == 'H' || posic == 'h')
   coord = 7;
  
  if(posic == 'I' || posic == 'i')
   coord = 8;

  if(posic == 'J' || posic == 'j')
   coord = 9;

  if(posic == 'K' || posic == 'k')
   coord = 10;

  if(posic == 'L' || posic == 'l')
   coord = 11;

  if(posic == 'M' || posic == 'm')
   coord = 12;

  if(posic == 'N' || posic == 'n')
   coord = 13;

  if(posic == 'O' || posic == 'o')
   coord = 14;

  if(posic == 'P' || posic == 'p')
   coord = 15;

  return coord;
}

//Comparo as posições do usuario quando menor que 10//
int compare_menor10(int *entradas)
{
  int acertos = 0;

  int vet_gabarito[11];

  std::ifstream batle;
  batle.open("Gabarito.txt");
  
  for (int i = 0; i < 11; ++i)
    batle >> vet_gabarito[i];

  for (int i = 0; i < 11; ++i)
  {
    for (int j = 0; j < 11; ++j)
    {
    if (vet_gabarito[i] == entradas[j])
    acertos ++;
    }
  }
 
 return acertos;
}

//Comparo as posições do usuario quando maior que 10//
int compare_maior10(int *entradas)
{
  int acertos = 0;

  int vet_gabarito[20];

  std::ifstream batle;
  batle.open("Gabarito.txt");
  
  for (int i = 0; i < 20; ++i)
    batle >> vet_gabarito[i];

  for (int i = 0; i < 11; ++i)
  {
    for (int j = 0; j < 20; ++j)
    {
    if (vet_gabarito[i] == entradas[j])
    acertos ++;
    }
  }
 
 return acertos;
}

//Mostro o gabarito para maior que 10//
void displaygabarito_menor10(int dimensoes, int colunas)
{
  char mapa[dimensoes];

  int vet_gabarito[11];

  char coord = 'A';

  int cont_jump;

  std::ifstream batle;
  batle.open("Gabarito.txt");
  
  for (int i = 0; i < 11; ++i)
    batle >> vet_gabarito[i];
 
  for (int i = 1; i < dimensoes + 1; ++i)
    mapa[i] = '=';

  for (int i = 1; i < dimensoes + 1; ++i)
  {
    for(int j = 0; j < 10; ++j)
    {
     if(vet_gabarito[j] == i)
     mapa[i] = 'X';
    }
  }

  std::cout << "GABARITO\n";

  for (int i = 0; i < colunas; ++i)
    std::cout << i + 1 << " ";

  std::cout << std::endl;

  for (int i = 1; i < dimensoes + 1; ++i)
  {
    std::cout << mapa[i] << " ";
    cont_jump++;
    if (cont_jump == colunas)
    { 
      std::cout << " " << coord;
      coord++;
      std::cout << std::endl;
      cont_jump = 0;
    }
  }
}

//Mostro o gabarito para maior que 10//
void displaygabarito_maior10(int dimensoes, int colunas)
{
  char mapa[dimensoes];

  int vet_gabarito[20];

  char coord = 'A';

  int cont_jump;

  std::ifstream batle;
  batle.open("Gabarito.txt");
  
  for (int i = 0; i < 11; ++i)
    batle >> vet_gabarito[i];


  for (int i = 1; i < dimensoes + 1; ++i)
    mapa[i] = '=';

  std::cout << std::endl;

  for (int i = 1; i < dimensoes + 1; ++i)
  {
    for(int j = 0; j < 20; ++j)
    {
     if(vet_gabarito[j] == i)
     mapa[i] = 'X';
    }
  }

  std::cout << "GABARITO\n";

  for (int i = 0; i < colunas; ++i)
  std::cout << i + 1 << " ";

  std::cout << std::endl;

  for (int i = 1; i < dimensoes + 1; ++i)
  {
    std::cout << mapa[i] << " ";
    cont_jump++;
    if (cont_jump == colunas)
    { 
      std::cout << " " << coord;
      coord++;
      std::cout << std::endl;
      cont_jump = 0;
    }
  }

  std::cout << std::endl;
}

//Checo se as coordenadas do menor que 10 são validas//
int checar_menor10(int numero, char linha)
{
  if (numero > 0 && numero < 10 && linha >= 'A' && linha <= 'P')
  {
   std::cout << "Coordenadas valida\n";
   return 1;
  }

  if(numero > 0 && numero < 10 && linha >= 'a' && linha <= 'p')
  {
  std::cout << "Coordenadas validas\n";
  return 1;
  }

  else 
    std::cout << "Coordenadas invalidas\n";
    return 0;
}

//Checo se as coordenadas do maior que 10 são validas//
int checar_maior10(int numero, char linha)
{
  if (numero > 0 && numero <= 15 && linha >= 'A' && linha <= 'P')
  {
   std::cout << "Coordenadas valida\n";
   return 1;
  }

  if(numero > 0 && numero <= 15 && linha >= 'a' && linha <= 'p')
  {
  std::cout << "Coordenadas validas\n";
  return 1;
  }

  else 
    std::cout << "Coordenadas invalidas\n";
    return 0;
}