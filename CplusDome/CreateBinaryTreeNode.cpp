#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* mLeft=NULL;
	BinaryTreeNode* mRight=NULL;
};
//BinaryTreeNode preTree[20];
//BinaryTreeNode midTree[20];

BinaryTree* ConstructCore(int preTree[],int midTree[],int startPre,int endPre,int startMid,int endMid){
	int rootValue=preTree[startPre];
	BinaryTreeNode* root=new BinaryTreeNode();
	root->value=rootValue;
	if(startPre==endPre){
		if(startMid==endMid){
			return root;
		}else{
			
		}
	}
	
	
}

int main(){
	int len;
	cin>>len;
	int preTree[20];
	int midTree[20]; 
	for(int i=0;i<len;i++){
		cin>>preTree[i];
	}
	for(int i=0;i<len;i++){
		cin>>midTree[i];
	}
	
	return 0;
}
