#ifndef LISTAENCADEADA_LISTA_ENCADEADA_H
#define LISTAENCADEADA_LISTA_ENCADEADA_H

#include <stdbool.h>

struct linked_list_node;
typedef struct linked_list_node * LLNode;

struct linked_list;
typedef struct linked_list * LList;


LList llist_new();
void llist_delete(LList list);

void llist_print(LList list);

int llist_size(LList list);

bool llist_insert_at(LList list, int index, int value);
bool llist_remove_back(LList list);

#endif //LISTAENCADEADA_LISTA_ENCADEADA_H
