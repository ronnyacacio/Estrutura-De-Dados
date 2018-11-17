#include <stdio.h>
#include <stdlib.h>
#include "qxdsorting.h"
#include "qxddefs.h"

void qx_insertion_sort(int array[], size_t num_elems){
	for (int i = 1; i < num_elems; i++) {
        int value = array[i];
        int j = i-1;

        while ((j >= 0) && (array[j] > value)) {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = value;
    }
}

void qx_selection_sort(int array[], size_t num_elems){
	int i, j, min, temp;
     for (i = 0; i < (num_elems-1); i++) {
         min = i;
         for (j = (i+1); j < num_elems; j++) {
             if(array[j] < array[min])
                 min = j;
         }
         if (array[i] != array[min]) {
             temp = array[i];
             array[i] = array[min];
             array[min] = temp;
         }
     }
}

void qx_bubble_sort(int array[], size_t num_elems){
	int i, j, temp;
    for (i = 0; i < num_elems - 1; i++){
        for (j = (i+1); j < num_elems; j++){
            if (array[j] < array[i]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void entrelacar(int v[], int p, int m, int q){
    int i, j, k, *w;
    w=(int*)malloc(q-p*(sizeof(int)));
    int n1=m-p+1;
    int n2=q-m;
    int m1[n1], m2[n2];

    for (i = 0; i < n1; i++) 
        m1[i] = v[p + i]; 
    for (j = 0; j < n2; j++) 
        m2[j] = v[m + 1+ j]; 

    i=0;
    j=0;
    k=p;

    while(i<n1 && j<n2){
        if(m1[i]<=m2[j]){
            v[k]=m1[i];
            i++;
        }
        else{
            v[k]=m2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        v[k]=m1[i];
        i++;
        k++;
    }
    while(j<n2){
        v[k]=m2[j];
        j++;
        k++;
    }
    
}

void mergeSort(int v[], int p, int q){
    if(p<q){
        int m=(p+q)/2;
        mergeSort(v, p, m);
        mergeSort(v, m+1, q);
        entrelacar(v, p, m, q); 
    }
}

void qx_merge_sort(int array[], size_t num_elems){
    mergeSort(array, 0, num_elems-1);
}

int partitioning(int array[], int p, int q){
    int i = p-1;
    int temp;
    int j;
    for (j = p; j < q ; j++) {
        if(array[j] <= array[q]){
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i+1];
    array[i+1] = array[j];
    array[j] = temp;
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

void qx_quick_sort(int array[], size_t num_elems){
	quickSort(array, 0, num_elems-1);
}

void qx_counting_sort(int array[], size_t num_elems, int min_val, int max_val){
    int temp[max_val-min_val+1];
    for(int i = 0; i <= max_val-min_val; i++){
        temp[i] = 0;
    }
    for (int i = 0; i < num_elems; i++) {
        temp[array[i]-min_val]++;
    }
    int j = 0;
    for (int i = 0; i <= max_val-min_val; i++) {
        if(temp[i] != 0){
            array[j] = i+min_val;
            temp[i]--;
            i--;
            j++;
        }
    }
}

void qx_radix_sort_i(int array[], size_t num_elems){
    int i;
    int *b;
    int maior = array[0];
    int exp = 1;

    b = (int *)calloc(num_elems, sizeof(int));

    for (i = 0; i < num_elems; i++) {
        if (array[i] > maior)
            maior = array[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
        for (i = 0; i < num_elems; i++)
            bucket[(array[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = num_elems - 1; i >= 0; i--)
            b[--bucket[(array[i] / exp) % 10]] = array[i];
        for (i = 0; i < num_elems; i++)
            array[i] = b[i];
        exp *= 10;
    }

    free(b);
}

void qx_radix_sort_f(float array[], size_t num_elems, short precision){
    
}