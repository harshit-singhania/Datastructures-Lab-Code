#include <stdio.h>

int upper_triangular(int row, int col, int arr[row][col]);
int lower_triangular(int row, int col, int arr[row][col]);

int main()
{
    int rows, cols, i, j;
    int a[rows][cols];
    printf("enter rows: ");
    scanf("%d", &rows);
    printf("enter cols: ");
    scanf("%d", &cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("enter element %d, %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    int c1 = upper_triangular(rows, cols, a[rows][cols]);
    int c2 = lower_triangular(rows, cols, a[rows][cols]);

    if (c1 == 1)
    {
        printf("upper triangular");
    }
    else if (c1 == -1)
    {
        if (c2 == 1)
        {
            printf("lower triangular");
        }
    }
    else if (c2 == -1)
    {
        int point = 0;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (i != j && a[i][j] != 0)
                {
                    point = 1;
                    break;
                }
            }
        }
        if (point == 1)
            printf("Given Matrix is not a diagonal Matrix.");
        else
            printf("Given Matrix is a diagonal Matrix.");
    }
}

int upper_triangular(int row, int col, int arr[row][col])
{
    int i, j;
    for (i = 1; i < row; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (arr[i][j] != 0)
            {
                return -1;
            }
        }
    }
    return 1;
}

int lower_triangular(int row, int col, int arr[row][col])
{
    int i, j;
    for (i = 1; i < row - 1; i++)
    {
        for (j = i + 1; j < row; j++)
        {
            if (arr[i][j] != 0)
            {
                return -1;
            }
        }
        return 1;
    }
}