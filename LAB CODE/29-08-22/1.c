#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;
struct Node *head = NULL;

void ImplementCLL(int choice)
{

    switch (choice)
    {
    case 1:
        // Traverse Circular Linked List
        if (last == NULL)
        {
            printf("Circular Linked List is empty");
        }
        else
        {
            struct Node *temp = last->next;
            do
            {
                printf("%d ", temp->data);
                temp = temp->next;
            } while (temp != last->next);
        }
        break;

    case 2:
        // Check if Circular Linked List is empty
        if (last == NULL)
        {
            printf("Circular Linked List is empty");
        }
        else
        {
            printf("Circular Linked List is not empty");
        }
        break;

    case 3:
        // Insert node at certain position in circular linked list
        int item, position;
        struct Node *curNode;
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        printf("Enter the position at which the item is to be inserted: ");
        scanf("%d", &position);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = item;
        curNode = head;
        for (int i = 0; i < position - 3; i++)
        {
            curNode = curNode->next;
        }
        newNode->next = curNode->next;
        curNode->next = newNode;
        break;

    case 4:
        // Delete node at certain position in circular linked list
        int pos;
        struct Node *firstnode = head, *prevnode = head;
        printf("Enter the position at which the item is to be deleted: ");
        scanf("%d", &pos);
        if (prevnode->next == prevnode)
        {
            head = NULL;
        }
        while (prevnode->next != head)
        {
            prevnode = prevnode->next;
        }
        prevnode->next = firstnode->next;
        free(firstnode);
        break;

    case 5:
        // Delete node for certain key in circular linked list
        int key;
        printf("Enter the key to be deleted: ");
        scanf("%d", &key);
        struct Node *curr = head, *prev;
        while (curr->data != key)
        {
            if (curr->next == head)
            {
                printf("\nGiven node is not found"
                       " in the list!!!");
                break;
            }

            prev = curr;
            curr = curr->next;
        }

        // Check if node is only node
        if (curr->next == head)
        {
            head = NULL;
            free(curr);
            return;
        }

        // If more than one node, check if
        // it is first node
        if (curr == head)
        {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = curr->next;
            prev->next = head;
            free(curr);
        }

        // check if node is last node
        else if (curr->next == head && curr == head)
        {
            prev->next = head;
            free(curr);
        }
        else
        {
            prev->next = curr->next;
            free(curr);
        }
        break;

    case 6:
        // Count the total number of nodes in circular linked list
        int counting = 0;
        struct Node *temp = head;
        if (head != NULL)
        {
            do
            {
                temp = temp->next;
                counting++;
            } while (temp != head);
        }
        break;

    case 7:
        // Search for item in circular linked list
        int searchitem;
        printf("Enter the item to be searched: ");
        scanf("%d", &searchitem);
        struct Node *currentnode = head;
        int index = 0;
        do
        {
            if (currentnode == NULL)
            {
                printf("List does not exist");
            }
            if (currentnode->data == searchitem)
            {
                printf("Item found at index %d", index);
            }
            currentnode = currentnode->next;
            index++;
        } while (currentnode != head);
        break;
    default:
        printf("Invalid choice");
    }
}

int main()
{
    int choice;
    printf("\n 1. Traverse List \n 2. Check if List is empty or not \n 3. Insert node at a certain position \n 4. Delete node at certain position \n 5. Delete node for given key \n 6. Count the total number of nodes \n 7. Search for given element \n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    ImplementCLL(choice);
    return 0;
}