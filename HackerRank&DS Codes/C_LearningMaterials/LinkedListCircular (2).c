#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	node *next;
};

void printer(node *);
node *appendConsecutive(node* , int);
node *sil(node*,int);

int main() {
	node *root;
	root = NULL;
	int n,num=0;
	scanf("%d",&n);

	for(int i=0; i<n; i++) {
		scanf("%d",&num);
		root = appendConsecutive(root,num);
	}
	root = sil(root,50);
	printer(root);

	return 0;
}

void printer(node *r) {
	node *iter = r;
	while (iter->next != r) {
		printf("%d ",iter -> data);
		iter = iter -> next;
	}
}

void append(node *r,int x) {
	node *iter = r;
	while (iter->next != r)
		iter = iter -> next;

	iter->next = (node*) malloc (sizeof(node));
	iter->next->data = x;
	iter->next->next = r;
	return r;

}



node * appendConsecutive(node *r,int x) {

	if (r==NULL) { // link list boþsa
		r=(node *) malloc(sizeof(node));
		r -> next = r;
		r -> data = x;
		return r;
	}

	if (r->data > x) { // ilk elemandan küçük durumu
		// root deðiþiyor çünkü ilk kutuya daha küçük eleman geldi
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
		temp = r;
		r = r -> next;
		free(temp);
		return r;
	}

	while(iter -> next != r && iter -> next -> data != x)
		iter = iter -> next;

	if(iter -> next == r) // sayý bulunamadý !
		printf("Sayi bulunamadi ");
	return r;

	temp = iter -> next;
	iter -> next = iter -> next -> next;
	free(temp);
	return r;

}

