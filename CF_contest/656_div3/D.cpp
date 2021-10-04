#include <bits/stdc++.h>
using namespace std;
#define ll long long int

char s[131080];
int len;

int good(unordered_map<char, multiset<int> > &occ, char g, int x, int y){
	int b=0, a=0, h, j;
	if(y-x==0) {
		if(s[x]==g) return 0; 
		else return 1;	
	}
	h = (y+1-x)/2;
	for(auto i=occ[g].lower_bound(x); *i <= y && i!=occ[g].end(); i++) {
		if(*i < x+h && *i >= x) b++;
		else if(*i >= x+h && *i <= y) a++;
	}
	return min(h - a + good(occ, g+1, x, x+h-1), h - b + good(occ, g+1, x+h, y));
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){		
		unordered_map<char, multiset<int> > occ;	
		scanf("%d", &len);
		scanf("%s", s);
		for(int i=0; i<len; i++) {
			occ[s[i]].insert(i);
		}
		printf("%d\n", good(occ, 'a', 0, len-1));		
	}
}