#include<stdio.h>
#include<stdlib.h>
#define maxSize 20
typedef struct {
	int top[2],bot[2];
	int elem[maxSize];
}DbStack;
void initStack(DbStack &dbS){
	dbS.bot[0]=dbS.top[0]=-1;
	dbS.bot[1]=dbS.top[1]=maxSize-1;
}

int stackEmpty(DbStack &dbS,int i){
	return dbS.top[i]==dbS.bot[i];
}

int stackFull(DbStack &dbS){
	return dbS.top[0]+1==dbS.top[1];
}

int Push(DbStack &dbS,int value,int ind){
	if(stackFull(dbS)){
		return 0;
	}else{
		if(ind==0){
			dbS.elem[++dbS.top[ind]]=value;
		}else if(ind==1){
			dbS.elem[--dbS.top[ind]]=value;
		}
		return 1;
	}
}

int Pop(DbStack &dbS,int ind){
	if(!stackEmpty(dbS,ind)){
		if(ind==0){
			return dbS.elem[dbS.top[ind]--];
		}else{
			return dbS.elem[dbS.top[ind]++];
		}
		
	}else{
		return NULL;
	}
}

int getTop(DbStack &dbS,int i){
	return dbS.elem[dbS.top[i]];
}
int main(){
	return 0;
}
