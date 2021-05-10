#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>

#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)

#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define bits bitset<10009>


#define MAX(a,b) ((a>b)?a:b)
#define max 10000

int primes[max+1] = {0};
char nums[max+1] = {0};
void generate_primes(){
    int i=3, ix;
    for(; i<=max; i+=2){
        ix=i+i;
        if(!nums[i]) for(; ix<=max; ix+=i) nums[ix] = 1; 
    }
    int next = 1;
    primes[0] = 2;
    i=3;
    for(; i<=max; i+=2){
        if(!nums[i]) primes[next]=i, next++;
    }
    primes[next] = -1;
}


bits occurences;
int prime_facts(int n){
    int i=0;
    occurences.reset();
    for(; i<10001 && primes[i]!=-1 && n>1; i++){
      while(n%primes[i] == 0 && n>1){
        occurences[i] = ( occurences[i]+1 ) % 2;
        n /= primes[i];
      }
    }
    return i;
} 


int main(){
	generate_primes();
	int i, ix, t, n, m, k, p, q, gg, x, y, z;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> a(n);
		vector<bits > xors(n);
		bool p = 0;
		for(int i=0; i<n; i++) {
    	scanf("%d", &a[i]);
    }

    for(int i=0; i<n; i++) {
    	prime_facts(a[i]);
    	xors[i] = occurences;
    }


    for(int i=0; i<n; i++) {
    	if( xors[i].count() > 0 ) p = 1;
    	for(int ix=0; ix<n; ix++) {
	    	if(xors[i] != xors[ix]) {
		  		p = 1;
		  		break;
		  	}
    	}
    }
    
    if(p) printf("YES\n");
    else printf("NO\n");

	}
}