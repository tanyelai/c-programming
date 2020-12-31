#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n *next;
};
typedef struct n node;


node *push(node*,int);
int pop(node*);
void print(node*);

int main()
{
	node *stack = NULL;
	stack = push(stack,3);
	stack = push(stack,2);
	stack = push(stack,1);
	print(stack);
	printf("%d ",pop(stack));
	stack = push(stack,1);
	printf("%d ",pop(stack));
	stack = push(stack,1);


	
	
	return 0;
}

node* push (node *root, int a)
{
	if (root == NULL){
		root = (node *) malloc (sizeof(node));
		root -> data = a;
		root -> next = NULL;
		return root;
	}	
	node *iter = root;
	while(iter -> next != NULL)
		iter = iter -> next;
	
	node *temp = (node *)malloc(sizeof(node));
	temp -> data = a;
	temp -> next = NULL;
	iter->next = temp;
	return root;
}


int pop(node *root)
{
	if(root == NULL){
		printf("Stack bos");
		return -1;
	}
	
	if(root->next == NULL){
		int rvalue = root->data;
		free(root);
		return rvalue;
	}
	
	else{
	node*temp=root;
	int rvalue = root->data;
	root = root->next;
	free(temp);
	return rvalue;
	}
}

void print(node*root)
{
	while(root != NULL){
		printf("%d ",root->data);
		root = root->next;
	}
}
