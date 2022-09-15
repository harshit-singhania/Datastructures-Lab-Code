#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void linkedList(int item, int choice)
{

    // Creation
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

    // Size
    struct node *nodes = (struct node *)malloc(sizeof(struct node *));
    int size = 0;
    while (nodes != NULL)
    {
        nodes = nodes->next;
        size++;
    }

    switch (choice)
    {
    case 1:
        // Traversal
        struct node *ptr = head;
        while (ptr != NULL)
        {
            printf("%d", ptr->data);
            ptr = ptr->next;
            printf("\n");
        }
        break;

    case 2:
        // Empty or not
        if (head == NULL)
        {
            printf("list is empty");
        }
        else
        {
            printf("list is not empty");
        }
        break;

    case 3:
        // insert into node

        int pos, data;
        printf("Enter data : ");
        scanf("%d", &data);
        struct node *newNode = (struct node *)malloc(sizeof(struct node *));
        newNode->data = data;
        newNode->next = NULL;
        printf("Enter position : ");
        scanf("%d", &pos);
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            struct node *temp11 = head;
            while (--pos)
            {
                temp11 = temp11->next;
                newNode->next = temp11->next;
                temp11->next = newNode;
            }
        }
        break;

    case 4:
        // Deletion
        int posDel;
        printf("Enter position for deleting : ");
        scanf("%d", &posDel);
        if (posDel == 0)
        {
            struct node *temp = head;
            head = head->next;
            free(temp);
        }
        else
        {
            struct node *temp = head;
            while (--posDel)
            {
                temp = temp->next;
            }
            struct node *temp1 = temp->next;
            temp->next = temp1->next;
            free(temp1);
        }
        break; 

        case 5 : 
        // Delete Node for given key
            int key; 
            printf("Enter key : ");
            scanf("%d", &key);
            struct node *tempKey = head;
            while(tempKey->data != key){
                tempKey = tempKey->next;
            }
            struct node *tempKey1 = tempKey->next;
            tempKey->next = tempKey1->next;
            free(tempKey1);
            break;
        
        case 6 : 
        // Count total number of nodes 
            int count = 0;
            struct node *tempCount = head;
            while(tempCount != NULL){
                tempCount = tempCount->next;
                count++;
            }
            printf("Total number of nodes : %d", count);
            break;
        
        case 7: 
        // Search for a given key
            int keySearch;
            printf("Enter key : ");
            scanf("%d", &keySearch);
            struct node *tempSearch = head;
            while(tempSearch->data != keySearch){
                tempSearch = tempSearch->next;
            }
            printf("Key found at %d", tempSearch);
            break;

    default:
        printf("Invalid choice");
        break;
    }
} 

int main() {
    printf("MENU \n"); 
    printf("1. Traversal \n");
    printf("2. Empty or not \n");
    printf("3. Insert into node \n");
    printf("4. Deletion \n");
    printf("5. Delete Node for given key \n");
    printf("6. Count total number of nodes \n");
    printf("7. Search for a given key \n");
    int choice, item;
    printf("Enter choice : ");
    scanf("%d", &choice);
    printf("Enter item : ");
    scanf("%d", &item);
    linkedList(item, choice);
    return 0;
}

    