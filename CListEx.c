#include <stdlib.h>
#include <stdio.h>
#include "CListEx.h"

list_t* list_create() {
    list_t* list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void list_add_end(list_t* list, void* data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void list_add_start(list_t* list, void* data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

void list_print(list_t* list, void (*print)(void*)) {
    node_t* current = list->head;
    while (current != NULL) {
        print(current->data);
        current = current->next;
    }
}

void list_free(list_t* list, void (*free_func)(void*)) {
    node_t* current = list->head;
    while (current != NULL) {
        node_t* temp = current;
        if (free_func) free_func(temp->data);
        current = current->next;
        free(temp);
    }
    free(list);
}