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

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		string s;
		cin >> s;
		for(int i=0; i<s.size(); i++) {
			if(s[s.size()-i-1] != 'a') {
				printf("YES\n");
				cout << s.substr(0, i) + 'a' + s.substr(i, s.size()-i) << "\n";
				break;
			}
			if(i==s.size()-1) {
				printf("NO\n");
			}
		} 
	}
}