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

string p, h;

int check(int s) {
	string t = h.substr(s, p.size());
	sort(t.A(), t.B());
	// cout << t << endl;
	return t==p;
}

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		cin >> p >> h;
		sort(p.begin(),p.end());
		// cout << p << " - " << h << endl;
		if(h.size()<p.size()) {
			printf("NO\n");
			continue;
		}
		bool poss=check(0);
		for(int i=1; i<=h.size()-p.size(); i++) {
			if(check(i)) poss = true;
		} 
		if(poss) printf("YES\n");
		else printf("NO\n");
	}
}