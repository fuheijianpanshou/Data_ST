#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int *data;
	int n;
	int maxSize=30;
	int initSize=30;
}SeqList;

//������Ա� 
void show(SeqList L){
	int i;
	if(L.n<=0){
		return;
	}
	for(i=0;i<L.n;i++){
		printf("%d ",L.data[i]);
	}
	
	printf("\n");
}

//��̬�������Ա� 
void reallocate(SeqList& L){
	int newSize;
	int i;
	int * newA;
	if(L.n>0.8*L.maxSize){
		newSize=2*L.maxSize;
		printf("���·���ռ�%d\n",newSize);
	}else if(L.n<0.2*L.maxSize){
		newSize=0.5*L.maxSize;
		printf("���·���ռ�%d\n",newSize);
	}
	newA=(int*)malloc(newSize*sizeof(int));
	for(i=0;i<L.n;i++){
		newA[i]=L.data[i];
	}
	L.maxSize=newSize;
	L.data=newA;	

	
}
//�������Ա� 
void createList(SeqList& L,int data[],int n){
	printf("��ʼ�����Ա�\n");
	int i;
	L.data=(int*)malloc(L.initSize*sizeof(int));
	for(i=0;i<n;i++){
		L.data[i]=data[i];
	}
	L.n=n;
	//reallocate(L);
	
}
//ͨ������ɾ�� 
void deleteByIndex(SeqList& L,int index,int& value){
	int i;
	if(index>=L.n||index<=-1){
		printf("����������\n");
		return;
	}
	
	value=L.data[index];
	for(i=index;i<L.n-1;i++){
		L.data[i]=L.data[i+1];
	}
	L.n--;	
}
//ͨ����������
void insertByIndex(SeqList& L,int index,int value){
	int i;
	if(L.n==L.maxSize){
		reallocate(L);
	}
	if(index>L.n||index<=-1){
		printf("����������\n");
		return;
	}
	for(i=L.n-1;i>=index;i--){
		L.data[i+1]=L.data[i];
	}
	L.data[index]=value;
	L.n++;	
}
//ɾ������Ԫ��ֵ��ͬ��Ԫ�أ�ÿ��Ԫ��ֻ����һ��ֵ 
void deleteSame(SeqList& L){
	int k,i;
	int j;
	if(L.n==0){
		return;
	}
	k=0;
	for(i=1;i<L.n;i++){
		for(j=0;j<=k;++j){
			if(L.data[i]==L.data[j]){
				break;
			}
		}
		if(j>k){
			k++;
			L.data[k]=L.data[i];
		}
	}
	L.n=k+1;
}
//ɾ�������ֵ��ͬ������Ԫ��
void deleteAllSame(SeqList &L,int value){
	int i,p,q;
	if(L.n<=1){
		return;
	}
	p=0;
	q=0;
	for(i=0;i<L.n;i++){
		L.data[p]=L.data[q];
		if(L.data[q]!=value){
			p++;
			q++;
		}else{
			q++;
		}
	}
	L.n=p;
} 
//�����������ͬ��Ԫ��ֻ����һ��
void afterDeleteOnlyOne(SeqList &L){
	int i,j;
	j=0;
	for(i=1;i<L.n;i++){
		if(L.data[i]!=L.data[j]){
			j++;
			L.data[j]=L.data[i];
		}
	}
	L.n=j+1;
}
//��������������Ա����ҵ���ͬ�Ĳ����������һ����
void intersect(SeqList &L1,SeqList &L2){
	int i=0,j=0,k=-1;
	while(i<L1.n&&j<L2.n){
		if(L1.data[i]>L2.data[j]){
			j++;
		}else if(L1.data[i]<L2.data[j]){
			i++;
		}else{
			if(k==-1){
				k++;
				L1.data[k]=L1.data[i];
				
			}else{
				if(L1.data[i]!=L1.data[k]){
					k++;
					L1.data[k]=L1.data[i];
				}
			}
			i++;
			j++;
		}
		
	}
	L1.n=k+1;
}
//�����Ա�A��ɾ�������Ա�B�����Ա�C�й��е�Ԫ��
void deleteOtherLinearSame(SeqList &L1,SeqList &L2,SeqList &L3){
	int i=0,j=0,k=0,m=0;
	int same;
	while(i<L1.n&&j<L2.n){
		if(L1.data[i]<L2.data[j]){
			i++;
		}else if(L1.data[i]>L2.data[j]){
			j++;
		}else{
			same=L1.data[i];
			while(i<L1.n&&L1.data[i]==same){
				i++;
			}
			while(j<L2.n&&L2.data[j]==same){
				j++;
			}
			while(k<L3.n){
				if(L3.data[k]<same){
					L3.data[m]=L3.data[k];
					m++;
					k++;
				}else if(L3.data[k]==same){
					k++;
				}else{
					break;
				}
			}
			if(k==L3.n){
				L3.n=m;
				return;
			}
		}
	}
	while(k<L3.n){
		L3.data[m]=L3.data[k];
		m++;
		k++;
	}
	L3.n=m;
} 
//10 5 5
//1 5 15 26 38 12 25 36 46 56
//ǰ�������ֵ���������������� 
void increaseSort(SeqList &L,int m,int n){
	int i=0,j,k,t;
	j=m;
	int temp;
	while(j<L.n){
		if(L.data[j]>L.data[j-1]){
			return;
		}
		while(L.data[i]<L.data[j]){
			i++;
		}
		temp=L.data[j];
		for(t=j;t>i;t--){
			L.data[t]=L.data[t-1];
		}
		L.data[i]=temp;
		j++;
	}
}


int main(){
	SeqList sl;
	SeqList sl1;
	SeqList sl2;
	int n1,n2,n3;
	int i;
	int value;
	int data[20];
	int data1[20];
	int data2[20];
	scanf("%d",&n1);
	scanf("%d%d",&n2,&n3);
	if(n2+n3!=n1){
		return 0;
	}
	for(i=0;i<n1;i++){
		scanf("%d",&data[i]);
	}
//	scanf("%d",&n2);
//	for(i=0;i<n2;i++){
//		scanf("%d",&data1[i]);
//	}
//	scanf("%d",&n3);
//	for(i=0;i<n3;i++){
//		scanf("%d",&data2[i]);
//	} 
	
	createList(sl,data,n1);
//	createList(sl1,data1,n2);
//	createList(sl2,data2,n3);
	show(sl);
	//deleteByIndex(sl,2,value);
	//insertByIndex(sl,4,6);
	//deleteAllSame(sl,2);
	//afterDeleteOnlyOne(sl);
	//intersect(sl,sl1);
	//deleteOtherLinearSame(sl,sl1,sl2);
	increaseSort(sl,n2,n3);
	
	show(sl);
	printf("%d\n",sl.n);
	return 0;
} 
