#include <stdio.h>

typedef struct{
	char matriz[3][3]	;
	int numJogadas;
	
}Tabuleiro;

void iniciar(Tabuleiro *jogo){
	int i,j;
	for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            jogo->matriz[i][j] = ' ';
        }
    }
}

void imprimir(Tabuleiro *jogo){
	int i,j;
	for (i= 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
        	printf(" %c ", jogo->matriz[i][j]);
            if(j<2){
				printf("|");
			}
        }
        printf("\n");
        if(i<2){
			printf("---------");
		}
		printf("\n");
    }
}

void main(){
	Tabuleiro jogo;
	
	int linha,coluna;
	int controle = 0;
	iniciar(&jogo);
	imprimir(&jogo);
	/*while(controle == 0){
		imprimir(&jogo);
	}
	*/
	
}



//Funçoes: 
/*
iniciar: preenche a matriz com ' '				OK
imprimir: imprime o tabuleiro					OK
verificar: verifica se há ganhadores			

Temos que verificar tambem se o game esta empatado, ou seja, ja foi o maximo de jogadas e mesmo assim não ha ganhador
Podemos controlar a quantidade de jogadas, assim so verifica se há ganhador a partir da 5° jogada




*/