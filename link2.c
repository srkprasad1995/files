#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
typedef struct node
{
    int data;
    struct node *next;
}node;
 
/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void del( node ** head , int k)
{
	node *ptr = *head;
	if(*head == NULL)
		return ;
	if(ptr->data == k)
	{
		node *temp = *head;
		*head = ptr->next;
		free(temp);
		return ;
	}
	ptr = *head;
	while (ptr !=NULL && ptr->next->data!= k)
		ptr=ptr->next;
	if(ptr == NULL)
		return ;
	node *temp1=ptr->next;
	ptr -> next = ptr ->next ->next;
	free(temp1);
}

void unknown( node **ptr)
{
	node *temp = *ptr;
	temp=temp->next;
	(*ptr)->data=temp->data;
	(*ptr)->next=temp->next;
	free(temp);
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
    del(&head, 1);
    unknown(&head->next);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}
