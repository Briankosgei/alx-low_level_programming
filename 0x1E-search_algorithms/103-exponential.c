#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * print_subarray - prints a subarray between two indices
 * @array: pointer to the first element of the array
 * @low: starting index
 * @high: ending index
 */
void print_subarray(int *array, size_t low, size_t high)
{
    size_t i;
    
    printf("Searching in array: ");
    for (i = low; i <= high; i++)
    {
        printf("%d", array[i]);
        if (i < high)
            printf(", ");
    }
    printf("\n");
}

/**
 * binary_search_range - binary search within a specific range
 * @array: pointer to the first element of the array
 * @low: starting index
 * @high: ending index
 * @value: value to search for
 * 
 * Return: index where value is located, or -1 if not found
 */
int binary_search_range(int *array, size_t low, size_t high, int value)
{
    size_t mid;

    while (low <= high)
    {
        print_subarray(array, low, high);
        
        mid = low + (high - low) / 2;
        
        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array
 *                      using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * 
 * Return: first index where value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1, low, high;

    /* Check if array is NULL or empty */
    if (array == NULL || size == 0)
        return (-1);

    /* Handle value at index 0 */
    if (array[0] == value)
    {
        printf("Value checked array[%lu] = [%d]\n", 
               (unsigned long)0, array[0]);
        return (0);
    }

    /* Exponential step: find range where value might be */
    bound = 1;
    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", 
               (unsigned long)bound, array[bound]);
        bound *= 2;
    }

    /* Determine the range for binary search */
    low = bound / 2;
    high = (bound < size) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n",
           (unsigned long)low, (unsigned long)high);

    /* Perform binary search within the found range */
    return (binary_search_range(array, low, high, value));
}
