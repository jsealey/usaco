/*
ID: jsealey1
LANG: C++
TASK: milk2
*/
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  ifstream in("milk2.in");
  ofstream out("milk2.out");
  bool vals[1000000] = {0};
  int n=0, lo=0, hi=0;
  int lo_bound=1000000, hi_bound=0;
  int longest_at_least_one_cow = 0,
      longest_no_cow = 0;
  in >> n;
  while(n--){
    in >> lo >> hi;
    lo_bound = min(lo_bound, lo);
    hi_bound = max(hi_bound, hi);

    for(int i=lo; i < hi;i++)
      vals[i] = true;
  }
  int cur_one_cow = 0, cur_no_cow = 0;

  for(int i=lo_bound; i < hi_bound;i++){
    if(vals[i]){
      cur_one_cow++;
      longest_no_cow = max(cur_no_cow,longest_no_cow);
      cur_no_cow = 0;
    } else {
      cur_no_cow++;
      longest_at_least_one_cow = max(cur_one_cow,longest_at_least_one_cow);
      cur_one_cow = 0;
    }
  }
  longest_no_cow = max(cur_no_cow,longest_no_cow);    
  longest_at_least_one_cow = max(cur_one_cow,longest_at_least_one_cow);
      
  out << longest_at_least_one_cow << " " << longest_no_cow << endl;
}
