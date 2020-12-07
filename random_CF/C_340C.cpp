#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

void print_128(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print_128(x / 10);
    putchar(x % 10 + '0');
}

int main(){
	int i, ix, t, n, a[S1];
	scanf("%d", &n);
	__int128 nom=0,denom=0,tt=0,tn=0,ext=0;
	rep(i, 0, n) scanf("%d", &a[i]);
	sort(a, a+n);
	// bigint nom=0, denom=0, tt=0, tn=1;	
	// // for(int i=n; i>0; i--) tn *= i;
	// // cout << tn << endl;
	// bigint ext=0;
	for(int i=0; i<n; i++) {
		tt = a[i];
		// cout << tt*(2*(i+1)-n-1) << endl;
		nom = nom + tt*(2*(i+1)-n-1);
		ext += tt; 
	} 
	print_128( (nom*2 + ext)/(__gcd(nom*2+ext,(__int128)n)));
	printf(" ");
	print_128((__int128)n/__gcd(nom*2+ext,(__int128)n));
	printf("\n");
	// cout << (ext);
	// cout << (nom*2+ext)*(tn/n) << " ";
	// cout << (nom*2 + ext)/(__gcd(nom*2+ext,(__int128)n)) << " ";
	// cout << n/__gcd(nom*2+ext,(__int128)n) << endl;
}