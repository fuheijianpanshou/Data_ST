#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int start;
	int end;
	int weight;
}Edge;
Edge edges[20];
int book[20];
int nodeNum=0;
int edgeNum=0;
void sortEdge(){
	int i;
	int j;
	Edge edge;
	for(i=0;i<edgeNum-1;i++){
		for(j=0;j<edgeNum-i-1;j++){
			if(edges[j].weight>edges[j+1].weight){
				edge.start=edges[j].start;
				edge.end=edges[j].end;
				edge.weight=edges[j].weight;
				edges[j].start=edges[j+1].start;
				edges[j].end=edges[j+1].end;
				edges[j].weight=edges[j+1].weight;
				edges[j+1].start=edge.start;
				edges[j+1].end=edge.end;
				edges[j+1].weight=edge.weight;
			}
		}
	}
//for(i=0;i<edgeNum;i++){
//		printf("%d ",edges[i].weight);
//	} 
}
void inputEdge(){
	int i,j;
	scanf("%d %d",&nodeNum,&edgeNum);
	for(i=1;i<=nodeNum;i++){
		book[i]=i;
	}
	for(i=0;i<edgeNum;i++){
		scanf("%d %d %d",&edges[i].start,&edges[i].end,&edges[i].weight);
	}
	
	
}
void Krushal(){
	int i;
	int j;
	int num=0;
	for(i=0;i<edgeNum;i++){
		if(book[edges[i].start]!=book[edges[i].end]){
			printf("%d %d %d\n",edges[i].start,edges[i].end,edges[i].weight);
			num++;
			if(book[edges[i].start]<book[edges[i].end]){
				book[edges[i].end]=book[edges[i].start];
			}else if(book[edges[i].start]>book[edges[i].end]){
				book[edges[i].start]=book[edges[i].end];
			}
			if(num==nodeNum-1){
				break;
			}
		}
	}
}
//6 9
//2 4 11
//3 5 13
//4 6 3
//5 6 4
//2 3 6
//4 5 7
//1 2 1
//3 4 9
//1 3 2
int main(){
	inputEdge();
	sortEdge(); 
	Krushal();
	return 0;
}
