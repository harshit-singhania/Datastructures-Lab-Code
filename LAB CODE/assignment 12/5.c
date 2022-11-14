// WAP to sort an array of n doubles in an descending order using
// quick sort.

#include <stdio.h>
#include <conio.h>

void quicksort(double [], int, int);
int partition(double [], int, int);

void main()
{
    int i, n;
    double a[50];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%lf", &a[i]);
    quicksort(a, 0, n - 1);
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%lf ", a[i]);
    getch();
}

void quicksort(double a[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(a, low, high);
        quicksort(a, low, pivot - 1);
        quicksort(a, pivot + 1, high);
    }
}

int partition(double a[], int low, int high)
{
    double pivot, temp;
    int i, j;
    pivot = a[low];
    i = low;
    j = high;
    while (i < j)
    {
        while (a[i] >= pivot && i <= high)
            i++;
        while (a[j] < pivot && j >= low)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

