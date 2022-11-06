#include <stdio.h>
int main()
{
    int n, i, flag = 1;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int container[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &container[i]);
    }
    int hunt;
    printf("Enter the element to be searched: ");
    scanf("%d", &hunt);
    while (flag == 1)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (hunt == container[i])
            {
                flag = 1;
                hunt *= 3;
                break;
            }
        }
    }
    printf("value of hunt is : %d ", hunt);
}
