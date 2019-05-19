#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int *elem;
	int maxSize=20;
	int front,rear;
	int currentSize=0;
}CircQueue;

void init(CircQueue &cq){
	cq.elem=(int*)malloc(cq.maxSize*sizeof(int));
	cq.front=cq.rear=0;
}

int isFull(CircQueue &cq){
	if(cq.front==(cq.rear+1)%cq.maxSize){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(CircQueue &cq){
	if(cq.front==cq.rear){
		return 1;
	}else{
		return 0;
	}
}

void enQueue(CircQueue &cq,int value){
	if(!isFull(cq)){
		cq.elem[cq.rear]=value;
		cq.rear=(cq.rear+1)%cq.maxSize;
		cq.currentSize++;
	}else{
		printf("¶ÓÁÐÂú\n");
		return;
	}
	
}
void deQueue(CircQueue &cq,int &value){
	if(!isEmpty(cq)){
		value=cq.elem[cq.front];
		cq.front=(cq.front+1)%cq.maxSize;
		cq.currentSize--;
	}
}

int findMin(CircQueue &cq){
	int i,k,m=0,n=cq.currentSize;
	int min;
	deQueue(cq,min);
	enQueue(cq,min);
	for(i=1;i<n;i++){
		deQueue(cq,k);
		if(k<min){
			min=k;
		}
		enQueue(cq,k);
	}
	return min;
}

int main(){
	int n,i,k,min;
	CircQueue cq;
	init(cq);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		enQueue(cq,k);
	}
	min=findMin(cq);
	printf("%d \n",min);
	return 0;
}

