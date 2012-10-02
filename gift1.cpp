/*
ID: jsealey1
LANG: C++
TASK: gift1
*/
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main(){
  ifstream in("gift1.in");
  ofstream out("gift1.out");
  map<string, int> given;
  vector<string> friends;
  string s,c;
  int NP=0,total=0,people=0;
  in >> NP;
  int T = NP;
  while(T--){
    in >> s;
    if(!given[s])
      friends.push_back(s);
  }
  T = NP;
  while(T--){
    in >> s >> total >> people;
    if(people!=0){
      given[s] -= total - (total%people);
      for(int i=0,j=(int)(total/people); i < people;++i){
        in >> c;
        given[c] += j;
      }
    }
  }
  for(int i=0;i < friends.size();++i){
    out << friends[i] << " " << given[ friends[i] ] << endl;
  }
  return 0;
}
