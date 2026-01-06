#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array
 *               using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * 
 * Return: first index where value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
    size_t jump, prev, i;

    /* Check if array is NULL or empty */
    if (array == NULL || size == 0)
        return (-1);

    /* Calculate jump step (square root of size) */
    jump = (size_t)sqrt(size);

    printf("Value checked array[%lu] = [%d]\n", (unsigned long)0, array[0]);

    /* Jump through the array */
    prev = 0;
    while (prev < size && array[prev] < value)
    {
        prev += jump;
        if (prev >= size)
            break;
        
        printf("Value checked array[%lu] = [%d]\n", (unsigned long)prev, array[prev]);
    }

    /* Print the range where value might be */
    if (prev >= jump)
        printf("Value found between indexes [%lu] and [%lu]\n", 
               (unsigned long)(prev - jump), (unsigned long)prev);
    else
        printf("Value found between indexes [%lu] and [%lu]\n", 
               (unsigned long)0, (unsigned long)prev);

    /* Perform linear search in the identified block */
    i = (prev >= jump) ? (prev - jump) : 0;
    
    while (i <= prev && i < size)
    {
        printf("Value checked array[%lu] = [%d]\n", (unsigned long)i, array[i]);
        
        if (array[i] == value)
            return (i);
        
        i++;
    }

    /* Value not found */
    return (-1);
}
