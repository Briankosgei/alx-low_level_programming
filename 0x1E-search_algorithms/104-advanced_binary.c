#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array_range - prints a subarray between two indices
 * @array: pointer to the first element of the array
 * @left: starting index
 * @right: ending index
 */
void print_array_range(int *array, size_t left, size_t right)
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
 * advanced_binary_recursive - recursive helper function for advanced binary search
 * @array: pointer to the first element of the array
 * @left: left index boundary
 * @right: right index boundary
 * @value: value to search for
 * 
 * Return: index of first occurrence of value, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    size_t mid;
    int result;

    if (left > right)
        return (-1);

    print_array_range(array, left, right);

    if (left == right)
    {
        if (array[left] == value)
            return (left);
        return (-1);
    }

    mid = left + (right - left) / 2;

    /* Since we want the first occurrence, we always search left first */
    if (array[mid] >= value)
    {
        result = advanced_binary_recursive(array, left, mid, value);
        if (result != -1)
            return (result);
    }
    
    /* If not found in left half or value is greater than array[mid] */
    if (array[mid] < value)
    {
        return advanced_binary_recursive(array, mid + 1, right, value);
    }
    
    /* If array[mid] == value but not found in left half, return mid */
    return (mid);
}

/**
 * advanced_binary - searches for the first occurrence of a value in a sorted array
 *                   using advanced binary search (returns first index for duplicates)
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * 
 * Return: first index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    /* Check if array is NULL or empty */
    if (array == NULL || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
