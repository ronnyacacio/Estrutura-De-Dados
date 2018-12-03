#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "qxqueue.h"
#include "qxddefs.h"

typedef struct node{
	int value;
	struct node* next;
}Node;

struct __qxd_queue{
	Node* first;
	Node* last;
};

QxQueue qx_queue_new(){
	QxQueue queue = malloc(sizeof(struct __qxd_queue));
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

Node* qxqueue_node_new(int value) {
    Node* node = malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

void qx_recursive_delete(Node* node){
	if(node != NULL) {
        qx_recursive_delete(node->next);
        free(node);
    }
}

void qx_queue_clear(QxQueue queue){
	qx_recursive_delete(queue->first);
	queue->first = NULL;
}

void qx_queue_delete(QxQueue queue){
	qx_queue_clear(queue);
	free(queue);
}

size_t qx_queue_size(QxQueue queue){
	Node* antnode = queue->first;
	int contnode = 0;
	while(antnode != NULL){
		contnode++;
		antnode = antnode->next;
	}
	return contnode;
}

bool qx_queue_empty(QxQueue queue){
	if(queue->first == NULL)
		return true;
	else
		return false;
}

bool qx_queue_contains(QxQueue queue, int element){
	Node* node = queue->first;
	while(node != NULL){
		if(node->value == element)
			return true;
		node = node->next;
	}
	return false;
}

size_t qx_queue_find(QxQueue queue, int element){
	Node* node = queue->first;
	Node* comparnode = NULL;
	int flag = 0;
	while(node != NULL && flag == 0){
		if(node->value == element){
			comparnode = node;
			flag++;
		}
		node = node->next;
	}
	node = queue->first;
	int cont = -1;
	while(node != comparnode && comparnode != NULL){
		node = node->next;
		cont++;
	}
	if(cont != -1){
		return cont+1;
	}
	return QX_LAMBDA_ELEMENT;
}

int qx_queue_font(QxQueue queue){
	if(queue->first != NULL){
		return queue->first->value;
	}
	return QX_LAMBDA_ELEMENT;
}

int qx_queue_back(QxQueue queue){
	if(queue->first != NULL){
		return queue->last->value;
	}
	return QX_LAMBDA_ELEMENT;
}

void qx_queue_enqueue(QxQueue queue, int elem){
	Node* node = qxqueue_node_new(elem);
	if(queue->first == NULL){
		queue->first = node;
		queue->last = node;
	} else {
		queue->last->next = node;
		queue->last = node;
	}
}

void qx_queue_dequeue(QxQueue queue){
	if(queue->first != NULL){
		Node* node = queue->first->next;
		free(queue->first);
		queue->first = node;
	}
}

void qx_queue_print_to(QxQueue queue, FILE *fp){
	fp = fopen("qx_queue_print_to.txt", "w");
	if(queue->first != NULL){
		fprintf(fp, "ELEMENTOS DA FILA.\n");
		fprintf(fp, "[");
		Node* antnode = queue->first;
		while(antnode != NULL){
			fprintf(fp, "%d, ", antnode->value);
			antnode = antnode->next;
		}
		fprintf(fp, "]");
		fclose(fp);
	} else {
		fprintf(fp, "AINDA NÃO EXISTEM ELEMENTOS NA FILA.\n");
		fclose(fp);
	}
}
