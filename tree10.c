#include<stdio.h>
#include<stdlib.h>
 
/* You would want to remove below 3 lines if your compiler
   supports bool, true and false */
#define bool int
#define true 1
#define false 0
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct node
{
  int data;
  struct node* left;
  struct node* right;
}node;
 
bool IsFoldable(node *root)
{
	if(root == NULL)
		return true;
	isFoldUtil(root->left,root->right);
}

bool isFoldUtil(node *a,node *b)
{
	if(a==NULL && b==NULL)
		return true;
	if(a==NULL || b==NULL)
		return false;
	return isFoldUtil(a->left,b->right) && isFoldUtil(a->right,b->left);
}
 
/*UTILITY FUNCTIONS */
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
 
/* Driver program to test mirror() */
int main(void)
{
  /* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->right->right= newNode(5);
 
  if(IsFoldable(root) == true)
  { printf("\n tree is foldable"); }
  else
  { printf("\n tree is not foldable"); }
 
  getchar();
  return 0;
}
