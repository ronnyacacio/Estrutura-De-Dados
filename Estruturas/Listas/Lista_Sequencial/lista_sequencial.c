//
// Created by araruna on 15/10/18.
//

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#include "lista_sequencial.h"

struct lista_seq {
    int *vetor;
    int tamanho;
    int ultimo;
};


ListaSeq list_new() {
    ListaSeq nova_lista = malloc(sizeof(struct lista_seq));

    nova_lista->vetor = malloc(10*sizeof(int));
    nova_lista->tamanho = 10;
    nova_lista->ultimo = -1;

    return nova_lista;
}

void list_delete(ListaSeq lista) {
    if(lista->tamanho > 0) {
        free(lista->vetor);
    }

    free(lista);
}

int list_size(ListaSeq lista) {
    return lista->ultimo + 1;
}

int list_at(ListaSeq lista, int indice) {
    if(indice < 0 || indice > lista->ultimo) {
        return INT_MIN;
    }

    return lista->vetor[indice];
}

void list_print(ListaSeq lista) {
    int i;
    printf("[");
    for(i = 0; i <= lista->ultimo; ++i) {
        printf("%d ", lista->vetor[i]);
    }
    printf("]\n");
}

void list_resize(ListaSeq lista, int incr) {
    lista->vetor = realloc(lista->vetor, sizeof(int)*(lista->tamanho + incr));
    lista->tamanho += incr;
}

void list_insert_back(ListaSeq lista, int elem) {
    if(elem != INT_MIN) {
        if (lista->ultimo >= lista->tamanho - 1) {
            // Lista está cheia. Realocar!
            list_resize(lista, 10);
        }

        lista->vetor[++lista->ultimo] = elem;
    }
}

int list_remove_front(ListaSeq lista) {
    if(lista->ultimo >= 0) {
        int temp = lista->vetor[0];

        lista->vetor[0] = lista->vetor[lista->ultimo--];

        return temp;
    }

    return INT_MIN;
}

int list_find_first(ListaSeq lista, int elem) {
    int i;
    for(i = 0; i <= lista->ultimo; ++i) {
        if(lista->vetor[i] == elem) {
            return i;
        }
    }

    return -1;
}




