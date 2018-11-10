#include "lista_encadeada.h"

#include <stdio.h>
#include <stdlib.h>

struct linked_list_node {
    int value;
    LLNode next;
};

struct linked_list {
    LLNode first;
};

LList llist_new() {
    LList list = malloc(sizeof(struct linked_list));

    list->first = NULL;

    return list;
}

LLNode llist_node_new(int value) {
    LLNode node = malloc(sizeof(struct linked_list_node));

    node->value = value;
    node->next = NULL;

    return node;
}

void llist_node_delete(LLNode node) {
    free(node);
}

void llist_node_delete_recursive(LLNode node) {
    if(node != NULL) {
        llist_node_delete_recursive(node->next);
        free(node);
    }
}

void llist_delete(LList list) {
    llist_node_delete_recursive(list->first);
    free(list);
}

void llist_print(LList list) {
    LLNode node = list->first;

    printf("[");
    while (node != NULL) {
        printf("%d, ", node->value);
        node = node->next;
    }
    printf("]\n");
}

int llist_size(LList list) {
    LLNode node = list->first;
    int count = 0;

    while(node != NULL) {
        ++count;
        node = node->next;
    }

    return count;
}

bool llist_insert_at(LList list, int index, int value) {
    LLNode node = NULL;

    if(index == 0) {
        node = llist_node_new(value);
        node->next = list->first;
        list->first = node;

        return true;
    } else if(index > 0) {
        LLNode antnode = list->first;
        int antindex = 0;

        while (antindex < index - 1 && antnode != NULL) {
            ++antindex;
            antnode = antnode->next;
        }

        if(antnode != NULL) {
            node = llist_node_new(value);

            node->next = antnode->next;
            antnode->next = node;

            return true;
        }
    }

    return false;
}

bool llist_remove_back(LList list) {
    LLNode node = list->first;

    if(node == NULL) {
        return false;
    }

    if(node->next == NULL) {
        llist_node_delete(node);
        list->first = NULL;

        return true;
    }

    while(node->next->next != NULL) {
        node = node->next;
    }

    llist_node_delete(node->next);
    node->next = NULL;

    return true;
}





