#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define X first
#define Y second
#define A begin
#define B end
#define S1 100009
#define vi vector<int>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

vector<int> tree(S1*4), lazy(S1*4);

// void print(vi &tree, int n){
//   for(int x=0; x<3; x++){
//     for (int i=0; i<n*2; i++){
//       cout << tree[i][x] << " ";
//       if(i==n-1) cout << "    ";
//     }
//     cout << endl;
//   }
// }

void update_lazy(vector<int> &lazy, int si, int ss, int mid, int se) {
	lazy[si] = 0;

 	lazy[si*2] = !lazy[si*2];
 	lazy[si*2+1] = !lazy[si*2+1];
 	
 	tree[si*2] = mid-ss+1 - tree[si*2];
 	tree[si*2+1] = se-mid - tree[si*2+1];
}

void printlazy(vi &tree, int n){
  for (int i=0; i<n*2; i++){
    cout << lazy[i] << " ";
    if(i==n-1) cout << "    ";
  }
  cout << endl;
}

void build(vi &a, vi &tree, int si, int ss, int se){
  //cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " lazy[si] " << lazy[si] << endl;
  if(ss==se){
    tree[si] = a[ss];
    return;
  }

  int mid = (ss+se)/2;
  build(a, tree, si*2, ss, mid);
  build(a, tree, si*2+1, mid+1, se);

  tree[si] = tree[si*2] + tree[si*2+1];
}

void update(vi &tree, vi &lazy, int n, int si, int ss, int se, int rs, int re){
  // cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " l:" << lazy[si] << endl;
  if(ss > se || rs > se || re < ss) return;
  if(ss==se){
    tree[si] = !tree[si];
	  // cout << "ve: " << tree[si] << endl;
    return;
  }

  //si*2 > n if si is a leaf node
  if(ss>=rs && se<=re && si*2<=n){
   	lazy[si] = !lazy[si];
   	tree[si] = se-ss+1 - tree[si];
	  // cout << "vl: " << tree[si] << endl;
   	return;
  }

  int mid = (ss+se)/2;

  if(lazy[si])
  	update_lazy(lazy, si, ss, mid, se);
  // cout << "vm: " << tree[si] << endl;

  update(tree, lazy, n, si*2, ss, mid, rs, re);
  update(tree, lazy, n, si*2+1, mid+1, se, rs, re);

  tree[si] = tree[si*2] + tree[si*2+1];
}

int query(vi &tree, vi &lazy, int n, int si, int ss, int se, int rs, int re){
  // cout << "Q ss: " << ss << " se: " << se << " v: " << tree[si] << " si: " << si << "l " << lazy[si] << endl;
  // printlazy(lazy, n);
  if(ss>re || se<rs || ss>se) return -1;
  if(ss==se) return tree[si];
  // if(rs>=ss && re<=se) {
	if(tree[si]==se-ss+1) return 1;
	if(tree[si]==0) return 0;
  // }

  int mid = (ss+se)/2; 
  
  if(lazy[si]){
	  update_lazy(lazy, si, ss, mid, se);
  }

  int ans = query(tree, lazy, n, si*2, ss, mid, rs, re);
  
  if(ans == -1)
  	ans = query(tree, lazy, n, si*2+1, mid+1, se, rs, re);
  
  return ans;
}


int main(){
	int i, ix, t, n, q, j, v;
	vector<int> a(S1);
	cin >> t;
	for(int tc=1; tc<=t; tc++) { 
		fill(tree.A(), tree.B(), 0);
		fill(lazy.A(), lazy.B(), 0);
		string s;
		cin >> s;
		n = s.size();
		rep(i, 1, n+1) a[i] = s[i-1]-'0';
		cin >> q;

		build(a, tree, 1, 1, n);
		char c;
		cout << "Case " << tc << ":\n";

		while(q--) {
			cin >> c;
			if(c=='I') {
				cin >> i >> j;
				update( tree, lazy, n, 1, 1, n, i, j);
			}else {
				cin >> i;
				cout << query(tree, lazy, n, 1, 1, n, i, i) << "\n";
			}

		} 
	}
}