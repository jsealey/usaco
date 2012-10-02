/*
ID: jsealey1
LANG: C++
TASK: dualpal
*/
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;
bool isPalendrome(string s){
  for(int i=0,max=s.length()/2,len=s.length()-1;i<max;++i)
    if(s[i]!=s[len-i]) return false;
  return true;
}
string toBase(int number, int base){
  string vals = "0123456789ABCDEFGHIJ";
  string result = "";
  while(number){
    result = vals[number%base] + result;
    number /= base;
  }
  return result;
}
int main()
{
  ifstream in("dualpal.in");
  ofstream out("dualpal.out");
  int N,S;
  in >> N >> S;

  for(int i=S+1; i < 100000 && N;++i){
    int total=0;
    for(int j=2; j <= 10; ++j)
      if(isPalendrome(toBase(i,j))){
        if(total){
          N--;
          out << i << endl;
          break;
        } else total++;
      }
  }
  return 0;  
}