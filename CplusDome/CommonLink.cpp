#include<iostream>
using namespace std;
struct ListNode{
	int value;
	ListNode* next=NULL;
}; 

ListNode* initLink(){
	ListNode* pHead=new ListNode();
	return pHead;
	
}

void AddToTail(ListNode* pHead,int value){
	ListNode* pNewNode=new ListNode();
	pNewNode->value=value;
	pNewNode->next=NULL;
	if(pHead->next==NULL){
		pHead->next=pNewNode;
	//	cout<<pHead->value<<endl;
	}else{
		ListNode* pNode=new ListNode();
		pNode=pHead;
		while(pNode->next!=NULL){
			pNode=pNode->next;
		}
	///	cout<<"fdd"<<endl;
		pNode->next=pNewNode;
	}
	
}

void AddToHead(ListNode* pHead,int value){
	ListNode* pNewNode=new ListNode();
	pNewNode->value=value;
	pNewNode->next=NULL;
	if(pHead->next==NULL){
		pHead->next=pNewNode;
	}else{
		pNewNode->next=pHead->next;
		pHead->next=pNewNode;
	}
}

void OutputList(ListNode* pHead){
	ListNode* pNode=new ListNode();
	pNode=pHead;
	//cout<<"ff1"<<endl;
	while(pNode->next!=NULL){
		pNode=pNode->next;
		cout<<pNode->value<<endl;
	}
}
void OutPut(ListNode* pHead){
	ListNode* pNode=new ListNode();
	pNode=pHead->next;
	if(pNode->next==NULL){
		cout<<pNode->value<<endl;
		return;
	}
	OutPut(pNode);
	cout<<pNode->value<<endl;
}

void RemoveNodeByValue(ListNode* pHead,int value){
	ListNode* p=new ListNode();
	ListNode* q=new ListNode();
	p=pHead;
	q=p->next;
	while(q->next!=NULL){
		if(q->value==value){
			p->next=q->next;
			delete q;
			break;
		}else{
			p=q;
			q=p->next;
		}
	}
}

void RemoveNodeByIndex(ListNode* pHead,int index){
	ListNode* p=new ListNode();
	ListNode* q=new ListNode();
	p=pHead;
	q=p->next;
	int flag=0;
	while(q->next!=NULL){
		if(flag==index){
			p->next=q->next;
			delete q;
			break;
		}else{
			p=q;
			q=p->next;
			flag++;
		}
	}
}

int main(){
	ListNode* pHead=initLink();
	for(int i=0;i<9;i++){
		AddToTail(pHead,i);
	///	cout<<"ff"<<endl;
	}
	OutputList(pHead);
	RemoveNodeByValue(pHead,3);
	OutputList(pHead);
	RemoveNodeByIndex(pHead,3);
	OutputList(pHead);
	AddToHead(pHead,100);
	cout<<endl;
	OutputList(pHead);
	cout<<endl;
	OutPut(pHead);
	return 0;
}
