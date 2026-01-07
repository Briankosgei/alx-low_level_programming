#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted singly linked list
 *             using the Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 * 
 * Return: pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    listint_t *jumper, *walker, *searcher;
    size_t jump, i;
    
    if (list == NULL || size == 0)
        return (NULL);
    
    jump = (size_t)sqrt(size);
    jumper = list;
    walker = list;
    
    while (jumper->index + jump < size && jumper->n < value)
    {
        walker = jumper;
        for (i = 0; i < jump && jumper->next != NULL; i++)
            jumper = jumper->next;
        printf("Value checked at index [%lu] = [%d]\n", jumper->index, jumper->n);
    }
    
    printf("Value found between indexes [%lu] and [%lu]\n", walker->index, jumper->index);
    
    searcher = walker;
    while (searcher != NULL && searcher->index <= jumper->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", searcher->index, searcher->n);
        if (searcher->n == value)
            return (searcher);
        searcher = searcher->next;
    }
    
    return (NULL);
}
