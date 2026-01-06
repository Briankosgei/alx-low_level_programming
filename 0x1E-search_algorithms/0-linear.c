#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers
 *                 using the Linear search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * 
 * Return: first index where value is located, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
    size_t i;

    /* Check if array is NULL */
    if (array == NULL)
        return (-1);

    /* Iterate through each element in the array */
    for (i = 0; i < size; i++)
    {
        /* Print the comparison as required */
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        
        /* Check if current element matches the value */
        if (array[i] == value)
            return (i);  /* Return index if found */
    }

    /* Value not found in array */
    return (-1);
}
