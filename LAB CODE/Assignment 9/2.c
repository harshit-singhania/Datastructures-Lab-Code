// Write a menu driven program to implement queue operations such as
// Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list.

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void queueLL(int choice)
{
    switch (choice)
    {
    // Enqueue
    case 1:
        struct queue *ptr = (struct queue *)malloc(sizeof(struct queue *));
        if (ptr == NULL)
        {
            printf("Queue is full");
        }
        else
        {
            int element;
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            ptr->data = element;
            ptr->next = NULL;
            if (front == NULL)
            {
                front = ptr;
                rear = ptr;
            }
            else
            {
                rear->next = ptr;
                rear = ptr;
            }
            printf("Element inserted successfully");
        }
        break;

    // Dequeue
    case 2:
        if (front == NULL)
        {
            printf("Underflow");
        }
        else
        {
            struct queue *ptr2 = front;
            front = front->next;
            free(ptr2);
        }
        break;

    // Peek
    case 3:
        if (front == NULL)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Element at the front is %d", front->data);
        }
        break;

    // Display
    case 4:
        if (front == NULL)
        {
            printf("Queue is empty");
        }
        else
        {
            struct queue *ptr3 = front;
            while (ptr3 != NULL)
            {
                printf("%d", ptr3->data);
                ptr3 = ptr3->next;
            }
        }
        break;

    // isEmpty()
    case 5:
        if (front == NULL)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Queue is not empty");
        }
        break;
    }
}

int main()
{
    int ch;
    printf("1. Enqueue \n");
    printf("2. Dequeue \n");
    printf("3. Peek \n");
    printf("4. Display \n");
    printf("5. isEmpty() \n");
    printf("Enter choice : ");
    scanf("%d", &ch);
    queueLL(ch);
    return 0;
}
