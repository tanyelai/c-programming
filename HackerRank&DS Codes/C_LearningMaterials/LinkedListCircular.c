#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	node *next;
};

void printer(node *);
node *appendConsecutive(node* , int);
node *sil(node*,int);
node* append(node*,int);

int main() {
	node *root;
	root = NULL;
	root = appendConsecutive(root,400);
	root = appendConsecutive(root,40);
	root = appendConsecutive(root,4);
	root = appendConsecutive(root,450);
	root = appendConsecutive(root,50);
	printer(root);
	root = sil(root,50);
	printer(root);
	root = sil(root,999);
	printer(root);
	root = sil(root,4);
	printer(root);
	root = append(root,50);
	printer(root);
	root = append(root,999);
	printer(root);
	return 0;
}

void printer(node *r) {
	node *iter = r;
	do{
		printf("%d ",iter->data);
		iter = iter->next;
		
	}while(iter != r);
	printf("\n");
}

node* append(node *r,int x) {
	node *iter = r;
	while (iter->next != r)
		iter = iter -> next;

	iter->next = (node*) malloc (sizeof(node));
	iter->next->data = x;
	iter->next->next = r;
	return r;
}



node * appendConsecutive(node *r,int x) {

	if (r==NULL) { // link list bo�sa
		r=(node *) malloc(sizeof(node));
		r -> next = r;
		r -> data = x;
		return r;
	}

	if (r->data > x) { // ilk elemandan k���k durumu
		// root de�i�iyor ��nk� ilk kutuya daha k���k eleman geldi
		node *temp = (node*)malloc(sizeof(node));
		temp -> data = x;
		temp -> next = r;

		node *iter = r;
		while(iter->next != r)
			iter = iter->next;

		iter->next = temp;
		return temp;
	}

	node *iter = r;
	while(iter->next != r && iter->next->data < x)
		iter = iter->next;

	node *temp = (node*)malloc(sizeof(node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> data = x;
	return r;

}

node * sil(node *r, int x) {
	node *temp;
	node *iter = r;
	if (r -> data == x) {
		while(iter->next != r)
			iter = iter->next;
		
		iter -> next = r -> next;
		free(r);
		return iter->next;
	}

	while(iter -> next != r && iter -> next -> data != x)
		iter = iter -> next;

	if(iter -> next == r){
		printf("Sayi bulunamadi ");
	return r;
	}

	temp = iter -> next;
	iter -> next = iter -> next -> next;
	free(temp);
	return r;

}

