#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node* tail = NULL;

void DoubleLL(int choice) {
    switch(choice) {
        case 1: 
            // Traverse List Forward 
            struct Node* temp = head; 
            while (temp!=NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            
            }
        break;
        case 2: 
            // Traverse List Backward
            struct Node* temp2 = tail;
            while (temp2!=NULL) {
                printf("%d ", temp2->data);
                temp2 = temp2->prev;
            }
        break; 
        case 3:
            // check if list is empty 
            if (head == NULL) {
                printf("List is empty");
            } else {
                printf("List is not empty");
            }
        break; 
        case 4: 
            // Insert Node at certain position 
            int pos, data; 
            printf("Enter position : ");
            scanf("%d", &pos);
            printf("Enter data : ");
            scanf("%d", &data);
            struct Node* newnode = (struct Node*)malloc(sizeof(struct Node*));
            newnode->data = data;
            newnode->next = NULL;
            newnode->prev = NULL;
            if (head==NULL) {
                head = newnode; 
                newnode->prev = NULL;
                newnode->next = NULL;
            } else {
                struct Node* temp3 = head; 
                int i = 1; 
                while (i<pos-1) {
                    temp3 = temp3->next;
                    i++;
                }
                newnode->next = temp3->next; 
                newnode->prev = temp3; 
                temp->next = newnode; 
                temp->next->prev = newnode; 
            }
        break; 
        case 5: 
            // Delete node at any positiion 
            int pos2, i=1;
            printf("Enter position : ");
            scanf("%d", &pos2);
            struct Node* temp4 = head, *position;
            if (head==NULL) {
                printf("Empty List");
            } else {
                while (i<pos2-1) {
                    temp4 = temp4->next;
                    i++;
                }
                position = temp4->next;
                if (position->next!=NULL){
                    position->next->prev = temp4; 

                } 
                temp->next = position->next;
                free(position);
            }
        break; 
        case 6: 
            // Delete node for given key 
            int key; 
            printf("Enter key : ");
            scanf("%d", &key);
            struct Node* temp5 = head;
            if (head==NULL) {
                printf("Empty List");
            } else {
                while (temp5->data!=key) {
                    temp5 = temp5->next;
                }
                if (temp5->next!=NULL) {
                    temp5->next->prev = temp5->prev;
                }
                temp5->prev->next = temp5->next;
                free(temp5);
            }
        break; 
        case 7: 
            // Count the total number of nodes
            int count = 0;
            struct Node* temp6 = head;
            while (temp6!=NULL) {
                count++;
                temp6 = temp6->next;
            }
            printf("Total number of nodes : %d", count);
        break; 
        case 8: 
            // Search for an element in the list 
            int key2, flag = 0;
            printf("Enter key : ");
            scanf("%d", &key2);
            struct Node* temp7 = head;
            while (temp7!=NULL) {
                if (temp7->data==key2) {
                    flag = 1;
                    break;
                }
                temp7 = temp7->next;
            }
            if (flag==1) {
                printf("Key found");
            } else {
                printf("Key not found");
            }
        break; 
        default: 
            printf("Invalid choice");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Traverse List Forward");
        printf("\n2. Traverse List Backward");
        printf("\n3. Check if list is empty");
        printf("\n4. Insert Node at certain position");
        printf("\n5. Delete node at any positiion");
        printf("\n6. Delete node for given key");
        printf("\n7. Count the total number of nodes");
        printf("\n8. Search for an element in the list");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        DoubleLL(choice);
    }
}