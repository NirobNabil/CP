#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int t, l;
	char s[int(2e5)], x;
	unordered_map<char, char> y;
	y['S'] = 'R';
	y['R'] = 'P';
	y['P'] = 'S';
	scanf("%d", &t);
	while(t--){
		map<int, char> occ;
		scanf("%s", s);
		l = strlen(s);
		occ[count(s, s+l, 'R')] = 'R';
		occ[count(s, s+l, 'P')] = 'P';
		occ[count(s, s+l, 'S')] = 'S';
		x = occ.rbegin()->second;
		for(int i=0; i<l; i++) {
			printf("%c", y[x]);
		}
		printf("\n");
	}
}