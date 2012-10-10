/*
ID: jsealey1
LANG: C++
TASK: clocks
*/
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

list<int> path;

enum bits {

  BITS_A = 3 << 0,
  BITS_B = 3 << 2,
  BITS_C = 3 << 4,
  BITS_D = 3 << 6,
  BITS_E = 3 << 8,
  BITS_F = 3 << 10,
  BITS_G = 3 << 12,
  BITS_H = 3 << 14,
  BITS_I = 3 << 16
};

void printclock(int c) {

  cout << (((c&BITS_A)>>0)+1)*3 << " ";
  cout << (((c&BITS_B)>>2)+1)*3 << " ";
  cout << (((c&BITS_C)>>4)+1)*3 << endl;

  cout << (((c&BITS_D)>>6)+1)*3 << " ";
  cout << (((c&BITS_E)>>8)+1)*3 << " ";
  cout << (((c&BITS_F)>>10)+1)*3 << endl;

  cout << (((c&BITS_G)>>12)+1)*3 << " ";
  cout << (((c&BITS_H)>>14)+1)*3 << " ";
  cout << (((c&BITS_I)>>16)+1)*3 << endl;
}

struct node {
	bool visited:  1;
	unsigned move: 4;
	int parent:   28;
} nodes[262144]; // 4^9 = 262144

void try_enqueue(int state, int move, int next_node){
	if(nodes[next_node].visited == false){
		nodes[next_node].visited = true;
		nodes[next_node].parent  = state;
		nodes[next_node].move    = move;
		path.push_back(next_node);
	}
}

int main()
{
  ifstream in("clocks.in");
  ofstream out("clocks.out");

  // Mask values for different states
  int a = 3<<0,
  	  b = 3<<2,
  	  c = 3<<4,
  	  d = 3<<6,
  	  e = 3<<8,
  	  f = 3<<10,
  	  g = 3<<12,
  	  h = 3<<14,
  	  i = 3<<16;

  int temp=0, temp_state;
  int final = 262143;
  int startnode = 0;
  for(int i=0; i < 18;i+=2){
  	in >> temp;
  	startnode |= (((temp/3)-1)<<i);
  }


  nodes[startnode].visited = true;
  path.push_back(startnode);


  while(!path.empty()){
  	int state = path.front();
  	path.pop_front();

  	// Result of clocks after incrementing
  	int aa = (state+(1<<0))&a,
  		bb = (state+(1<<2))&b,
  		cc = (state+(1<<4))&c,
  		dd = (state+(1<<6))&d,
  		ee = (state+(1<<8))&e,
  		ff = (state+(1<<10))&f,
  		gg = (state+(1<<12))&g,
  		hh = (state+(1<<14))&h,
  		ii = (state+(1<<16))&i;

  	// move 1
  	temp_state = (state&(~(a|b|d|e)))|aa|bb|dd|ee;
  	try_enqueue(state, 1, temp_state);
  	if(temp_state == final) break;

  	// move 2
  	temp_state = (state&(~(a|b|c)))|aa|bb|cc;
  	try_enqueue(state, 2, temp_state);
  	if(temp_state == final) break;

  	// move 3
  	temp_state = (state&(~(b|c|e|f)))|bb|cc|ee|ff;
  	try_enqueue(state, 3, temp_state);
  	if(temp_state == final) break;

  	// move 4
  	temp_state = (state&~(a|d|g))|aa|dd|gg;
  	try_enqueue(state, 4, temp_state);
  	if(temp_state == final) break;

  	// move 5
  	temp_state = (state&~(b|d|e|f|h))|bb|dd|ee|ff|hh;
  	try_enqueue(state, 5, temp_state);
  	if(temp_state == final) break;

  	// move 6
  	temp_state = (state&(~(c|f|i)))|cc|ff|ii;
  	try_enqueue(state, 6, temp_state);
  	if(temp_state == final) break;

  	// move 7
  	temp_state = (state&(~(d|e|g|h)))|dd|ee|gg|hh;
  	try_enqueue(state, 7, temp_state);
  	if(temp_state == final) break;

  	// move 8
  	temp_state = (state&(~(g|h|i)))|gg|hh|ii;
  	try_enqueue(state, 8, temp_state);
  	if(temp_state == final) break;

  	// move 9
  	temp_state = (state&(~(e|f|h|i)))|ee|ff|hh|ii;
  	try_enqueue(state, 9, temp_state);
  	if(temp_state == final) break;
  }

  path.clear();
  	printclock(final);
  	cout << nodes[final].move;
  	cout << endl;
  do{
  	path.push_back(nodes[final].move);
  	cout << "parent: " << nodes[final].parent << endl << endl;
  	final = nodes[final].parent;
  	printclock(final);
  	cout << nodes[final].move;
  	cout << endl;
  }while(final!=startnode);

  path.sort();
  list<int>::iterator it = path.begin(), end = path.end();
  while(true){
  	out << *it++;
  	if(it!=end) out << " ";
  	else break;
  }

  out << endl;
  return 0;
}
