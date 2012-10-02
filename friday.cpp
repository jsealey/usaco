/*
ID: jsealey1
LANG: C++
TASK: friday
*/
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>

using namespace std;
int main(){
  ifstream in("friday.in");
  ofstream out("friday.out");
  int day=1,N=0,year=1900;
  int days[7]={0}; // sunday, monday, tuesday, wednesday, thursday, friday, saturday
  int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  in >> N;

  for(int i=0;i < N;++i){ // for every year
    for(int j=0;j < 12;++j){ // for every month
      days[(day+12)%7]++;
      if((year+i)%4==0 && ((year+i)%100!=0||(year+i)%400==0) && j==1) 
          day = (day+month[j]+1)%7;
      else day = (day+month[j])%7;
    }
  }
  for(int i=6; i < 13;++i)
    out << days[i%7] << (i==12?"":" ");
  out << endl;
  return 0;
}