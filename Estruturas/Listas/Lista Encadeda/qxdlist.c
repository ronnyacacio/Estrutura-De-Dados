#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "qxdlist.h"
#include "qxddefs.h"

typedef struct node{
	int value;
	struct node* next;
}Node;

struct __qxd_list{
	Node* first;
};

QxList qx_list_new(){
	QxList list = malloc(sizeof(struct __qxd_list));
	list->first = NULL;
	return list;
}

Node* qxlist_node_new(int value) {
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

void qx_list_clear(QxList list){
	qx_recursive_delete(list->first);
	list->first = NULL;
}

void qx_list_delete(QxList list){
	qx_list_clear(list);
	free(list);
}

size_t qx_list_size(QxList list){
	Node* antnode = list->first;
	int contnode = 0;
	while(antnode != NULL){
		contnode++;
		antnode = antnode->next;
	}
	return contnode;
}

bool qx_list_empty(QxList list){
	if(list->first == NULL)
		return true;
	else
		return false;
}

bool qx_list_contains(QxList list, int element){
	Node* node = list->first;
	while(node != NULL){
		if(node->value == element)
			return true;
		node = node->next;
	}
	return false;
}

qxIndex qx_list_find(QxList list, int element, qxIndex fromIndex){
	Node* node = list->first;
	int contnode = 0;
	while(node != NULL){
		if(node->value == element && contnode >= fromIndex)
			return contnode;
		node = node->next;
		contnode++;
	}
	return QX_LAMBDA_INDEX;
}

qxIndex qx_list_find_last(QxList list, int element, qxIndex upToIndex){
	Node* node = list->first;
	int contnode = 0;
	int contreturn = -1;
	while(node != NULL && contnode <=upToIndex){
		if(node->value == element)
			contreturn = contnode;
		node = node->next;
		contnode++;
	}
	if(contreturn >= 0)
		return contreturn;
	else
		return QX_LAMBDA_INDEX;
}

int qx_list_at(QxList list, qxIndex index){
	Node* node = list->first;
	int contnode = 0;
	while(node != NULL){
		node = node->next;
		contnode++;
	}
	if(index >= 0 && index <= contnode){
		Node* node = list->first;
		contnode = 0;
		while(node != NULL){
			if(contnode == index)
				return node->value;
			node = node->next;
			contnode++;
		}
	}
	return QX_LAMBDA_ELEMENT;
}

int qx_list_font(QxList list){
	if(list->first != NULL)
		return list->first->value;
	return QX_LAMBDA_ELEMENT;
}

int qx_list_back(QxList list){
	Node* node = list->first;
	while(node != NULL){
		if(node->next == NULL)
			return node->value;
		node = node->next;
	}
	return QX_LAMBDA_ELEMENT;
}

bool qx_list_insert_at(QxList list, int element, qxIndex index){
	Node* node = NULL;
	Node* antnode = list->first;
	int contnode = 0;
	while(antnode != NULL){
		antnode = antnode->next;
		contnode++;
	}
	if(index >= 0 && index <= contnode){
	    if(index == 0) {
	        node = qxlist_node_new(element);
	        node->next = list->first;
	        list->first = node;
	        return true;
	    } else if(index > 0) {
	        Node* antnode = list->first;
	        int antindex = 0;
	        while (antindex < index - 1 && antnode != NULL) {
	            ++antindex;
	            antnode = antnode->next;
	        }
	        if(antnode != NULL) {
	            node = qxlist_node_new(element);
	            node->next = antnode->next;
	            antnode->next = node;
	            return true;
	        }
	    }
	    return false;
	}
	return false;
}

void qx_list_push_front(QxList list, int element){
	Node* node = qxlist_node_new(element);
	node->next = list->first;
	list->first = node;
}

void qx_list_push_back(QxList list, int element){
	Node* node = qxlist_node_new(element);
	Node* antnode = list->first;
	if(antnode == NULL){
		list->first = node;
	} else {
		Node* antnode = list->first;
		while(antnode->next != NULL){
			antnode = antnode->next;
		}
		antnode->next = node;
	}
}

qxIndex qx_list_remove_element_first(QxList list, int element){
	Node* antnode = list->first;
	int contnode = 0;
	if(antnode != NULL){
		if(antnode->value == element && contnode == 0){
				list->first = list->first->next;
				free(antnode);
				return contnode;
		} else {
			while(antnode->next != NULL){
				if(antnode->next->value == element && contnode != 0){
					Node* tempnode = antnode->next;
					antnode->next = antnode->next->next;
					free(tempnode);
					return contnode+1;
				}
				antnode = antnode->next;
				contnode++;
			}
		}
	}
	return QX_LAMBDA_INDEX;
}

qxIndex qx_list_remove_element_last(QxList list, int element){
	Node* antnode = list->first;
	Node* tempnode = NULL;
	Node* auxnode = NULL;
	int contnode = 0;
	int contreturn;
	if(antnode != NULL){
		if(antnode->next == NULL){
			if(antnode->value == element){
				free(antnode);
				list->first = NULL;
				return 0;
			}
			return QX_LAMBDA_INDEX;
		}
		if(antnode->value == element){
			list->first = list->first->next;
			free(antnode);
			return 0;
		}
		while(antnode->next != NULL){
			if(antnode->next->value == element){
				tempnode = antnode->next;
				auxnode = antnode;
				contreturn = contnode+1;
			}
			antnode = antnode->next;
			contnode++;
		}
		if(tempnode != NULL){
			auxnode->next = tempnode->next;
			free(tempnode);
			return contreturn;
		}
		return QX_LAMBDA_INDEX;
	}
	return QX_LAMBDA_INDEX;
}

unsigned int qx_list_remove_element_all(QxList list, int element){
	Node* antnode = list->first;
	Node* tempnode = NULL;
	int contnode = 0;
	if(antnode != NULL){
		while(antnode->next != NULL){
			if(antnode->next->value == element){
				tempnode = antnode->next;
				antnode->next = antnode->next->next;
				free(tempnode);
				contnode++;
			} else
				antnode = antnode->next;
		}
		antnode = list->first;
		if(antnode->value == element){
			list->first = list->first->next;
			free(antnode);
			contnode++;
		}
		return contnode;
	}
	return QX_LAMBDA_ELEMENT;
}

bool qx_list_remove_at(QxList list, qxIndex index){
	Node* antnode = list->first;
	Node* tempnode = NULL;
	int contnode = 0;
	while(antnode != NULL){
		antnode = antnode->next;
		contnode++;
	}
	antnode = list->first;
	if(index <= contnode && index >= 0){
		contnode = 0;
		if(index == 0){
			list->first = antnode->next;
			free(antnode);
			return true;
		}
		while(antnode->next != NULL){
			tempnode = antnode;
			antnode = antnode->next;
			contnode++;
			if(contnode == index){
				tempnode->next = tempnode->next->next;
				free(antnode);
				return true;
			}
		}
	}
	return false;
}

void qx_list_pop_front(QxList list){
	if(list->first != NULL){
		Node* antnode = list->first->next;
		free(list->first);
		list->first = antnode;
	}
}

void qx_list_pop_back(QxList list){
	if(list->first != NULL){
		if(list->first->next == NULL){
			free(list->first);
			list->first = NULL;
		} else {
			Node* antnode = list->first;
			while(antnode->next->next != NULL){
				antnode = antnode->next;
			}
			free(antnode->next);
			antnode->next = NULL;
		}
	}
}

void qx_list_print_to(QxList list, FILE *fp){
	fp = fopen("qx_list_print_to.txt", "w");
	if(list->first != NULL){
		fprintf(fp, "ELEMENTOS DA LISTA.\n");
		fprintf(fp, "[");
		Node* antnode = list->first;
		while(antnode != NULL){
			fprintf(fp, "%d, ", antnode->value);
			antnode = antnode->next;
		}
		fprintf(fp, "]");
		fclose(fp);
	} else {
		fprintf(fp, "AINDA NÃO EXISTEM ELEMENTOS NA LISTA.\n");
		fclose(fp);
	}
}
