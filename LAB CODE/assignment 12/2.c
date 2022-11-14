// WAP to sort an array of n floats in an ascending order using
// selection sort.

#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(float arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(float arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%f ", arr[i]);
}

int main()
{
    int n;
    printf("Enter the number of floats: ");
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the float: ");
        scanf("%f", &arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}