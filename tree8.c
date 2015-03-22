#include<stdio.h>
#include<stdlib.h>

struct node* newNode(int data);

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

int diameter(node *root)
{
	int res=0;
	diam(root,&res);
	return res;
}

int diam(node *root,int *res)
{
	if(root==NULL)
	{
		return 0;
	}
	int lheight=diam(root->left,res);
	int rheight=diam(root->right,res);
	if(*res<(lheight+rheight+1))
		*res=(lheight+rheight+1);
	return lheight>rheight ? (lheight+1):(rheight+1);
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

int main()
{
 
  /* Constructed binary tree is 
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->left->left= newNode(5);
 
  printf("Diameter of the given binary tree is %d\n", diameter(root));
 
  getchar();
  return 0;
}
