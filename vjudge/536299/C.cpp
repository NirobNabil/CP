#include<bits/stdc++.h>
#define PB push_back
#define mod 1000000007
#define sz 2000


using namespace std;
typedef long long ll;


vector<int>prime;
int dp[400][sz][20];


void init()
{
    int i,j,k;
    for(i=0; i<400; i++)
    {
        for(j=0; j<sz; j++)
        {
            for(k=0; k<20; k++) dp[i][j][k]=-1;
        }
    }
}


void Getpirme()
{
    int i,j,k,l;
    int ar[sz]= {0};

    for(i=3; (i*i)<=sz; i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i; j<sz; j+=(2*i))
            {
                ar[j]=1;
            }
        }
    }

    prime.push_back(2);
    for(i=3; i<sz; i+=2)
    {
        if(ar[i]==0)
        {
            prime.push_back(i);
        }
    }
}


int DP(int pos,int rem,int cnt)
{
    if(rem==0)
    {
        if(cnt==0) return 1;
        else return 0;
    }
    if(cnt<0 || rem<prime[pos]) return 0;
    if(dp[pos][rem][cnt]!=-1) return dp[pos][rem][cnt];

    dp[pos][rem][cnt] = DP(pos+1,rem-prime[pos],cnt-1)+DP(pos+1,rem,cnt);
    return dp[pos][rem][cnt];
}


int main()
{
    Getpirme();
    int n,k;
    scanf("%d %d",&n,&k);

    while(n || k)
    {
        init();
        int ans = DP(0,n,k);
        printf("%d\n",ans);
        scanf("%d %d",&n,&k);
    }

    return 0;
}
