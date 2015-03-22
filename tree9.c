#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

int isBST(node *root)
{
	return BSTutil(root,INT_MAX,INT_MIN);
}

int BSTutil(node *root,int max,int min)
{
	if(root==NULL)
		return 1;
	if(root->data<max  &&  root->data>min)
	{
		return 
		BSTutil(root->left,root->data,min) &&
		BSTutil(root->right,max,root->data);
	}
	return 0;
}

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}  
