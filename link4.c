#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
typedef struct node
{
    int data;
    struct node* next;
}node;

void reverse(struct node **head)
{
	if(*head==NULL  || (*head)->next==NULL)
		return ;
	node *temp = (*head)->next;
	reverse(&temp);
	(*head)->next->next=*head;
	(*head)->next= NULL;
	(*head)=temp;
	return ;
}

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
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     printList(head);    
     reverse(&head);                      
     printf("\n Reversed Linked list \n");
     printList(head);    
     getchar();
}

