#include <bits/stdc++.h>
#define pb push_back
#define sz 100000005
#define mod1 1000000016000000063
#define mod 1000000007
#define mod3 4294967296
#define base 3181



using namespace std;
typedef long long unsigned ll;


vector<ll>prime,mul;
ll a[sz/64 +100];


void seive()
{
    ll i,j;

    for (i = 3; (i*i)<=sz; i += 2) {
		if(!(a[i/64]&(1LL<<(i%64)))) {
			for(j = i * i; j <= sz; j += 2 * i) {
				a[j/64] |= (1LL<<(j%64));
			}
		}
	}
    prime.pb(2);
    for(i=3; i<=sz; i+=2)
    {
        if(!(a[i / 64] & (1LL << (i % 64)))) prime.pb(i);
    }
    mul.pb(2);
    for(i=1; i<prime.size(); i++)
    {
        mul.pb((prime[i]*mul[i-1])%mod3);
//        cout<<mul[i]<<endl;
//        cout<<i<<' '<<mul[i-1]<<" "<<prime[i]<<endl;
//        cout<<i-1<<" "<<mul[i-1]<<endl;
    }
}


ll bsearch(ll num)
{
    ll lo=0,hi=prime.size()-1,mid,ret=0ll;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(prime[mid]<=num)
        {
            ret=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return ret;
}


int main()
{
    ll t,t1;
    cin>>t;
    //seive();
    return 0;
    for(t1=1; t1<=t; t1++)
    {
        ll i,j,k,l,n,ans=1ll;
        cin>>n;

        j=bsearch(n);
        ans*=mul[j];
        //cout<<ans<<endl;

        for(i=0; (prime[i]*prime[i])<=n; i++)
        {
            ll num=n;
            num/=prime[i];
            while(num>=prime[i])
            {
                num/=prime[i];
                ans*=prime[i];
                ans%=mod3;
            }
        }

        cout<<"Case "<<t1<<": "<<ans<<endl;
    }
}
