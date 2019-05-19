#include<iostream>
using namespace std;
//find a number from a formal matrix
bool matrixFun(int matrix[10][10],int rows,int columns,int number){
	bool found=false;
	if(rows<=0||columns<=0){
		return false;
	}
	int row=0;
	int column=columns-1;
	while(row<rows||column>=0){
		if(matrix[row][column]==number){
			return true;
		}else if(matrix[row][column]>number){
			column--;
		}else if(matrix[row][column]<number){
			row++;
		}
	}
	return false;
}
int main(){
	int rows,columns;
	int number;
	int matrix[10][10];
	cin>>rows>>columns;
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cin>>matrix[i][j];
		}
	}
	cin>>number;
	if(matrixFun(matrix,rows,columns,number)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	return 0;
}
