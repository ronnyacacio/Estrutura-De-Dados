#include "player.h"
#include <stdio.h>
#include <stdbool.h>

int main(){

	LList player = player_new();
    int opcao;
    while(opcao != 10){
		opcao = chamarMenu();
		if(opcao == 1){
			setStatus(player, 0);
		} else if(opcao == 2){
			setStatus(player, 1);
		} else if(opcao == 3){
			setStatus(player, 2);
		} else if(opcao == 4){
			avancar(player);
		} else if(opcao == 5){
			retroceder(player);
		} else if(opcao == 6){
			mostrar(player);
		} else if(opcao == 7){
			char music[11];
			int pos;
			printf("Digite o nome da nova musica: ");
			scanf(" %[^\n]", music);
			printf("Digite o índice da nova música: ");
			scanf("%d", &pos);
			bool temp = adicionar(player, music, pos);
			if(temp){
				printf("Música adicionada com sucesso!\n");
			} else {
				printf("Falha na adição!\n");
			}
		} else if(opcao == 8){
			int pos;
			scanf("%d", &pos);
			bool temp = remover(player, pos);
			if(temp){
				printf("Música removida com sucesso!\n");
			} else {
				printf("Falha na remoção!\n");
			}
		} else if(opcao == 9){
			int estado = estado_atual(player);
			if(estado == 0){
				printf("Tocando!\n");
			} else if(estado == 1){ 
				printf("Pausado!\n");
			} else {
				printf("Parado!\n");
			}
		} else if(opcao == 10){
			encerrar(player);
		} else {
			printf("Digite outro número!\n");
		}
	}

    return 0;
}
