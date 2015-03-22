#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int sum[500],min=INT_MAX,max=INT_MIN;

struct node
{
    int data;
    struct node *left, *right;
};

void verticalutil(struct node *root,int count)
{
	if(root==NULL)
		return ;
	verticalutil(root->left,count-1);
	if(min > count)
		min=count;
	if(max < count)
		max=count;
	sum[count] += root->data;
	verticalutil(root->right,count+1);
	return ;
}

 
void verticalSum(struct node *root)
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
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
 
    verticalSum(root);
    int i;
    for(i=min;i<=max;i++)
	printf("%d   ",sum[i]);
 
    return 0;
}

