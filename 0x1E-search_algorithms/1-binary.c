#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - prints an array of integers
 * @array: pointer to the first element of the array
 * @left: starting index to print
 * @right: ending index to print
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * binary_search - searches for a value in a sorted array
 *                 using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * 
 * Return: index where value is located, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left, right, mid;

    /* Check if array is NULL or empty */
    if (array == NULL || size == 0)
        return (-1);

    left = 0;
    right = size - 1;

    /* Print the initial array */
    print_array(array, left, right);

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        /* Check if value is present at mid */
        if (array[mid] == value)
            return (mid);

        /* If value is greater, ignore left half */
        if (array[mid] < value)
        {
            left = mid + 1;
            if (left <= right)
                print_array(array, left, right);
        }
        /* If value is smaller, ignore right half */
        else
        {
            right = mid - 1;
            if (left <= right)
                print_array(array, left, right);
        }
    }

    /* Value not present in array */
    return (-1);
}
