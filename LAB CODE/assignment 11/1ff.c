// Binary tree operations without recursion 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct sNode
{
  struct node *t;
  struct sNode *next;
};

void push(struct sNode** top_ref, struct node *t);
struct node *pop(struct sNode** top_ref);
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

void push(struct sNode **top_ref, struct node *t) {
    struct sNode* new_tNode = (struct sNode*) malloc(sizeof(struct sNode));
    if(new_tNode == NULL)
  {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }            
  
  /* put in the data  */
  new_tNode->t  = t;
  
  /* link the old list off the new tNode */
  new_tNode->next = (*top_ref);   
  
  /* move the head to point to the new tNode */
  (*top_ref)    = new_tNode;

  
}

void binaryTree(int choice) {

    switch(choice)
    {
        // Exit 
        case 0: 
            exit(0); 
            break; 

        // Creation of binary tree without recursion 
        case 1: 

    }
}