#include <iostream>
#include <fstream>
#include <stack>

struct Cavalo {
	int x;
	int y;
};

struct Tabuleiro {
	int ** matriz;
	int tam;
	int i;
	int j;
};

using namespace std;

/*Divide and Conquer!*/

/*Faremos aqui algumas convenções!*/
/*Convencionaremos que no tabuleiro, o valor -1 significa que é uma posição proibida*/
/*Convencionaremos que no tabuleiro, o valor 0 significa a ausência de CAVALO*/
/*Convencionaremos que o valor 1 significa a presença de um cavalo.*/
/*Por fim, o valor 2 significa que é a zona de ataque de algum cavalo*/

/*Funções criadas para auxiliar.*/
bool setZonaAtaque(Cavalo &c, int ** tab, int tam);
bool movimentarCavalo(Cavalo &c, int ** tab, int tam, int x, int y); /*Não usada, mas poderia ter usada.*/
bool setCavalo(Cavalo &c, int ** tab, int tam);
Cavalo * getCavalo(int ** tab, int tam);

/****************Função exigida no trabalho.*******************/
int numeroMaximoDeCavalos(char *nomeArquivo);

/*****Funções auxiliares na alocação de memória, liberação e visualização do tabuleiro.*********/
int * alocarVetor(int n);
void liberarVetor(int *v);
int ** alocarTabuleiro(int n);
int ** copiarTabuleiro(int ** tab, int n);
void liberarTabuleiro(int **&v, int n);
void liberarCavalo(Cavalo * v);
void imprimirTabuleiro(int **matriz, int ordem);