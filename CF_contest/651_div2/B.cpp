#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 20000

unordered_set<int, int> primes(MAX);
char nums[MAX+1] = {0};
int generate_primes(){
    int i=3, ix;
    for(; i<=MAX; i+=2){
        ix=i+i;
        if(!nums[i]) for(; ix<=MAX; ix+=i) nums[ix] = 1; 
    }
    int next = 1;
    primes.insert(2);
    i=3;
    for(; i<=MAX; i+=2){
        if(!nums[i]) primes.insert(i);
    }
}
int arr[1001] = {0};
set<int> perm[1001];

int main(){
	int t, n, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=1; i<n; i++) scanf("%d", &arr[i]);
		for(int i=1; i<n; i++) {
			for(int ix=i+1; ix<n; ix++) {
				if(arr[i] != -1 && arr[ix] != -1 && primes.find(arr[i] + arr[ix]) != primes.end()){
					perm[i].inesrt(ix), perm[ix].insert(i);
					// arr[i] = arr[ix] = -1;
					// break;
				}
			}
			for(int i=0; i<n; i++) 
		}

	}
}