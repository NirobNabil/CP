#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int a[2500], b[2500], t, n, m, m_i;

int b_prop(int i){
	// printf("called b_prop(%d)\n", i);
	if(i==-1) return 1;
	if( (i%n!=n-1 && (a[i+1]<=a[i] || b[i+1]<=b[i])) || (i+n<=m_i && ( b[i+n]<=b[i] || a[i+n]<=a[i])) ) {
		if( ( !(i%n!=n-1) || (a[i+1]>b[i] && b[i+1]>a[i])) && ( !(i+n<=m_i) || ( a[i+n]>b[i] && b[i+n]>a[i])) ) {
			t = a[i];
			a[i] = b[i];
			b[i] = t;
			return b_prop(i-1);
		}else return 0;
	}else if(i+n>m_i){
		return b_prop(i-1);
	}else return 1;
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i=0; i<n*m; i++) scanf("%d", &a[i]);
	for(int i=0; i<n*m; i++) scanf("%d", &b[i]);
	int flag=1, flag2=0;
	for(int i=1; i<n*m && flag; i++) {
		if( ((i%n!=0 && (a[i]<=a[i-1] || b[i]<=b[i-1])) || (i>=n && ( b[i]<=b[i-n] || a[i]<=a[i-n])) ) ) {
			if( ( !(i%n!=0) || (a[i]>b[i-1] && b[i]>a[i-1])) && ( !(i>=n) || ( a[i]>b[i-n] && b[i]>a[i-n])) ) {
				t = a[i];
				a[i] = b[i];
				b[i] = t;
				flag2 = 0;
			}else if(flag2!=1){
				m_i=i;
				flag = b_prop(i-1);
			}
			if(!flag) {
				t = a[i];
				a[i] = b[i];
				b[i] = t;
				m_i=i;
				flag = b_prop(i-1);
			}
		}
	}
	if (flag==0)
	{
		printf("Impossible\n");
	}else printf("Possible\n");
}

