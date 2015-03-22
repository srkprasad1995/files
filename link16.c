#include<stdio.h>
#include<stdlib.h>
 
/* Linked list node */
typedef struct node
{
    int data;
    struct node* next;
}node;
 
/* Function to create a new node with given data */
struct node *newNode(int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = newNode(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Adds contents of two linked lists and return the head node of resultant list */
struct node* addTwoLists (struct node* first, struct node* second)
{
	node *result=NULL;
	node *temp,*prev;
	node *a=first;
	node *b=second;
	int carry=0;
	while(a!=NULL || b!=NULL)
	{
		int sum=carry+(a?a->data:0)+(b?b->data:0);
		carry=sum>=10 ? 1:0 ;
		sum=sum%10;
		temp=newNode(sum);
		if(result==NULL)
			result=temp;
		else
			prev->next=temp;
		prev=temp;
		if(a) a=a->next;
		if(b) b=b->next;
	}
	if(carry>0){
		temp=newNode(carry);
		prev->next=temp;
	}
	return result;
}
 
// A utility function to print a linked list
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
/* Drier program to test above function */
int main(void)
{
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);
 
    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);
 
   return 0;
}
