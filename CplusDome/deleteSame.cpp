#include<stdio.h>
typedef struct{
	int n;
	int a[100];
}Node;

Node node;

void init(){
	int n,i;
	scanf("%d",&n);
	node.n=n;
	for(i=0;i<n;i++){
		scanf("%d",&node.a[i]);
	}
}

void deleteSame(){
	if(node.n==0){
		printf("���\n");
		return;
	}
	
	int i,j,k=0;
	for(i=1;i<node.n;i++){
		for(j=0;j<=k;j++){
			if(node.a[i]==node.a[j]){
				break;
			}
		}
		if(j>k&&++k!=i){
			node.a[k]=node.a[i];
		}
	}
	node.n=k+1;
}

void show(){
	
	int i;
	printf("%d\n",node.n);
	for(i=0;i<node.n;i++){
		printf("%d ",node.a[i]);
	}
	printf("\n");
}
int main(){
	printf("���Ա�ɾ����ͬԪ�أ�����һ��\n");
	init();
	deleteSame();
	show();
	return 0;
}
