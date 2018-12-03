#include <stdio.h>
#include <stdlib.h>
#include "qxddefs.h"
#include "qxdstack.h"

struct __qxd_stack{
	int* array;
	size_t initCapacity;
	int top;
};

QxStack qx_stack_new(size_t initCapacity){
	QxStack stack = malloc(sizeof(struct __qxd_stack));
	stack->array = malloc(initCapacity*(sizeof(int)));
	stack->top = -1;
	stack->initCapacity = initCapacity;
}

void qx_stack_delete(QxStack stack){
	free(stack->array);
	free(stack);
}

size_t qx_stack_size(QxStack stack){
	int size = 0;
	for(int i = 0; i <= stack->top; ++i){
		size++;
	}
	return size;
}

size_t qx_stack_capacity(QxStack stack){
	return stack->initCapacity - (stack->top+1);
}

bool qx_stack_empty(QxStack stack){
	if(stack->top == -1){
		return true;
	}
	return false;
}

bool qx_stack_full(QxStack stack){
	if(stack->top+1 == stack->initCapacity){
		return true;
	}
	return false;
}

int qx_stack_top(QxStack stack){
	if(stack->top != -1){
		return QX_LAMBDA_ELEMENT;
	}
	return stack->array[stack->top];
}

bool qx_stack_contains(QxStack stack, int element){
	for(int i = 0; i <= stack->top; ++i){
		if(stack->array[i] == element){
			return true;
		}
	}
	return false;
}

size_t qx_stack_find(QxStack stack, int element){
	if(stack->top >= 0){
		int temp;
		for(int i = 0; i <= stack->top; ++i){
			if(stack->array[i] == element){
				temp = i;
			}
		}
		return stack->top - (temp);
	}
	return QX_LAMBDA_ELEMENT;
}

void qx_stack_push(QxStack stack, int elem){
	if(qx_stack_full(stack)){
		stack->array = realloc(stack->array, sizeof(int)*(stack->initCapacity+10));
	}
	stack->top++;
	stack->array[stack->top] = elem;
}

void qx_stack_pop(QxStack stack){
	if(qx_stack_empty(stack)){
		return;
	}
	stack->top--;
}

void qx_stack_clear(QxStack stack){
	stack->top = -1;
}

void qx_stack_print_to(QxStack stack, FILE *fp){
	fp = fopen("qx_stack_print_to.txt", "w");
	if(stack->top >= 0){
		fprintf(fp, "ELEMENTOS DA PILHA.\n");
		fprintf(fp, "[");
		for (int i = 0; i <= stack->top; ++i){
			fprintf(fp, "%d, ", stack->array[i]);
		}
		fprintf(fp, "]");
		fclose(fp);
	} else {
		fprintf(fp, "AINDA NÃO EXISTEM ELEMENTOS NA PILHA.\n");
		fclose(fp);
	}
}