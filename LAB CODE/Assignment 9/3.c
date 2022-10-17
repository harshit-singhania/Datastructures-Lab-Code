// Write a menu driven program to implement circular queue operations
// such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull
// using static array.

#include <stdio.h>
#include <stdlib.h>

int queue[100], front = -1, rear = -1, size;

int circularQueueArray(int choice) {
    switch (choice) {
        // Enqueue
        case 1:
            if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
                printf("Queue is full");
            } else {
                int element;
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                if (front == -1) {
                    front = 0;
                }
                rear = (rear + 1) % size;
                queue[rear] = element;
                printf("Element inserted successfully");
            }
            break;

        // Dequeue
        case 2:
            if (front == -1) {
                printf("Queue is empty");
            } else {
                printf("Element deleted is %d", queue[front]);
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % size;
                }
            }
            break;

        // Peek
        case 3:
            if (front == -1) {
                printf("Queue is empty");
            } else {
                printf("Element at the front is %d", queue[front]);
            }
            break;

        // Display
        case 4:
            if (front == -1) {
                printf("Queue is empty");
            } else {
                int i;
                printf("Elements in the queue are: ");
                for (i = front; i != rear; i = (i + 1) % size) {
                    printf("%d ", queue[i]);
                }
                printf("%d", queue[i]);
            }
            break;

        // IsEmpty
        case 5:
            if (front == -1) {
                printf("Queue is empty");
            } else {
                printf("Queue is not empty");
            }
            break;

        // IsFull
        case 6:
            if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
                printf("Queue is full");
            } else {
                printf("Queue is not full");
            }
            break;

        default:
            printf("Invalid choice");
    }
}

int main() {
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
        circularQueueArray(ch);
    }
    return 0;
}

