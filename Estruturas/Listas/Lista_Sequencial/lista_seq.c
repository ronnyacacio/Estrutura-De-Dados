#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"lista_sequencial.h"


struct lista_seq{
    int *vetor;
    int tamanho;//quant. de pos. do vetor
    int ultimo;
};

Listaseq list_new(){

    Listaseq nova_lista= malloc(sizeof(struct lista_seq));

    nova_lista-> vetor=malloc(10*sizeof(int));
    nova_lista-> tamanho=10;
    nova_lista-> ultimo=-1;

    return nova_lista;
}

void list_delete(Listaseq lista){
    if(lista->tamanho>0){
        free(lista->vetor);
    }
    free(lista);
}

int list_size(Listaseq lista){
    return lista->ultimo+1;
}

int list_at(Listaseq lista, int indice){
    if(indice < 0 || indice > lista->ultimo){
        return INT_MIN;
    }
    return lista->vetor[indice];
}

void list_print(Listaseq lista){
    int i;
    printf("[");
    for(i=0; i<= lista->ultimo; ++i){
        printf("%d ", lista->vetor[i]);
    }
    printf("]\n");
}


void list_realloc(Listaseq lista, int incr){
    lista->vetor=realloc(lista->vetor, lista->tamanho+10*sizeof(int));
    lista->tamanho += incr;
}

void list_insert_back(Listaseq lista, int elem){

    if(elem != INT_MIN){
        if(lista->ultimo >= lista->tamanho-1){
            //lista está cheia. realocacando o tamamanho
            list_realloc(lista, 10);
        }
        lista->vetor[++lista->ultimo]=elem;
    }
}

int list_remove_front(Listaseq lista){

    if(lista->ultimo>=0){
        int temp= lista->vetor[0];

        lista->vetor[0]=lista->vetor[lista->ultimo];
        --lista->ultimo;

        return temp;
    }

    return INT_MIN;
}

int list_find_first(Listaseq lista, int elem){
    int i;

    for(i=0; i<=lista->ultimo; ++i){
        if(lista->vetor[i] == elem){
            return i;
        }
    }
    return -1;
}
