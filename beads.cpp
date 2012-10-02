/*
ID: jsealey1
LANG: C++
TASK: beads
*/
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  /**/
  int iNum;
  fin>>iNum;
  string sNecklace,sLinkedNecklace;
  fin>>sNecklace;
  sLinkedNecklace=sNecklace+sNecklace;//"+" operation for string.
  int color(0); //color is used to track the color of last bead
  int current(0);//current is used to track 
  //the number of beads on current segment
  int previous(0);// previous is used track
  //the number of beads on previous segment
  int result(0);
  int w(0);
  for(int i=0;(i<iNum*2)&&(previous+current<iNum);++i)
  {
    if (sLinkedNecklace[i]=='w')
      { 
        w++;
        ++current;
      }
    else if (sLinkedNecklace[i]==color)
      {
        w=0;
        ++current;
      }
    else
    { 
      color=sLinkedNecklace[i];
      if(previous+current>result) result=previous+current;
      previous=current-w;
      current=1+w;
      w=0;
    }

  }
if(result<(current+previous))
    {
      fout<<current+previous<<endl;
    }
  else
    {
    fout<<result<<endl;
    }
}
