#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int sum[500],min=INT_MAX,max=INT_MIN;

typedef struct node
{
    int data;
    struct node *left, *right;
}Node;

void verticalutil(struct node *root,int count)
{
	if(root==NULL)
		return ;
	if(min > count)
		min=count;
	if(max < count)
		max=count;
	sum[count]+=root->data;
	verticalutil(root->left,count-1);
	verticalutil(root->right,count+1);
	return ;
}

 
void topView(struct node *root)
{
	int count=100;
	verticalutil(root , count);
	return;
}

// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

 
// Driver Program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
 
    topView(root);
    int i;
    for(i=min;i<=max;i++)
	printf("%d   ",sum[i]);
 
    return 0;
}

