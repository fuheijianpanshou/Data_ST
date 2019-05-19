#include<stdio.h>
int check(char *p,char s,int plen){
	int i;
	for(i=plen-1;i>=0;i--){
		if(s==p[i]){
			break;
		}
	}
	if(i==-1){
		return -1;
	}else{
		return i;
	}
}
int sunday(char *p,char *s,int plen,int slen){
	int i,j=0,k=0;
	int flag;
	while(j<slen&&k<plen){
		if(p[k]==s[j]){
			j++;
			k++;
		}else{
			if(j+plen-k+1<slen){
				flag=check(p,s[j+plen-k],plen);
				if(flag==-1){
					j=j+plen-k+1;
					printf("b%db ",j);
					k=0;
				}else{
					j=j+plen-flag;
					printf("a%da ",j);
					k=0;
				}	
			}else{
				return -1;
			}
			
		}
	}
	if(k==plen){
		return j-k;
	}else{
		return -1;
	}
}
int main(){
	int i;
	int plen=0,slen=0;
	char p[20];
	char s[50];
	int index;
	gets(p);
	gets(s);
	for(i=0;p[i]!='\0';i++){
		plen++;
	}
	for(i=0;s[i]!='\0';i++){
		slen++;
	}
	index=sunday(p,s,plen,slen);
	printf("%d ",index);
	return 0;
}

