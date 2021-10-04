#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int ck(char x, char y) {
	return (x-'0') + (y-'0');
}

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		string a,b;
		cin >> a;
		// printf("\n");
		// cout << a;
		for(int i=0; i<a.size(); i++) b.push_back('1');
		// cout << b << " ";
		for(int i=1; i<a.size(); i++) {
			if(ck(a[i],b[i]) == ck(a[i-1],b[i-1])) {
				// printf("%c %c\n", a[i],b[i]);
				// printf("%c %c\n", a[i-1],b[i-1]);
				// printf("%d %d\n", ck(a[i],b[i]), ck(a[i-1],b[i-1]));
				// printf("\n");
				b[i]='0';
			}
		}
		cout << b << "\n";  
	}
}