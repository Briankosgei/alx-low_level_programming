/* simple_test.c - Minimal test without helper functions */
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/* Simple implementation of listint_t structure */
typedef struct listint_s {
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;

/* Your jump_list function should already be in 105-jump_list.c */
listint_t *jump_list(listint_t *list, size_t size, int value);

/* Minimal test case */
int main(void) {
    /* Create a simple linked list manually for testing */
    listint_t *head = NULL, *node, *result;
    int array[] = {0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99};
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;
    
    /* Build the linked list manually */
    for (i = 0; i < size; i++) {
        node = malloc(sizeof(listint_t));
        node->n = array[i];
        node->index = i;
        node->next = NULL;
        
        if (head == NULL) {
            head = node;
        } else {
            listint_t *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
    
    /* Test 1: Search for existing value */
    printf("Test 1: Searching for 53\n");
    result = jump_list(head, size, 53);
    if (result != NULL) {
        printf("Found %d at index: %lu\n\n", 53, result->index);
    }
    
    /* Test 2: Search for another value */
    printf("Test 2: Searching for 2\n");
    result = jump_list(head, size, 2);
    if (result != NULL) {
        printf("Found %d at index: %lu\n\n", 2, result->index);
    }
    
    /* Test 3: Search for non-existent value */
    printf("Test 3: Searching for 999\n");
    result = jump_list(head, size, 999);
    if (result == NULL) {
        printf("Found 999 at index: (nil)\n");
    }
    
    /* Cleanup */
    while (head != NULL) {
        node = head;
        head = head->next;
        free(node);
    }
    
    return 0;
}
