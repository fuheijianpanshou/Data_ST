#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int weight;
	int parent;
	int lch;
	int rch;
	int isCho;
}Node;
Node tree[30];
int num=0;
int currentNum=0;
int totalNum=0;
void inputWight(){
	int i;
	scanf("%d",&num);
	totalNum=2*num-1;
	currentNum=num;
	for(i=0;i<num;i++){
		scanf("%d",&tree[i].weight);
		tree[i].parent=-1;
		tree[i].rch=-1;
		tree[i].lch=-1;
		tree[i].isCho=0;
	}
	for(i=num;i<totalNum;i++){
		tree[i].weight=-1;
		tree[i].parent=-1;
		tree[i].rch=-1;
		tree[i].lch=-1;
		tree[i].isCho=0;
	}
} 
void getTwoMin(int &min,int k){
	int i=0,j;
	int min_val;
	int min_index;
	while(tree[i].isCho==1&&i<k)
	i++;
	min_val=tree[i].weight;
	min_index=i;
	for(;i<k;i++){
		if(tree[i].weight<min_val&&tree[i].isCho==0){
			min_val=tree[i].weight;
			min_index=i;
		}
	}
	min=min_index;
	tree[min_index].isCho=1;
}
//7
//1 4 6 7 8 11 12
void createHuffman(){
	int min1=-1;
	int min2=-1;
	int i;
	i=num;
	int times=num-1;
	//printf("%d ",num);
	getTwoMin(min1,i);
	getTwoMin(min2,i);
	//printf("%d ",min2);
	while(times--){
		//printf("%d %d",min1,min2);
		tree[currentNum].lch=min1;
		tree[currentNum].rch=min2;
		tree[currentNum].weight=tree[min1].weight+tree[min2].weight;
		tree[min1].parent=currentNum;
		tree[min2].parent=currentNum;
		currentNum++;
		min1=-1;
		min2=-1;
		getTwoMin(min1,currentNum);
		getTwoMin(min2,currentNum);	
	}
		

}
void show(){
	int nu;
	nu=currentNum-1;
	while(tree[nu].lch!=-1){
		printf("%d ",tree[nu].weight);
		nu=tree[nu].lch;
	}
}
//7
//1 4 6 7 8 17 20
void codeing(){
	int code[20][20];
	int i,j;
	int start;
	int current;
	int parent;
	int flag;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			code[i][j]=-1;
		}
	}
	for(i=0;i<num;i++){
		current=i;
		start=num-1;
		parent=tree[current].parent;
		flag=0;
		while(parent!=-1){
			if(tree[parent].lch==current){
				code[i][flag++]=0;
			}else{
				code[i][flag++]=1;
			}
			current=parent;
			parent=tree[parent].parent;
		} 
	}
	for(i=0;i<num;i++){
		for(j=0;code[i][j]!=-1;j++){
			printf("%d",code[i][j]);
		}
		printf("\n");
	}
}
int main(){
	inputWight();
	createHuffman();
	//show();
	codeing();
	return 0;
}
