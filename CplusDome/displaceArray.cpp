#include<stdio.h>
void Reverse(int *num,int left,int right){
	int p=left;
	int q=right;
	int temp;
	while(p<q){
		temp=num[p];
		num[p]=num[q];
		num[q]=temp;
		p++;
		q--;
	}
} 
//7
//3
//1 2 3 4 5 6 7
int main(){
	printf("线性表循环移位时间复杂度n 空间复杂度1\n");
	int n,i;
	int num[20];
	int displaceNum;
	scanf("%d",&n);
	scanf("%d",&displaceNum);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	Reverse(num,0,n-1);
	Reverse(num,0,displaceNum-1);
	Reverse(num,displaceNum,n-1);
	for(i=0;i<n;i++){
		printf("%d ",num[i]);
	}
	return 0;
	
	
}
