#include <stdio.h>

void lower_triangular(int row, int col, int arr[row][col]);

int main()
{
    int rows, cols, i, j;
    int matrix[rows][cols];
    printf("enter rows: ");
    scanf("%d", &rows);
    printf("enter cols: ");
    scanf("%d", &cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("enter element %d, %d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    lower_triangular(rows, cols, matrix);
    
}

void lower_triangular(int row, int col, int arr[row][col]) {
    int i, j;
    for (i = 1; i < row - 1; i++)
    {
        for (j = i + 1; j < row; j++)
        {
            if (arr[i][j] != 0)
            {
                printf("false");
            }
        }
        printf("true");
    }
}