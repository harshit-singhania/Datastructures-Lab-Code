#include<stdio.h>
#include<stdlib.h>
struct BST
{
    int data;
    struct BST *lchild;
    struct BST *rchild;
};
typedef struct BST * NODE;

NODE create()
{
    NODE temp;
    temp = (NODE) malloc(sizeof(struct BST));
    printf("\nEnter The value: ");
    scanf("%d", &temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void insert(NODE root, NODE newnode);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void search(NODE root);
void smallest(NODE root);
void largest(NODE root);

void insert(NODE root, NODE newnode)
{
    if (newnode->data < root->data)
    {
        if (root->lchild == NULL)
            root->lchild = newnode;
        else
            insert(root->lchild, newnode);
    }
    if (newnode->data > root->data)
    {
        if (root->rchild == NULL)
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);
    }
}

void search(NODE root)
{
    int key;
    NODE cur;
    if(root == NULL)
    {
        printf("\nBST is empty.");
        return;
    }
    printf("\nEnter Element to be searched: ");
    scanf("%d", &key);
    cur = root;
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            printf("\nKey element is present in BST");
            return;
        }
        if (key < cur->data)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }
    printf("\nKey element is not found in the BST");
}

void inorder(NODE root)
{
    if(root != NULL)
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

void smallest(NODE root)
{
    while(root != NULL && root->lchild != NULL)
    {
        root = root->lchild;
    }
    printf("\nSmallest value is %d\n", root->data);
}

void largest(NODE root)
{
    while (root != NULL && root->rchild != NULL)
    {
        root = root->rchild;
    }
    printf("\nLargest value is %d", root->data);
}

void delete1(NODE root)
{
    printf("\nElement deleted");
}
int main()
{
    int ch, key, val, i, n;
    NODE root = NULL, newnode;
    while(1)
    {
        printf("\n\n-----------------------");
        printf("\nBinary Search Tree Menu");
        printf("\n-----------------------");
        printf("\n1 - Create binary tree\n");
        printf("2 - Inorder Traversal\n");
        printf("3 - Preorder Traversal\n");
        printf("4 - Postorder Traversal\n");
        printf("5 - Search\n");
        printf("6 - Find Smallest Element\n");
        printf("7 - Find Largest Element\n");
        printf("8 - Deletion of tree\n");
        printf("9 - Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nEnter the number of elements: ");
                    scanf("%d", &n);
                    for(i=1;i<=n;i++)
                    {
                        newnode = create();
                        if (root == NULL)
                            root = newnode;
                        else
                            insert(root, newnode);
                    }
                    break;
            case 2: if (root == NULL)
                        printf("\nTree Is Not Created");
                    else
                        printf("\nThe Inorder display : ");
                        inorder(root);
                    break;
            case 3: if (root == NULL)
                        printf("\nTree Is Not Created");
                    else
                        printf("\nThe Preorder display : ");
                        preorder(root);
                    break;
            case 4: if (root == NULL)
                        printf("\nTree Is Not Created");
                    else
                        printf("\nThe Postorder display : ");
                        postorder(root);
                    break;
            case 5: search(root);
                    break;
            case 6: smallest(root);
                    break;
            case 7: largest(root);
                    break;
            case 8: delete1(root);
                    break;
            case 9: exit(0);
        }
    }
}

