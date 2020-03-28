#include<stdio.h>
#include<string.h>
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
int multiply(int n, long int big[10]){
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
    for(; i<1000 && primes[i]!=-1; i++){
        while(n%primes[i] == 0 && n){
            occurences_temp[primes[i]]++;
            n /= primes[i];
        }
    }
    for(i=1; i<=max; i++){
        occurences[i] = MAX(occurences[i], occurences_temp[i]);
    }
}

void print_big(){
    int i;
    for(i=len-1; i; i--) if(big[i-1]!=0) break;
    printf("%ld", (long)big[i-1]);
    for(i--; i; i--) printf("%ld", (long)big[i-1]);    
}

int main()
{
    generate_primes();
    int t, ix;
    scanf("%d", &t);
    for(ix=1; ix<=t; ix++){
        int n;
        scanf("%d", &n);
        big[0] = 1;
        int nums[n], i;
        for(i=0; i<n; i++){
            scanf("%d", &nums[i]);
            prime_facts(nums[i]);
        }
        for(i=1; i<=max; ){
            if(occurences[i] != 0){
                printf("%d - %d\n", i, occurences[i]);
                multiply(i, big);
                occurences[i]--;
                continue;
            }
            i++;
        }
        printf("Case %d: ", ix);
        print_big();
        putchar('\n');
    }
    return 0;
}