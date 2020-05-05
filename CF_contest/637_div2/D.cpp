#include <bits/stdc++.h>
using namespace std;
int dig[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
int check_dig[10] = {0b0001000, 0b1101101, 0b0100010, 0b0100100, 0b1000101, 0b0010100, 0b0010000, 0b0101101, 0b0000000, 0b0000100};
int in[2000], out[2000], cost[2000][10], max_off[2001];
int max_dig[2001][2001]={0};

void itoa(int a)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < 7; i++)
    {
        if((mask&a) >= 1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    cout<<binary<<" ";
}

void check(int n, int ix){
	for(int i=9; i>=0; i--){
		// char a[10], b[10], c[10];
		// printf("%d ", i);
		// itoa(dig[i]);
		// itoa(check_dig[i]);
		// itoa(n);
		// itoa(check_dig[i] | n);
		// itoa(dig[i] ^ n);
		// cout << endl;
		// printf("%d %d\n", check_dig[i] | n, dig[i] ^ n);
		if(check_dig[i] & n) cost[ix][i]=-1;
		else{
			int diff = dig[i] ^ n, count=0;
			for(int i=0; i<7; i++) count += (diff & 1<<i)?1:0;
			// printf("%d\n", count);
			cost[ix][i] = count;
				// k-=count;
				// printf("\n");
				// return i;
			// }
		}
	}
}

int max_num(int ix, int n, int k){
	if(max_dig[ix][k] != -2){
		return 1;
	}else if(ix==n-1){
		for(int i=9; i>=0; i--){
			max_dig[ix][cost[ix][i]] = i;
			return 1;
		}
		return -1;
	}else{
		for(int i=9; i>=0; i--){
			// if(max_dig[ix+1][k-cost[ix][i]]) max_dig[ix][k] = i;
			if(max_num(ix+1, k-cost[ix][i])){
				max_dig[ix][k] = i;
			}
		}
		return -1;
	}
}

int get_max(int ix, int n, int k){
	if(max_dig[ix][k] != -2){
		return 1;
	}
	else if(ix==n-1){
		for(int i=9; i>=0; i--){
			printf("ff %d %d %d\n", ix, i, cost[ix][i], k);
			if(cost[ix][i]==k){
				printf("came %d\n", cost[ix][i]);
				max_dig[ix][k] = i;
				return 1;
			}
		}
		return -1; 
	} else{
		int i=9;
		for(; i>=0; i--){
			// int temp;
			if(cost[ix][i]!=-1 && k-cost[ix][i]>=0 && k-cost[ix][i]>=max_off[ix+1]){
				// temp = ;
				printf("%d %d %d %d\n", ix, i, cost[ix][i], k);
				if(get_max(ix+1, n, k-cost[ix][i])!=-1){
					max_dig[ix][k] = i;
					// out[i] = i;
					printf("%d\n", max_dig[ix][k]);
					return 1;	
				}
			}
		}
	}
	// printf("\n");
	return -1;
}

int maxs(int n){
	int diff = 0b1111111 ^ n, count=0;
	for(int i=0; i<7; i++) count += (diff & 1<<i)?1:0;
	return count;
}

int main(){
	for(int i=0; i<2001; i++) {
		for(int ix=0; ix<2001; ix++) max_dig[i][ix] = -2;
	}
	// printf("%d\n", max_dig[1][200]);
	int n,k,temp;
	char temp_in[10];
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%s", temp_in);
		// printf("%ld\n", (int)strtol(temp_in, NULL, 2));
		in[i] = (int)strtol(temp_in, NULL, 2);
		//printf("gg %s %ld\n", temp_in, dig[1]);
	}
	// max_off[n-1] = maxs(in[n-1]);
	// max_off[n] = 0;
	// for(int i=n-2; i>=0; i--) max_off[i] = max_off[i+1] + maxs(in[i]);//, printf("%d\n", max_off[i]);
	for(int i=0; i<n; i++) check(in[i], i);
	// for(int i=0; i<n; i++){
	// 	for(int ix=0; ix<=9; ix++) printf("%d, ", cost[i][ix]);
	// 	printf("\n");
	// }
	if(get_max(0, n, k)!=-1){
		for(int i=0; i<n; i++){
			printf("%d", max_dig[i][k]);
			k -= cost[i][max_dig[i][k]];
		}
	}
	else printf("-1\n");
	// printf("\n");
	// printf("%d\n", in[0]);
}