#include <bits/stdc++.h>

using namespace std;
void writeln(vector<vector<int> > &
	pegs, int n, int from, int to){
	pegs[to].push_back(*--pegs[from].end());
	pegs[from].pop_back();
	for(peg : pegs){
		for(int i : peg) cout << i << " ";
		cout << "\n";
	}
	cout << endl;
}

void Hanoi(vector<vector<int> > &pegs, int N, int From, int To_, int Temp){
	if(N>0){
	     Hanoi(pegs, N-1, From, Temp, To_);
	     writeln (pegs, N, From, To_);
	     Hanoi(pegs, N-1, Temp, To_, From);
	}
}

int main(){
	// set<pair<int, int> > g;
	// g.insert(make_pair(1,2));
	// g.insert(make_pair(2,3));
	// for(auto i : g) cout << i.first << " " << i.second << endl;
	// g.erase(make_pair(2,3));
	// for(auto i : g) cout << i.first << " " << i.second << endl;
	list<int> gg;
	gg.push_back(1);
	gg.push_back(2);
	gg.push_back(3);
	gg.push_back(4);
	gg.push_back(5);
	gg.push_back(6);
	auto i = gg.begin();
	i++; i++; i++; i++;
	cout << *i << endl;
	gg.insert((++i)--, gg.begin(), ++++gg.begin());
	cout << *i << endl;
	for(i : gg) cout << i << " ";
}