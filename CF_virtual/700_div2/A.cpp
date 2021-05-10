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
	int i, ix, t, n;
	scanf("%d", &t);
	while(t--){
		string a;
		cin >> a;
		for(int i=0; i<a.length(); i++) {
			if(i%2==0) a[i] = a[i]=='a'?'b':'a';
			else a[i] = a[i]=='z'?'y':'z';
		}
		cout << a << "\n";
	}
}