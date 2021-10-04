#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll m=1000000009, p=32;
int pi[100009];

int main(){
	int t;
	scanf("%d", &t);
	pi[0]=1;
	int key, i, ix;
	for(int i=1; i<100009; i++) pi[i]=(pi[i-1]*p)%m;
	unordered_set<int> task;
	//printf("%d\n", pi[100000]);
	while(t--){
		task.clear();
		int n, k;
		scanf("%d %d", &n, &k);
		char s[n];
		scanf("%s", &s);
		for(int i=0; i<n; i++) s[i] = s[i]-'a'+1;
		for(i=0; i<n-k+1; i++){
			key=0;
			for(ix=i; ix<i+k; ix++){
				key += (s[ix]*pi[ix-i])%m;
			}
			task.insert(key%m);
		}
		printf("%d\n", task.size());
	}
	return 0;
}