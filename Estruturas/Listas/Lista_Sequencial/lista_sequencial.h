//
// Created by araruna on 15/10/18.
//

#ifndef LISTASEQUENCIAL_LISTA_SEQUENCIAL_H
#define LISTASEQUENCIAL_LISTA_SEQUENCIAL_H

struct lista_seq;

typedef struct lista_seq * ListaSeq;

ListaSeq list_new();
void list_delete(ListaSeq lista);

int list_size(ListaSeq lista);

int list_at(ListaSeq lista, int indice);

void list_print(ListaSeq lista);

void list_insert_back(ListaSeq lista, int elem);

#endif //LISTASEQUENCIAL_LISTA_SEQUENCIAL_H
