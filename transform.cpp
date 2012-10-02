/*
ID: jsealey1
LANG: C++
TASK: transform
*/
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int N;
int* reflect(int *arr){
  int *newArr = new int[N*N];
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j){
      newArr[i*N+j] = arr[i*N + N-j-1];
    }
    return newArr;
}
int* rotatecw(int *arr){
  int *newArr = new int[N*N];
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j){
      newArr[j*N + N-i-1] = arr[i*N+j];
    }
    return newArr;
}
bool isSame(int *a1, int *a2){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      if(a1[i*N + j] != a2[i*N + j])
        return false;
  return true;
}
/*
void print(int *a){
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j)
      cout << (char)a[i*N + j];
    cout << endl;
  }
}
*/
int main()
{
  ifstream in("transform.in");
  ofstream out("transform.out");
  
  in >> N;
  int *a1 = new int[N*N], *a2 = new int[N*N];

  in.get();
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j)
      a1[i*N + j] = in.get();
    in.get();
  }
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j)
      a2[i*N + j] = in.get();
    in.get();
  }

  //print(a1);
  //print(a2);
  // 90
  // 180 = 2x90
  // 270 = 3x90
  // Reflection = 180 = 2x90
  // Combination = 270 = 3x90
  // No Change = 0x90
  // Invalid Transformation = new pattern not obtained
  int result = 7;
  int isReflected = false;
  if(isSame(a1,a2)) result = 6;
 
    for(int i=0; i < 2;++i){
      if(i==1){
        isReflected = true;

        a1 = reflect(a1);
        /*
        cout << "BEFORE REFLECT: " << endl << endl;
          print(a1);
          print(a2);

        
          cout << "REFLECT: " << endl << endl;
          print(a1);
          print(a2);
          */
        if(isSame(a1,a2)){
          result = min(result, 4);
          break;
        }
      }
      for(int j=0; j < 4;++j){
        a1 = rotatecw(a1);
        /*
        if(j==0){
          cout << endl << endl;
          print(a1);
          print(a2);
        }
        */
        if(isSame(a1,a2)){
          if(isReflected){
            result = min(result, 5);
            break;
          } else {
            switch(j){
             case 0: result = min(result, 1); break;
             case 1: result = min(result, 2); break;
             case 2: result = min(result, 3); break;
            }
            break;
          }
        }
      }
    }
  out << result << endl;
  delete [] a1;
  delete [] a2;
}
