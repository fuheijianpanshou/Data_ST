#include<iostream>
using namespace std;
//find the first repeated number 
void findAgain(int numbers[],int length){
	if(length<=0){
		return;
	}
	for(int i=0;i<length;++i){
		while(numbers[i]!=i){
			if(numbers[i]!=i){
			if(numbers[i]==numbers[numbers[i]]){
				cout<<numbers[i]<<endl;
				return;
				//numbers[i]=i;
			}else{
				int temp=numbers[i];
				numbers[i]=numbers[temp];
				numbers[temp]=temp;
				//cout<<"oo"<<endl;
			}
		}
		}
		
	}
}
int main(){
	int length=0;
	int numbers[100];
	cin>>length;
	for(int i=0;i<length;i++){
		int temp=0;
		cin>>temp;
		if(temp<0||temp>=length){
			i--;
			cout<<"input error,please input again!";
		}else{
			numbers[i]=temp;
		}
	}
	findAgain(numbers,length);
	return 0;
}
