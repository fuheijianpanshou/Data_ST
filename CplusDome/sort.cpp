#include<stdio.h>
void bubbleSort(int container[],int len){
	int i,j,temp;
	bool flag=false;
	for(i=0;i<len-1;i++){
		flag=false;
		for(j=0;j<len-i-1;j++){
			if(container[j]>container[j+1]){
				flag=true;
				temp=container[j];
				container[j]=container[j+1];
				container[j+1]=temp;
			}
		}
		if(flag=false){
			break;
		}
	}
	printf("bubblesort:");
	for(i=0;i<len;i++){
		printf("%d ",container[i]);
	}
	printf("\n");
}
void selectSort(int container[],int len){
	int i,j,temp,index;
	for(i=0;i<len-1;i++){
		index=i;
		for(j=i+1;j<len;j++){
			if(container[j]<container[index]){
				index=j;
			}
		}
		if(i!=index){
			temp=container[i];
			container[i]=container[index];
			container[index]=temp;
		}
	}
	printf("selectsort:");
	for(i=0;i<len;i++){
		printf("%d ",container[i]);
	}
	printf("\n");
}
void quick(int *container,int left,int right){
	if(left>right){
		return;
	}
	int t;
	int temp=container[left];
	int i=left;
	int j=right;
	while(i!=j){
		while(container[j]>=temp&&i<j){
			j--;
		}
		while(container[i]<=temp&&i<j){
			i++;
		}
		if(i<j){
			t=container[j];
			container[j]=container[i];
			container[i]=t;
		}
	}
	container[left]=container[i];
	container[i]=temp;
	quick(container,left,i-1);
	quick(container,i+1,right);
	
}
void quickSort(int container[],int len){
	int i;
	quick(container,0,len-1);
	printf("quicksort:");
	for(i=0;i<len;i++){
		printf("%d ",container[i]);
	}
	printf("\n");
}
void shellSort(int container[],int len){
	int step;
	int i,j;
	int temp;
	for(step=len/2;step>=1;step=step/2){
		for(i=step;i<len;i++){
			temp=container[i];
			j=i;
			while(j-step>=0&&container[j-step]>temp){
				container[j]=container[j-step];
				j=j-step;
			}
			container[j]=temp;
		}
	}
	printf("shellsort:");
	for(i=0;i<len;i++){
		printf("%d ",container[i]);
	}
	printf("\n");
}
void swap(int *container,int i,int j){
	int temp;
	temp=container[i];
	container[i]=container[j];
	container[j]=temp;
}
void sitDown(int *container,int start,int end){
	int i,j;
	i=start;
	j=start*2+1;
	int temp=container[start];
	while(j<=end){
		while(j<end&&container[j]<container[j+1]){
			j++;
		}
		if(temp>=container[j]){
			break;
		}else{
			container[i]=container[j];
			i=j;j=j*2+1;
		}
	}
	container[i]=temp;
	
}
void heapSort(int container[],int len){
	int i,j;
	for(i=(len-2)/2;i>=0;i--){
		sitDown(container,i,len-1);
	}
	for(j=len-1;j>=0;j--){
		swap(container,0,j);
		sitDown(container,0,j-1);
	}
	printf("heapsort:");
	for(i=0;i<len;i++){
		printf("%d ",container[i]);
	}
	printf("\n");
}
void merge(int *container,int *virContainer,int left,int mid,int right){
	int l1=left;
	int l2=mid+1;
	int l3=left;
	int i;
	for(i=left;i<=right;i++){
		virContainer[i]=container[i];
	}
	while(l1<=mid&&l2<=right){
		if(virContainer[l1]<virContainer[l2]){
			container[l3]=virContainer[l1];
			l1++;
		}else{
			container[l3]=virContainer[l2];
			l2++;
		}
		l3++;
	}
	while(l1<=mid){
		container[l3]=virContainer[l1];
		l1++;
		l3++;
	}
	while(l2<=right){
		container[l3]=virContainer[l2];
		l2++;
		l3++;
	}
}
void realMergeSort(int *container,int *virContainer,int left,int right){
	
	int mid;
	if(left>=right){
		return;
	}
	mid=(right+left)/2;
	realMergeSort(container,virContainer,left,mid);
	realMergeSort(container,virContainer,mid+1,right);
	merge(container,virContainer,left,mid,right);
	
}
void mergeSort(int container[],int len){
	int i;
	int virContainer[20];
	realMergeSort(container,virContainer,0,len-1);
	printf("mergesort:");
	for(i=0;i<len;i++){
		printf("%d ",container[i]);
	}
	printf("\n");
	
}
//10
//5 1 15 3 85 42 65 94 52 43
int main(){
	int len=0;
	int i;
	int container[30];
	scanf("%d",&len);
	for(i=0;i<len;i++){
		scanf("%d",&container[i]);
	}
	bubbleSort(container,len);
	selectSort(container,len);
	quickSort(container,len);
	shellSort(container,len);
	heapSort(container,len);
	mergeSort(container,len);
	return 0;
}

