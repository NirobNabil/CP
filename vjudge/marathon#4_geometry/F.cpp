#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
	// const double 2 = 1.41421356237;
	int i, ix, t, n;
	scanf("%d", &t);
	while(t--){
		long long int px=0, py=0, x,y;
		char c;
		long long int ans=0;
		// scanf("%c", &c);
		string s;
		cin >> s;
		if(s.size()<3) {
			printf("0\n");
			continue;
		}
		for(int i=0; i<s.size()-1; i++) {
			// cout << "c- " << px << "," << py << " -- ";
			int d = s[i]-'0';
			switch(d) {
				case 1: x = px-1; y = py-1; break;
				case 3: x = px+1; y = py-1; break;
				case 9: x = px+1; y = py+1; break;
				case 7: x = px-1; y = py+1; break;
				case 2: x = px; y = py-1; break;
				case 8: x = px; y = py+1; break;
				case 6: x = px+1; y = py; break;
				case 4: x = px-1; y = py; break;
			}
			ans += (px*y - x*py);
			px = x;  py = y;
			// printf("%lf, %lf\n", x,y);
		}
		ans = ans<0?-ans:ans;
		// ans += (0*y - x*0) / 2.0;

		// for(auto i:p) cout << i.x << ", " << i.y << "\n";
		if(ans%2==0) cout << ans/2 << "\n";
		else cout << ans/2 << ".5\n"; 
	}
	return 0;
}