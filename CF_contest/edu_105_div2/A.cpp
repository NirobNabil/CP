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

int i, ix, t, n;
string a, b, c="(((";

int check() {
	b = "";
	for(int i=0; i<a.length(); i++) {
		b.push_back(c[a[i]-'A']);
	} 
	// cout << b << endl;
	stack<bool> s;
	for(int i=0; i<b.length(); i++) {
		if(b[i]=='(') {
			s.push(1);
		} else {
			if(s.empty()) return 0;
			s.pop();
		}
	}
	if(s.empty())	return 1;
	else return 0;
}

int change(int i) {
	if(i==2) {
		c[i] = '(';
		if(check()) return 1;
		c[i] = ')';
		return check();
	}
	c[i] = '(';
	if(change(i+1)) return 1;
	c[i] = ')';
	return change(i+1);
}

int main(){
	scanf("%d", &t);
	while(t--){
		cin >> a;
		b = "";
		string ans = change(0)?"YES":"NO";
		cout << ans << "\n";
	}
}