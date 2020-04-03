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

long int big[600] = {0};
int len = 500;
int multiply(int n, long int big[600]){
    long long int carry=0;
    int i=0;
    for(i=0; i<len; i++) {
        long long int tmp = n*(long long int)big[i] + carry;
        /*printf("%d %d\n", tmp, carry);*/
        big[i] = tmp % 1000000000;
        carry = tmp / 1000000000;
    }
    if (carry) big[len++] = carry;
    return 0;
}

int occurences[10001] = {0};
void prime_facts(int n){
    int occurences_temp[10001] = {0};
    int i=0;
    for(; i<10001 && primes[i]!=-1 && n; i++){
        while(n%primes[i] == 0 && n>1){
            occurences_temp[primes[i]]++;
            n /= primes[i];
        }
    }
    for(i=0; i<10001 && primes[i]!=-1 && n; i++){
        occurences[primes[i]] = MAX(occurences[primes[i]], occurences_temp[primes[i]]);
    }
}   

void print_big(){
    int i;
    for(i=len-1; i; i--) if(big[i-1]!=0) break;
    printf("%ld", (long)big[i-1]);
    for(i--; i; i--) printf("%.9ld", (long)big[i-1]);    
    /*for(i=len-1; i; i--) printf("%.9ld", (long)big[i-1]);*/
}