#include <stdio.h>
#include <stdlib.h>
#define MAX 500
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

struct node** create_queue(int *, int *);
void enqueue(struct node **, int *, struct node *);
struct node *deque(struct node **,int *);

void printLevelOrder(node *root)
{
	node *temp=root;
	int front,rear;
	node **queue=create_queue(&front,&rear);
	while(temp)
	{
		printf("%d ",temp->data);
		if(temp->left)
			enqueue(queue,&rear,temp->left);
		if(temp->right)
			enqueue(queue,&rear,temp->right);
		temp=deque(queue,&front);
	}
}

node **create_queue(int *front,int *rear)
{
	node **queue=(node **)malloc(sizeof(node*) * MAX);
	*front=*rear=0;
	return queue;
}
void enqueue(node **queue,int *rear,node *root)
{
	queue[*rear]=root;
	(*rear)++;
}

node *deque(node **queue,int *front)
{
	(*front)++;
	return queue[(*front)-1];
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
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
 
  getchar();
  return 0;
}
