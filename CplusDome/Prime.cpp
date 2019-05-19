#include<stdio.h>
int inf=10000;
int book[20];
int edge[20][20];
int nodeNum=0;
int edgeNum=0;
int dis[20];
void input(){
	int i,j;
	int x,y,w;
	scanf("%d%d",&nodeNum,&edgeNum);
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			edge[i][j]=inf;
			if(i==j){
				edge[i][j]=0;
			}
		}
		book[i]=0;
	}
	for(i=0;i<edgeNum;i++){
		scanf("%d%d%d",&x,&y,&w);
		edge[x][y]=w;
		edge[y][x]=w;
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
void Prime(){
	int i,j;
	int count=0;
	int sum=0;
	int min=inf;
	int index;
	for(i=1;i<=nodeNum;i++){
		dis[i]=edge[1][i];
	}
	book[1]=1;
	count++;
	while(count<nodeNum){
		min=inf;
		for(i=1;i<=nodeNum;i++){
			if(dis[i]<min&&book[i]==0){
				index=i;
				min=dis[i];	
			}
		}
		printf("%d ",index);
		sum+=dis[index];
		count++;
		book[index]=1;
		for(j=1;j<=nodeNum;j++){
			if(edge[index][j]<dis[j]&&book[j]==0){
				dis[j]=edge[index][j];
			}
		}
	}
	printf("\n");
	printf("%d",sum);
}
int main(){
	input();
	Prime();
	return 0;
}
