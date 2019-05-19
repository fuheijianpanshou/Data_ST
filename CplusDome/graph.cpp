#include<stdio.h>
#include<stdlib.h>
typedef struct linknode{
	int loca;
	int startEdge;
	int endEdge;
	int weight;
	linknode* next=NULL;
}LinkNode;
typedef struct headnode{
	int name;
	LinkNode* firstEdge=NULL;
}HeadNode;

HeadNode head[30];
int visit[20];
int nodeNum=0;
int edgeNum=0; 
LinkNode *queue[20];
int header=0;
int tail=0;
void createGraph(){
	int i;
	int j;
	int firstLoca,endLoca;
	LinkNode *p,*q;
	scanf("%d%d",&nodeNum,&edgeNum);
	for(i=0;i<nodeNum;i++){
		head[i].name=i+1;
	}
	for(i=0;i<edgeNum;i++){
		LinkNode *newEdge=(LinkNode*)malloc(sizeof(LinkNode));
		newEdge->next=NULL;
		scanf("%d%d%d",&newEdge->startEdge,&newEdge->endEdge,&newEdge->weight);
		for(j=0;j<nodeNum;j++){
			if(head[j].name==newEdge->startEdge){
				firstLoca=j;
			}
			if(head[j].name==newEdge->endEdge){
				endLoca=j;
			}
		} 
		newEdge->loca=endLoca;
		if(head[firstLoca].firstEdge==NULL){
			head[firstLoca].firstEdge=newEdge;
		}else{
			p=head[firstLoca].firstEdge;
			while(p!=NULL){
				q=p;
				p=p->next;
			}
			q->next=newEdge;
		}
	}
}
void createNoDirectionGra(){
	int i;
	int j;
	int k;
	int temp;
	int firstLoca,endLoca;
	int staEdge;
	int enEdge,we;
	LinkNode *p,*q;
	scanf("%d%d",&nodeNum,&edgeNum);
	for(i=0;i<nodeNum;i++){
		head[i].name=i+1;
	}
	for(i=0;i<edgeNum;i++){
		scanf("%d%d%d",&staEdge,&enEdge,&we);
		for(k=0;k<2;k++){
			LinkNode *newEdge=(LinkNode*)malloc(sizeof(LinkNode));
			newEdge->next=NULL;
			newEdge->weight=we;
			if(k==1){
				temp=staEdge;
				staEdge=enEdge;
				enEdge=temp;
			}
			newEdge->startEdge=staEdge;
			newEdge->endEdge=enEdge;
		for(j=0;j<nodeNum;j++){
			if(head[j].name==newEdge->startEdge){
				firstLoca=j;
			}
			if(head[j].name==newEdge->endEdge){
				endLoca=j;
			}
		} 
		newEdge->loca=endLoca;
		if(head[firstLoca].firstEdge==NULL){
			head[firstLoca].firstEdge=newEdge;
		}else{
			p=head[firstLoca].firstEdge;
			while(p!=NULL){
				q=p;
				p=p->next;
			}
			q->next=newEdge;
		}	
		}
		
	}
}

void showGraph(){
	int i;
	LinkNode *p;
	for(i=0;i<nodeNum;i++){
		if(head[i].firstEdge!=NULL){
			p=head[i].firstEdge;
			while(p!=NULL){
				printf("%d ",p->loca);
				p=p->next;
			}
			printf("\n");
		}
	}
}

void wideFirstSearch(int curN){
	LinkNode *p;
	if(visit[curN]==0){
		visit[curN]=1;
		printf("%d ",head[curN].name);
		p=head[curN].firstEdge;
		while(p!=NULL){
			if(visit[p->loca]==0){
				visit[p->loca]=1;
				printf("%d ",head[p->loca].name);
				queue[tail++]=p;
			}
			p=p->next; 
		}
		p=queue[header++];
		while(tail>header){
			if(visit[p->loca]==0){
			wideFirstSearch(p->loca);
			}
		p=queue[header++];
		}	
	}else{
		return;
	}
}

void DeepFirstSearch(int curN){
//	5 7
//1 2 1
//1 5 1
//5 2 1
//5 3 1
//5 4 1
//3 4 1
//4 1 1
	LinkNode *p;
	if(visit[curN]==0){
		visit[curN]=1;
	printf("%d ",head[curN].name);
	p=head[curN].firstEdge;
	while(p!=NULL){
		if(visit[p->loca]==0){
			DeepFirstSearch(p->loca);
		}
		p=p->next;
	}
	}else{
		return;
	}
	
		
}
int main(){
	int i;
	createNoDirectionGra();
	for(i=0;i<nodeNum;i++){
		visit[i]=0;
	}	
	showGraph();
	printf("\n");
	for(i=0;i<nodeNum;i++){
		//DeepFirstSearch(i);
		wideFirstSearch(i);
	}
	return 0;
}
