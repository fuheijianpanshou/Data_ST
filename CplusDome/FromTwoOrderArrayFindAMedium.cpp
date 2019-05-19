#include<stdio.h>
void FindMedium(int *one,int *two,int oneLeft,int oneRight,int twoLeft,int twoRight){
	//printf("%d ",oneLeft);
	//printf("%d %d",one[oneLeft],two[twoLeft]);
	if(oneRight-oneLeft==0&&twoRight-twoLeft==0){
		if(one[oneRight]>two[twoRight]){
			printf("%d",two[twoRight]);
		}else{
			printf("%d",one[oneRight]);
		}
		return;
	}
	int mid1=(oneRight+oneLeft)/2;
	int mid2=(twoRight+twoLeft)/2;
	if(one[mid1]==two[mid2]){
		printf("%d",one[mid1]);
		return;
	}
	printf("%d %d\n",mid1,mid2);
	if(one[mid1]<two[mid2]){
		if((oneRight-oneLeft+1)%2==0){
			mid1++;
		}
		FindMedium(one,two,mid1,oneRight,twoLeft,mid2);
	}else{
		if((twoRight-twoLeft+1)%2==0){
			mid2++;
		}
		FindMedium(one,two,oneLeft,mid1,mid2,twoRight);
	}
}
//5
//1 4 9 11 15
//3 6 8 10 16
int main(){
	printf("找到两个有序数组合并后的中位数\n");
	int n;
	int i=0;
	int one[30],two[30];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&one[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&two[i]);
	}
	FindMedium(one,two,0,n-1,0,n-1);
	
	return 0;
}
