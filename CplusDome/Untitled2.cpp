#include<stdio.h>
int test1(int *p){
	for(int i=0;i<5;i++){
		printf("%d",*p);//我们在这里还可以用）*(p+i)来输出数组中的值
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
		printf("%d",a[i]);//我们在这里还可以用）*(p+i)来输出数组中的值
	}
	test1(p);
	
}
