/*
ID: jsealey1
LANG: C++
TASK: packrec
*/
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
#include<sstream>

using namespace std;
int best_area;
vector< pair<int,int> > rectangles;
vector< pair<int,int> > results;
bool cmp(pair<int,int> p1, pair<int,int> p2){
  return min(p1.first,p1.second) < min(p2.first,p2.second);
}
bool check(int x,int y, int case_){
  if(x*y<best_area){
    cout << "case: " << case_ << endl;
    cout << "best_area: " << x*y << endl;
    cout << "x: " << x << endl << "y: " << y << endl;
    results.clear();
    results.push_back(pair<int,int>(x,y));
    best_area = x*y;
    return true;
  } else if (x*y==best_area)
    if(find(results.begin(),results.end(),pair<int,int>(x,y))==results.end() 
    && find(results.begin(),results.end(),pair<int,int>(y,x))==results.end()){
      results.push_back(pair<int,int>(x,y));
      cout << "case: " << case_ << endl;
      cout << "best_area: " << x*y << endl;
      cout << "x: " << x << endl << "y: " << y << endl;
      return true;
    }
  return false;
}

int caseCheck(bool rotated[4]){
  vector< pair<int,int> > rects = rectangles;
  for(int i=0; i < 4;++i)
    if(rotated[i])
      swap(rects[i].first,rects[i].second);

  for(int i=0; i < 4;++i)
    cout << "Rects[" << i << "].x: " << rects[i].first << endl
         << "Rects[" << i << "].y: " << rects[i].second << endl;

  int x,y;

  // Side by side
  x=y=0;
  for(int i=0; i < 4;++i){
    x+=rects[i].first;
    y=max(rects[i].second,y);
  }
  check(x,y,1);

  // 3 on top of one
  for(int i=0; i < 4;++i){
    x=y=0;
    for(int j=0;j<4;++j)
      if(i!=j){
        x+=rects[j].first;
        y=max(rects[j].second,y);
      }
    x = max(x, rects[i].first);
    y+=rects[i].second;
    check(x,y,2);
  }

  // two on top of one
  for(int i=0; i < 4;++i)
    for(int j=0; j < 4;++j){
      if(j==i) continue;
      x=y=0;
      //The other 2 in the middle
      for(int k=0; k < 4;++k)
        if(k!=i && j!=k){
            x += rects[k].first;
            y = max(y,rects[k].second);
        }
      //One on bottom
      x = max(x, rects[j].first);
      y += rects[j].second;
      // One on side
      x += rects[i].second;
      y = max(y, rects[i].first);
      check(x,y,3);
    }

  // one on top of one
  // exterior rectangle
  for(int i=0; i < 4;++i)
    // exterior rectangle
    for(int j=0; j < 4;++j){
      if(j==i) continue;
      x=y=0;
      //The other 2 in the middle
      for(int k=0; k < 4;++k)
        if(k!=i && j!=k){
            x = max(x,rects[k].first);
            y += rects[k].second;
        }
      //exterior rectangle
      x += rects[j].first;
      y = max(y, rects[j].second);
      //exterior rectangle
      x += rects[i].second;
      y = max(y, rects[i].first);
      check(x,y,4);
    }

  // one on top of one, another on top of the other
  for(int i=0; i < 4;++i)// top left
    for(int j=0; j < 4;++j)// top right
      if(j==i)continue; else
      for(int k=0; k < 4;++k)// bottom left
        if(k==i || k==j) continue; else
        for(int l=0; l < 4;++l)// bottom right
          if(l==i||l==j||l==k) continue; else {
            x=y=0;
            x = max(rects[k].first,rects[i].first) + max(rects[j].first,rects[l].first);
            int x2 = max(rects[k].first+rects[l].first,rects[i].first+rects[j].first);
            y = max(rects[k].second+rects[i].second, rects[j].second+rects[l].second);

            //int x2,y2;

            //x2 = max(rects[i].first + rects[j].first,rects[k].first + rects[l].first);
            //y2 = max(rects[k].second + rects[i].second,rects[j].second + rects[l].second);
            if(rects[k].second < rects[l].second && rects[k].first > rects[i].first) check(x2,y,5);
            else check(x,y,5);
            /*

            x = max(rects[k].first,rects[i].first) + max(rects[j].first,rects[l].first);
            y = max(rects[k].second+rects[i].second, rects[j].second+rects[l].second);

            y2 = max(rects[k].second,rects[i].second) + max(rects[j].second,rects[l].second);
            x2 = max(rects[k].first+rects[i].first, rects[j].first+rects[l].first);
            */
            
            if(check(x,y,5)){
              cout << "top_left: " << i << " "
            << "top_right: " << j << " "
            << "bottom_left: " << k << " "
            << "bottom_right: " << l << endl;
            }
          }
}

// Pre-condition: rotates = {0}
//            0000
//           /   \
//       0001    0000
//         /      \ ...
void permute(bool rotated[4]){
  for(int i=0; i < 16;++i){
    rotated[0] = i&1;
    rotated[1] = i&2;
    rotated[2] = i&4;
    rotated[3] = i&8;
    caseCheck(rotated);
    for(int j=0;j<4;++j) cout << rotated[j];
    cout << endl;
  } 
}

int main()
{
  ifstream in("packrec.in");
  ofstream out("packrec.out");
  bool rotated[4] = {0};
  for(int i=0; i< 4;++i){
    int x_,y_;
    in>>x_>>y_;
    rectangles.push_back(pair<int,int>(x_,y_));
  }
  best_area = 1E9;
  permute(rotated);

  stable_sort(results.begin(),results.end(),cmp);
  out << results[0].first*results[0].second << endl;
  for(int i=0; i < results.size();++i)
    out  << min(results[i].first, results[i].second) 
    <<" "<< max(results[i].first, results[i].second) << endl;
  return 0; 
}