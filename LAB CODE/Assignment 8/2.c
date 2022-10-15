#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head;

int stackInLL(int choice)
{
    switch (choice)
    {
    // isEmpty
    case 1:
        if (head == NULL)
        {
            printf("true");
        }
        else
        {
            printf("false");
        }
        break;

    // display
    case 2:
        int i;
        struct node *ptr;
        ptr = head;
        if (ptr == NULL)
        {
            printf("Stack is empty\n");
        }
        else
        {
            printf("Printing Stack elements \n");
            while (ptr != NULL)
            {
                printf("%d\n", ptr->val);
                ptr = ptr->next;
            }
        }
        break;

    // push
    case 3:
        int val;
        struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
        if (ptr1 == NULL)
        {
            printf("not able to push the element");
        }
        else
        {
            printf("Enter the value");
            scanf("%d", &val);
            if (head == NULL)
            {
                ptr1->val = val;
                ptr1->next = NULL;
                head = ptr1;
            }
            else
            {
                ptr1->val = val;
                ptr1->next = head;
                head = ptr1;
            }
            printf("Item pushed");
        }
        break;

    // pop
    case 4:
        int item;
        struct node *ptr2;
        if (head == NULL)
        {
            printf("Underflow");
        }
        else
        {
            item = head->val;
            ptr2 = head;
            head = head->next;
            free(ptr2);
            printf("Item popped");
        }
    }
}

int main()
{
    int ch;
    printf("1. isEmpty \n 2. Display \n 3. Push \n 4. Pop \n");
    printf("Enter choice : ");
    scanf("%d", &ch);
    int c = stackInLL(ch);
    printf("%d \n", c);
}