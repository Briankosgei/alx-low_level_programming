#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct dlistint_s - doubly linked list node
 * @n: integer stored in the node
 * @prev: pointer to the previous node
 * @next: pointer to the next node
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/* Function prototype */
size_t print_dlistint(const dlistint_t *h);

#endif /* LISTS_H */
