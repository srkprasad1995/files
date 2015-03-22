#include<stdio.h>
#include<stdlib.h>
 
 
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Compute the "maxDepth" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int maxDepth(struct node* node) 
{
	if(node ==NULL)
		return 0;
	return maxDepth(node->left)>maxDepth(node->right)?(maxDepth(node->left)+1):(maxDepth(node->right)+1);
} 
 
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
   
int main()
{
    struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->left->left = newNode(4);
    root->left->left->left->left = newNode(5); 
   
    printf("Hight of tree is %d", maxDepth(root));
   
    getchar();
    return 0;
}

