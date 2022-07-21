void print_128(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print_128(x / 10);
    putchar(x % 10 + '0');
}


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

int occurences[10001] = {0};
int prime_facts(int n){
    int i=0;
    for(; i<10001 && primes[i]!=-1 && n>1; i++){
        while(n%primes[i] == 0 && n>1){
            occurences[primes[i]]++;
            n /= primes[i];
        }
    }
    return i;
}  
map<int,int> primes;
void prime_factors(map<int,int> &occurences, int n)
{
    while (n % 2 == 0)
    {
        primes[2] = 1;
        occurences[2]++;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primes[i] = 1;
            occurences[i]++;
            n = n/i;
        }
    }
 
    if (n > 2) {
        primes[n] = 1;
        occurences[n]++;
    }
}
void print_big(){
    int i;
    for(i=len-1; i; i--) if(big[i-1]!=0) break;
    printf("%ld", (long)big[i-1]);
    for(i--; i; i--) printf("%.9ld", (long)big[i-1]);    
    /*for(i=len-1; i; i--) printf("%.9ld", (long)big[i-1]);*/
}

ll fact(ll n, ll k){
    ll c=1;
    for(ll i=0, j=n; i<k; i++, j--) {
        c *= j;
    }
    return c;
}

ll NcR(ll n, ll r) 
{ 
    ll p = 1, k = 1; 
    if (n - r < r) r = n - r; 
    if (r != 0) { 
        while ( r-- && n-- ) { 
            p *= n; 
            k *= r; 
            ll m = __gcd(p, k); 
            p /= m; 
            k /= m;   
        } 
    } 
    else  p = 1; 
  return p;
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


