// Write the following menu driven program for the binary search tree

// ----------------------------------------
// Binary Search Tree Menu
// ----------------------------------------
// 0. Quit
// 1. Create
// 2. In-Order Traversal
// 3. Pre-Order Traversal
// 4. Post-Order traversal
// 5. Search
// 6. Find Smallest Element
// 7. Find Largest Element
// 8. Deletion of Tree
// ----------------------------------------
// Enter your choice:

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void create();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void search(struct node *, int);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
void deleteTree(struct node *);

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
    }
    return 0;
}

void create()
{
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
}

void inorder(struct node *ptr)
{
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
}

void preorder(struct node *ptr)
{
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
}

void postorder(struct node *ptr)
{
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
}

void search(struct node *ptr, int item)
{
    if (ptr != NULL)
    {
        if (item > ptr->data)
        {
            search(ptr->right, item);
        }
        else if (item < ptr->data)
        {
            search(ptr->left, item);
        }
        else
        {
            printf("Item %d found", item);
            return;
        }
    }
    printf("Item %d not found", item);
}

struct node *findSmallestElement(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Tree is empty");
        return NULL;
    }
    else if (ptr->left != NULL)
    {
        return findSmallestElement(ptr->left);
    }
    return ptr;
}

struct node *findLargestElement(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Tree is empty");
        return NULL;
    }
    else if (ptr->right != NULL)
    {
        return findLargestElement(ptr->right);
    }
    return ptr;
}

void deleteTree(struct node *ptr)
{
    if (ptr != NULL)
    {
        deleteTree(ptr->left);
        deleteTree(ptr->right);
        free(ptr);
    }
}

