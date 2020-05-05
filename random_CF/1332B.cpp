#include <stdio.h>
#include <string.h>
#include <set>
#define MAX(a,b) ((a>b)?a:b)
#define max 1000

int primes[max+1] = {0};
char nums[max+1] = {0};
int generate_primes(){
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
    return next;
}
int occurences[max+1] = {0};
void prime_facts(int n){
    memset(occurences, 0, sizeof(occurences));
    int i=0;
    for(; i<max+1 && primes[i]!=-1 && n; i++){
        while(n%primes[i] == 0 && n>1){
            occurences[primes[i]]++;
            n /= primes[i];
        }
    }
}

int main(){
	int t, n, inputs[1000];
	generate_primes();
	// for(int i=0; primes[i]!=-1; i++) printf("%d, ", primes[i]);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &inputs[i]);
			//printf("        %d\n", inputs[i]);
			//printf("g1\n");
			prime_facts(inputs[i]);
			for(int ix=0; primes[ix]!=-1; ix++){
				//printf("%d %d\n", primes[ix], occurences[primes[ix]]);
				if(occurences[primes[ix]]){
					inputs[i]=ix+1; 
					break;
				}
			}
		}
		std::set<int> colors;
		int colors_gg[12]={0};
		for(int i=0; i<n; i++){
			colors.insert(inputs[i]);
		}
		printf("%d\n", colors.size());
		int next=1;
		for(std::set<int>::iterator it=colors.begin(); it!=colors.end(); ++it){
			colors_gg[*it] = next++;
			//printf("%d\n", *it);
		}
		//for(int i=0; i<colors.size(); i++) printf("%d\n", colors_gg[i]);
		for(int i=0; i<n; i++){
			printf("%d ", colors_gg[inputs[i]]);
		}
		printf("\n");
	}
}