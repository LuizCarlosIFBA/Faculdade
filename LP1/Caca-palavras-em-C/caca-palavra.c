
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

void main()
{
 int i,j; //Variáveis Auxiliares
 int Linhas, Colunas = 3;
 
 //Criando o vetor
 char **m = (char**)malloc(Linhas * sizeof(char*)); //Aloca um Vetor de Ponteiros
 for (i = 0; i < Linhas; i++){ 
    m[i] = (char*) malloc(Colunas * sizeof(char)); //Aloca um Vetor de char para cada posição do Vetor de Ponteiros.
    for (j = 0; j < Colunas; j++){ //Percorre o Vetor de char atual.
        m[i][j] = ' '; //Inicializa.
    }
 }
  
 //Preenche  
 m[0][0] = 'N';
 m[1][1] = 'A';
 m[2][2] = 'O';
 
 m[0][1]= 'X';
 m[0][2]= 'Y';

 m[1][0]= 'Z';
 m[1][2]= 'T';

 m[2][0]= 'W';
 m[2][1]= 'S';
 
 //imprimir 
 printf("CACA-PALAVRAS\n\n");
 for(int i =0;i<3;i++){
	for(int j =0;j<3;j++)
		printf("%c ",m[i][j]);
	printf("\n");
 }
 
 //usuario acerta
 printf("\n ---------------------\n");
 if(pesquisar(m,'N',0,0) && pesquisar(m,'A',1,1) && pesquisar(m,'O',2,2)==1){
	 printf("A respota programada acertou o caca-palavras\n");
	 printf("Todas as posicoes escolhidas estao corretas e a palavra foi NAO");
 }
 printf("\n ---------------------\n");
	  
}
