#ifndef BP_H
#define BP_H

int checar_maior10(int numero, char linha);
int checar_menor10(int numero, char linha);
void displaygabarito_menor10(int dimensoes, int colunas);
void displaygabarito_maior10(int dimensoes, int colunas);
int compare_maior10(int *entradas);
int compare_menor10(int *entradas);
int convertposic(char posic);
void jogar_maior10(int dimensoes, int colunas, char *tabuleiro);
int get_puzzle(int qtd_puzzles);
void jogar_menor10(int dimensoes, int colunas, char *tabuleiro);
void preenchercopia(char *tabuleiro, int dimensoes);
void displaymapa(char *tabuleiro, int dimensoes, int colunas);
void Printar_gabarito(char *tabuleiro, int dimensoes, int colunas);
void Limpar_gabarito();
void armazenarpuzzle(char *tabuleiro, int dimensoes, int colunas);
void Limpar_arq();
void linha_colunas_qntpuzzles(int argc, char** argv);
void Construcao(int linhas, int colunas, int qtd_puzzles);
int get_posision(int dimensoes);
void Submarino(char *tabuleiro, int dimensoes);
void cond_submarino(char *tabuleiro, int dimensoes, int colunas, int linhas);
void Destroyer(char *tabuleiro, int dimensoes, int colunas);
void Cruiser(char *tabuleiro, int dimensoes, int colunas);
void Battleship(char *tabuleiro, int dimensoes, int colunas);
void Preencher(char *tabuleiro, int dimensoes);
void Printar(char *tabuleiro, int dimensoes, int colunas);
void cond_destroyer(char *tabuleiro, int dimensoes, int colunas);
void cond_cruiser(char *tabuleiro, int dimensoes, int colunas);
void cond_battleship(char *tabuleiro, int dimensoes, int colunas);
void limpar(char *tabuleiro, int dimensoes);
void Destroyer_V(char *tabuleiro, int dimensoes, int colunas, int linhas);
void Battleship_v(char *tabuleiro, int dimensoes, int colunas, int linhas);
void Destroyer_V(char *tabuleiro, int dimensoes, int colunas);
void Cruiser_V(char *tabuleiro, int dimensoes, int colunas, int linhas);
void cond_destroyer_V(char *tabuleiro, int dimensoes, int colunas, int linhas);
void cond_cruiser_V(char *tabuleiro, int dimensoes, int colunas, int linhas);
void cond_batttleship_V(char *tabuleiro, int dimensoes, int colunas, int linhas);
int set_boat(int dimensoes);
void run(char *map_battle, int dimensoes, int colunas, int linhas);
void run_menor10(char *map_battle, int dimensoes, int colunas, int linhas);
void Printar_arq(char *tabuleiro, int dimensoes,int numero_de_jogos);


#endif

//para compilar g++ -Wall -std=c++11 bp.cpp fun_bp.cpp -o vai
