#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "qxdvector.h"
#include "qxddefs.h"

struct __qxd_vector
{
	int* vetor;
	size_t tamanho;
	int ultimo;
};

QxVector qx_vector_new(size_t capacity){
	QxVector vector = malloc(sizeof(struct __qxd_vector));
	vector->vetor = malloc(capacity * sizeof(int));
	vector->tamanho = capacity;
	vector->ultimo = -1;
	return vector;
}

void qx_vector_delete(QxVector vector){
	if(vector->tamanho > 0) {
        free(vector->vetor);
    }

    free(vector);
}

size_t qx_vector_size(QxVector vector){
	return vector->ultimo+1;
}

size_t qx_vector_capacity(QxVector vector){
	return vector->tamanho;
}

bool qx_vector_empty(QxVector vector){
	if(vector->ultimo >= 0)
		return false;
	else
		return true;
}

bool qx_vector_full(QxVector vector){
	if(vector->ultimo+1 == vector->tamanho)
		return true;
	else
		return false;
}

bool qx_vector_contains(QxVector vector, int element){
	for (int i = 0; i <= vector->ultimo; ++i){
		if(vector->vetor[i] == element){
			return true;
		}
	}
	return false;
}

qxIndex qx_vector_find(QxVector vector, int element, qxIndex fromIndex){
	if(vector->ultimo >= 0){
		for (int i = fromIndex; i <= vector->ultimo; ++i){
			if(vector->vetor[i] == element){
				return i;
			}
		}
	}
	return QX_LAMBDA_INDEX;
}

qxIndex qx_vector_find_last(QxVector vector, int element, qxIndex upToIndex){
	if(vector->ultimo >= 0){
		for (int i = 0; i <= upToIndex; ++i){
			if(vector->vetor[i] == element){
				return i;
			}
		}
	}
	return QX_LAMBDA_INDEX;
}

int qx_vector_at(QxVector vector, qxIndex index){
	if(index <= vector->ultimo && index >=0){
		return vector->vetor[index];
	}
	return QX_LAMBDA_ELEMENT;
}

int qx_vector_font(QxVector vector){
	if(vector->ultimo >= 0){
		return vector->vetor[0];
	}
	return QX_LAMBDA_ELEMENT;
}

int qx_vector_back(QxVector vector){
	if(vector->ultimo >= 0){
		return vector->vetor[vector->ultimo];
	}
	return QX_LAMBDA_ELEMENT; 
}

bool qx_vector_insert_at(QxVector vector, int element, qxIndex index){
	if(index != QX_LAMBDA_ELEMENT){	
		if(vector->tamanho-1 == vector->ultimo){
			vector->vetor = realloc(vector->vetor, sizeof(int)*(vector->tamanho+10));
	    	vector->tamanho += 10;
		}
		if(index > vector->ultimo){
			index = vector->ultimo;
		}
		if(vector->ultimo >= 0){
			int temp = vector->vetor[index];
			vector->vetor[index] = element;
			vector->vetor[vector->ultimo+1] = temp;
			vector->ultimo += 1;
			return true;
		} else {
			vector->vetor[0] = element;
			vector->ultimo++;
		}
	}
	return false;
}

void qx_vector_push_front(QxVector vector, int element){
	if(element != QX_LAMBDA_ELEMENT){
		if(vector->tamanho-1 == vector->ultimo){
			vector->vetor = realloc(vector->vetor, sizeof(int)*(vector->tamanho+10));
	    	vector->tamanho += 1;
		}
		if(vector->ultimo >= 0){
			int temp = vector->vetor[0];
			vector->vetor[0] = element;
			vector->vetor[vector->ultimo+1] = temp;
			vector->ultimo += 1;
		} else {
			vector->vetor[0] = element;
			vector->ultimo++;
		}
	}
}

void qx_vector_push_back(QxVector vector, int element){
	if(element != QX_LAMBDA_ELEMENT){
		if(vector->tamanho-1 == vector->ultimo){
			vector->vetor = realloc(vector->vetor, sizeof(int)*(vector->tamanho+10));
	    	vector->tamanho += 10;
		}
		vector->ultimo++;
		vector->vetor[vector->ultimo] = element;
	}
}

qxIndex qx_vector_remove_element_first(QxVector vector, int element){
	if(vector->ultimo >= 0){
		for (int i = 0; i <= vector->ultimo; ++i){
			if(vector->vetor[i] == element){
				vector->vetor[i] = vector->vetor[vector->ultimo];
				vector->ultimo--;
				return i;
			}
		}
	}
	return QX_LAMBDA_INDEX;
}

qxIndex qx_vector_remove_element_last(QxVector vector, int element){
	if(vector->ultimo >= 0){
		for (int i = vector->ultimo; i >= 0; --i){
			if(vector->vetor[i] == element){
				vector->vetor[i] = vector->vetor[vector->ultimo];
				vector->ultimo--;
				return i;
			}
		}
	}
	return QX_LAMBDA_INDEX;
}

unsigned int qx_vector_remove_element_all(QxVector vector, int element){
	if(vector->ultimo >= 0){
		int cont = 0;
		for (int i = 0; i <= vector->ultimo; ++i){
			if(vector->vetor[i] == element){
				vector->vetor[i] = vector->vetor[vector->ultimo];
				vector->ultimo--;
				cont++;
			}
		}
		return cont;
	}
	return QX_LAMBDA_ELEMENT;
}

bool qx_vector_remove_at(QxVector vector, qxIndex index){
	if(index != QX_LAMBDA_INDEX){
		if(vector->ultimo >= 0){
			vector->vetor[index] = vector->vetor[vector->ultimo];
			vector->ultimo--;
			return true;
		} else {
			return false;
		}
	}
	return false;
}

void qx_vector_pop_front(QxVector vector){
	if(vector->ultimo >= 0){
		vector->vetor[0] = vector->vetor[vector->ultimo];
		vector->ultimo--;
	}
}

void qx_vector_pop_back(QxVector vector){
	if(vector->ultimo >= 0){
		vector->ultimo--;
	}
}

void qx_vector_print_to(QxVector vector, FILE *fp){
	fp = fopen("qx_vector_print_to.txt", "w");
	if(vector->ultimo >= 0){
		fprintf(fp, "ELEMENTOS DA LISTA.\n");
		fprintf(fp, "[");
		for (int i = 0; i <= vector->ultimo; ++i){
			fprintf(fp, "%d, ", vector->vetor[i]);
		}
		fprintf(fp, "]");
		fclose(fp);
	} else {
		fprintf(fp, "AINDA NÃO EXISTEM ELEMENTOS NA LISTA.\n");
		fclose(fp);
	}
}