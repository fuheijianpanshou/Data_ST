#include<stdio.h>
int main(){
	printf("ʱ�临�Ӷ�nɾ��˳��洢ָ��Ԫ��\n");
	int num[20];
	int i=0;
	int n;
	int p,q,value;
	p=0;
	q=0;
	int deleteNum=0;;
	scanf("%d",&n);
	scanf("%d",&value);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<n;i++){
		num[p]=num[q];
		if(num[i]==value){
			q++;
			deleteNum++;
		}else{
			q++;
			p++;
		}
	}
	for(i=0;i<n-deleteNum;i++){
		printf("%d ",num[i]);
	}
}
//10
//5
//1 2 5 4 6 3 5 6 8 5
