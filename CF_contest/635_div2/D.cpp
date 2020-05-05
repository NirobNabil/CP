#include <bits/stdc++.h>
using namespace std;
#define MIN(a,b) ((a>b)?b:a)
#define DIFF(a, b) ((a-b)*(a-b))
#define D(a,b) ((a>b)?a-b:b-a)
#define ll long long int

int t, i, nr, ng, nb, xd;
long long int temp, minx;
set<ll>::iterator tgl, tbl, trl, tgu, tbu, tru, tge, tbe, tre;

void setMin(set<ll> &rs, set<ll> &gs, set<ll> &bs){
	for(auto it = rs.begin(); it != rs.end(); it++){
		//printf("loop %d\n", xxx++);
		vector<set<ll>::iterator> tgs, tbs;
		trl = it;
		tge = gs.end();
		tbe = bs.end();

		tgl = (*(--gs.end()) < *trl)?(--gs.end()):gs.lower_bound(*trl);
		xd=3;
		if((++tgl)--!=tge) tgs.push_back((++tgl)--);
		while(xd-- && tgl!=tge) tgs.push_back(tgl--);
		
		tbl = (*(--bs.end()) < *trl)?(--bs.end()):bs.lower_bound(*trl);
		xd=3;
		if((++tbl)--!=tbe) tbs.push_back((++tbl)--);
		while(xd-- && tbl!=tbe) tbs.push_back(tbl--);

		for(auto ix : tgs) for(auto iy : tbs) minx = MIN((DIFF(*trl, *ix)+DIFF(*trl, *iy)+DIFF(*ix, *iy)), minx);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		minx=LLONG_MAX;
		set<ll> rs,gs,bs;
		scanf("%d %d %d", &nr, &ng, &nb);
		for(i=0; i<nr; i++) scanf("%lld", &temp), rs.insert(temp);
		for(i=0; i<ng; i++) scanf("%lld", &temp), gs.insert(temp);
		for(i=0; i<nb; i++) scanf("%lld", &temp), bs.insert(temp);

		setMin(rs, gs, bs);
		setMin(gs, rs, bs);
		setMin(bs, rs, gs);
		printf("%lld\n", minx);
	}
}



/*
qsort(nrs, nr, sizeof(int), compare);
		qsort(ngs, ng, sizeof(int), compare);
		qsort(nbs, nb, sizeof(int), compare);
		int lnr=0, lng=0, lnb=0, min=1000000000, ldiff1=1000000000, ldiff2=1000000000;
		for(;lnr<nr; lnr++){
			for(;lng<ng && D(ngs[lng], nrs[lnr])<=ldiff1; lnr++){
				ldiff1 = D(ngs[lng], nrs[lnr]);
				for(;lnb<nb && D(nbs[lnb], ngs[lng])<=ldiff2;){
					ldiff2 = D(nbs[lnb], ngs[lng]);
					min = MIN((ldiff1*ldiff1 + ldiff2*ldiff2 + DIFF(nrs[lnr], nbs[lnb]) ), min);
					if(lnb+1<nb) min = MIN((ldiff1*ldiff1 + DIFF(ngs[lng], nbs[lnb+1]) + DIFF(nbs[lnb+1], nrs[lnr]) ), min);
					if(lnb+1<nb && lng+1<ng)min = MIN((DIFF(nrs[lnr], ngs[lng+1]) + DIFF(ngs[lng+1], nbs[lnb+1]) + DIFF(nbs[lnb+1], nrs[lnr]) ), min);
					if(lnb+2<nb && lng+1<ng)min = MIN((DIFF(nrs[lnr], ngs[lng+1]) + DIFF(ngs[lng+1], nbs[lnb+2]) + DIFF(nbs[lnb+2], nrs[lnr]) ), min);
					if(lnb+1<nb && D(nbs[lnb+1], ngs[lng])<=ldiff2) lnb++;
					else break;
				}
				if(lng+1<ng && D(ngs[lng+1], nrs[lnr])<=ldiff1) lng++;
				else break;
			}
		}
*/