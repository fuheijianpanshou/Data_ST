#include<stdio.h>
int test1(int *p){
	for(int i=0;i<5;i++){
		printf("%d",*p);//���������ﻹ�����ã�*(p+i)����������е�ֵ
	}	
}

void getint(int a[5]){
//	a[0]=2;
	a[1]=9;
	a[2]=9;
	a[3]=9;
	a[4]=9;

}
 
int main(){
	
	int b[9];
	printf("%d\n",b[0]); 
	
	int* p;
	int a[5];
	getint(a);
	for(int i=0;i<5;i++){
		printf("%d",a[i]);//���������ﻹ�����ã�*(p+i)����������е�ֵ
	}
	test1(p);
	
}
