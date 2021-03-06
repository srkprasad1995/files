#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
typedef struct node
{
    int data;
    struct node* next;
}node;
 
/* function prototypes */
struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef);
 
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct node** headRef)
{
	if(*headRef==NULL || (*headRef)->next==NULL)
		return ;
	node *a=NULL,*b=NULL;
	FrontBackSplit(*headRef,&a,&b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef=SortedMerge(a,b);	
}
 
/* See http://geeksforgeeks.org/?p=3622 for details of this 
   function */
struct node* SortedMerge(struct node* a, struct node* b)
{
 	node *result;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a->data<=b->data)
	{
		result=a;
		result->next=SortedMerge(a->next,b);
	}
	else
	{
		result=b;
		result->next=SortedMerge(a,b->next);
	} 
	return result;
}
 
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.
     If the length is odd, the extra node should go in the front list.
     Uses the fast/slow pointer strategy.  */
void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef)
{
	node *fast=source,*slow=source,*prev=NULL;
	while(fast!=NULL&&fast->next!=NULL)
	{
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
    }
    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
    *frontRef = source;
    *backRef = prev->next;
    prev->next = NULL;
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
  
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* res = NULL;
  struct node* a = NULL;
  
  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2); 
  
  /* Sort the above created Linked List */
  MergeSort(&a);
  
  printf("\n Sorted Linked List is: \n");
  printList(a);           
  
  getchar();
  return 0;
}
