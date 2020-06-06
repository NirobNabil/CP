#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define CEIL(A,B) ((A%B==1)?(A/B+1) : (A/B))

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n,m, ans=0;
		scanf("%d %d", &n, &m);
		if(n==1){
			printf("%d\n", CEIL(m,2));
		}else if(m==1){
			printf("%d\n", CEIL(n,2));
		}else if(!(n%2) && !(m%2)){
			printf("%d\n", (n*m)/2);
		}else if((n%2) && !(m%2)){
			printf("%d\n", (m*(n-1))/2 + CEIL(m,2));
		}else if((m%2) && !(n%2)){
			printf("%d\n", (n*(m-1))/2 + CEIL(n,2));
		}else if(n%2 && m%2){
			printf("%d\n", ((m-1)*(n-1))/2 + n/2 + m/2 + 1);
		}
	}
}