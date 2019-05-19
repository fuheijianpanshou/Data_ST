#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	Node *preLink;
	Node *nextLink;
};
void init(Node *head){
	int n,i;
	scanf("%d",&n);
	Node *p=head;
	for(i=0;i<n;i++){
		Node *node=(Node*)malloc(sizeof(Node));
		node->value=i+1;
		node->nextLink=NULL;
		node->preLink=p;
		p->nextLink=node;
		p=node;
	}
}
void show(Node *head){
	Node *p;
	p=head->nextLink;
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->nextLink;
	}
}
void reverse(Node *head){
	Node *p,*q,*t;
	if(head->nextLink!=NULL){
		p=head->nextLink;
		head->nextLink=NULL; 
		while(p!=NULL){
			t=p;
			q=p->nextLink;
			p->nextLink=head->nextLink;
			p->preLink=q;
			head->nextLink=p;
			p=q;
		}
		t->preLink=head;
	}
}
void anotherShow(Node *head){
	Node *p,*q;
	p=head->nextLink;
	while(p->nextLink!=NULL){
		p=p->nextLink;
	}
	while(p!=head){
		printf("%d ",p->value);
		p=p->preLink;
	}
}
int main(){
	printf("Ë«ÏòÁ´ÄæÖÃ\n");
	Node *head=(Node*)malloc(sizeof(Node));
	head->nextLink=NULL;
	head->preLink=NULL;
	init(head);
	show(head);
	reverse(head);
	printf("\n");
	show(head);
	printf("\n");
	anotherShow(head);
}
