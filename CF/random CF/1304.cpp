#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> pp;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, temp, time=0;
		bool possible = true;
		vector <pp> customers(n);
		cin >> n >> temp;
		for(int i=0; i<n; i++){
			int time, start, end;
			cin >> time >> start >> end;
			customers.push_back(make_pair(time, make_pair(start, end)));
		}
		for(int i=0; i<n && possible; i++){
			int ctime=customers[i].first, ctempS=customers[i].second.first, ctempE=customers[i].second.second;
			if((temp < ctempS && ctime-time<ctempS-temp) || (temp > ctempE && ctime-time<temp-ctempE))
			if(temp < ctempS && ctempS-temp <= ctime-time) temp=ctempS;
			if(temp > ctempE && temp-ctempE <= ctime-time) temp=ctempE;
		}
	}
}