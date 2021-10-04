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

  //si*2 > n if si is a leaf node
  // if(ss>=rs && se<=re && si*2<n){
  //  lazy[si] += add;
  //  tree[si] += add;
  //   return;
  // }

  int mid = (ss+se)/2;
  update(a, tree, lazy, n, si*2, ss, mid, rs, re, add);
  update(a, tree, lazy, n, si*2+1, mid+1, se, rs, re, add);

  tree[si] = tree[si*2] + tree[si*2+1];
}

int query(vi &tree, vi &lazy, int n, int si, int ss, int se, int rs, int re){
  //cout << "Q ss: " << ss << " se: " << se << " rs: " << rs << " re: " << re << " si: " << si << "lazy[si] " << lazy[si] << endl;
  // printlazy(lazy, n);
  if(ss>re || se<rs || ss>se) return 0;
  if(ss==se) return tree[si];
  if(ss>=rs && se<=re) return tree[si];

  // if(lazy[si]){
  //  tree[si*2] = lazy[si];
  //  tree[si*2+1] = lazy[si];
  // }

  int mid = (ss+se)/2;
  return (
    query(tree, lazy, n, si*2, ss, mid, rs, re) 
    + query(tree, lazy, n, si*2+1, mid+1, se, rs, re)
  );
}
