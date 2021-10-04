#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#ifdef RUBICK
#include "dbg.h"
#else
#define dbg(exp) {/* nop; */}
#endif

// F cin/cout
#define cin nullptr
#define cout nullptr

#define MONKE 0

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;

int main() {
    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc ++) {
        double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        double r1 = a * b + c * d + 0.5 * min(a, c) * abs(b - d);
        double r2 = a * b + c * d + 0.5 * min(a, d) * abs(b - c);
        double r3 = a * b + c * d + 0.5 * min(b, c) * abs(a - d);
        double r4 = a * b + c * d + 0.5 * min(b, d) * abs(a - c);

        printf("Case %d: %.020lf\n", tc, min({r1, r2, r3, r4}));
    }

    return MONKE;
}