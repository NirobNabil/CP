#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

vector<string> in;
vector<vector<char> > grid;

bool isVowel(char c) {
	return (
		c == 'A' ||
		c == 'E' ||
		c == 'I' ||
		c == 'O' ||
		c == 'U' ||
		c == 'Y'
	);
}

void extract(int ir, int ic) {
	grid.clear();
	for(int ix=ir; ix<ir+4; ix++) {
		vector<char> row;
		for(int iy=ic; iy<ic+8; iy+=2) {
			row.pb(in[ix][iy]);
		} 
		grid.pb(row);
	}

	// for(auto i:grid) {
	// 	for(auto ix:i) {
	// 		printf("%c", ix);
	// 	}
	// 	printf("\n");
	// }
}

map<string, int> pos1, pos2;

void chk(int r, int c, int mask, string s, int v, int d, map<string,int> &pos) {
	if(d>3) {
		if(s == "OGNA") {
			printf("xx %d\n", v);
 		}
 		if(v == 2) {
 			// cout << s << endl;
			pos[s] = 1;
			return;
		}else return;
	}  
	for(int ir=r-1; ir<r+2; ir++) {
		for(int ic=c-1; ic<c+2; ic++) {
			if(ir<0 || ir>3 || ic<0 || ic>3 || ( (mask & 1<<ir) && (mask & 1<<(ic+5)) ) ) continue;
			chk(ir, ic, mask | 1<<ir | 1<<(ic+5), s + grid[ir][ic], v+isVowel(grid[ir][ic]), d+1, pos);
		}
	} 
}

int solve(map<string,int> &pos) {
	for(int i=0; i<4; i++) {
		for(int ix=0; ix<4; ix++) {
			chk(i, ix, 0, "", 0, 0, pos);
		} 
	}
}

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	string s;
	while(1) {
		getline(cin, s);
		if(s=="#") break;
		in.pb(s);
	}
	for(int i=0; i<in.size(); i+=5){
		extract(i, 0);
		solve(pos1);
		grid.clear();
		extract(i, 11);
		solve(pos2);
		for(auto i:pos1) {
			if(pos2[i.X]) cout << i.X << "\n";
		}
		// for(auto i:pos1) cout << i.X << "\n";
		// for(auto i:pos2) cout << i.X << "\n";
	} 
}

// D F F B    W A S U
// T U G I    B R E T
// O K J M    Y A P Q
// K M B E    L O Y R
