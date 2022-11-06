// Write a menu driven program to implement queue operations such as
// Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull using static
// array.

#include <stdio.h>
#include <stdlib.h>

int queue[100], front = -1, rear = -1, size;
void queueArray(int choice)
{

    switch (choice)
    {
    // Enqueue
    case 1:
        if (rear == size - 1)
        {
            printf("Queue is full");
        }
        else
        {
            int element;
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            queue[rear] = element;
            printf("Element inserted successfully");
        }
        break; 
    
    // Dequeue 
    case 2:
        if (front == -1 || front > rear)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Element deleted is %d", queue[front]);
            front++;
        }
        break;
    
    // Pe ek
    case 3: 
        if (front == -1 || front > rear)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Element at the front is %d", queue[front]);
        }
        break;
    
    // Display
    case 4:
        if (front == -1 || front > rear)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Elements in the queue are: ");
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        break;
    
    // isEmpty() 
    case 5:
        if (front == -1 || front > rear)
        {
            printf("Queue is empty");
        }
        else
        {
            printf("Queue is not empty");
        }
        break;
    
    // isFull()
    case 6: 
        if (rear == size - 1)
        {
            printf("Queue is full");
        }
        else
        {
            printf("Queue is not full");
        }
        break;
    }
}

int main()
{
    int ch; 
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    while (1) {
        printf("1. Enqueue \n"); 
        printf("2. Dequeue \n");
        printf("3. Peek \n");
        printf("4. Display \n");
        printf("5. isEmpty() \n");
        printf("6. isFull() \n");
        printf("Enter choice : "); 
        scanf("%d", &ch); 
        queueArray(ch);
    }
    return 0;
}