#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
typedef struct node
{
    int data;
    struct node* next;
}node;
 
/* The function removes duplicates from a sorted list */
void removeDuplicates(struct node* head)
{
	node *temp=head;
	node *temp1;
	while(temp->next!=NULL)
	{
		temp1=temp->next;
		int f=0;
		while(temp1!=NULL && temp1->data==temp->data)
		{
			f=1;
			temp->next=temp1->next;
			node *temp2=temp1;
			free(temp2);
			temp1=temp->next;
		}
		if(f==0)
			temp=temp->next;
	}
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
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
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
} 
 
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
   
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 11->11->11->13->13->20 */
  push(&head, 20);
  push(&head, 13);
  push(&head, 13);  
  push(&head, 11);
  push(&head, 11);
  push(&head, 11);                                    
 
  printf("\n Linked list before duplicate removal  ");
  printList(head); 
 
  /* Remove duplicates from linked list */
  removeDuplicates(head); 
 
  printf("\n Linked list after duplicate removal ");         
  printList(head);            
   
  getchar();
}
