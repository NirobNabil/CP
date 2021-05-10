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
#define ABS(a) (a<0?(a)*-1:a)

struct compare { 
  bool operator()(const pair<int, int>& value,  
                              const int& key) 
  { 
      return (value.first < key); 
  } 
  bool operator()(const int& key,  
                  const pair<int, int>& value) 
  { 
      return (key < value.first); 
  } 
}; 

int main(){
	int i, ix, t, n, r, c;
	char g;
	while(scanf("%d %d\n", &r, &c) != EOF){
		printf("%d %d\n", r, c);
		map<char, vector<pair<int,int> > > xy;
		for(int i=0; i<r; i++) {
			for(int ix=0; ix<c; ix++) {
				scanf("%c\n", &g);
				xy[g].push_back({ix,i});
			} 
		} 
		for(char i=45; i<='Z'; i++)  {
			sort(xy[i].A(), xy[i].B());
			if(xy[i].size()==0) continue;
			printf("%c -", i);
			for(auto ix:xy[i]) cout << ix.X << "," << ix.Y << " ";
			printf("\n");
		}
		string s; 
		cin >> s;
		ll cx = 0, cy = 0, ctx = 0, cty = 0, cxy = INT_MAX, ciy = INT_MAX, k = 0; 
		s.append("*");
		for(int i=0; i<s.length(); i++) {
			ctx = INT_MAX;   cty = INT_MAX;
			for(auto ix:xy[s[i]]) {
				// cout << ix.X << "," << ix.Y << " ";
				if(ABS(cx-ix.X)+ABS(cy-ix.Y) < ABS(ctx-cx)+ABS(cty-cy)) {
					ctx = ix.X;
					cty = ix.Y;
				} 
			} 
			printf("%d %d\n", ABS(ctx-cx), ABS(cty-cy));
			k += ABS(ctx-cx) + ABS(cty-cy);
			cx = ctx;   cy = cty;
		} 
		printf("%d\n", k + s.length());
	}
}

// 4 7
// ABCDEFG
// HIJKLMN
// OPQRSTU
// VWXYZ**
// CONTEST
// 5 20
// 12233445566778899000
// QQWWEERRTTYYUUIIOOPP
// -AASSDDFFGGHHJJKKLL*
// --ZZXXCCVVBBNNMM--**
// --------------------
// ACM-ICPC-WORLD-FINALS-20
// 152 19
// ABCDEFGHIJKLMNOPQZYX
// *****************Y
// AZAZ
// 6 4
// AXYB
// BBBB
// KLMB
// OPQB
// DEFB
// GHI*
// AB