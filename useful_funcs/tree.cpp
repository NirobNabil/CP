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
	const int n = 5;
	int mat[n][n] = {
		{1 ,0 ,0 ,0 ,0 },
		{2 ,3 ,0 ,0 ,0 },
		{4 ,5 ,6 ,0 ,0 },
		{7 ,8 ,9 ,10,0 },
		{11,12,13,14,15},
	};
	int matl[(n*(n+1))/2 +1];
	
	//retreival function
	auto jk2i = [](int j, int k) {
		if(k>j) return 0;
		return (j*(j-1))/2 + k;
	};
	
	for(int i=0; i<n; i++) {
		for(int ix=0; ix<n; ix++) {
			printf("%d ", jk2i(i+1, ix+1));
			matl[jk2i(i+1, ix+1)] = mat[ix][i];
		}
		printf("\n");
	}	

}