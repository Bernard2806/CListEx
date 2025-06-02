#ifndef LIST_H
#define LIST_H

typedef struct node {
    void* data;
    struct node* next;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail; // 🆕 for fast appending at the end
} list_t;

// Create list
list_t* list_create();

// Add to the end (as before)
void list_add_end(list_t* list, void* data);

// Add to the beginning 🆕
void list_add_start(list_t* list, void* data);

// Print list
void list_print(list_t* list, void (*print)(void*));

// Free memory
void list_free(list_t* list, void (*free_func)(void*));

#endif