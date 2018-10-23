#include<stdio.h>
#include"lista_sequencial.h"

int main()
{
    Listaseq L=list_new();

    list_insert_back(L, 20);
    list_insert_back(L, 30);
    list_insert_back(L, 10);
    list_insert_back(L, 80);
    list_insert_back(L, 40);
    list_insert_back(L, 90);
    list_insert_back(L, 50);
    list_insert_back(L, 80);
    list_insert_back(L, 40);
    list_insert_back(L, 90);
    list_insert_back(L, 50);

    list_print(L);

    printf( "\n%d\n" ,list_size(L));

    list_delete(L);
    return 0;
}
