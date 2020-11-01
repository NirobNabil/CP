#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int it=1; it<=t; it++){
		int n, q;
		scanf("%d %d", &n, &q);
		int num[n+2];
		int mins[n+1][(int)ceil(log2(n))+2];
		for(int i=1; i<=n; i++){
			scanf("%d", &num[i]);
			mins[i][0] = num[i];
		}
		//num[n] = INT_MAX;
		int log = (int)log2(n)+1;
		//cout << log << " " << (int)pow(2,1) << endl;
		for(int ix=1; ix<=log; ix++){
			for(int i=1; i<=n; i++){
				//cout << mins[i][ix-1] << ", " << mins[i+(int)pow(2,ix) -(int)pow(2,ix-1)][ix-1] << "= " << min(mins[i][ix-1], mins[i+(int)pow(2,ix) -(int)pow(2,ix-1)][ix-1]) << endl; 
				mins[i][ix] = min(mins[i][ix-1], mins[min(n, i+(int)pow(2,ix) -(int)pow(2,ix-1))][ix-1]);  						
			}
		}
		// for(int ix=0; ix<=log; ix++){
		// 	cout << ix << endl;
		// 	for(int i=1; i<=n; i++) cout << mins[i][ix] << " ";
		// 	cout << endl << endl;	
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


//4 9 1 3 10 6 -3 -1 0 7  9  -10
//1 2 3 4 5  6  7  8 9 10 11  12