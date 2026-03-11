#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _node node_t;
struct _node {
    char *data;
    node_t *next;
};

int main() {
    node_t *head = NULL;
    add_to_front(&head, "abc");

}

void add_to_front(node_t **head_ptr, char *data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = (char*)malloc(strlen(data)+1);
    strcpy(node->data, data);
    node->next = *head_ptr;
    *head_ptr = node;
}