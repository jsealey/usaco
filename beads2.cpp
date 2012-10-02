/*
ID: jsealey1
LANG: C++
TASK: beads
*/
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>

using namespace std;
int main(){
  ifstream in("beads.in");
  ofstream out("beads.out");

  string s;
  int total=0, c;
  in >> c >> s;

  int l, r;
  int l_r, l_b, r_r, r_b;

  for(int i=0,j=s.length(); i < j-1; ++i){
    l_r = l_b = r_r = r_b = 0;
    bool *check = new bool[j];
    for(int k=0; k < j; ++k) check[k] = 0;

    l = i; 
    do{ // Check left for reds/whites 
      if(s[abs(l%j)]=='b') break;
      else if((s[abs(l%j)]=='r' || s[abs(l%j)]=='w') && check[abs(l%j)]==0) { l_r++; check[abs(l%j)]=1; }
      check[abs(l%j)]==1;
    }while(abs(--l%j)!=i);
    r = i+1; 
    do{ // Check right for reds/whites
      if(s[abs(r%j)]=='b') break;
      else if((s[abs(r%j)]=='r' || s[abs(r%j)]=='w') && check[abs(r%j)]==0){ r_r++;  check[abs(r%j)]=1; }
      check[abs(r%j)]=1;
    }while(abs(++r%j)!=i+1);

    for(int k=0; k < j; ++k) check[k] = 0;

    l = i; 
    do{ // Check left for blues/whites 
      if(s[abs(l%j)]=='r') break;
      else if((s[abs(l%j)]=='b' || s[abs(l%j)]=='w') && check[abs(l%j)]==0) { l_b++; check[abs(l%j)]=1; }
      check[abs(l%j)]=1;
    }while(abs(--l%j)!=i);
    r = i+1;
    do{ // Check right for blues/whites 
      if(s[abs(r%j)]=='r') break;
      else if((s[abs(r%j)]=='b' || s[abs(r%j)]=='w') && check[abs(r%j)]==0){ r_b++;  check[abs(r%j)]=1; }
      check[abs(r%j)]=1;
    }while(abs(++r%j)!=i+1);

    int all_red = l_r + r_r;
    int all_blue = r_r + r_b;

    total = max(max(all_red,all_blue), total);

    delete [] check;
  }

    // Check left and right from every position painting all whites RED
  for(int i=0,j=s.length(); i < j-1; ++i){
    l_r = l_b = r_r = r_b = 0;
    bool *check = new bool[j];
    for(int k=0; k < j; ++k) check[k] = 0;

    l = i; 
    do{ // Check left for reds/whites 
      if(s[abs(l%j)]=='b') break;
      else if((s[abs(l%j)]=='r' || s[abs(l%j)]=='w') && check[abs(l%j)]==0) { l_r++; check[abs(l%j)]=1; }
      check[abs(l%j)]=1;
    }while(abs(--l%j)!=i);
    r = i+1; 
    do{ // Check right for blues/whites 
      if(s[abs(r%j)]=='r') break;
      else if((s[abs(r%j)]=='b' || s[abs(r%j)]=='w') && check[abs(r%j)]==0){ r_b++;  check[abs(r%j)]=1; }
      check[abs(r%j)]=1;
    }while(abs(++r%j)!=i+1);

    for(int k=0; k < j; ++k) check[k] = 0;

    l = i; 
    do{ // Check left for blues/whites 
      if(s[abs(l%j)]=='r') break;
      else if((s[abs(l%j)]=='b' || s[abs(l%j)]=='w') && check[abs(l%j)]==0) { l_b++; check[abs(l%j)]=1; }
      check[abs(r%j)]=1;
    }while(abs(--l%j)!=i);
    r = i+1;
        do{ // Check right for reds/whites
      if(s[abs(r%j)]=='b') break;
      else if((s[abs(r%j)]=='r' || s[abs(r%j)]=='w') && check[abs(r%j)]==0){ r_r++;  check[abs(r%j)]=1; }
      check[abs(r%j)]=1;
    }while(abs(++r%j)!=i+1);

    int red_blue = l_r + r_b;
    int blue_red = l_b + r_r;

    total = max(max(red_blue,blue_red), total);

    delete [] check;
  }

  out << total << endl;
  return 0;
}
