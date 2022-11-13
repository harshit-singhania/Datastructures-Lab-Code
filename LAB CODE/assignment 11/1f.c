#include <stdio.h>
#include <stdlib.h>
#define bool int
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct sNode
{
  struct tNode *t;
  struct sNode *next;
};

void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);

struct node *root = NULL;

void binaryTree(int choice);

int main()
{
    int choice, num;

    while (1)
    {
        printf("---------------------------------------- \n");
        printf("Binary Search Tree Menu \n");
        printf("---------------------------------------- \n");
        printf("0. Quit \n");
        printf("1. Create \n");
        printf("2. In-Order Traversal \n");
        printf("3. Pre-Order Traversal \n");
        printf("4. Post-Order traversal \n");
        printf("5. Search \n");
        printf("6. Find Smallest Element \n");
        printf("7. Find Largest Element \n");
        printf("8. Deletion of Tree \n");
        printf("---------------------------------------- \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        binaryTree(choice);
    }
    return 0;
}

void binaryTree(int choice)
{
    int num;
    switch (choice)
    {
    // Exit
    case 0:
        exit(0);
        break;

    // Create
    case 1:
        struct node *temp, *ptr;
        int item;

        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Out of Memory Space");
            exit(0);
        }
        printf("Enter the data value for the node: ");
        scanf("%d", &item);
        temp->data = item;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            ptr = root;
            while (ptr != NULL)
            {
                if (item > ptr->data)
                {
                    if (ptr->right == NULL)
                    {
                        ptr->right = temp;
                        return;
                    }
                    ptr = ptr->right;
                }
                else
                {
                    if (ptr->left == NULL)
                    {
                        ptr->left = temp;
                        return;
                    }
                    ptr = ptr->left;
                }
            }
        }
        break;

    // In-Order Traversal
    case 2:
        if (root == NULL)
        {
            printf("Tree is empty");
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->left);
            printf("%d -> ", ptr->data);
            inorder(ptr->right);
        }
        break;

    // Pre-Order Traversal
    case 3:
        if (root == NULL)
        {
            printf("Tree is empty");
            return;
        }
        if (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            preorder(ptr->left);
            preorder(ptr->right);
        }
        break;

    // Post-Order traversal
    case 4:
        if (root == NULL)
        {
            printf("Tree is empty");
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->left);
            postorder(ptr->right);
            printf("%d -> ", ptr->data);
        }
        break;

    // Search
    case 5:
        if (root == NULL)
        {
            printf("Tree is empty");
            return;
        }
        printf("Enter the element to be searched: ");
        scanf("%d", &num);
        search(root, num);
        break;

    // Find smallest element 
    case 6:
        if (root == NULL)
        {
            printf("Tree is empty");
            return;
        }
        ptr = findSmallestElement(root);
        printf("Smallest element is: %d", ptr->data);
        break;

    // Find largest element
    case 7:
        if (root == NULL)
        {
            printf("Tree is empty");
            return;
        }
        ptr = findLargestElement(root);
        printf("Largest element is: %d", ptr->data);
        break;

    // Deletion of Tree
    case 8:
        if (root == NULL)
        {
            printf("Tree is empty");
            return;
        }
        deleteTree(root);
        printf("Tree deleted");
        break;

    default:
        printf("Wrong choice");
        break;
    }
}