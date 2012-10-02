/*
ID: jsealey1
LANG: C++
TASK: namenum
*/
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
string c[10] = {"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
bool match(string &index, string &s){
  if(index.length() != s.length()) return false;
  for(int i=0,sz=s.length(); i < sz;++i){
    if(c[ index[i]-'0' ][0]!=s[i] && c[ index[i]-'0' ][1]!=s[i] && c[ index[i]-'0' ][2]!=s[i])
      return false;
  }
  return true;
}
int main()
{
  ifstream in("namenum.in");
  ofstream out("namenum.out");

  string input;
  in >> input;

  vector<string> names;
  string s;
  ifstream dict("dict.txt");
  while(getline(dict,s))
    if(match(input, s))
      names.push_back(s);

  if(names.size() > 0)
    for(int i=0; i < names.size();++i)
      out << names[i] << endl;
  else out << "NONE" << endl;

  return 0;  
}
