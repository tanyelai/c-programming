#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	node *next;
};

void printer(node *);
void append(node *, int);

int main()
{
	node *root;
	root = (node*) malloc (sizeof(node));
	root -> next = NULL;
	root -> data = 15;
	
	int i;
	for (i=0; i<5; i++){
		append(root, i*10);	
	}
	
	printer(root);
	
	return 0;
}

void printer(node *r)
{
	while (r != NULL){
		printf("%d ",r -> data);
		r = r -> next;
	}	
}

void append(node *r, int x)
{
	while ( r -> next != NULL){
		r = r -> next;
	}
		
	r -> next = (node*) malloc (sizeof(node));
	r -> next -> data = x;
	r -> next -> next = NULL;	
}
