/* listint_mock.c - Mock implementations for testing */
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

listint_t *create_list(int *array, size_t size) {
    listint_t *head = NULL, *node, *tail = NULL;
    size_t i;
    
    for (i = 0; i < size; i++) {
        node = malloc(sizeof(listint_t));
        if (node == NULL) return NULL;
        
        node->n = array[i];
        node->index = i;
        node->next = NULL;
        
        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    return head;
}

void print_list(const listint_t *list) {
    printf("List :\n");
    while (list != NULL) {
        printf("Index[%lu] = [%d]\n", list->index, list->n);
        list = list->next;
    }
}

void free_list(listint_t *list) {
    listint_t *temp;
    
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}
