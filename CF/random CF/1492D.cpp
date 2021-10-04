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
	int i, ix, t, n, a, b, k;
	scanf("%d %d %d", &a, &b, &k);
	b--;
	string as="1", bs="1";
	if(k!=0 && k>a+b-1 || (k>0 && (b<1 || a<1))) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	if(k>a) {
		for(int i=0; i<b-(k-a)-1; i++) as+="1", bs+="1";
		if(b) as+="1";  
		if(a) bs+="0";
		b = max(0,(k-a)+1);
		for(int i=0; i<b-1; i++) as+="1", bs+="1"; 
		for(int i=0; i<a; i++) as+="0"; 
		for(int i=0; i<a-1; i++) bs+="0"; 
		if(b) bs+="1";
	}else {
		for(int i=0; i<b-1; i++) as+="1", bs+="1";
		for(int i=0; i<a-k; i++) as+="0", bs+="0";
		a -= max(0,a-k);
		if(b) as+="1"; 
		for(int i=0; i<a; i++) bs+="0"; 
		for(int i=0; i<a; i++) as+="0"; 
		if(b) bs+="1";
	}
	cout << as << "\n" << bs << "\n";
}