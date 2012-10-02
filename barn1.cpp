/*
ID: jsealey1
LANG: C++
TASK: barn1
*/
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
bool cmp(int a, int b){ return a > b; }
int main()
{
  ifstream in("barn1.in");
  ofstream out("barn1.out");
  int M, S, C, hi=0,lo=1000;
  vector<int> spaces;
  in >> M >> S >> C;
  int vals[2][201];
  for(int i=0; i < S;++i) vals[0][i] = vals[1][i] = 0;
  for(int i=0; i < C;++i){
    int temp;
    in >> temp;
    vals[0][temp] = 1;
    hi = max(hi,temp);
    lo = min(lo,temp);
  }

  for(int i=lo; i <= hi;++i) {
    vals[1][i] = 1;
    cout << vals[0][i];
  }
  cout << endl;

  int spaceCount = 0;
  for(int i=lo; i <= hi;++i){
    if(vals[0][i]==1) {
      if(spaceCount == 0) continue;
      spaces.push_back(spaceCount);
      spaceCount = 0;
      cout << "Skip at i=" << i << endl;
    } else {
      spaceCount++;
      cout << "spaceCount: " << spaceCount << " i: " << i << endl;
    }
  }

  stable_sort(spaces.begin(),spaces.end(), cmp);
  for(int i=0; i < spaces.size();++i) cout << "spaces[" << i << "]: " << spaces[i] << endl;

  cout << "blocked: " << hi-lo << endl;
  int blocked = hi-lo, numboard = 1;
  int spaceTotal = spaces.size();
  cout << "Size: " << spaces.size() << endl << "block: " << blocked << endl;
  for(;numboard < M;numboard++){
    blocked -= spaces[0];
    cout << "block: " << blocked << endl;
    spaces.erase(spaces.begin());
    if(spaceTotal==numboard) break;
  }
  out << blocked + 1 << endl;  
}
