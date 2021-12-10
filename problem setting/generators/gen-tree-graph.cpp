#include "testlib.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int t = 90;

    cout << t << "\n";
    while(t--) {
        int n = rnd.next(1,35);
        int t = rnd.next();

        vector<int> p(n);
        forn(i, n)
            if (i > 0)
                p[i] = rnd.wnext(i, t);

        printf("%d %d\n", n, n-1);
        vector<int> perm(n);
        forn(i, n)
            perm[i] = i;
        shuffle(perm.begin() + 1, perm.end());
        vector<pair<int,int> > edges;

        for (int i = 1; i < n; i++)
            if (rnd.next(2))
                edges.push_back(make_pair(perm[i], perm[p[i]]));
            else
                edges.push_back(make_pair(perm[p[i]], perm[i]));

        shuffle(edges.begin(), edges.end());

        for (int i = 0; i + 1 < n; i++)
            printf("%d %d %.0f\n", edges[i].first + 1, edges[i].second + 1, floor(rnd.next()*1000));

    }

    return 0;
}
