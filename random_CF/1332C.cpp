#include <string.h>
#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

char s[1000000], chars_c[100000], maxs[100000];
int tochange, n, k, max, chars[27];

char check(int i, char gg){
	printf("checking %c - ", gg);
	int count = 0;
	for(int ix=i; ix<n; ix+=k){
		if(s[ix]==gg) count++;
		printf("%c ", s[ix]);
	}	
	printf("%d\n", count);
	return count;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		tochange = 0;
		scanf("%d %d", &n, &k);
		scanf("%s", s);
		for(int i=0; i<((k%2==0)?k/2:k/2+1); i++){
			max=0;
			memset(chars, 0, sizeof(chars));
			for(int ix=i; ix<n; ix+=k){
				chars[s[ix]-'a']++;
				if(k%2!=0 && i==k/2){
				}else chars[s[(ix/k)*k+k-(ix%k)-1]-'a']++;
			}
			for(int ix=0; ix<27; ix++){
				max = MAX(chars[ix], max);
			}
			int gg = (((k%2!=0 && i==k/2)?1:2)*n);
			tochange += gg/k - max;
		}
		printf("%d\n", tochange);
	}
}