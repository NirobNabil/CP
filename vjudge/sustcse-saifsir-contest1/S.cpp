#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	char g;
	string a="";
	scanf("%c", &g);
	a += g;
	for(int i=0; i<2; i++) {
		for(int ii=0; ii<5; ii++) scanf("%c", &g);
		a += g;
	}
	cout << a << "\n";
}