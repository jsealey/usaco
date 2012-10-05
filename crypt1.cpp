/*
ID: jsealey1
LANG: C++
TASK: crypt1
*/
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstdlib>
#include<cstdio>

using namespace std;
int main()
{
  ifstream in("crypt1.in");
  ofstream out("crypt1.out");
  stringstream ss("");
  char c;
  int N=0,temp=0,solutions=0,ai[10] = {0};
  vector<char> vc;
  in >> N;
  temp = N;
  while(temp--){
    in >> c;
    vc.push_back(c);
    ai[c-'0'] = 1;
  }
  //for(int i=0; i < vc.size(); ++i) cout << "vc[" << i << "]: " << vc[i] << endl;
  string s1="",s2="",s3="";
  int n1=0, n2=0, n3=0, partial1=0, partial2=0, result=0, total=0;
  for(int i=0,len=vc.size(); i < len;++i)
    for(int j=0; j < len;++j)
      for(int k=0; k < len;++k)
        for(int l=0;l < len;++l){
          n1 = 100*(vc[i]-'0') + 10*(vc[j]-'0') + (vc[k]-'0');
          n2 = vc[l]-'0';
          partial1 = n1 * n2;
          ss.str("");
          ss << partial1;
          s1 = ss.str();
          if(!(ai[s1[0]-'0']&&ai[s1[1]-'0']&&ai[s1[2]-'0'])) continue;
          //if(s1.length()==4 && !ai[s1[3]-'0']) continue;
          if(s1.length()==4) continue;
          for(int m=0;m < len;++m){
            n3 = vc[m]-'0';
            partial2 = n1*n3;
            ss.str("");
            ss << partial2;
            s2 = ss.str();
            if(!(ai[s2[0]-'0']&&ai[s2[1]-'0']&&ai[s2[2]-'0'])) continue;
            if(s2.length()==4 && !ai[s2[3]-'0']) continue;
            result = partial1 + (partial2*10);
            ss.str("");
            ss << result;
            s3 = ss.str();
            if(!(ai[s3[0]-'0']&&ai[s3[1]-'0']&&ai[s3[2]-'0']&&ai[s3[3]-'0'])) continue;
            if(s3.length()==5) continue;
            //if(s3.length()==5 && !ai[s3[4]-'0']) continue;
            total++;
          }
      }
  out << total << endl;
}
