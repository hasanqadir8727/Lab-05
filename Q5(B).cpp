#include<iostream>
using namespace std;
bool isSafe(int**maze, int x, int y, int rows, int columns){
	if(x<rows && y<columns && maze[1][1]==1){
		return true;
	}
	return false;
}
bool ratInMaze(int **maze, int x, int y, int rows, int columns, int**sol){
	if(x==(rows-1) && y==(columns-1)){
		sol[x][y]=1;
		return true;
	}
	if(isSafe(maze,x,y,rows,columns)){
		sol[x][y]=1;
		if(ratInMaze(maze,x+1,y,rows,columns,sol)){
			return true;
		}
		if(ratInMaze(maze,x,y+1,rows,columns,sol)){
			return true;
		}
		sol[x][y]=0;
		return false;
	}
	return false;
}
int main(){
	int rows=3;
	int columns=4;
	int mazeData[3][4]={{1,0,0,1},
				        {0,1,1,1},
				        {0,1,1,0}};
	int** maze=new int *[rows];
	int** sol=new int* [rows];
	for(int i=0;i<rows;i++){
		maze[i]=new int[columns];
		sol[i]=new int[columns];
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			maze[i][j]=mazeData[i][j];
			sol[i][j]=0;
		}
	}
	if(ratInMaze(maze,0,0,rows,columns,sol)){
		cout<<"Solution: \n";
		for(int i=0;i<rows;i++){
			for(int j=0;j<columns;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else{
		cout<<"Solution is not possible";
	}
}