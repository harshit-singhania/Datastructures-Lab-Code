#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void deleteNode(struct Node **head_ref, struct Node *del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}

void removeDuplicates(struct Node **head_ref)
{
    if ((*head_ref) == NULL)
        return;

    struct Node *current = *head_ref;
    struct Node *next;

    while (current->next != NULL)
    {

        if (current->data == current->next->data)

            deleteNode(head_ref, current->next);

        else
            current = current->next;
    }
}

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node *head)
{

    if (head == NULL)
        printf("Doubly Linked list empty");

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{

    struct Node *head = NULL;

    push(&head, 12);
    push(&head, 12);
    push(&head, 10);
    push(&head, 8);
    push(&head, 8);
    printf("Original List ");
    printList(head);

    removeDuplicates(&head);

    printf("\nList after removing duplicates ");
    printList(head);

    return 0;
}