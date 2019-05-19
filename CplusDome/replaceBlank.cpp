#include<iostream>
using namespace std;
void ReplaceBlank(char string[],int len){
	int blankNu=0;
	for(int i=0;i<len;i++){
		if(string[i]==' '){
			blankNu++;
		}
	}
	int Alllen=len+blankNu*2;
	int ptr1=len-1;
	int ptr2=Alllen-1;
	while(ptr1>0&&ptr2!=ptr1){
		if(string[ptr1]==' '){
			string[ptr2--]='%';
			string[ptr2--]='0';
			string[ptr2--]='2';
		}else{
			string[ptr2--]=string[ptr1];
		}
		ptr1--;
	}
	cout<<string<<endl;
	
}

int main(){
	char string[30];
	//cin>>string;
	int len=1;
	gets(string);
	cout<<string<<endl;
	for(int i=0;string[i]!='\0';i++){
		len++;
	}
	ReplaceBlank(string,len);
	//cout<<len<<endl;
	
}
