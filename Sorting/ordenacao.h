#ifndef ORDENACAO_H
#define ORDENACAO_H

void print_vector(int* vet, int length);

int* vector_new(int length);

void vector_delete(int* vet);

void bubbleSort(int* vet, int length);

void selectionSort(int* vet, int length);

void insertionSort(int* vet, int length);

void countingSort(int* vet, int length);

void quickSort(int* vet, int p, int q);

void mergeSort();

#endif