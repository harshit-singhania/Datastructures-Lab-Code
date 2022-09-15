#include <stdio.h>
#include <stdlib.h>

const row = 3;
const col = 3;

void isUpper(int arr[row][col]) {
    int i,j; 
    for (i=0; i<row; i++) {
        for (j=0; j<i; j++) {
            if (arr[i][j]!=0) {
                printf("false");
            }
        }
    }
    printf("true");
}

int isLower(int arr[row][col]) {
    int i,j;
    for (i=0; i<row-1; i++) 
        for (j=i+1; j<col;j++) 
            if (arr[i][j]!=0) 
                return -1;
    return 1;
}

int isDiagonal(int arr[row][col]) {
    int i,j;
    for (i=0; i<row; i++) 
        for (j=0; j<col; j++) 
            if (i==j) 
                if (arr[i][j]==0) 
                    return -1;
                else if (arr[i][j+1]==0)
                    return -1;
                else if (arr[i+1][j]==0)
                    return -1;
    return 1;
}
int main()
{
    int a[row][col], i, j, row, col;
    printf("\nEnter values to the matrix :: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\nEnter a[%d][%d] value :: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n\n");
    printf("isUpper \n"); 
    isUpper(a[row][col]);
}