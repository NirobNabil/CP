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

void build(vi &a, vi &tree, int si, int ss, int se){
  //cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << " lazy[si] " << lazy[si] << endl;
  if(ss==se){
    tree[si] += a[ss];
    return;
  }

  int mid = (ss+se)/2;
  build(a, tree, si*2, ss, mid);
  build(a, tree, si*2+1, mid+1, se);

  tree[si] = tree[si*2] + tree[si*2+1];
}

void update(vi &a, vi &tree, vi &lazy, int n, int si, int ss, int se, int rs, int re, int add){
  // cout << "U ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << endl;
  if(ss > se || rs > se || re < ss) return;
  if(ss==se){
    tree[si] += add;
    a[ss] += add;
    return;
  }

  int mid = (ss+se)/2;
  update(a, tree, lazy, n, si*2, ss, mid, rs, re, add);
  update(a, tree, lazy, n, si*2+1, mid+1, se, rs, re, add);

  tree[si] = tree[si*2] + tree[si*2+1];
}

int query(vi &tree, vi &lazy, int n, int si, int ss, int se, int rs, int re){
  //cout << "Q ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << "lazy[si] " << lazy[si] << endl;
  if(ss>re || se<rs || ss>se) return 0;
  if(ss==se) return tree[si];
  if(ss>=rs && se<=re) return tree[si];

  int mid = (ss+se)/2;
  return (
  	query(tree, lazy, n, si*2, ss, mid, rs, re) 
  	+ query(tree, lazy, n, si*2+1, mid+1, se, rs, re)
  );
}

int main(){
	int i, ix, t, n, q;
	vector<int> a(S1);
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++) { 
		fill(tree.A(), tree.B(), 0);
		scanf("%d %d", &n, &q);
		rep(i, 1, n+1) scanf("%d", &a[i]);
		build(a, tree, 1, 1, n);
		int c, i, j, v;
		printf("Case %d:\n", tc);
		while(q--) {
			scanf("%d", &c);
			if(c==1) {
				scanf("%d", &i);
				printf("%d\n", a[i+1]);
				update(a, tree, lazy, n, 1, 1, n, i+1, i+1, -a[i+1]);
			}else if(c==2) {
				scanf("%d %d", &i, &v);
				update(a, tree, lazy, n, 1, 1, n, i+1, i+1, v);
			}else {
				scanf("%d %d", &i, &j);
				printf("%d\n", query(tree, lazy, n, 1, 1, n, i+1, j+1));
			}

			// printf("c- %d\n", c);
			// for(int i=1; i<=n; i++) printf("%d ", a[i]);
			// printf("\n");
		} 
	}
}