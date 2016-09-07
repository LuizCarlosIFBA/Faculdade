#ifndef _FUNCOESBUSCA_H
#define _FUNCOESBUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void check ( char * letra, char other){ // Transforma letras maiusculas em minusculas para comparar.
	if (isupper(other))	*letra = tolower(other);
	else *letra = other;
}

int verticalReversa(char **bp, char palavra[], int *pI, int *pJ, char *direcao, int linhaMax, int colunaMax)
{
	int i,j,cont,sizeWord, existWord = 0, indWord = 0;
	//inicializa
	sizeWord = strlen(palavra);
	//percorre a matriz
	 for(j = 0; j < colunaMax;j++){
	 	
		 for(i = linhaMax-1; i >= 0;i--){
			
			if(tolower(bp[i][j]) == palavra[indWord])//as letras são iguais?
			{
				if(indWord == 0){//é a primeira letra?, se sim, guarde os indices
					*pI = i;
					*pJ = j;
				}
				existWord++;//incrementa a possibilidade de ser a palavra
				indWord++;//vai para a próxima letra da palavra
			}else{// letras diferentes
				if(tolower(bp[i][j]) != palavra[0]){//se esta letra não é igual a primeira letra da palavra, zere os indices
					indWord = 0;
					existWord = 0;  
				}else{//senao atribua os indices para a busca continuar deste ponto
				     *pI = i;
					 *pJ = j;
				}
			}
			//se achou a palavra	
			if(sizeWord == existWord){
				//transfome-a para maiuscula e guarde na matriz
				for(cont = 0; cont < sizeWord; cont++)
				{
					bp[*pI][*pJ] = toupper(bp[*pI][*pJ]);
					*pI -= 1;
				}
				//guarde a direção na qual a palavra se encontra
				strcpy(direcao,"VR");
				return 1;
			}
		  }
		}
		
	return 0;
}

int verticalDireta(char **bp, char palavra[], int *pI, int *pJ, char *direcao, int linhaMax, int colunaMax)
{	
	int i,j,cont,sizeWord, existWord = 0, indWord = 0;
	//inicializa
	sizeWord = strlen(palavra);
	//percorre a matriz
	for(j = 0; j < colunaMax;j++)
	{
			for(i = 0; i < linhaMax;i++)
			{
				if(tolower(bp[i][j]) == palavra[indWord])//as letras são iguais?
				{
					if(indWord == 0){//é a primeira letra?, se sim, guarde os indices
						*pI = i;
						*pJ = j;
					}
					existWord++;//incrementa a possibilidade de ser a palavra
					indWord++;//vai para a próxima letra da palavra
				}else{// letras diferentes
					if(tolower(bp[i][j]) != palavra[0]){//se esta letra não é igual a primeira letra da palavra, zere os indices
						indWord = 0;
						existWord = 0;  
					}else{//senao atribua os indices para a busca continuar deste ponto
						*pI = i;
						*pJ = j;
					}
				}
				//se achou a palavra	
				if(sizeWord == existWord){
					//transfome-a para maiuscula e guarde na matriz
					for(cont = 0; cont < sizeWord; cont++)
					{
						bp[*pI][*pJ] = toupper(bp[*pI][*pJ]);
						*pI += 1;
					}
					//guarde a direção na qual a palavra se encontra
					strcpy(direcao,"VD");
					return 1;
				}
			}
		}
	
	return 0;
}

int horizontalDireta(char **bp, char palavra[], int *pI, int *pJ, char *direcao, int linhaMax, int colunaMax)
{
	int i,j,cont,sizeWord, existWord = 0, indWord = 0;
	//inicializa
	sizeWord = strlen(palavra);
	
	/*BUSCA HORIZONTAL DIRETA*/
	for(i = 0; i < linhaMax;i++)
	{
		for(j = 0; j < colunaMax;j++)
		{
			if(tolower(bp[i][j]) == palavra[indWord])//as letras são iguais?
			{
				//guarda a posição da primeira letra dentro da tabela
				if(indWord == 0){
					*pI = i;
					*pJ = j;
				}
				existWord++;//incrementa a possibilidade de ser a palavra
				indWord++;//vai para a próxima letra da palavra
			}else{//se esta letra não é igual a primeira letra da palavra, zere os indices
				if(tolower(bp[i][j]) != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{//senao atribua os indices para a busca continuar deste ponto
				     *pI = i;
					 *pJ = j;
				}
			}
			//se achou a palavra	
			if(sizeWord == existWord){
				//transfome-a para maiuscula e guarde na matriz
				for(cont = 0; cont < sizeWord; cont++)
			    {
					bp[*pI][*pJ] = toupper(bp[*pI][*pJ]);
					*pJ += 1;
				}
				//guarde a direção na qual a palavra se encontra
				strcpy(direcao,"HD");
				return 1;
			}
	    }
	 }
	 
	return 0;
}

int horizontalReversa(char **bp, char palavra[], int *pI, int *pJ, char *direcao, int linhaMax, int colunaMax)
{
	int i,j,cont,sizeWord, existWord = 0, indWord = 0;
	//inicializa
	sizeWord = strlen(palavra);
	
	for(i = 0; i < linhaMax;i++)
	 {
		for(j = colunaMax-1; j >= 0;j--)
	    {
			if(tolower(bp[i][j]) == palavra[indWord])//as letras são iguais?
			{
				if(indWord == 0){//primeiro indice? entao guarde-os indices do diagrama
					*pI = i;
					*pJ = j;
				}
				existWord++;//incrementa a possibilidade de ser a palavra
				indWord++;//vai para a próxima letra da palavra
			}else{//se esta letra não é igual a primeira letra da palavra, zere os indices
				/*Se a primeira letra da palavra recebida for diferente da letra da tabela reinicie os parametros*/
				if(tolower(bp[i][j]) != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{//senao atribua os indices para a busca continuar deste ponto
				     *pI = i;
					 *pJ = j;
				}
			}
			/*se encontrou a palavra saia do loop*/	
			if(sizeWord == existWord){
				//transfome a palavra encontrada para maiusculo
				for(cont = 0; cont < sizeWord; cont++)
				{
					bp[*pI][*pJ] = toupper(bp[*pI][*pJ]);
					*pJ -= 1;
				}
				strcpy(direcao,"HR");
				return 1;
			}
		  }
		}
		return 0;
}
int diagonalDireta(char **bp, char palavra[], int *pI, int *pJ, char *direcao, int linhaMax, int colunaMax)
{
	int i,j,cont,sizeWord, existWord = 0, indWord = 0;
	//inicializa
	sizeWord = strlen(palavra);
	
	for(i = 0; i < linhaMax; i++)
	{
		for(j =0; j < colunaMax; j++)
		{
			
		}
	}
}
int buscaPalavra(char **matriz, char palavra[], int *pI, int *pJ, char *direcao, int linhaMax, int colunaMax)
{
	int found = horizontalDireta(matriz, palavra,pI,pJ,direcao,linhaMax,colunaMax);
	if(!found) found = horizontalReversa(matriz, palavra,pI,pJ,direcao,linhaMax,colunaMax);
	if(!found) found = verticalDireta(matriz, palavra,pI,pJ,direcao,linhaMax,colunaMax);
	if(!found) found = verticalReversa(matriz, palavra,pI,pJ,direcao,linhaMax,colunaMax);
	
	return found;
}
#endif

