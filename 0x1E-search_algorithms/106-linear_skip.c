#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 *               using the linear search algorithm with express lane
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * 
 * Return: pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *prev;
    
    if (list == NULL)
        return (NULL);
    
    express = list->express;
    prev = list;
    
    /* Traverse the express lane first */
    while (express != NULL && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        prev = express;
        express = express->express;
    }
    
    /* If we reached end of express lane, find the last node */
    if (express == NULL)
    {
        express = prev;
        while (express->next != NULL)
            express = express->next;
    }
    
    /* Print the range for linear search */
    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, express->index);
    
    /* Perform linear search in the normal lane */
    while (prev != NULL && prev->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n",
               prev->index, prev->n);
        
        if (prev->n == value)
            return (prev);
        
        prev = prev->next;
    }
    
    return (NULL);
}
