#include<iostream>
using namespace std;
bool isSafe(int **maze, int x, int y, int size){
	if(x<size && y<size && maze[x][y]==1){
		return true;
	}
	return false;
}
bool ratInMaze(int** maze, int x, int y, int size, int** sol){
	if(x==size-1 && y==size-1){
		sol[x][y]=1;
		return true;
	}
	if(isSafe(maze,x,y,size)){
		sol[x][y]=1;
		if(ratInMaze(maze,x+1, y,size, sol)){
			return true;
		}
		if(ratInMaze(maze,x,y+1,size,sol)){
			return true;
		}
		sol[x][y]=0;
		return false;
	}
	return false;
}

int main(){
	int size;
	cout<<"Size:";
	cin>>size;
	int **maze=new int*[size];
	int **sol=new int*[size];
	for(int i=0;i<size;i++){
		maze[i]= new int[size];
		sol[i]= new int [size];
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"Enter value for ["<< i+1 <<"]["<<j+1<<"]: " ;
			cin>>maze[i][j];
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			sol[i][j]=0;
		}
	}
	cout<<"Orignal maze: \n";
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<maze[i][j]<<" ";
		}
		cout<<"\n";
	}
	if(ratInMaze(maze,0,0,size,sol)){
		cout<<"Solution: \n";
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else{
		cout<<"No Solution Exists";
	}
}