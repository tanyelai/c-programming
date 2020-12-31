#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
    struct n *next;
    struct n *prev;
};
typedef struct n node;



void printer(node *);
node *appendConsecutive(node* , int);
node *del(node*,int);

int main() {
	node *root;
	root = NULL;
	root = appendConsecutive(root,400);
	root = appendConsecutive(root,40);
	root = appendConsecutive(root,4);
	root = appendConsecutive(root,450);
	root = appendConsecutive(root,50);
	printer(root);
	root = del(root,50);
	printer(root);
	root = del(root,999);
	printer(root);
	root = del(root,4);
	printer(root);

	return 0;
}

void printer(node *r) {
	node *iter = r;
	do{
		printf("%d ",iter->data);
		iter = iter->next;
		
	}while(iter != NULL);
	printf("\n");
}


node * appendConsecutive(node *r,int x) {

	if (r==NULL) { // link list boşsa
		r=(node *) malloc(sizeof(node));
		r -> next = NULL;
		r -> prev = NULL;
		r -> data = x;
		return r;
	}
	

	if (r->data > x) { // ilk elemandan küçük durumu
		// root değişiyor çünkü ilk kutuya daha küçük eleman geldi
		node *temp = (node*)malloc(sizeof(node));
		temp -> data = x;
		temp -> next = r;
		r -> prev = temp;
		return temp;

	}

	node *iter = r;
	while(iter->next != NULL && iter->next->data < x)
		iter = iter->next;

	node *temp = (node*)malloc(sizeof(node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> prev = iter;
	temp -> data = x;
	if (temp->next != NULL)
		temp -> next -> prev = temp;
	return r;

}

node * del(node *r, int x) {
	node *temp;
	node *iter = r;
	if (r -> data == x) {
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}

	while(iter -> next != NULL && iter -> next -> data != x)
		iter = iter -> next;

	if(iter -> next == NULL){
		printf("Sayi bulunamadi ");
		return r;
	}

	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	if (iter->next != NULL)
		iter ->next ->prev = iter;
	return r;

	
}
