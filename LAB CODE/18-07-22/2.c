#include <stdio.h>

int main()
{
    int a[50], i, n; 
    printf("How many elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("enter element %d:", i + 1);
        scanf("%d", &a[i]);
    }
    printf("current array is \n" ) ; 
    for (i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
    printf("reversed array will be : \n"); 
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d \n", a[i]);
    }
}