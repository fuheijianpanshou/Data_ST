#include<bits/stdc++.h>
using namespace std;
struct Node{
	int value;
	Node* next;
};
void CreateCirLink(Node* rear,int n){
	rear->value=1;
	rear->next=rear;
	Node* pN=new Node();
	pN=rear;
	for(int i=2;i<=n;i++){
		Node* node=new Node();
		node->value=i;
		pN->next=node;
		node->next=rear;
		pN=node;
	//	rear->next=node;	
	}
}
void ShowValue(Node* rear){
	Node* node=new Node();
	node=rear;
	while(1){
		if(node->next==rear){
			cout<<node->value<<endl;
			break;
		}
		cout<<node->value<<endl;
		node=node->next;
	}
}
void Winer(Node* rear,int m){
	Node* p=new Node();
	Node* q=new Node();
	p=rear;
	//q=rear->next;
	int k=8;
	int count=1;
	while(k>1){
		if(count==m-1){
			q=p->next;
			p->next=q->next;
			//cout<<
			delete q;
			
			count=0;
			k--;
		}else{
			p=p->next;
			//q=p->next;
			count++;	
		}
	}
	cout<<p->value<<endl;
	 
	
}
int main(){
	Node* rear=new Node();
	rear->next=rear;
	CreateCirLink(rear,8);
	ShowValue(rear);
	cout<<endl;
	Winer(rear,3);
	return 0;
}
