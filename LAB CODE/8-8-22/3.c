// Simple C++ program to find n'th node from end
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
typedef struct Node {
	int data;
	struct Node* next;
}Node;

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(Node* head, int n)
{
	int len = 0, i;
	Node* temp = head;

	// count the number of nodes in Linked List
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}
	if (len < n)
		return;
	temp = head;
	for (i = 1; i < len - n + 1; i++)
		temp = temp->next;
	printf("%d",temp->data);
	return;
}

void push(struct Node** head_ref, int new_data)
{
	Node* new_node = (Node *)malloc(sizeof(Node));


	new_node->data = new_data;


	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

// Driver Code
int main()
{

	/* Start with the empty list */
	struct Node* head = NULL;

	// create linked 35->15->4->20
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	printNthFromLast(head, 4);
	return 0;
}
