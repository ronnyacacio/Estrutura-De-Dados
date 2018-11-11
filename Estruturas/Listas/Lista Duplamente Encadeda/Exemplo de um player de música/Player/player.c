#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musicas {
    char music[11];
    LLNode next;
    LLNode back;
};

struct player {
    LLNode first;
    int status;
    LLNode atual;
};

LList player_new(){
    LList list = malloc(sizeof(struct player));
    list->status = 1;
    list->first = NULL;
    list->atual = NULL;

    return list;
}

void setStatus(LList list, int value){
    list->status = value;
}

LLNode music_new(char music[]) {
    LLNode node = malloc(sizeof(struct musicas));

    strcpy(node->music, music);
    node->next = NULL;
    node->back = NULL;

    return node;
}

void music_delete(LLNode node) {
    free(node);
}

void music_delete_recursive(LLNode node) {
    if(node != NULL) {
        music_delete_recursive(node->next);
        free(node);
    }
}

void tocar(LList list){
    list->status = 0;
}

void pausar(LList list){
    list->status = 1;
}

void parar(LList list){
    list->status = 2;
    list->atual = list->first;
}

void avancar(LList list){
    list->atual = list->atual->next;
}

void retroceder(LList list){
    list->atual = list->atual->back;
}

void mostrar(LList list){
    LLNode node = list->first;
    if(node == NULL){
        printf("Ainda não existe músicas no player!\n");
    } else if(node->next == node){
        printf("(0) %s\n", node->music);
    } else {
        int index = -1;
        while(node != list->first->back){
            index++;
            int temp = strcmp(node->music, list->atual->music);
            if(temp == 0){
                printf("(%d) %s\n", index, node->music);
            } else {
                printf("%d %s\n", index, node->music);
            }
            node = node->next;
        }
        int temp = strcmp(node->music, list->atual->music);
        if(temp == 0){
            printf("(%d) %s\n", index+1, node->music);
        } else {
            printf("%d %s\n", index+1, node->music);
        }
    }    
}

bool adicionar(LList list, char music[], int pos){
    if(pos >= 0){
        LLNode node = music_new(music);
        LLNode antnode = list->first;
        if(antnode == NULL){
            list->first = node;
            list->atual = node;
            node->next = node;
            node->back = node;
            return true;
        } else {
            int antindex = 0;
            while(antindex < pos && antnode->next != list->first){
                ++antindex;
                antnode = antnode->next;
            }
            if(antindex == 0){
                node->next = antnode;
                node->back = antnode->back;
                antnode->back->next = node;
                antnode->back = node;
                list->first = node;
            } else if(antindex == pos) {
                node->next = antnode;
                node->back = antnode->back;
                antnode->back->next = node;
                antnode->back = node;
            } else if(antindex < pos){
                node->next = list->first;
                node->back = antnode;
                antnode->next = node;
                list->first->back = node;
            }
        }
        return true;
    }
    return false;
}

void remover(LList list, int pos){
    if(pos >= 0){
        LLNode antnode = list->first;
        if(antnode != NULL){    
            int antindex = 0;
            while(antindex < pos && antnode->next != list->first){
                ++antindex;
                antnode = antnode->next;
           }
            antnode->back->next = antnode->next;
            antnode->next->back = antnode->back;
            if(pos == 0){
                if(antnode->next != antnode){
                list->first = antnode->next;
                list->atual = antnode->next;
                } else {
                    list->first = NULL;
                    list->atual = NULL;
                }   
            }
            music_delete(antnode);
            printf("Música removida com sucesso!\n");
        }
    } else {
       printf("Não existem músicas no player!\n");
    }
}

int estado_atual(LList list){
    return list->status;
}

void encerrar(LList list){
    music_delete_recursive(list->first);
    free(list);
}

int chamarMenu(){
    int opcao;
    printf("---------------------------\n");
    printf("Digite 1 para tocar;\n");
    printf("Digite 2 para pausar;\n");
    printf("Digite 3 para parar;\n");
    printf("Digite 4 para avançar;\n");
    printf("Digite 5 para retroceder;\n");
    printf("Digite 6 para mostrar;\n");
    printf("Digite 7 para adicionar;\n");
    printf("Digite 8 para remover;\n");
    printf("Digite 9 para ver o estado atual;\n");
    printf("Digite 10 para encerrar!\n\n");
    printf("Opcão: ");
    scanf("%d", &opcao);
    printf("---------------------------\n");
    return opcao;
}
