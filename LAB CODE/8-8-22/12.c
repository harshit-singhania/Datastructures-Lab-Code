#include<stdio.h>
#include<stdlib.h>

struct node{
    double data;
    struct node *next;
    
};
struct node *head=NULL;
struct node *tail=NULL;

void task1(double x);
void task2(struct node **h, double x);
void task3(struct node **h, int x, double y);
void task4(struct node *h);

int main()
{
    int n, choice, key, i;
    struct node *cur;
    double n1;

    printf("\n\n");
    printf("Node Creation ");
    printf("\n");

    printf("Enter the number of nodes that you want to create: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Node: %d\n", i+1);
        cur=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value for the node: ");
        scanf("%lf", &cur->data);
        cur->next=NULL;
        if (head==NULL){
            tail=head=cur;
        }
        else{
            tail->next=cur;
            tail=cur;
        }
    }

    printf("Enter the data that you want to find: ");
    scanf("%lf", &n1);

    task1(n1);

    return 0;
}

void task1(double x)
{
    struct node *ptr;
    double temp;
    int count=0, pos=0;

    for (ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        if (ptr->data==x)
        {
            printf("\nThe number is found\n");
            temp=x;
            count++;
            break;
        }
    }
    if (count==0)
        printf("\nData not found\n");

    printf("\n\n");
    if (temp>0 || temp<0)
    {
        task2(&head, temp);
        task3(&head, pos, temp);
        task4(head);
    }
}

void task2(struct node **h, double x)
{
    struct node *ptr, *prv;

    if (*h==NULL)
    {
        printf("The list is empty\n");
    }
    else 
    {
        ptr=*h;
        while (ptr!=NULL)
        {
            if (ptr->data==x)
                break;
            else
            {
                prv=ptr;
                ptr=ptr->next;
            }
        }
        if (ptr==NULL)
        {
            printf("The data is not found\n");
        }
        else if (ptr==*h)
        {
            *h=ptr->next;
            free(ptr);
        }
        else
        {
            prv->next=ptr->next;
            free(ptr);
        }
    }
}

void task3(struct node **h, int x, double y)
{  
    struct node *cur, *ptr;

    cur=(struct node *)malloc(sizeof(struct node));
    cur->data=y;
    cur->next=NULL;

    if (*h==NULL)
    {
        *h=cur;
    }
    else if (x==0)
    {
        cur->next=*h;
        *h=cur;
    }
}

void task4(struct node *h)
{
    for (h; h!=NULL; h=h->next)
    {
        printf("Data= %.2lf | Address= %u | Next Address= %u\n", 
                                            h->data, h, h->next);
    }
}