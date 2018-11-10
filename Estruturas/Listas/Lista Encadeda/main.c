#include "lista_encadeada.h"

#include <stdio.h>

int main() {
    LList list = llist_new();

    llist_insert_at(list, 0, 2);
    llist_insert_at(list, 0, 8);
    llist_insert_at(list, 1, 9);
    llist_insert_at(list, 0, 3);
    llist_insert_at(list, 2, 5);
    llist_insert_at(list, 0, 0);
    llist_insert_at(list, 3, 1);

    llist_remove_back(list);
    llist_remove_back(list);
    llist_remove_back(list);

    llist_insert_at(list, 0, 5);
    llist_insert_at(list, 1, 9);
    llist_insert_at(list, 4, 2);

    llist_print(list);

    return 0;
}