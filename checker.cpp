/*
ID: jsealey1
LANG: C++
TASK: checker
*/
#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int N;
struct xyz{
	int s[3][13];
	int total;
} node;
void recurse(int row, int state[], int col[]){
	for(int column=0; column < N;++column){
		if(col[column]) goto otog;

		// top left
		for(int r = row, c = column; r > -1 && c > -1;--r,--c)
			if(state[r]==c) goto otog;
		// top right
		for(int r = row, c = column; r > -1 && c < N;--r,++c)
			if(state[r]==c) goto otog;

		state[row] = column;
		col[column] = 1;
		recurse(row+1,state, col);
		state[row] = -1;
		col[column] = 0;

		otog: continue;
	}
	if(row==N){ 
		if(node.total < 3){
			for(int i=0; i < N;++i)
				node.s[node.total][i] = state[i];
			node.total++;
		}
		else node.total++;
	}
}
int main(){
  ifstream in("checker.in");
  ofstream out("checker.out");
  in >> N;
  int ar[13] = {-1}, ar2[13] = {0};
  recurse(0,ar,ar2);
  for(int i=0; i < 3; ++i){
  	for(int j=0; j < N; ++j){
  		out << node.s[i][j] + 1 << (j==N-1 ? "" : " ") ;
  	}
  	out << endl;
  }
  out << node.total << endl;
  return 0; 
}