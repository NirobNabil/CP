void merge_inplace(vector<int> &a, int s, int m, int e) {
	cerr << s << " " << m << " " << e << endl;
	vector<int> v;
	const int tm = m, ts = s;
	while(s < tm || m < e) {
		if(m < e && s < e && a[m] < a[s]) v.push_back(a[m]), m++;
		else if(s < tm) v.push_back(a[s]), s++;
		else v.push_back(a[m]), m++;
	}
	for(int i=ts; i<e; i++) a[i] = v[i-ts]; 
}

void merge_sort(vector<int> &a, int s, int e){
	if(s==e) return;
	merge_sort(a, s, (s+e)/2);
	merge_sort(a, (s+e)/2+1, e);
	merge_inplace(a, s, (s+e)/2 +1, e+1);
}