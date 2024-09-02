#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char matriz[3][3] ;
	int numJogadas ;
	int jogoAtivo ; // 1 para ativo e 0 para jogo finalizado
	int vitoriasX ;
    int vitoriasO ;
    int empates ;
    
}Tabuleiro;

void iniciar(Tabuleiro *jogo){
	int i,j;
	
	jogo->jogoAtivo = 1;
	jogo->numJogadas = 0;

	for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            jogo->matriz[i][j] = ' ';
        }
    }
}//fim do iniciar

void imprimir(Tabuleiro *jogo){
	int i,j;
	printf("---------- JOGO DA IDOSA ----------\n\n");
	printf("    1   2   3\n");
	for (i= 0; i < 3; i++) {
		printf(" %d ", i + 1);
        for (j = 0; j < 3; j++) {
        	printf(" %c ", jogo->matriz[i][j]);
            if(j<2){
				printf("|");
			}
        }
        printf("\n");
        if(i<2){
			printf("   -----------");
		}
		printf("\n");
    }
}//fim do imprimir

void exibirPlacar(Tabuleiro *jogo) {
	
    printf("\n------------PLACAR------------\n");
    printf("Jogador X: %d vitorias\n", jogo->vitoriasX);
    printf("Jogador O: %d vitorias\n", jogo->vitoriasO);
	printf("Empates: %d \n", jogo->empates);
    printf("------------------------------\n\n");
    
}//Fim do exibirPlacar

void jogada(Tabuleiro *jogo,char nome){
	int x;
    int y;
	while(1){
		
			system("cls");
			exibirPlacar(jogo);
			imprimir(jogo);
			printf("------ Jogador %c -----\n",nome);
			fflush(stdin);
			printf("\nLINHA (1-3): ");
			scanf("%d", &x);
        	printf("\nCOLUNA (1-3):");
        	scanf("%d", &y);
        	
        	x--; 
			y--;
			
        	
        	//Validando jogada
        	if(x >= 0 && x < 3 && y >= 0 && y < 3 && jogo->matriz[x][y] == ' '){
				jogo->matriz[x][y] = nome;
				jogo->numJogadas++;
				system("pause");
				break;
			}
			else{
				printf("\nEspaco ja preenchido ou jogada invalida, escolha outro lugar!\n");
				system("pause");
			}
		}
}//Fim do jogada

void jogadaComputador(Tabuleiro *jogo, char nome) {
	
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (jogo->matriz[x][y] != ' ');

    jogo->matriz[x][y] = nome;
    jogo->numJogadas++;
    
} //Fim do jogadaComputador

void verificarGanhador(Tabuleiro *jogo,char nome){
	
	int i;
	
	//Verificar linhas e colunas
	for(i = 0; i < 3; i++) {
    	if((jogo->matriz[i][0] == nome && jogo->matriz[i][1] == nome && jogo->matriz[i][2] == nome)||
		(jogo->matriz[0][i] == nome && jogo->matriz[1][i] == nome && jogo->matriz[2][i] == nome)){
			
			if (nome == 'X') {  //Contagem de vitórias para 'X'
                jogo->vitoriasX ++;
            } else {  //Contagem de vitórias para 'O'
                jogo->vitoriasO ++;
            }
            
			system("cls");
			
			imprimir(jogo);
			printf("\nJogador %c ganhou! ",nome);
			jogo->jogoAtivo = 0;
			
			

			system("pause");
			return;
		}
	}
	
	//Verificar diagonal
	if((jogo->matriz[0][0]==nome && jogo->matriz[1][1]==nome && jogo->matriz[2][2]==nome) || 
 	 (jogo->matriz[0][2]==nome && jogo->matriz[1][1]==nome && jogo->matriz[2][0]==nome)){
 	 	
		if (nome == 'X') {  //Contagem de vitórias para 'X'
                jogo->vitoriasX++;
		} else {  //Contagem de vitórias para 'O'
                jogo->vitoriasO++;
		}
		  
		system("cls");
 	 	
		imprimir(jogo);
		printf("\nJogador %c ganhou!",nome);
		jogo->jogoAtivo = 0;
		
		system("pause");
		return;
	}
	
	//Verificar empate
	if(jogo->numJogadas == 9){
		system("cls");
		
		imprimir(jogo);
		printf("DEU EMPATE!\n");
		jogo->empates++;
		jogo->jogoAtivo = 0;
		
		system("pause");
		return;
	}

	
	
}//Fim do verificarGanhador



void main(){
	Tabuleiro jogo;

	int controle;

	while(1){
		
		iniciar(&jogo);
		system("cls");
		fflush(stdin);
		imprimir(&jogo);
		
		printf("\n1 - JOGAR 1 vs 1");
		printf("\n2 - JOGAR 1 vs COM");
		printf("\n0 - SAIR");
		printf("\n>>> ");
		scanf("%d", &controle);
		
		if (controle == 0) {
            break;
        } else if (controle == 1) {
        	
            jogo.vitoriasX = 0;
			jogo.vitoriasO = 0;
			jogo.empates = 0;
			
            while ((jogo.vitoriasX+jogo.vitoriasO+jogo.empates < 4)||(jogo.vitoriasX == 2 && jogo.vitoriasO == 2)) {  
                iniciar(&jogo);
                while(1) {
                	
                    jogada(&jogo, 'X');
                    verificarGanhador(&jogo,'X');
                    if (jogo.jogoAtivo == 0){
						break;
					}
					
                    jogada(&jogo, 'O');
                    verificarGanhador(&jogo,'O');
                    if (jogo.jogoAtivo == 0){
						break;
					}
                }
                if(jogo.vitoriasX == 3 || jogo.vitoriasO == 3){
					break;
				}
                 
            }

            // Exibir o resultado final
            system("cls");
            if (jogo.vitoriasX > jogo.vitoriasO) {  
                printf("Jogador X venceu o jogo!\n");
                
            } else if (jogo.vitoriasO > jogo.vitoriasX) {  
                printf("Jogador O venceu o jogo!\n");
                
            } else {  
                printf("O jogo terminou empatado após a rodada de desempate!\n");
                
            }
			exibirPlacar(&jogo);
            system("pause");
        }else if(controle == 2){
        	
			jogo.vitoriasX = 0;
			jogo.vitoriasO = 0;
			jogo.empates = 0;
			
            while ((jogo.vitoriasX+jogo.vitoriasO+jogo.empates < 4)||(jogo.vitoriasX == 2 && jogo.vitoriasO == 2)) {  
                iniciar(&jogo);
                while(1) {
                	
                    jogada(&jogo, 'X');
                    verificarGanhador(&jogo,'X');
                    if (jogo.jogoAtivo == 0){
						break;
					}
					
                    jogadaComputador(&jogo, 'O');
                    verificarGanhador(&jogo,'O');
                    if (jogo.jogoAtivo == 0){
						break;
					}
                }
                
                if(jogo.vitoriasX == 3 || jogo.vitoriasO == 3){
					break;
				}

            }

            // Exibir o resultado final
            system("cls");
            if (jogo.vitoriasX > jogo.vitoriasO) {  
                printf("Jogador X venceu o jogo!\n");
                
            } else if ((jogo.vitoriasO > jogo.vitoriasX)) {  
                printf("Jogador O venceu o jogo!\n");
                
            } else {  
                printf("O jogo terminou empatado após a rodada de desempate!\n");
                
            }
			exibirPlacar(&jogo);
            system("pause");
            
		} else {
            printf("OPÇÃO INVÁLIDA!\n");
            system("pause");
        }



	}


}// Fim da main


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char matriz[3][3] ;
	int numJogadas ;
	int jogoAtivo ; // 1 para ativo e 0 para jogo finalizado
	int vitoriasX ;
    int vitoriasO ;
    int empates ;
    
}Tabuleiro;

void iniciar(Tabuleiro *jogo){
	int i,j;
	
	jogo->jogoAtivo = 1;
	jogo->numJogadas = 0;

	for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            jogo->matriz[i][j] = ' ';
        }
    }
}//fim do iniciar

void imprimir(Tabuleiro *jogo){
	int i,j;
	printf("---------- JOGO DA IDOSA ----------\n\n");
	printf("    1   2   3\n");
	for (i= 0; i < 3; i++) {
		printf(" %d ", i + 1);
        for (j = 0; j < 3; j++) {
        	printf(" %c ", jogo->matriz[i][j]);
            if(j<2){
				printf("|");
			}
        }
        printf("\n");
        if(i<2){
			printf("   -----------");
		}
		printf("\n");
    }
}//fim do imprimir

void exibirPlacar(Tabuleiro *jogo) {
	
    printf("\n------------PLACAR------------\n");
    printf("Jogador X: %d vitorias\n", jogo->vitoriasX);
    printf("Jogador O: %d vitorias\n", jogo->vitoriasO);
	printf("Empates: %d \n", jogo->empates);
    printf("------------------------------\n\n");
    
}//Fim do exibirPlacar

void jogada(Tabuleiro *jogo,char nome){
	int x;
    int y;
	while(1){
		
			system("cls");
			exibirPlacar(jogo);
			imprimir(jogo);
			printf("------ Jogador %c -----\n",nome);
			fflush(stdin);
			printf("\nLINHA (1-3): ");
			scanf("%d", &x);
        	printf("\nCOLUNA (1-3):");
        	scanf("%d", &y);
        	
        	x--; 
			y--;
			
        	
        	//Validando jogada
        	if(x >= 0 && x < 3 && y >= 0 && y < 3 && jogo->matriz[x][y] == ' '){
				jogo->matriz[x][y] = nome;
				jogo->numJogadas++;
				system("pause");
				break;
			}
			else{
				printf("\nEspaco ja preenchido ou jogada invalida, escolha outro lugar!\n");
				system("pause");
			}
		}
}//Fim do jogada

void jogadaComputador(Tabuleiro *jogo, char nome) {
	
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (jogo->matriz[x][y] != ' ');

    jogo->matriz[x][y] = nome;
    jogo->numJogadas++;
    
} //Fim do jogadaComputador

void verificarGanhador(Tabuleiro *jogo,char nome){
	
	int i;
	
	//Verificar linhas e colunas
	for(i = 0; i < 3; i++) {
    	if((jogo->matriz[i][0] == nome && jogo->matriz[i][1] == nome && jogo->matriz[i][2] == nome)||
		(jogo->matriz[0][i] == nome && jogo->matriz[1][i] == nome && jogo->matriz[2][i] == nome)){
			
			if (nome == 'X') {  //Contagem de vitórias para 'X'
                jogo->vitoriasX ++;
            } else {  //Contagem de vitórias para 'O'
                jogo->vitoriasO ++;
            }
            
			system("cls");
			
			imprimir(jogo);
			printf("\nJogador %c ganhou! ",nome);
			jogo->jogoAtivo = 0;
			
			

			system("pause");
			return;
		}
	}
	
	//Verificar diagonal
	if((jogo->matriz[0][0]==nome && jogo->matriz[1][1]==nome && jogo->matriz[2][2]==nome) || 
 	 (jogo->matriz[0][2]==nome && jogo->matriz[1][1]==nome && jogo->matriz[2][0]==nome)){
 	 	
		if (nome == 'X') {  //Contagem de vitórias para 'X'
                jogo->vitoriasX++;
		} else {  //Contagem de vitórias para 'O'
                jogo->vitoriasO++;
		}
		  
		system("cls");
 	 	
		imprimir(jogo);
		printf("\nJogador %c ganhou!",nome);
		jogo->jogoAtivo = 0;
		
		system("pause");
		return;
	}
	
	//Verificar empate
	if(jogo->numJogadas == 9){
		system("cls");
		
		imprimir(jogo);
		printf("DEU EMPATE!\n");
		jogo->empates++;
		jogo->jogoAtivo = 0;
		
		system("pause");
		return;
	}

	
	
}//Fim do verificarGanhador



void main(){
	Tabuleiro jogo;

	int controle;

	while(1){
		
		iniciar(&jogo);
		system("cls");
		fflush(stdin);
		imprimir(&jogo);
		
		printf("\n1 - JOGAR 1 vs 1");
		printf("\n2 - JOGAR 1 vs COM");
		printf("\n0 - SAIR");
		printf("\n>>> ");
		scanf("%d", &controle);
		
		if (controle == 0) {
            break;
        } else if (controle == 1) {
        	
            jogo.vitoriasX = 0;
			jogo.vitoriasO = 0;
			jogo.empates = 0;
			
            while ((jogo.vitoriasX+jogo.vitoriasO+jogo.empates < 4)||(jogo.vitoriasX == 2 && jogo.vitoriasO == 2)) {  
                iniciar(&jogo);
                while(1) {
                	
                    jogada(&jogo, 'X');
                    verificarGanhador(&jogo,'X');
                    if (jogo.jogoAtivo == 0){
						break;
					}
					
                    jogada(&jogo, 'O');
                    verificarGanhador(&jogo,'O');
                    if (jogo.jogoAtivo == 0){
						break;
					}
                }
                if(jogo.vitoriasX == 3 || jogo.vitoriasO == 3){
					break;
				}
                 
            }

            // Exibir o resultado final
            system("cls");
            if (jogo.vitoriasX > jogo.vitoriasO) {  
                printf("Jogador X venceu o jogo!\n");
                
            } else if (jogo.vitoriasO > jogo.vitoriasX) {  
                printf("Jogador O venceu o jogo!\n");
                
            } else {  
                printf("O jogo terminou empatado após a rodada de desempate!\n");
                
            }
			exibirPlacar(&jogo);
            system("pause");
        }else if(controle == 2){
        	
			jogo.vitoriasX = 0;
			jogo.vitoriasO = 0;
			jogo.empates = 0;
			
            while ((jogo.vitoriasX+jogo.vitoriasO+jogo.empates < 4)||(jogo.vitoriasX == 2 && jogo.vitoriasO == 2)) {  
                iniciar(&jogo);
                while(1) {
                	
                    jogada(&jogo, 'X');
                    verificarGanhador(&jogo,'X');
                    if (jogo.jogoAtivo == 0){
						break;
					}
					
                    jogadaComputador(&jogo, 'O');
                    verificarGanhador(&jogo,'O');
                    if (jogo.jogoAtivo == 0){
						break;
					}
                }
                
                if(jogo.vitoriasX == 3 || jogo.vitoriasO == 3){
					break;
				}

            }

            // Exibir o resultado final
            system("cls");
            if (jogo.vitoriasX > jogo.vitoriasO) {  
                printf("Jogador X venceu o jogo!\n");
                
            } else if ((jogo.vitoriasO > jogo.vitoriasX)) {  
                printf("Jogador O venceu o jogo!\n");
                
            } else {  
                printf("O jogo terminou empatado após a rodada de desempate!\n");
                
            }
			exibirPlacar(&jogo);
            system("pause");
            
		} else {
            printf("OPÇÃO INVÁLIDA!\n");
            system("pause");
        }



	}


}// Fim da main
