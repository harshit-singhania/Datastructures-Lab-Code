#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} ;

struct node *head = NULL;

void createNode(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return;
    }
    else
    {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("successfully inserted element \n");
    }
}

void traverseList()
{
    
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
        printf("\n");
    }
}

void isEmpty()
{
    if (head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else
    {
        printf("\nlist is not empty\n");
    }
}

int getSize(struct node *node)
{
    int size = 0;
    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}

void insertNode(int n, int data, struct node **head)
{
    int size = getSize(*head);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (n < 0 || n > size)
    {
        printf("\nInvalid position");
        return;
    }
    else if (n == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct node *temp = *head;
        while (--n)
        {
            temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteNode (struct node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("\nList is empty");
        return;
    }
    struct node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    } 
    for (int i=0; temp!=NULL && i<position-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("\nInvalid position");
        return;
    }
    struct node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void deleteNodeKey(struct node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("\nList is empty");
        return;
    }
    struct node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    } 
    for (int i=0; temp!=NULL && i<position-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("\nInvalid position");
        return;
    }
    struct node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void countNodes() {
    struct node *temp = head;
    int count=0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    printf("\n Number of nodes in the list is %d \n", count);
}

int searchElements(struct node* head, int item, int index) {
    if (head == NULL) {
        return -1;
    }
    if (head->data == item) {
        return index;
    }
    index++; 
    return searchElements(head->next, item, index);
}

int main()
{
    int item, n, i;
    printf("enter the number of elements:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("item:");
        scanf("%d", &item);
        createNode(item);
    }
    int choice;
    printf("enter what you want to do:\n");
    scanf("%d", &choice);
    switch (choice)
    { 
        case 1:
            traverseList();
            break;
        case 2:
            isEmpty();
            break;
        case 3:
            insertNode(1, 10, &head);
            traverseList();
            break; 
        case 4: 
            deleteNode(&head, 1);
            traverseList();
            break;
        case 5: 
            deleteNodeKey(&head, 1);
            traverseList();
            break;
        case 6: 
            countNodes();
            break;
        case 7: 
            int call = searchElements(head, 10, 0);
            printf("\n%d", call);
            break;
        default:
            printf("\nInvalid choice");
            break;
        
    }
}