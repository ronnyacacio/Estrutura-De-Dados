#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

struct lista_seq;
typedef struct lista_seq *Listaseq;

Listaseq list_new();

int list_at(Listaseq lista, int indice);

int list_size(Listaseq lista);

void list_delete(Listaseq lista);

void list_print(Listaseq lista);

void list_insert_back(Listaseq lista, int elem);

int list_size(Listaseq lista);

int list_remove_front(Listaseq lista);

int list_find_first(Listaseq lista, int elem);

#endif //LISTA_SEQUENCIAL_H