#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	Node *next;
};
void init(Node *head){
	int n;
	int i;
	scanf("%d",&n);
	if(n%2==1){
		n++;
	}
	Node *p=head;
	for(i=0;i<n;i++){
		Node *node=(Node*)malloc(sizeof(Node));
		node->next=NULL;
		node->value=i+1;
		p->next=node;
		p=node;
	}
}
void show(Node *head){
	Node *p=head->next;
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->next;
	}
}
void departLink(Node *head,Node *L2){
	Node *p,*q,*r;
	if(head->next!=NULL){
		p=head->next;
		r=head;
		while(p!=NULL){
			r->next=p;
			r=p;
			p=p->next;
			q=p->next;
			p->next=L2->next;
			L2->next=p;
			p=q;
			r->next=NULL;	
		}
	}
	
}
int main(){
	printf("偶数个结点的链表分裂为两个单链表，L1正向，L2逆向\n");
	Node *head=(Node*)malloc(sizeof(Node));
	init(head);
	show(head);
	Node *L2=(Node*)malloc(sizeof(Node));
	L2->next=NULL;
	departLink(head,L2);
	printf("\n");
	show(head);
	printf("\n");
	show(L2);
	return 0;
}
