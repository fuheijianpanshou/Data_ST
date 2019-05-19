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
	Node *p=head;
	for(i=0;i<n;i++){
		Node *node=(Node*)malloc(sizeof(Node));
		node->next=NULL;
		node->value=i+1;
		p->next=node;
		p=node;
	}
}
void SearchNode(Node *head,int k){
	Node *p,*q;
	int n=0;
	if(head->next!=NULL){
		p=head->next;
		q=head->next;
		while(p!=NULL){
			p=p->next;
			if(n<k){
				n++;	
			}else{
				q=q->next;
			}
		}
		if(n!=k){
			printf("û���ҵ���\n");
		}else{
			printf("%d ",q->value);
		}
		
	}
}
void show(Node *head){
	Node *p=head->next;
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->next;
	}
}
int main(){
	printf("�ٲ��ı���������£��ҵ�����ĵ�����k�����\n");
	Node *head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	init(head);
	int k;
	scanf("%d",&k);
	printf("\n");
	show(head);
	printf("\n");
	SearchNode(head,k);
	printf("\n");
	show(head);
	printf("\n");
	return 0;
}

