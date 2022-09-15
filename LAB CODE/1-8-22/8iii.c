#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, i, j;
    printf("enter row:");
    scanf("%d", &row);
    printf("enter column:");
    scanf("%d", &col);
    int a[row][col];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\nEnter a[%d][%d] value :: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n Check wether matrix is upper triangular or not \n");
    int flag1 = 1;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (a[i][j] != 0)
            {
                flag1 = 0;
            }
        }
    }
    flag1 = 1;

    if (flag1 == 0)
        printf("it is not upper triangular");
    else if (flag1 == 1)
        printf("it is upper triangular");

    printf("\n Check wether matrix is lower triangular or not \n");
    int flag2 = 1;
    for (i = 0; i < row - 1; i++)
        for (j = i + 1; j < col; j++)
            if (a[i][j] != 0)
                flag2 = 0;
    flag2 = 1;

    if (flag2 == 0)
        printf("it is not lower triangular");
    else if (flag2 == 1)
        printf("it is lower triangular");

    printf("\n Check wether matrix is tri diagonal or not \n");
    int flag3 = 1; 
    for (i=0; i<row; i++) 
        for (j=0; j<col; j++) 
            if (i==j) 
                if (a[i][j]==0) 
                    flag3=0;
                else if (a[i][j+1]==0)
                    flag3=0;
                else if (a[i+1][j]==0)
                    flag3=0;
    flag3=1;

    if (flag3 == 0)
        printf("it is not tri diagonal");
    else if (flag3 == 1)
        printf("it is tri diagonal");
}