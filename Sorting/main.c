#include <stdio.h>
#include "ordenacao.h"

int main() {

    int length;
    printf("Enter the size of the vector\n");
    scanf("%d", &length);
    int *v = vector_new(length);

    //bubbleSort(v, length);
    //selectionSort(v, length);
    //insertionSort(v, length);
    //countingSort(v, length);
    quickSort(v, 0, length-1);

    print_vector(v, length);

    vector_delete(v);

    return 0;
}