/*
ID: jsealey1
LANG: C++
TASK: pprime
*/
#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
vector<bool> num;
void sieve(int n) {
  num[0]=0;
  num[1]=0;
  int m=(int)sqrt(n);
  for (int i=2; i<=m; i++) 
    if (num[i])
      for (int k=i*i; k<=n; k+=i) 
        num[k]=0;
}

int main(){
  ifstream in("pprime.in");
  ofstream out("pprime.out");
  num = vector<bool>(1E8,1);
  sieve(1E8);
  int palindrome=0, lo, hi;
  in >> lo >> hi;
  for(int i=0; i < 9;++i){
        palindrome = i;
        if(palindrome > hi) goto end;
        if(num[palindrome] && palindrome >=lo) out << palindrome << endl;

  }
  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    for (int d2 = 0; d2 <= 9; d2++) {
      for (int d3 = 0; d3 <= 9; d3++) {
        palindrome = 10*d1 + d1;
        if(palindrome > hi) goto end;
        if(num[palindrome] && palindrome >=lo) out << palindrome << endl;

      }
    }

  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    for (int d2 = 0; d2 <= 9; d2++) {
      for (int d3 = 0; d3 <= 9; d3++) {
        palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
        if(palindrome > hi) goto end;
        if(num[palindrome] && palindrome >=lo) out << palindrome << endl;

      }
    }
  }
  end: return 0; 
}