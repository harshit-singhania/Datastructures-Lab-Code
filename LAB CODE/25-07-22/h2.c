#include <stdio.h>

void maxoccurence(int a[], int ar_size)
{
    int max = a[0], count = 0, i;

    for (i = 0; i < ar_size; i++)
    {
        if (a[i] == max)

            count++;

        if (a[i] > max)
        {
            max = a[i];

            count = 1;
        }
    }

    printf("Maximum element in the array is %d\n", max);
    printf("the maximum occurence of %d is %d\n", max, count);
}

int main()
{
    int n, i, a[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    maxoccurence(a, n);
}