/*
ID: jsealey1
LANG: C++
TASK: ariprog
*/
#include<fstream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
	return !(a.second == b.second ? a.first > b.first : a.second > b.second);
}
int main(){
  ifstream in("ariprog.in");
  ofstream out("ariprog.out");
  int N, M;

  vector<bool> ar(125001,false);
  vector< pair<int,int> > results;
  int count = 0;
  int vb[125001];
  in >> N >> M;

  for(int i = 0; i <= M; i++)
  	for (int j = 0; j <= M; j++){
  		if(!ar[i*i + j*j]){
  			vb[count++] = i*i + j*j;
  			ar[i*i + j*j] = 1;
  		}
  	}
  stable_sort(vb,vb+count);
  for(int a=0;a < count;++a){
	for(int b = 1, isValid = 1; b <= vb[count-1]/(N-1);++b, isValid = 1){
	  for(int j=0; j < N && isValid;++j) isValid &=  ar[vb[a] + b*j];
	  if(isValid) results.push_back(pair<int,int>(vb[a],b));
	}
  }
  stable_sort(results.begin(),results.end(),cmp);
  for(int i=0; i < results.size();++i) out << results[i].first << " " << results[i].second << endl;
  	if(results.size()==0) out << "NONE" << endl;
  return 0; 
}