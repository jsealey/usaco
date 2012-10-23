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
#define EPS 1e-7
typedef long long LL;

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
bool IsPrimeSlow (LL x)
{
  if(x<=1) return false;
  if(x<=3) return true;
  if (!(x%2) || !(x%3)) return false;
  LL s=(LL)(sqrt((double)(x))+EPS);
  for(LL i=5;i<=s;i+=6)
  {
    if (!(x%i) || !(x%(i+2))) return false;
  }
  return true;
}

int main(){
  ifstream in("pprime.in");
  ofstream out("pprime.out");
  num = vector<bool>(1E7,1);
  sieve(1E7);
  int palindrome=0, lo, hi;
  in >> lo >> hi;

  // 1 digit
  for(int i=0; i < 9;++i){
        palindrome = i;
        if(palindrome > hi) goto end;
        if(num[palindrome] && palindrome >=lo) out << palindrome << endl;

  }

  // 2 digits
  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    palindrome = 10*d1 + d1;
    if(palindrome > hi) goto end;
    if(num[palindrome] && palindrome >=lo) out << palindrome << endl;
  }

  // 3 digits
  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    for (int d2 = 0; d2 <= 9; d2++) {        
      palindrome = 100*d1 + 10*d2 + d1;
      if(palindrome > hi) goto end;
      if(num[palindrome] && palindrome >=lo) out << palindrome << endl;
    }
  }

  // 4 digits
  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    for (int d2 = 0; d2 <= 9; d2++) {
      palindrome = 1000*d1 + 100*d2 + 10*d2 + d1;
      if(palindrome > hi) goto end;
      if(num[palindrome] && palindrome >=lo) out << palindrome << endl;
    }
  }

  // 5 digits
  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    for (int d2 = 0; d2 <= 9; d2++) {
      for (int d3 = 0; d3 <= 9; d3++) {
        palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
        if(palindrome > hi)goto end;
        if(num[palindrome] && palindrome >=lo) out << palindrome << endl;
      }
    }
  }
  // 6 digits
  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    for (int d2 = 0; d2 <= 9; d2++) {
      for (int d3 = 0; d3 <= 9; d3++) {
        palindrome = 100000*d1 + 10000*d2 + 1000*d3 +100*d3 + 10*d2 + d1;
        if(palindrome > hi) goto end;
        if(num[palindrome] && palindrome >=lo) out << palindrome << endl;
      }
    }
  }

  // 7 digits
  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    for (int d2 = 0; d2 <= 9; d2++) {
      for (int d3 = 0; d3 <= 9; d3++){
        for (int d4=0; d4 <= 9; d4++) {
          palindrome = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 +100*d3 + 10*d2 + d1;
          if(palindrome > hi) goto end;
          if(num[palindrome] && palindrome >=lo) out << palindrome << endl;
        }
      }
    }
  }

    // 8 digits
  for (int d1 = 1; d1 <= 9; d1+=2) {  /* only odd; evens aren't so prime */
    for (int d2 = 0; d2 <= 9; d2++) {
      for (int d3 = 0; d3 <= 9; d3++){
        for(int d4=0; d4 <= 9; d4++){
          palindrome = 1E7*d1 + 1E6*d2 + 1E5*d3 + 1E4*d4 + 1E3*d4 + 1E2*d3 + 10*d2 + d1;
          if(palindrome > hi) goto end;
          if(IsPrimeSlow(palindrome) && palindrome >=lo) out << palindrome << endl;
        }
      }
    }
  }

  end: return 0;
}