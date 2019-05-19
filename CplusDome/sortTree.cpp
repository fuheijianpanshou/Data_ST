#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int value;
	node* leftNode;
	node* rightNode;
}Node;
Node* createSortTree(){
	Node *root;
	int value;
	Node *p,*q,*newNode;
	root=NULL;
	while(1){
		scanf("%d",&value);
		if(value==-1){
			return root;
		}else{
			if(root==NULL){
				root=(Node*)malloc(sizeof(Node));
				root->value=value;
				root->leftNode=NULL;
				root->rightNode=NULL;
			}else{
				p=root;
				while(p!=NULL){
					if(value<p->value){
						q=p;
						p=p->leftNode;
					}else if(value>p->value){
						q=p;
						p=p->rightNode;
					}else{
						break;
					}
				}
				if(p==NULL){
						newNode=(Node*)malloc(sizeof(Node));
						newNode->leftNode=NULL;
						newNode->rightNode=NULL;
						newNode->value=value;
					if(value<q->value){
						q->leftNode=newNode;
					}else{
						q->rightNode=newNode;
					}
				}
			}
		}
	}
}
Node* deleteNode(Node *root,int value){
	Node *p,*q;
	Node *work1,*work2;
	if(root!=NULL){
		p=root;
		while(p!=NULL){
			if(value>p->value){
				q=p;
				p=p->rightNode;
			}else if(value<p->value){
				q=p;
				p=p->leftNode;
			}else{
				break;
			}
		}
		if(p==NULL){
			printf("没有找到该结点！\n");
			return root;
		}else{
			if(p->leftNode==NULL||p->rightNode==NULL){
				if(p->leftNode==NULL&&p->rightNode!=NULL){
					if(value>q->value){
						q->rightNode=p->rightNode;
					}else{
						q->leftNode=p->rightNode;
					}
				}else if(p->leftNode!=NULL&&p->rightNode==NULL){
					if(value>q->value){
						q->rightNode=p->leftNode;
					}else{
						q->leftNode=p->leftNode;
					}
				}else{
					if(value>q->value){
						q->rightNode=NULL;
					}else{
						q->leftNode=NULL;
					}
				}
			}else{
				
				work2=p;
				work1=p->leftNode;
				while(work1->rightNode!=NULL){
					work2=work1;
					work1=work1->rightNode;
				}
				work2->rightNode=NULL;
				work1->rightNode=p->rightNode;
				work1->leftNode=p->leftNode;
				if(value>q->value){
					q->rightNode=work1;
				}else{
					q->leftNode=work1;
				}
				
			}
		}
		return root;
	}
}
void showTree(Node *root){
	Node *stack[30];
	Node *p,*q;
	int top=0;
	if(root!=NULL){
		p=root;
		while(1){
		while(p!=NULL){
			stack[++top]=p;
			p=p->leftNode;
		}
		if(top==0){
			break;
		}
		if(p==NULL){
			p=stack[top--];
			printf("%d ",p->value);
			p=p->rightNode;
		}
	} 
	}
	
}
int main(){
	Node *root=createSortTree();
	showTree(root);
	root=deleteNode(root,4);
	showTree(root);
	
	
	
}
