#include<stdio.h>
#include <stdlib.h>
 
// A linked list node
typedef struct node
{
  int data;
  struct node *next;
}node;

void push(node **head,int new_data)
{
	node *newnode = (node *)malloc (sizeof(node));
	newnode->data = new_data;
	newnode->next = *head;
	*head = newnode;
}

void end (node **head,int new_data)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = new_data;
	newnode->next=NULL;
	node *ptr = *head;
	if(*head==NULL)
		*head=newnode;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = newnode;
}

void printList(struct node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
 
  // Insert 6.  So linked list becomes 6->NULL
  push(&head, 6);
 
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 7);
 
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push(&head, 1);
 
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  end(&head, 4);
 
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  end(&head, 8);
 
  printf("\n Created Linked list is: ");
  printList(head);
  return 0;
}	
