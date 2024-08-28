#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			printf("-----------");
		}
		printf("\n");
    }
}

void pvp(Tabuleiro *jogo){
    int x;
    int y;
    int jgds;

    while(jgds < 9){

        system("cls");
        printf("-------- FACA SUA JOGADA ------\n\n");
        printf("LINHA: ");
        scanf("%d\n", &x);
        printf("COLUNA: ");
        scanf("%d\n", &y);
        jgds++;
        jogo->matriz[x][y] = 'x';
        imprimir(&jogo);
        system("pause");

    }

}//fim PVP

void main(){
	Tabuleiro jogo;

	int linha,coluna;
	char controle;
	iniciar(&jogo);

	while(1){

		system("cls");
		printf("---------- JOGO DA IDOSA DOS CRIA ----------\n\n");
		imprimir(&jogo);
		printf("\n1 - JOGAR 1 vs COM");
		printf("\n2 - JOGAR 1 vs 1");
		printf("\n0 - SAIR");
		printf("\n>>> ");
		scanf("%c", &controle);

		if(controle == '0'){
			break;
		}else{
			switch(controle){
			case '1':
				//chamar função jogarCOM
				break;
			case '2':
                pvp(&jogo);
				break;
			default:
				printf("OPCAO INVALIDA");
				break;
			}
		}



	}


}// fim da main



//Funçoes:
/*
iniciar: preenche a matriz com ' '				OK
imprimir: imprime o tabuleiro					OK

jogarCOM: função que pegue as opções do jogador e sortei as jogadas do computador
jogar1vs1: função que pega as jogadas dos dois jogadores

verificar: verifica se há ganhadores

Temos que verificar tambem se o game esta empatado, ou seja, ja foi o maximo de jogadas e mesmo assim não ha ganhador
Podemos controlar a quantidade de jogadas, assim so verifica se há ganhador a partir da 5° jogada

// \t --> printa o espaço de um TAB\



*/
