/*
ID: jsealey1
LANG: C++
TASK: palsquare
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
  ifstream in("palsquare.in");
  ofstream out("palsquare.out");
  int B;
  in >> B;
  stringstream ss;
  for(int i=1; i <= 300; ++i){
    ss.str("");
    ss << toBase((int)pow((double)i,2), B);
    if(isPalendrome(ss.str()))
      out << toBase(i,B) << " " << ss.str() << endl;
  }
  return 0;  
}
