#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#ifdef RUBICK
#include "dbg.h"
#else
#define dbg(exp) {/* nop; */}
#endif

#define MONKE 0

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;

map<pair<string, int>, set<int> > left_most;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;

        set<int> avail;
        for(int i=0; i<n; i++) avail.insert(i);

        while (m--) {
            string piece;
            cin >> piece;

            if (avail.size() == 0) 
                continue;

            if (left_most[{piece, 3}].size() > 0)
                continue;

            left_most[{piece, 1}].insert(*avail.begin());
            avail.erase(avail.begin());


            if (left_most[{piece, 1}].size() == k) {
                left_most[{piece, 2}].insert(*left_most[{piece, 1}].begin());
                
                for(auto it=++avail.begin(); it!=avail.end(); it++) 
                    avail.insert(i);
                left_most[{piece, 1}].clear();
            }

            if (left_most[{piece, 2}].size() == k) {
                left_most[{piece, 2}].insert(*left_most[{piece, 1}].begin());
                
                for(auto it=++avail.begin(); it!=avail.end(); it++) 
                    avail.insert(i);
                left_most[{piece, 1}].clear();
            }

        }
    }

    return MONKE;
}