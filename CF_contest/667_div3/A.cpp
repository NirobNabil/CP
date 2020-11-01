#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n,x,y, temp;
		scanf("%d %d %d", &n, &x, &y);
		std::set<int> v;
		// if(n>max(x,y)-min(x,y)){
		// 	y = max(x,y);
		// 	temp = y;
		// 	while(y>0 && n-->=0) v.insert(y--);
		// 	y = ++temp;
		// 	while(n-->=0) v.insert(y++);
		// }else {
			int g;
			g = max(x,y);
			x = min(x,y);
			y = max(g,y);
			g = y-x;
			temp = n--;
			while(g%n!=0) n--;
			g = g/n;
			n=temp;
			temp = y;
			while(n>0 && y>0) v.insert(y), y-=g, n--;
			y = temp + g;
			while(n>0) v.insert(y), y+=g, n--;
		// }
		for(auto i:v) printf("%d ", i);
		printf("\n");
	}
}