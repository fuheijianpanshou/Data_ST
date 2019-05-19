#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode{
	int t_value;
	treeNode* leftNode=NULL;
	treeNode* rightNode=NULL;
	int leftTag;
	int rightTag;
	int tag;
}TreeNode;
//递归前序创建二叉树 
TreeNode* createTree(int* num){
	TreeNode* root;
	int value;
	scanf("%d",&value);
	if(value>=0){
		*num=*num+1;
		root=(TreeNode*)malloc(sizeof(TreeNode));
		root->t_value=value;
		root->leftNode=createTree(num);
		root->rightNode=createTree(num);
	}else{
		root=NULL;
	}
	return root;
}
//使用序号创建二叉树 
TreeNode* CreateTreeByNum(){
	TreeNode *T,*p,*s[20];
	int val;
	int i,j;
	while(1){
		scanf("%d",&i);
		if(i==0){
			break;
		}else{
			scanf("%d",&val);
			p=(TreeNode*)malloc(sizeof(TreeNode));
			p->t_value=val;
			p->leftNode=NULL;
			p->rightNode=NULL;
			s[i]=p;
			if(i==1){
				T=p;
			}else{
				j=i/2;
				if(i%2==0){
					s[j]->leftNode=p;
				}else{
					s[j]->rightNode=p;
				}
			}
		}
	}
	return T;
}
//计算二叉树叶子节点的个数
int searchleaves(TreeNode* root){
	TreeNode* stack[20];
	TreeNode *T,*p=root;
	int top=0;
	int sum=0;
	if(p!=NULL){
		stack[++top]=p;
		while(top>0){
			p=stack[top--];
			if(p->rightNode==NULL&&p->leftNode==NULL){
				sum++;
			}
			if(p->rightNode!=NULL){
				stack[++top]=p->rightNode;
			}
			if(p->leftNode!=NULL){
				stack[++top]=p->leftNode;
			}
		}
	}
	return sum;
} 
//计算树的深度
int searchDeeph(TreeNode* root){
	TreeNode *Queue[20];
	TreeNode *p=root;
	int front=0;
	int rear=0;
	int depth=0,level;
	if(root!=NULL){
		Queue[++rear]=p;
		level=rear;
		while(front<rear){
			p=Queue[++front];
			if(p->leftNode!=NULL){
				Queue[++rear]=p;
			}
			if(p->rightNode!=NULL){
				Queue[++rear]=p;
			}
			if(front==level){
				depth++;
				level=rear;
			}
		}
	}
	return depth;
	
} 
//递归前序遍历二叉树 
void RecursivePreSearch(TreeNode* root){
	if(root==NULL){
		return;
		
	}else{
		printf("%d ",root->t_value);
		RecursivePreSearch(root->leftNode);
		RecursivePreSearch(root->rightNode);
	}
	printf("\n");
}
//递归中序遍历二叉树 
void RecursiveMidSearch(TreeNode* root){
	if(root==NULL){
		return;
		
	}else{
		RecursiveMidSearch(root->leftNode);
		printf("%d ",root->t_value);
		RecursiveMidSearch(root->rightNode);
	}
	printf("\n");
}
//递归后续遍历二叉树 
void RecursiveLatterSearch(TreeNode* root){
	if(root==NULL){
		return;
		
	}else{
		RecursiveLatterSearch(root->leftNode);
		RecursiveLatterSearch(root->rightNode);
		printf("%d ",root->t_value);
	}
	printf("\n");
}
//非递归前序遍历二叉树
int* CommonPreSearch(TreeNode* root){
	TreeNode* stack[10];
	TreeNode* p;
	int top=0;
	p=root;
	int pre[10];
	int nu=0;
	while(top>=0&&p!=NULL){
		while(p!=NULL){
			if(p->rightNode!=NULL){
				stack[top]=p->rightNode;
				top++;
			}
			printf("%d ",p->t_value);
			pre[nu]=p->t_value;
			nu++;
			p=p->leftNode;	
		}
		p=stack[--top];
	}
	printf("\n");
	return pre;
} 
void test(TreeNode* root){
	TreeNode* stack[10];
	TreeNode *p,*last=NULL;
	int top=0;
	p=root;
	int nu=0;
	while(top>=0&&p!=NULL){
		while(p!=NULL){
			if(p->rightNode!=NULL){
				stack[top]=p->rightNode;
				top++;
			}
			printf("%d ",p->t_value);
			if(p->leftNode!=NULL){
				p->leftTag=0;
				if(p->t_value==4){
					printf("NO\n");
				}
			}else{
				p->leftTag=1;
				p->leftNode=last;
				if(p->t_value==4){
					printf("Yes\n");
				}
			}
			if(last!=NULL){
				if(last->rightNode!=NULL){
					last->rightTag=0;
				}else{
					last->rightTag=1;
					last->rightNode=p;
				}
			}
			last=p;
			p=p->leftNode;	
		}
		p=stack[--top];
	}
	last->rightTag=1;
	printf("\n");
}
//非递归中序遍历二叉树
int* CommonMidSearch(TreeNode* root){
	TreeNode* stack[10];
	TreeNode* p;
	int top=0;
	p=root;
	int mid[10];
	int nu=0;
	while(1){
		while(p!=NULL){
			stack[top]=p;
			top++;
			p=p->leftNode;
		}
		if(p==NULL){
			if(top<=0){
				break;
			}
			p=stack[--top];
			printf("%d",p->t_value);
			mid[nu]=p->t_value;
			nu++;
			p=p->rightNode;
		}
	}
	printf("\n");
	return mid;
} 
//非递归后续二叉树遍历
void CommonLatterSearch(TreeNode* root){
	TreeNode* stackNode[10];
	TreeNode* p;
	int top=0;
	int stackTag[10];	
	int tag;
	p=root;
	while(1){
		while(p!=NULL){
			stackNode[top]=p;
			stackTag[top]=0;
			top++;
			p=p->leftNode;
		}
		if(p==NULL){
			tag=stackTag[top-1];
			if(tag==0){
				p=stackNode[top-1];
				stackTag[top-1]=1;
				p=p->rightNode;
			}else{
				p=stackNode[--top];
			//	printf("%d",p->t_value);
				p=NULL;
				if(top==0){
					break;
				}
			}
			
		}
	}
	printf("\n");
	
} 
//构造前序遍历线索二叉树
void PreOder_Thread(TreeNode* root){
	TreeNode *p,*last,*stack[20];
	int top=0;
	last=NULL;
	if(root!=NULL){
		stack[++top]=root;
		while(top>0){
			p=stack[top--];
			if(p->leftNode!=NULL){
				p->leftTag=0;
				if(p->t_value==4){
					printf("NO\n");
				}
			}else{
				p->leftTag=1;
				p->leftNode=last;
				if(p->t_value==4){
					printf("Yes\n");
				}
			}
			if(last!=NULL){
				if(last->rightNode!=NULL){
					last->rightTag=0;
				}else{
					last->rightTag=1;
					last->rightNode=p;
				}
			}
			last=p;
			if(p->rightNode!=NULL){
				stack[++top]=p->rightNode;
			}
			if(p->leftNode!=NULL){
				stack[++top]=p->leftNode;
			}
		}
		last->rightTag=1;
	}
} 
//构造中序线索二叉树
void InOredr_Threading(TreeNode *root){
	TreeNode *p,*last,*stack[20];
	int top=0;
	p=root;
	last=NULL;
	while(top>0||p!=NULL){
		if(p!=NULL){
			stack[++top]=p;
			p=p->leftNode;
		}else{
			p=stack[top--];
		if(p->leftNode!=NULL){
			p->leftTag=0;
		}else{
			p->leftTag=1;
			p->leftNode=last;
		}
		if(last!=NULL){
			if(last->rightNode!=NULL){
				last->rightTag=0;
			}else{
				last->rightTag=1;
				last->rightNode=p;
			}
		}
		last=p;
		p=p->rightNode; 
		}
		
	}
	last->rightTag=1;
	
} 
//先序遍历线索二叉树
void PreThreadSearch(TreeNode *root){
	TreeNode *p=root;
	while(p!=NULL){
		printf("%d ",p->t_value);
		if(p->t_value==4){
			printf("\n");
			printf("%d",p->leftTag);
			printf("%d",(p->rightNode)->t_value);
		}
		if(p->leftTag==0){
			p=p->leftNode;
		}else{
			p=p->rightNode;
		}
		
	}
} 
//中序遍历线索二叉树
void InThreadSearch(TreeNode *root){
	TreeNode *p;
	if(root!=NULL){
		p=root;
		while(p->leftTag==0){
			p=p->leftNode;
		}
		while(p!=NULL){
			printf("%d ",p->t_value);
			if(p->rightTag==1){
				p=p->rightNode;
			}else{
				p=p->rightNode;
				while(p->leftTag==0){
					p=p->leftNode;
				}
			}
		}
	}
} 
//使用中序遍历和前序遍历的数组创建二叉树
//TreeNode* CreateTreeByPreAndMid(int pre[],int mid[],int prehead,int pretail,int midhead,int midtail){
//
//	TreeNode* root;
//	int i=0;
//	int flag=0;
//	root=(TreeNode*)malloc(sizeof(TreeNode));
//	root->t_value=pre[prehead];
//	root->leftNode=root->rightNode=NULL;
//	if(prehead==pretail&&midhead==midtail&&pre[prehead]==mid[midhead]){
//		return root;
//	}
//	
//	for(i=midhead;i<=midtail;i++){
//		
//		if(mid[i]==pre[prehead]){
//			flag=i;
//			printf("%d ",flag);
//			break;
//		}
//	}
//	int leftLength=flag-midhead;
//	int leftPreEnd=prehead+flag;
//	if(leftLength>0){
//		root->leftNode=CreateTreeByPreAndMid(pre,mid,prehead+1,leftPreEnd,midhead,flag-1);
//	}
//	if(leftLength<pretail-prehead){
//		root->rightNode=CreateTreeByPreAndMid(pre,mid,prehead+flag+1,pretail,midhead+flag+1,midtail);
//
//	}
//	return root;
//	
//	
//} 
int main(){
	TreeNode* root;
	TreeNode* root2;
	int *num=(int*)malloc(sizeof(int));
	*num=0;
	//root=createTree(num);
	root=CreateTreeByNum();
	//CommonPreSearch(root);
	InOredr_Threading(root);
	InThreadSearch(root);
	//PreOder_Thread(root);
	//PreThreadSearch(root);
	
	//CommonMidSearch(root);
	//CommonLatterSearch(root);
	printf("叶子数为：%d",searchleaves(root));
	//RecursivePreSearch(root2);
	return 0;
}
