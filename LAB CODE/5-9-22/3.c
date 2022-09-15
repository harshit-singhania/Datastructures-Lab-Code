// swap nodes if first given key is greater than second given key in circular 
// linked list 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node* next;
}; 

struct Node* head = NULL; 
struct Node* tail = NULL;

void printList() {
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted Element : %d\n", data);
}

void swapNodes(int key1, int key2) {
    struct Node* temp = head;
    struct Node* prev1 = NULL;
    struct Node* prev2 = NULL;
    struct Node* node1 = NULL;
    struct Node* node2 = NULL;
    do {
        if (temp->data == key1) {
            node1 = temp;
            break;
        }
        prev1 = temp;
        temp = temp->next;
    } while (temp != head);
    temp = head;
    do {
        if (temp->data == key2) {
            node2 = temp;
            break;
        }
        prev2 = temp;
        temp = temp->next;
    } while (temp != head);
    if (node1 == NULL || node2 == NULL) {
        printf("Invalid Input\n");
        return;
    }
    if (prev1 != NULL) {
        prev1->next = node2;
    } else {
        head = node2;
    }
    if (prev2 != NULL) {
        prev2->next = node1;
    } else {
        head = node1;
    }
    struct Node* temp1 = node1->next;
    node1->next = node2->next;
    node2->next = temp1;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    swapNodes(1, 3);
    printList();
}