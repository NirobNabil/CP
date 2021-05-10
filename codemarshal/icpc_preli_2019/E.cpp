#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000

int main(){
	int i, ix, t, n, x, y, z;
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++) {
		scanf("%d", &n);
		vector<int> a(n);
		for(int i=0; i<n; i++) {
      scanf("%d", &a[i]);
    }
    int i = 0, sum = 0, c = 0, p = 0, q = 0;
   	for(int i=0; i<n;) {
   		while(i<n && a[i] > 0) sum += a[i++], p=1;
   		while(i<n && a[i] <=0) {
   			if(a[i] != 0) q=1;
   			else q = max(q, 0);
   			i++;
   		}
   		// printf("%d %d %d ", i, p, q);
   		if(p && q) {
   			c++;
   		}
 			if(i!=n) p=0, q=0;
   		// printf("%d\n", c);
   	}

    // int sum2 = 0, c2 = 0, p2 = 0, q2 = 0;
   	// for(int i=n-1; i>=0; i--)  {
   	// 	while(i>=0 && a[i] > 0) sum2 += a[i--], p2=1;
   	// 	while(i>=0 && a[i] <=0) {
   	// 		if(a[i] != 0) q2=1;
   	// 		else q2 = max(q2, 0);
   	// 		i--;
   	// 	}
   	// 	if(p2 && q2) {
   	// 		c2++;
   	// 		if(i!=0) p2=0, q2=0;
   	// 	}
   	// }

   	if(c==0 && p==0) {
   		sum = *max_element(a.A(), a.B());
   	}

   	printf("Case %d: %d %d\n", tc, sum, max(0, c-(p && q)));
	}
}