#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack 
{
	char *ar;
	struct stack *next;
}stack;
stack *pop(stack *top);
stack *push(char *a,int,stack *top);
int main()
{
	stack *top=NULL;
	char s[2000002]="";
	int p;
	scanf("%d",&p);
	top=push(s,strlen(s),top);
	
	while(p!=0)
	{
	int t,i;
	int len=strlen(s);
	//printf("len=%d",len);
	scanf("%d",&t);
	switch(t)
	{
		case 1:{
			char *w=(char*)malloc(1000002*sizeof(char));
			top=push(s,len,top);
			scanf("%s",w);
			strcat(s,w);
			free(w);
			break;
		}
		case 2:{
			int d;
			top=push(s,len,top);
			scanf("%d",&d);
			s[len-d]=NULL;
			break;
		}
		case 3:{
			int d;
			scanf("%d",&d);
			printf("%c\n",s[d-1]);
			break;
		}
		case 4:{
		//	printf("stack=%s",top->ar);
			strcpy(s,top->ar);
		//	printf("s=%s",s);
			top=pop(top);
			break;
		}
	}
p--;
}
}
stack *push(char a[],int len,stack *top)
{
	stack *temp=(stack*)malloc(sizeof(stack));
	temp->ar=(char*)malloc((len+3)*sizeof(char));
	if(temp==NULL)
	{
		printf("Memory not available");
		return;
	}
	strcpy(temp->ar,a);

	if(top==NULL)
	{
		top=temp;
		temp->next=NULL;
		return top;
	}
	temp->next=top;
	top=temp;
	return top;
}

stack *pop(stack *top)
{
	if(top==NULL)
	{
		printf("To few argue ments to use this func\n");
		return NULL;
	}
	stack *temp=top;
	top=top->next;
	free(temp);
	return top;
}








