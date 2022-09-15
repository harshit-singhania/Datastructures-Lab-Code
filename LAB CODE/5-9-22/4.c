// COUNT TOTAL NUMBER OF NODES IN CLL AND IF COUNT IS GREATER THAN A CERTAIN VALUE
// THEN DELETE THE NODES FROM THE BEGINNING OF THE LIST

#include <stdio.h>
#include <stdlib.h>

/* A structure of linked list node */
struct Node
{
    int data;
    struct Node *next;
}; 
struct Node* head = NULL; 
struct Node* tail = NULL; 

void printList() {
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void insert(int num) {
     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = head;
    /* make new node as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", num);
}

void deleteVal(int value) {
    struct Node* temp = head; 
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp!=head);
    if (count > value) {
        struct Node* temp = head; 
        do {
            temp = temp->next;
        } while (temp->next!=head);
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
}

int main() {
    insert(1);
    insert(2);
    insert(3); 
    insert(4); 
    insert(5);
    deleteVal(3);
    printList();
}