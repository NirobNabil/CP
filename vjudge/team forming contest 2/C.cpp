#include<bits/stdc++.h>
using namespace std;

#define eps 1e-5

int main(){
	while(1){
		double l, w;
		cin>>l>>w;
		if(l==0 && w==0){
			break;
		}
		double left=l/2.0-l/4.0, right=l/2.0;
		double ans=l+w;

		while(abs(left-right)>eps){
			double mid=(left+right)/2.0;
			double y=(l*l)-2.0*l*mid;
			y=sqrt(y);
			double kans=l-mid+w-y+l-mid;
			
			if(ans>kans){
				ans=kans;
				right=mid;
			}
			else left=mid;
			//cout << left << " " << right << endl;		
		}
		std::cout << std::fixed << std::showpoint;
		cout << setprecision(4);
		cout<<ans<<"\n";
	}
}