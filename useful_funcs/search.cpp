int _lower_bound(vector<int> v, int l, int r, int x) {
	int mid = (r+l)/2;
	while(l!=r && l+1!=r) {
		printf("%d %d %d\n", l, v[mid], r);
		if(v[mid]>x) {
			r = mid;
		}else l = mid;
		mid = (r+l)/2;
	}
	if(v[r]==x) return r;
	else if(v[l]==x) return l;
	else return -1;
}

ll ternary(){
	ll m, h=n, l=0;
	double pc1, pc2;
	while(h!=l && h!=l+1) {
		m = l + (h-l)/2;
		pc1 = check(m);
		cout << n-m << " " << pc1 << " " << h << " " << l << endl;
		if(pc1 <= (double)n-m && pc1>=0) return m;
		if(pc1 > (double)n-m) l = m;
		else h = m;
	}
	if(h==l+1) {
		m = l;
		pc1 = check(m);
		// printf("%lld %lld %lld %lld\n", m, pc1, h, l);
		if(pc1 <= (double)n-m && pc1>=0) return m;
		pc2 = check(m+1);
		// printf("%lld %lld %lld %lld\n", m+1, pc2, h, l);
		if(pc2 <= (double)n-m-1 && pc2>=0) return m+1;
	}
	return -1;
}

// offline rmq
// We are given an array a[] and we have to compute some minima in given segments of the array.

// The idea to solve this problem with DSU is the following: We will iterate over the array and when we are at the ith element we will answer all queries (L, R) with R == i. To do this efficiently we will keep a DSU using the first i elements with the following structure: the parent of an element is the next smaller element to the right of it. Then using this structure the answer to a query will be the a[find_set(L)], the smallest number to the right of L.

// This approach obviously only works offline, i.e. if we know all queries beforehand.

// It is easy to see that we can apply path compression. And we can also use Union by rank, if we store the actual leader in an separate array.

struct Query {
    int L, R, idx;
};
void offline_rmq() {

	vector<int> answer;
	vector<vector<Query>> container;

	// container[i] contains all queries with R == i.

	stack<int> s;
	for (int i = 0; i < n; i++) {
	    while (!s.empty() && a[s.top()] > a[i]) {
	        parent[s.top()] = i;
	        s.pop();
	    }
	    s.push(i);
	    for (Query q : container[i]) {
	        answer[q.idx] = a[find_set(q.L)];
	    }
	}
}

