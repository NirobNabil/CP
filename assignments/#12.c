#define MAX(a,b) ((a>b)?a:b)
#define max 10000
 
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
}