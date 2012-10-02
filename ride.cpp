/*
ID: jsealey1
LANG: C++
TASK: ride
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
  ifstream in("ride.in");
  ofstream out("ride.out");
  string comet, group;
  int m_comet=1, m_group=1;
  in >> comet >> group;
  for(int i=0; i < comet.length();++i)
    m_comet *= comet[i]-'A'+1;
  for(int i=0; i < group.length();++i)
    m_group *= group[i]-'A'+1;

  if(m_group%47 == m_comet%47) out << "GO" << endl;
  else out << "STAY" << endl;
  return 0;
}
