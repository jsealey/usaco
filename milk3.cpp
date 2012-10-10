/*
ID: jsealey1
LANG: C++
TASK: milk3
*/
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
#include<sstream>

using namespace std;

struct bucket {
  bucket(){}
  bucket(int a_, int b_, int c_):a(a_),b(b_),c(c_){}
	bool visited: 1;
	int a: 6;
  int b: 6;
  int c: 6;
  int wordalign: 13;
} buckets[21][21][21];

list<bucket> path;
int a, b, c, aa, bb, cc, MAX[3];

void try_enqueue(){
	if(buckets[aa][bb][cc].visited == false){
		buckets[aa][bb][cc].visited = true;
		buckets[aa][bb][cc].a = aa;
    buckets[aa][bb][cc].b = bb;
    buckets[aa][bb][cc].c = cc;
		path.push_back(bucket(aa,bb,cc));
	}
}

void transfer(int &from, int &to, int maxto){
  cout <<"BEFORE: from: " << from << "  to: " << to << endl;
  while(from!=0 && to!=MAX[maxto]){
    from--;
    to++;
  }
  cout <<"AFTER: from: " << from << "  to: " << to << endl;
}

int main()
{
  ifstream in("milk3.in");
  ofstream out("milk3.out");
  in >> MAX[0] >> MAX[1] >> MAX[2];
  a = 0; 
  b = 0;
  c = MAX[2];

  bool results[21] = {0};
  buckets[a][b][c].visited = true;


  path.push_back(bucket(a,b,c));

  while(!path.empty()){
  	bucket state = path.back();
  	path.pop_back();
    a = state.a;
    b = state.b;
    c = state.c;
  	
  cout << "a: " << a <<" b: " << b << " c: " << c << endl;

    // A to B
    aa=a;bb=b;cc=c;
    transfer(aa,bb,1);
    try_enqueue();
    if(aa==0) results[cc] = 1;

    // A to C
    aa=a;bb=b;cc=c;
    transfer(aa,cc,2);
    try_enqueue();
    if(aa==0) results[cc] = 1;

    // B to A
    aa=a;bb=b;cc=c;
    transfer(bb,aa,0);
    try_enqueue();
    if(aa==0) results[cc] = 1;

    // B to C
    aa=a;bb=b;cc=c;
    transfer(bb,cc,2);
    try_enqueue();
    if(aa==0) results[cc] = 1;

    // C to A
    aa=a;bb=b;cc=c;
    transfer(cc,aa,0);
    try_enqueue();
    if(aa==0) results[cc] = 1;

    // C to B
    aa=a;bb=b;cc=c;
    transfer(cc,bb,1);
    try_enqueue();
    if(aa==0) results[cc] = 1;
    cout << endl;
    for(int i=0; i < 21;++i)
      cout << i << ": " << results[i] << " ";
    cout << endl;
  }
  stringstream ss;
  for(int i=0; i<21;++i)
    if(results[i]) ss << i << " ";
  string s = ss.str();
  out << s.substr(0, s.length()-1) << endl;
  return 0;
}
