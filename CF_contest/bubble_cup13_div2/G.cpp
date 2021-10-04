#include "bits/stdc++.h"
using namespace std;
#define ll long long int

set<int> p;
unordered_map<int, int> x,y;

int main(){
	int n, b, d;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &b, &d);
		p.insert(b);
		p.insert(d);
		x[b]++;
		y[d]++;
	}
	int t_a=0, c_a=0, m_a=0, m_y=0;
	for(auto i:p){
		// t_a=c_a;
		if(x[i]) t_a+=x[i];
		// printf("x[%d]=%d %d ", i, x[i], t_a);
		if(y[i]) t_a-=y[i];
		// printf("%d %d\n", t_a, m_y);
		if(t_a > c_a) {
			m_y = i;
			c_a = t_a;
		}
	}
	printf("%d %d\n", m_y, c_a);
}