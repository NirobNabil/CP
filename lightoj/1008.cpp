#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int it=1; it<=t; it++){
        
        // for(int ix=0; ix<=log; ix++){
        //  cout << ix << endl;
        //  for(int i=1; i<=n; i++) cout << mins[i][ix] << " ";
        //  cout << endl << endl;  
        // }
        printf("Case %d:\n", it);
        while(q--){
            int a, b;
            scanf("%d %d", &a, &b);
            int max_p = (int)log2(b-a+1);
            //cout << a << " " << b << endl;
            printf("%d\n", min(mins[a][max_p], mins[b-(int)pow(2,max_p)+1][max_p]));
        }
    }
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++) {
		long long int n;
		scanf("%lli", &n);
		long long int xd = sqrt(n),a,b;
		if(xd*xd==n) a=(xd%2==0)?xd:1, b=(xd%2==0)?1:xd;
		else if(xd%2==0){
			if(n-xd*xd<=(xd+1)) a=xd+1, b=n-xd*xd;
			else a=xd+1-(n-xd*xd)%(xd+1), b=xd+1;	
		}else{
			if(n-xd*xd<=(xd+1)) a=n-xd*xd, b=xd+1;
			else a=xd+1, b=((xd+1)*(xd+1)-n)+1;
		}
		printf("Case %d: %lli %lli\n", i,a,b);
	}
}