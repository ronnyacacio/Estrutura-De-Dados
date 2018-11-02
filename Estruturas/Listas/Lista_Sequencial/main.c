#include <stdio.h>

#include "lista_sequencial.h"

int main() {
    ListaSeq L = list_new();
    int i;

    list_insert_back(L, 20);
    list_insert_back(L, 30);
    list_insert_back(L, 10);
    list_insert_back(L, 80);
    list_insert_back(L, 40);
    list_insert_back(L, 90);
    list_insert_back(L, 50);
    list_insert_back(L, 60);
    list_insert_back(L, 100);
    list_insert_back(L, 120);
    list_insert_back(L, 150);

    for(i = 0;  i < list_size(L); ++i) {
        printf("%d ", list_at(L, i));
    }
    printf("\n");

    list_delete(L);

    return 0;
}