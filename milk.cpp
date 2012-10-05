/*
ID: jsealey1
LANG: C++
TASK: milk
*/
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int main()
{
  ifstream in("milk.in");
  ofstream out("milk.out");
  
  int N, M, P, A, price=0;
  int sellers[1001] = {0};

  in >> N >> M;
  for(int i=0; i < M;++i){
    in >> P >> A;
    sellers[P] += A;
  }

  for(int i=0; i < 1001 && N;++i){
    if(sellers[i] >= N){
      price += N*i;
      break;
    } else {
      price += sellers[i]*i;
      N -= sellers[i];
    }
  }
  out << price << endl;
}
