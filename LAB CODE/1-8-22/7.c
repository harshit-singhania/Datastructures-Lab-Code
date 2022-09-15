#include <stdio.h>

int search(int a[],int n,int key)
{
    int count = 0, i;
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            count++;
    return count;
}
int main()
{
    int arr[100];
    int n;
    int find;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter %d element:", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("enter key:");
    scanf("%d", &find);
    int call = search(arr, n,find);
    printf("%d", call);
    return 0;
}