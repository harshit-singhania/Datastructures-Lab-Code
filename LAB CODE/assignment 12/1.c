// WAP to sort an array of n dates in an ascending order using
// Bubble sort. Date structure is {day, month, year }

#include <stdio.h>
#include <stdlib.h>

struct date
{
    int day;
    int month;
    int year;
};

void swap(struct date *a, struct date *b)
{
    struct date temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct date arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].year > arr[j + 1].year)
                swap(&arr[j], &arr[j + 1]);
            else if (arr[j].year == arr[j + 1].year)
                if (arr[j].month > arr[j + 1].month)
                    swap(&arr[j], &arr[j + 1]);
                else if (arr[j].month == arr[j + 1].month)
                    if (arr[j].day > arr[j + 1].day)
                        swap(&arr[j], &arr[j + 1]);
}

void printArray(struct date arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d/%d/%d ", arr[i].day, arr[i].month, arr[i].year);
}

int main()
{
    int n;
    printf("Enter the number of dates: ");
    scanf("%d", &n);
    struct date arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the date in the format dd/mm/yyyy: ");
        scanf("%d/%d/%d", &arr[i].day, &arr[i].month, &arr[i].year);
    }
    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}

