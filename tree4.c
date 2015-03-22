#include<stdio.h>
#include<stdlib.h>
 
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node 
{
    int data;
    struct node* left;
    struct node* right;
}node;
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}
 

void mirror(struct node* head) 
{
	if(head==NULL)
		return ;
	mirror(head->left);
	mirror(head->right);
	node *temp=head->left;
	head->left=head->right;
	head->right=temp;
	return ;
} 
 
 
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in 
   increasing sorted order.*/
void inOrder(struct node* node) 
{
  if (node == NULL) 
    return;
   
  inOrder(node->left);
  printf("%d ", node->data);
 
  inOrder(node->right);
}  
 
 
/* Driver program to test mirror() */
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
   
  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);
   
  /* Convert tree to its mirror */
  mirror(root); 
   
  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");  
  inOrder(root);
   
  getchar();
  return 0;  
}

