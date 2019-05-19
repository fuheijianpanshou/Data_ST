#include<stdio.h>
int next[50];
void getNext(char *p,int plen){
	int j=0;
	int k=-1;
	int i;
	next[0]=-1;
	while(j<plen-1){
		if(k==-1||p[j]==p[k]){
			j++;
			k++;
			if(p[j]==p[k]){
				next[j]=next[k];
			}else{
				next[j]=k;
			}
		}else{
			k=next[k];
		}
	}
	for(i=0;i<plen;i++){
		printf("%d ",next[i]);
	}
	printf("\n");
	
}

int kmp(char *s,int slen,char *p,int plen){
	int i,j=0,k=0;
	while(j<slen&&k<plen){
		if(k==-1||s[j]==p[k]){
			k++;
			j++;
		}else{
			k=next[k];
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
	getNext(p,plen);
	index=kmp(s,slen,p,plen);
	printf("%d ",index);
	return 0;
	
}
