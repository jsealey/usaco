/*
ID: jsealey1
LANG: C++
TASK: beads
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
  ifstream in("beads.in");
  ofstream out("beads.out");

  int count;
  string beads;
  in >> count;
  in.get();
  getline(in, beads);
  beads += beads;
  int best = 0;
  for(int i=1; i < beads.length(); ++i){
    int red_left=0, blue_left=0, red_right=0, blue_right=0;
    bool seen_red_left = false, seen_blue_left = false, seen_red_right = false, seen_blue_right = false;
    for(int j=0; j < beads.length(); ++j){
      if(i-j-1>=0)
      switch(beads[i-j-1]){
        case 'r': if(!seen_blue_left)red_left++;seen_red_left=true; break;
        case 'b': if(!seen_red_left)blue_left++;seen_blue_left!=true; break;
        case 'w': 
          if(!seen_blue_left)red_left++;
          if(!seen_red_left)blue_left++;
          break;
      }
      if(i+j<beads.length())
      switch(beads[i+j]){
        case 'r': if(!seen_blue_right)red_right++;seen_red_right=true; break;
        case 'b': if(!seen_red_right)blue_right++;seen_blue_right=true; break;
        case 'w': 
        if(!seen_blue_right)red_right++;
        if(!seen_red_right) blue_right++;
        break;
      }
    }
    best = max(best, max( red_left + blue_right, red_right + blue_left));
  }
  if(best > beads.length()/2) best = beads.length()/2;
  out << best << endl;

  return 0;
}
