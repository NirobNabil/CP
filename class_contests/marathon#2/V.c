#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	long long n;
	char name[10];
	scanf("%d", &t);
	for (int ix = 1; ix <= t; ix++) {
		scanf("%lld", &n);
		scanf("%s", name);
		n = n % 3;
		printf("Case %d: ", ix);
		if(!strcmp(name, "Alice")) {
			if(n == 0 || n == 2) printf("Alice\n");
			else printf("Bob\n");
		}
		else{
			if(n == 1 || n == 2) printf("Bob\n");
			else printf("Alice\n");
		}
	}
}