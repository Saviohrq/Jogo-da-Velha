#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char matriz[3][3];
	int numJogadas;
	int jogoAtivo;

}Tabuleiro;

void iniciar(Tabuleiro *jogo){
	int i,j;
	jogo->jogoAtivo = 1;
	for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            jogo->matriz[i][j] = ' ';
        }
    }
}//fim do iniciar

void imprimir(Tabuleiro *jogo){
	int i,j;
	printf("---------- JOGO DA IDOSA DOS CRIA ----------\n\n");
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
}//fim do imprimir

void jogada(Tabuleiro *jogo,char nome){
	int x;
    int y;
	while(1){
			imprimir(jogo);
			system("cls");
			printf("------ Jogador %c -----\n",nome);
			fflush(stdin);
			printf("\nLINHA: ");
			scanf("%d", &x);
        	printf("\nCOLUNA: ");
        	scanf("%d", &y);

        	//Validando jogada
        	if(jogo->matriz[x][y] == ' '){
				jogo->matriz[x][y] = nome;
				imprimir(jogo);
				system("pause");
				break;
			}
			else{
				printf("Espaco ja preenchido, escolha outro lugar!\n");
				system("pause");
			}
		}
}//Fim do jogada
void verificarGanhador(Tabuleiro *jogo,char nome,int numJgds){

	int i,j;

	//Verificar linhas e colunas
	for(i = 0; i < 3; i++) {
    	if((jogo->matriz[i][0]==nome && jogo->matriz[i][1]==nome && jogo->matriz[i][2] == nome)||
		(jogo->matriz[0][i]==nome && jogo->matriz[1][i]==nome && jogo->matriz[2][i] == nome)){

			system("cls");
			imprimir(jogo);
			printf("JOGADOR %c GANHOU!\n\n",nome);
			jogo->jogoAtivo = 0;
			system("pause");
			return;
		}
	}//Fim do For

	//Verificar diagonal
	if((jogo->matriz[0][0]==nome && jogo->matriz[1][1]==nome && jogo->matriz[2][2]==nome) ||
 	 (jogo->matriz[0][2]==nome && jogo->matriz[1][1]==nome && jogo->matriz[2][0]==nome)){

        system("cls");
		imprimir(jogo);
	  	printf("JOGADOR %c GANHOU!\n\n",nome);
		jogo->jogoAtivo = 0;
		system("pause");
		return;
	}

	//Verificar empate
	if(numJgds > 9){
        system("cls");
		imprimir(jogo);
		printf("DEU IDOSA (EMPATE)!\n\n");
		jogo->jogoAtivo = 0;
		system("pause");
		return;
	}



}//Fim do verificarGanhador


void main(){
	Tabuleiro jogo;

	int controle;
	int numJogadas;


	while(1){

		iniciar(&jogo);
		system("cls");
		fflush(stdin);
		imprimir(&jogo);

		printf("\n1 - JOGAR 1 vs 1");
		printf("\n2 - JOGAR 1 vs 1");
		printf("\n0 - SAIR");
		printf("\n>>> ");
		scanf("%d", &controle);

		if(controle == 0){
			break;
		}else{
			switch(controle){
			case 1:
				numJogadas = 1;
				while(1){
					jogada(&jogo,'X');
					numJogadas++;
					if(numJogadas >= 4){
						verificarGanhador(&jogo,'X',numJogadas);
						if(jogo.jogoAtivo==0){
							break;
						}
					}
					jogada(&jogo,'O');
					numJogadas++;
					if(numJogadas >= 4){
						verificarGanhador(&jogo,'O',numJogadas);
						if(jogo.jogoAtivo==0){
							break;
						}
					}

				}
				break;
			case 2:

				break;
			default:
				printf("OPCAO INVALIDA");
				system("pause");
				break;
			}
		}



	}


}// Fim da main



//Funçoes:
/*
iniciar: preenche a matriz com ' ' --> OK
imprimir: imprime o tabuleiro --> OK

jogarCOM: função que pegue as opções do jogador e sortei as jogadas do computador
jogar1vs1: função que pega as jogadas dos dois jogadores

verificar: verifica se há ganhadores --> OK

Temos que verificar tambem se o game esta empatado, ou seja, ja foi o maximo de jogadas e mesmo assim não ha ganhador --> OK
Podemos controlar a quantidade de jogadas, assim so verifica se há ganhador a partir da 5° jogada

// \t --> printa o espaço de um TAB\



*/
