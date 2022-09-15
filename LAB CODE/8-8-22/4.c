#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void traverseList()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        printf("\n");
    }
}

void push(struct node **head, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void searchElement(int key)
{
    struct node *current = head;
    int index = 0;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return key;
            pushToFirst(head, current);
            delete (key, current);
            traverseList();
        }
        current = current->next;
        index++;
    }
    return -1;
}

void delete (int key, struct node **head)
{
    struct node *temp, *head, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void pushToFirst(struct node **head, int val)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = head;
    *head = new_node;
}

int main()
{
    int search;
    printf("Searching for:");
    scanf("%d", &search);
    searchElement(search);
    return 0;
}