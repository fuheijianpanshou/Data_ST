#include<stdio.h>
int edges[20][20];
int edgeNum=0;
int nodeNum=0;
int book[20]={0};
int dis[20];
int inf=1000;
void input(){
	int i,j;
	int x,y,w;
	scanf("%d%d",&nodeNum,&edgeNum);
	for(i=1;i<=nodeNum;i++){
		for(j=1;j<nodeNum;j++){
			edges[i][j]=inf;
			if(i==j){
				edges[i][j]=0;
			}
		}
	}
	for(i=1;i<=edgeNum;i++){
		scanf("%d%d%d",&x,&y,&w);
		edges[x][y]=w;
		edges[y][x]=w;
	}
}
void Dijistra(){
	int i,j;
	int count=0;
	int min;
	int index;
	int pre[20];
	for(i=1;i<=nodeNum;i++){
		pre[i]=0;
	}
	for(i=1;i<=nodeNum;i++){
		dis[i]=edges[1][i];
	}
	book[1]=1;
	count++;
	while(count<nodeNum){
		min=inf;
		for(i=1;i<=nodeNum;i++){
			if(dis[i]<min&&book[i]==0){
				min=dis[i];
				index=i;
			}
		}
		count++;
		book[index]=1;
		for(i=1;i<=nodeNum;i++){
			if(dis[index]+edges[index][i]<dis[i]&&book[i]==0){
				dis[i]=dis[index]+edges[index][i];
				book[i]=1;
				pre[i]=index;
			}
		}
	}
	printf("\n");
	for(i=1;i<=nodeNum;i++){
		printf("%d ",dis[i]);
	}
	for(i=1;i<=nodeNum;i++){
		printf("%d ",pre[i]);
	}
}
int main(){
	input();
	Dijistra();
}
