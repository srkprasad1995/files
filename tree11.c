#include <stdio.h>
#include <stdlib.h>
 
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
 
/* just add elements to test */
/* NOTE: A sorted array results in skewed tree */
int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
 
/* same alias */
typedef struct node_t node_t;
 
/* Binary tree node */
struct node_t
{
    int data;
 
    node_t* left;
    node_t* right;
};
 
/* simple stack that stores node addresses */

/* Iterative insertion
   Recursion is least preferred unless we gain something
*/
node_t *insert_node(node_t *root, node_t* node)
{
    /* A crawling pointer */
    node_t *pTraverse = root;
    node_t *currentParent = root;
 
    // Traverse till appropriate node
    while(pTraverse)
    {
        currentParent = pTraverse;
 
        if( node->data < pTraverse->data )
        {
            /* left subtree */
            pTraverse = pTraverse->left;
        }
        else
        {
            /* right subtree */
            pTraverse = pTraverse->right;
        }
    }
 
    /* If the tree is empty, make it as root node */
    if( !root )
    {
        root = node;
    }
    else if( node->data < currentParent->data )
    {
        /* Insert on left side */
        currentParent->left = node;
    }
    else
    {
        /* Insert on right side */
        currentParent->right = node;
    }
 
    return root;
}
 
/* Elements are in an array. The function builds binary tree */
node_t* binary_search_tree(node_t *root, int keys[], int const size)
{
    int iterator;
    node_t *new_node = NULL;
 
    for(iterator = 0; iterator < size; iterator++)
    {
        new_node = (node_t *)malloc( sizeof(node_t) );
 
        /* initialize */
        new_node->data   = keys[iterator];
        new_node->left   = NULL;
        new_node->right  = NULL;
 
        /* insert into BST */
        root = insert_node(root, new_node);
    }
 
    return root;
}

void kutil(node_t *root,int *count,int k)
{
	if(root==NULL)
		return ;
	kutil(root->left,count,k);
	(*count)++;
	if(*count==k)
		printf("%d",root->data);
	kutil(root->right,count,k);
}
 
void k_smallest_element_inorder(node_t *root, int k)
{
	int count=0;
	kutil(root,&count,k);    
}

 
/* Driver program to test above functions */
int main(void)
{
    node_t* root = NULL;
 
    int k = 3;
 
    /* Creating the tree given in the above diagram */
    root = binary_search_tree(root, ele, ARRAY_SIZE(ele));
 
    k_smallest_element_inorder( root, k);
 
 
    getchar();
    return 0;
}
