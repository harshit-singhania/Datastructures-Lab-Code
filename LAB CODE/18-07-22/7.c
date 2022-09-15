#include <stdio.h>

void count_zeros(int row, int col, int matrix[row][col]);
void sum_leading_zeros(int row, int col, int matrix[row][col]);
void product_diagonal_elements(int row, int col, int matrix[row][col]);
void display_elements_minor(int row, int col, int matrix[row][col]);

int main()
{
    int i, j;
    int rowm, colm;
    printf("Enter the number of rows: ");
    scanf("%d", &rowm);
    printf("Enter the number of columns: ");
    scanf("%d", &colm);
    int matrixm[rowm][colm];
    for (i = 0; i < rowm; i++)
    {
        for (j = 0; j < colm; j++)
        {
            printf("Enter the element: ");
            scanf("%d", &matrixm[i][j]);
        }
    }
    count_zeros(rowm, colm, matrixm);
    sum_leading_zeros(rowm, colm, matrixm);
    product_diagonal_elements(rowm, colm, matrixm);
    display_elements_minor(rowm, colm, matrixm);
}

void count_zeros(int row, int col, int matrix[row][col])
{
    int i, j;
    int count = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
}

void sum_leading_zeros(int row, int col, int matrix[row][col])
{
    int i, j;
    int sum = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (j > 1)
            {
                sum += matrix[i][j];
            }
        }
    }
    printf("%d\n", sum);
}

void product_diagonal_elements(int row, int col, int matrix[row][col])
{
    int i, j;
    int product = 1;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i == j)
            {
                product *= matrix[i][j];
            }
        }
    }
    printf("%d\n", product);
}

void display_elements_minor(int row, int col, int matrix[row][col])
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = col - 1; j >= 0; j--)
        {
            if (i == j)
                printf("%d ", matrix[i][j]);
        }
    }
}