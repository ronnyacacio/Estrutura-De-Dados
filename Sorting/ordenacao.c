#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

void print_vector(int* vet, int length){
    for(int i = 0; i < length; i++){
        printf("%d ", vet[i]);
    }
}

int* vector_new(int length){

    int* vet= malloc(10*sizeof(int));
    printf("Fill in the vector!\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &vet[i]);
    }
    return vet;
}

void vector_delete(int* vet){
    free(vet);
}


void bubbleSort( int* vet, int length ) {
    int i, j, temp;

    for (i = 0; i < length - 1; i++){
        for (j = (i+1); j < length; j++){
            if (vet[j] < vet[i]){
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}

void selectionSort(int* vet, int length){
     int i, j, min, temp;
     for (i = 0; i < (length-1); i++) {
         min = i;
         for (j = (i+1); j < length; j++) {
             if(vet[j] < vet[min])
                 min = j;
         }
         if (vet[i] != vet[min]) {
             temp = vet[i];
             vet[i] = vet[min];
             vet[min] = temp;
         }
     }
}

void insertionSort(int* vet, int length){
    for (int i = 1; i < length; i++) {
        int value = vet[i];
        int j = i-1;

        while ((j >= 0) && (vet[j] > value)) {
            vet[j+1] = vet[j];
            j--;
        }

        vet[j+1] = value;
    }
}

void countingSort(int* vet, int length){
    int max = vet[0];
    for(int i = 0; i < length; i++){
        if(vet[i] > max){
            max = vet[i];
        }
    }
    int temp[max+1];
    for(int i = 0; i < max+1; i++){
        temp[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        temp[vet[i]]++;
    }
    int j = 0;
    for (int i = 0; i <= max; i++) {
        if(temp[i] != 0){
            vet[j] = i;
            temp[i]--;
            i--;
            j++;
        }
    }
}

int partitioning(int* vet, int p, int q){
    int i = p-1;
    int temp;
    int j;
    for (int j = p; j < q ; j++) {
        if(vet[j] <= vet[q]){
            i++;
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }
    temp = vet[i+1];
    vet[i+1] = vet[j];
    vet[j] = temp;
    return i+1;
}
void quickSort(int* vet, int p, int q){
    if(p >= q){
        return;
    }
    int pivo = partitioning(vet, p, q);
    quickSort(vet, p, pivo-1);
    quickSort(vet, pivo+1, q);
}


