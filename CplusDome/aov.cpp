#include<stdio.h>
#include<stdlib.h>
typedef struct EdgeNode{
	int loca;
	int w;
	EdgeNode *next;
	
}EdgeNode;
typedef struct HeadNode{
	int name;
	int deg;
	EdgeNode *headEdge=NULL;
}HeadNode;
HeadNode head[20];
int book[20]={0};
int nodeNum=0;
int edgeNum=0;
void createGra(){
	int i,j;
	int x,y,w;
	EdgeNode *p;
	scanf("%d%d",&nodeNum,&edgeNum);
	for(i=1;i<=nodeNum;i++){
		head[i].name=i;
	}
	for(i=1;i<=edgeNum;i++){
		scanf("%d%d%d",&x,&y,&w);
		EdgeNode *newEdge=(EdgeNode*)malloc(sizeof(EdgeNode));
		newEdge->loca=y;
		newEdge->next=NULL;
		newEdge->w=w; 
		p=head[x].headEdge;
		if(p==NULL){
			head[x].headEdge=newEdge;
		}else{
			while(p->next!=NULL){
				p=p->next;
			}
			p->next=newEdge;
		}
		
	}
}
void updateDeg(){
	int i,j;
	EdgeNode *p,*q;
	for(i=1;i<=nodeNum;i++){
		if(book[i]==0){
			p=head[i].headEdge;
			while(p!=NULL){
			head[p->loca].deg++;
			p=p->next;
		}	
	}
	}
	printf("\n");
	for(i=1;i<=nodeNum;i++){
		printf("%d ",head[i].deg);
	}
	printf("\n");
}
//5 5
//1 5 1
//1 3 1
//5 4 1
//3 4 1
//4 2 1
void sort(){
	int i,j;
	EdgeNode *p,*q;
	updateDeg();
	for(i=1;i<=nodeNum;i++){
		for(j=1;j<=nodeNum;j++){
			if(head[j].deg==0&&book[j]==0){
				book[j]=1;
				p=head[j].headEdge;
				q=p;
				while(p!=NULL){
					q=p->next;
					head[p->loca].deg--;
					free(p);
					p=q;
				}
				printf("%d ",head[j].name);
			}
		}
	}
	
}
int main(){
	int i;
	createGra();
	for(i=1;i<=nodeNum;i++){
		head[i].deg=0;
	}
	sort();
	return 0;
}

