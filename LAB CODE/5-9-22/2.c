#include <stdio.h>
#include <stdlib.h>

/* A structure of linked list node */
struct node
{
    int data;
    struct node *next;
} * head;

void initialize()
{
    head = NULL;
}

/*
Given a Inserts a node in front of a singly linked list.
*/
void insert(int num)
{
    /* Create a new Linked List node */
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = head;
    /* make new node as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", num);
}

void convertToCircularLL(struct node *head)
{
    /* Input Validation */
    if (head == NULL)
    {
        printf("Error : Invalid Input !!!!\n");
        return INT_MIN;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;
}

/*
Prints a linked list from head node till tail node
*/
void printCircularLinkedList(struct node *head)
{
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    initialize();
    /* Creating a linked List*/
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    convertToCircularLL(head);

    /* Printing Circular Linked List */
    printCircularLinkedList(head);
    return 0;
}