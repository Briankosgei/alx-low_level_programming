#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array
 *                        using the Interpolation search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * 
 * Return: first index where value is located, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
    size_t low, high, pos;

    /* Check if array is NULL or empty */
    if (array == NULL || size == 0)
        return (-1);

    low = 0;
    high = size - 1;

    while (low <= high && value >= array[low] && value <= array[high])
    {
        /* Prevent division by zero */
        if (array[high] == array[low])
            break;

        /* Calculate probe position using the given formula */
        pos = low + (((double)(high - low) / 
                     (array[high] - array[low])) * 
                     (value - array[low]));

        /* Check if position is out of bounds */
        if (pos >= size)
        {
            printf("Value checked array[%lu] is out of range\n", 
                   (unsigned long)pos);
            return (-1);
        }

        printf("Value checked array[%lu] = [%d]\n", 
               (unsigned long)pos, array[pos]);

        /* Check if value is found */
        if (array[pos] == value)
            return (pos);

        /* Adjust search boundaries */
        if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }

    /* Handle the case when array[high] == array[low] */
    if (array[low] == value && low < size)
    {
        printf("Value checked array[%lu] = [%d]\n", 
               (unsigned long)low, array[low]);
        return (low);
    }

    /* Value not found, but we need to check if it would be out of range */
    if (value > array[high] && high == size - 1)
    {
        /* Calculate where it would be if it existed */
        pos = low + (((double)(high - low) / 
                     (array[high] - array[low])) * 
                     (value - array[low]));
        if (pos >= size)
        {
            printf("Value checked array[%lu] is out of range\n", 
                   (unsigned long)pos);
        }
    }

    return (-1);
}
