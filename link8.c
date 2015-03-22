#include<stdio.h>
#include <stdlib.h>
 
// A linked list node
typedef struct node
{
  int data;
  struct node *next;
}node;

void sortedInsert(struct node** head, struct node* new_node)
{
	node *ptr=*head;
	if(*head==NULL||(*head)->data>=new_node->data)
	{
		new_node->next=*head;
		*head=new_node;
	}
	else{
	while(ptr->next!=NULL && ( ptr->next->data<new_node->data))
		ptr=ptr->next;
	new_node->next=ptr->next;
	ptr->next=new_node;
	}
}

struct node *newNode(int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
    new_node->next =  NULL;
 
    return new_node;
}
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 
/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    struct node *new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    printList(head);
 
    getchar();
    return 0;
}


