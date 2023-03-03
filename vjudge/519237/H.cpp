

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vv vector<int>
#define pp pair<int,int>
#define pb(x) push_back(x)
#define in(x) insert(x)
#define del(x) erase(x)
#define emp(x) emplace_back(x)
#define mt make_tuple
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef MONKE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


pp dir[] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
int r, c;

void print( map<int, map<int,char> > nmap ) {
    for( int ir=0; ir<r; ir++) {
        for( int ic=0; ic<c; ic++ ) {
             cerr << nmap[ir][ic] << " ";
        }
        cerr << "\n";
    }
}

void print( unordered_map<int, unordered_map<int,int> > nmap ) {
    for( int ir=0; ir<r; ir++) {
        for( int ic=0; ic<c; ic++ ) {
             cerr << nmap[ir][ic] << " ";
        }
        cerr << "\n";
    }
}

char str[210];

void bfs(int tc) {

//     unordered_map<int, unordered_map<int, char> > mmap;
//     unordered_map<int, unordered_map<int, int> > nmap, tmap;
    vector<pp> fires;
    pp init = {-1,-1};
    int MX = 100;
    
    scanf("%d %d", &r, &c);
//     cin >> r >> c;
    vector< vector<char> > mmap( r, vector<char>(c) );
    vector< vector<int> > nmap( r, vector<int>(c) ), tmap( r, vector<int>(c) );
//     debug( r, c );
    char x;
    for( int ir=0; ir<r; ir++) {
        scanf("%s", str);
        for( int ic=0; ic<c; ic++ ) {
//             scanf("%c", &x);
            x = str[ic];
            mmap[ir][ic] = x;
            nmap[ir][ic] = MX;
            tmap[ir][ic] = MX;
            if( x == 'F' ) fires.push_back({ir,ic}), nmap[ir][ic] = 0;
            else if( x == 'J' ) init = {ir,ic}, tmap[ir][ic] = 0;
        }
    }


//     debug( r, c );
//     print( mmap ); 


    for( int i=0; i<fires.size(); i++ ){
        pp cur = fires[i];
        deque<pp> q;
        q.push_back(cur);
        unordered_map< int, unordered_map< int, int > > vis;
        while( !q.empty() ) {
//             debug(q);
            cur = q.front();
            vis[cur.X][cur.Y] = true;
            q.pop_front();
            for( int id=0; id<4; id++ ) {
                pp ncur = { cur.X+dir[id].X, cur.Y+dir[id].Y }; 
                if( ncur.X >= r || ncur.Y >= c || ncur.X < 0 || ncur.Y <0 ) continue;
                if( mmap[ncur.X][ncur.Y] != '#' && nmap[ncur.X][ncur.Y] > nmap[cur.X][cur.Y] + 1 ) {
                    nmap[ncur.X][ncur.Y] = nmap[cur.X][cur.Y]+1;
                    q.push_back(ncur);
                }
            }
//             print( vis );
        }
    }

//     print( nmap );

    int pos = -1;
    pp cur = init;
    deque<pp> q;
    q.push_back(cur);
    while( !q.empty() && pos == -1 ) {
        cur = q.front();
        q.pop_front();
        for( int id=0; id<4; id++ ) {
            pp ncur = { cur.X+dir[id].X, cur.Y+dir[id].Y }; 
            if( ncur.X >= r || ncur.Y >= c || ncur.X < 0 || ncur.Y < 0 ) {
                pos = tmap[cur.X][cur.Y] + 1;
                break;
            };
            if( mmap[ncur.X][ncur.Y] != '#' && tmap[ncur.X][ncur.Y] > tmap[cur.X][cur.Y]+1 && nmap[ncur.X][ncur.Y] > tmap[cur.X][cur.Y]+1 ) {
                tmap[ncur.X][ncur.Y] = tmap[cur.X][cur.Y] + 1;
                q.push_back(ncur);
            }
        }
    } 
//     print( tmap );

    if( pos != -1 ) {
        printf("Case %d: %d\n", tc, pos );
//         cout << "Case " << tc << ": " << pos << "\n";
    } else {
        printf("Case %d: IMPOSSIBLE\n", tc);
//         cout << "Case " << tc << ": IMPOSSIBLE\n";
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, ix, t, n, m, k, p, q, gg, x, y, z;
//     cin >> t;
    scanf("%d", &t);
    for( int tc=1; tc<=t; tc++ ){
        bfs( tc );
    }

    return 0;
}

