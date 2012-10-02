#include<iostream>
using namespace std;
int main(){
  int c=1;

  for(int i=0; i < 100; ++i){
    cout << abs((c--)%29) << endl;
  }
  return 0;
}
