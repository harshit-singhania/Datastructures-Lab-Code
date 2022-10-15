#include <stdio.h>
#include <stdlib.h>
int stack[100], n = 100, top = -1;

int stackInArray(int choice)
{
    switch (choice)
    {
    // isEmpty
    case 1:
        if (top==-1) {
            printf("true"); 
        } else {
            printf("false"); 
        }
        break;

    // display the stack
    case 2:
        if (top >= 0)
        {
            printf("Stack elements \n");
            for (int i = top; i >= 0; i--)
            {
                printf(" %d \n", i);
            }
        }
        break;

    // push
    case 3:
        int val;
        printf("enter value : ");
        scanf("%d", &val);
        if (top >= n - 1)
        {
            printf("Stack overflow");
            exit(1);
        }
        else
        {
            top++;
            stack[top] = val;
        }
        break;

    // pop
    case 4:
        if (top <= -1)
        {
            printf("Stack underflow");
            exit(1);
        }
        else
        {
            printf("The popped element is %d \n", stack[top]);
            top--;
        }
        break;

        default: 
            printf("Invalid choice");
            break;
    }
}

int main() {
    int ch;
    printf("1. isEmpty \n 2. Display \n 3. Push \n 4. Pop \n") ;
    printf("Enter choice : ");
    scanf("%d", &ch); 
    int c = stackInArray(ch); 
    printf("%d \n", c);
}