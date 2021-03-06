#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Function protoypes */
void printGivenLevel(struct node* root, int level, int ltr);
int height(struct node* node);
struct node* newNode(int data);
 
/* Function to print spiral traversal of a tree*/
void printSpiral(struct node* root)
{
	int h=height(root),i;
	bool f=false;
	for(i=0;i<=h;i++)
	{
		printGivenLevel(root , i, f);
		f=!f;
	}
}
 
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int i, int f)
{
	if(root==NULL)
		return ;
	if(i==1)
	{
		printf("%d ",root->data);
		return ;
	}
	if(f)
	{
		printGivenLevel(root->right,i-1,f);
		printGivenLevel(root->left,i-1,f);
	}
	else 
	{
		printGivenLevel(root->left,i-1,f);
		printGivenLevel(root->right,i-1,f);
	}
	return;
}

int max(int a,int b)
{
	return a>b?a:b;
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* root)
{
	if(root==NULL)
		return 0;
	else 
		return max(height(root->left)+1,height(root->right)+1);
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
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printSpiral(root);
 
    return 0;
}

