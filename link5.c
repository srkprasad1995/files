#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
typedef struct node
{
  int data;
  struct node* next;
}node;
 
void push(struct node** head_ref, int new_data)
{
  /* allocate node */
  struct node* new_node =
  (struct node*) malloc(sizeof(struct node));
 
  /* put in the data  */
  new_node->data  = new_data;
 
  /* link the old list off the new node */
  new_node->next = (*head_ref);
 
  /* move the head to point to the new node */
  (*head_ref)    = new_node;
}

void detectloop(node *head)
{
	node *slow_ptr=head,*fast_ptr=head;
	int f=0;
	while(fast_ptr!=NULL && fast_ptr->next!=NULL)
	{
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		if(fast_ptr==slow_ptr)
		{
			f=1;
			break;
		}
	}
	if(f==1)
		printf("present\n");
	else printf("NO\n");
	return ;
}

int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
 
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);
 
  /* Create a loop for testing */
  detectloop(head);
 
  getchar();
}
