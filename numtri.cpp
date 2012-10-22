/*
ID: jsealey1
LANG: C++
TASK: numtri
*/
#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
  ifstream in("numtri.in");
  ofstream out("numtri.out");
 
  int rows, maxx=-1, temp;
  in >> rows;
  int *old = new int[rows];
  int *vals= new int[rows];
  for(int i=0; i < rows;++i){
  	for(int j=0; j <= i;++j){
  		in >> vals[j];
  		if(j==0 && j==i){
  			// do nothing
  		} else {
	  		if(j==0){
	  			vals[j] += old[j];
	  		} else if(j==i){
	  			vals[j] += old[j-1];
	  		} else {
	  			vals[j] = max(old[j]+vals[j],old[j-1]+vals[j]);
	  		}
	  	}
  	}
  	for(int j=0; j <= i;++j) {
  		old[j] = vals[j];
  		cout << old[j] << " ";
  	}
  	cout << endl;
  }

  for(int i=0; i < rows;++i) maxx = max(old[i],maxx);

  out << maxx << endl;

  return 0; 
}