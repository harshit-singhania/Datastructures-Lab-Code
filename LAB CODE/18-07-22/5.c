#include <stdio.h>
#include <stdlib.h>

int get_count(int arr[], int n, int num1, int num2)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num1)
        {
            break;
        }
    }
    if (i >= n - 1)
        return 0;

    int j = 0;
    for (j = n - 1; j >= i + 1; j--)
        if (arr[j] == num2)
            break;

    if (j == i)
        return 0;

    return (j - i);
}

int main()
{
    int arr[] = {1, 2, 2, 7, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num1 = 6, num2 = 10;
    int call = get_count(arr, n, num1, num2);
    printf("%d\n", call);
    return 0;
}