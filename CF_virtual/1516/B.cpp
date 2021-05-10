#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)

#define X first
#define Y second
#define A begin
#define B end
#define S1 2009

int xors[S1][S1];
vector<int> a(S1);
int i, ix, t, n, m, k, p, q, gg, x, y, z;

int XOR(int i, int j) {
	if(i == j) return xors[i][j];
	return xors[i][j-1] ^ a[j];
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    	xors[i][i] = a[i];
    }
   	for(int i=0; i<n; i++) {
   		for(int j=i; j<n; j++) {
   			xors[i][j] = XOR(i,j);
   		} 
   	}

   	ll p = 0;
   	for(int i=0; i<n; i++) {
   		for(int j=i+1; j<n; j++) {
   			if(j == i+1) {
   				p += xors[0][i] == xors[j][n-1];
   				continue;
   			}

   			p += xors[0][i] == xors[j][n-1] && xors[i+1][j-1] == xors[0][i];
   		} 
   	}

   	printf("%s\n", p ? "YES":"NO");

	}
}