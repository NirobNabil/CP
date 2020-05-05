#include <bits/stdc++.h>
using namespace std;
int writeln(char state[64], vector<vector<int> > &pegs, int n, int from, int to){
	char Tstate[64] = "";
	pegs[to].push_back(*--pegs[from].end());
	pegs[from].pop_back();
	for(auto peg : pegs){
		//cout << "| ";
		sprintf(Tstate, "%s|", Tstate);
		//for(auto i=peg.begin(); i!=peg.end(); i++) cout << *i << " ";
		for(auto i=peg.rbegin(); i!=peg.rend(); i++) sprintf(Tstate, "%s%d", Tstate, *i);
		//cout << "\n";
	}
	//cout << Tstate << endl;
	//cout << endl;
	if(strcmp(state, Tstate) == 0) return -1;
	return 1;
}

int Hanoi(int &gg, char state[64], vector<vector<int> > &pegs, int N, int From, int To_, int Temp){
	int n = 0;
	if(N>0){
	     n += Hanoi(gg, state, pegs, N-1, From, Temp, To_);
	     if(writeln (state, pegs, N, From, To_)==-1) gg = n+1;
	     else n += 1;
	     n += Hanoi(gg, state, pegs, N-1, Temp, To_, From);
	}
	return n;
}

int main(){
	int xd, n;
	scanf("%d", &n);
	xd=n;
	vector<deque<int> > pegs(3, deque<int>());
	char state[64] = "";
	//while(xd--) pegs[0].pop_back(), pegs[1].pop_back(), pegs[2].pop_back();
	//vector<int> ins(n);
	for(int i=1; i<=n; i++){
		//printf("%d\n", n);
		int temp;
		scanf("%d", &temp);
		pegs[temp-1].push_back(i);
	}
	for(auto peg : pegs){
		sprintf(state, "%s|", state);
		for(int i : peg) sprintf(state, "%s%d", state, i);
	}
	//printf("%s\n", state);
	// for(auto i=ins.rbegin(); i!=ins.rend(); i++) cout << *i << endl;
	// for(int i=ins.size()-1; i>0; i--) pegs[ins[i]-1].push_back(i);
	int min1;
	//cout << pegs[2].back();
	if(pegs[1].empty() || pegs[2].empty()){
		if(pegs[1].empty()) min1 = 2;
		else if(pegs[2].empty()) min1 = 1;
		else{
			printf("0\n");	
			return 0;
		}
		int i=1, x=pegs[min1].back()-1;
		while(x--){
			i = i*2+1;
		}
		printf("%d\n", i);
		return 0;
	}
	else if(pegs[1].back() > pegs[2].back()) min1 = 2;
	xd=n;
	vector<vector<int> > tpegs(3, vector<int>(n));
	for(int i=0; i<xd; i++) tpegs[0].pop_back(), tpegs[1].pop_back(), tpegs[2].pop_back();
	for(int i=pegs[((min1==1)?2:1)].back()-1; i>0; i--) tpegs[min1].push_back(i);
	for(int i=n; i>pegs[((min1==1)?2:1)].back()-1; i--) tpegs[0].push_back(i);
	//writeln(state, tpegs, 0, 0, 0);
	int t=0, i=0, x=pegs[((min1==1)?2:1)].back();
	while(x--){
		i = 2*i+1;
	}
	//cout << min1 << endl;
	writeln(state, tpegs, 0, 0, 0);
	if(writeln(state, tpegs, 1, 0, ((min1==1)?2:1))==-1) cout << i +1 << endl;
	else{
		int gg;
		int xx = Hanoi(gg, state, tpegs, tpegs[min1][0], min1, ((min1==1)?2:1), 0);
		cout << i + 1 + gg;
	}
}