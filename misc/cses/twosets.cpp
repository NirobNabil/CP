#include "bits/stdc++.h"
using namespace std;
#define ll long long int

int main(){
    int t=1;
    int n;
    while(t--){
        scanf("%d", &n);
        // scanf("%s", &s);
        vector<int> ans1, ans2;
        if( (n%2==0 && (n/2)%2==0) || (n%2==1 && ((n-1)/2)%2==1)){
            printf("YES\n");
            if(n%2==1 && ((n-1)/2)%2==1) {
                ans2.push_back(n);
                n--;
            }
        }else {
            // printf("%d\n", (n-1)/2);
            printf("NO\n");
            continue;
        }
        int i=1;
        for(; i<=n/2; i++) {
            if(i%2==1) ans1.push_back(i);   
            else ans2.push_back(i);
        }
        for(; i<=n; i++) {
            if(i%2==1) ans2.push_back(i);   
            else ans1.push_back(i);
        }
        printf("%d ", ans1.size());
        for(auto i:ans1) printf("%d ", i);
        printf("\n");
        printf("%d ", ans2.size());
        for(auto i:ans2) printf("%d ", i);
        printf("\n");
    }
}