#include <stdio.h>
#include <stdlib.h>
#include "qxbuffer.h"
#include "qxddefs.h"

struct __qxd_buffer{
	int* array;
	int start;
	int last;
	size_t capacity;
};

QxBuffer qx_buffer_new(size_t capacity){
	QxBuffer buffer = malloc(sizeof(struct __qxd_buffer));
	buffer->array = malloc(capacity*(sizeof(int)));
	buffer->start = -1;
	buffer->last = -1;
	buffer->capacity = capacity;
}

void qx_buffer_delete(QxBuffer buffer){
	free(buffer->array);
	free(buffer);
}

size_t qx_buffer_size(QxBuffer buffer){
	int cont = 0;
	if(buffer->start != -1){
		if(qx_buffer_full(buffer)){
			return buffer->capacity;
		}
		for(int i = buffer->start; i != buffer->last; i = (i+1)%buffer->capacity ){
			cont++;
		}
	}
	return cont;
}

size_t qx_buffer_capacity(QxBuffer buffer){
	int cont = 0;
	if(buffer->start != -1){
		if(qx_buffer_full(buffer)){
			return cont;
		}
		for(int i = buffer->start; i != buffer->last; i = (i+1)%buffer->capacity ){
			cont++;
		}
	}
	return buffer->capacity - cont;
}

bool qx_buffer_empty(QxBuffer buffer){
	if(buffer->start == -1){
		return true;
	}
	return false;
}

bool qx_buffer_full(QxBuffer buffer){
	if(buffer->start == buffer->last && buffer->start != -1){
		return true;
	}
	return false;
}

int qx_buffer_font(QxBuffer buffer){
	if(qx_buffer_empty(buffer))
		return QX_LAMBDA_ELEMENT;
	return buffer->array[buffer->start];
}

int qx_buffer_back(QxBuffer buffer){
	if(qx_buffer_empty(buffer))
		return QX_LAMBDA_ELEMENT;
	if(buffer->last-1 < 0)
		return buffer->array[buffer->capacity];
	else
		return buffer->array[buffer->last-1];
}

void qx_buffer_enqueue(QxBuffer buffer, int elem){
	if(qx_buffer_full(buffer)){
		return;
	}
	if(qx_buffer_empty(buffer)){
		buffer->last += 2;
		buffer->start++;
		buffer->array[buffer->start] = elem;
		return;
	}
	buffer->array[buffer->last] = elem;
	buffer->last = (buffer->last+1)%buffer->capacity;
}

void qx_buffer_dequeue(QxBuffer buffer){
	if(qx_buffer_empty(buffer))
		return;
	if(qx_buffer_size(buffer) == 1){
		buffer->start = -1;
		buffer->last = -1;
		return;
	}
	buffer->start = (buffer->start+1)%buffer->capacity;
}	

size_t qx_buffer_move(QxBuffer buffer, QxBuffer to){
	int cont = 0;
	while(qx_buffer_empty(buffer) == false && qx_buffer_full(to) == false){
		qx_buffer_enqueue(to, buffer->array[buffer->start]);
		qx_buffer_dequeue(buffer);
		cont++;
	}
	return cont;
}

void qx_buffer_clear(QxBuffer buffer){
	buffer->last = -1;
	buffer->start = -1;
}

void qx_buffer_print_to(QxBuffer buffer, FILE *fp){
	fp = fopen("qx_buffer_print_to.txt", "w");
	if(qx_buffer_empty(buffer)){
		fprintf(fp, "AINDA NÃO EXISTEM ELEMENTOS NO BUFFER.\n");
		fclose(fp);
	} else {
		fprintf(fp, "ELEMENTOS DO BUFFER.\n");
		fprintf(fp, "[");
		buffer->last--;
		int flag = 0;
		for (int i = buffer->start; i != buffer->last; i = (i+1)%buffer->capacity){
			if(flag == 0){
				buffer->last++;
				flag++;
			}
			fprintf(fp, "%d, ", buffer->array[i]);
		}
		fprintf(fp, "]");
		fclose(fp);
	}
}