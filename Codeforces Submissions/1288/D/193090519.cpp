#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "stdio.h"

using namespace std;
using namespace __gnu_pbds;

// #define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ff first
#define ss second
#define sz(a) (a).size()
template<typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class C = null_type> using ordered_tree = tree<T, C, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long double ld;

namespace io{

    template<typename F, typename S> ostream& operator << ( ostream &os, const pair<F, S> &p ) { return os << p.ff << " " << p.ss; }
    template<typename F, typename S> ostream& operator << ( ostream &os, const map<F, S> &mp ) { for( auto it : mp ) { os << it << endl;  } return os; }
    template<typename F> ostream& operator << ( ostream &os, const vector<F> &v ) { bool space = false; for( F x : v ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename F> ostream& operator << ( ostream &os, const deque<F> &d ) { bool space = false; for( F x : d ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename F> ostream& operator << ( ostream &os, const set<F> &st ) { bool space = false; for( F x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename F> ostream& operator << ( ostream &os, const multiset<F> &st ) { bool space = false; for( F x : st ) { if( space ) os << " "; space = true; os << x; } return os; }

    template<typename F, typename S> istream& operator >> ( istream &is, pair<F, S> &p ) { return is >> p.ff >> p.ss; }
    template<typename F> istream& operator >> ( istream &is, vector<F> &v ) { for( F &x : v ) { is >> x; } return is; }

    long long fastread(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x; }

    static bool sep = false;

    using std::to_string;

    string to_string( bool x ){ return ( x ? "true" : "false" ); }
    string to_string( const string & s ){ return "\"" + s + "\""; }
    string to_string( const char * s ){ return "\"" + string( s ) + "\""; }
    string to_string ( const char & c ) { string s; s += c; return "\'" + s + "\'"; }

    template<typename Type> string to_string( vector<Type> );
    template<typename F, typename S> string to_string( pair<F, S> );
    template<typename Collection> string to_string( Collection );

    template<typename F, typename S> string to_string( pair<F, S> p ){ return "{" + to_string( p.ff ) + ", " + to_string( p.ss ) + "}"; }
    template<typename Type> string to_string( vector<Type> v ) { bool sep = false; string s = "["; for( Type x: v ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "]"; return s; }
    template<typename Collection> string to_string( Collection collection ) { bool sep = false; string s = "{"; for( auto x: collection ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "}"; return s; }

    void print() { cout << endl; sep = false; }
    template <typename F, typename... Other> void print( F ff, Other... other ) { if( sep ) cout << " | "; sep = true; cout << to_string( ff ); print( other... ); }

} using namespace io;

namespace utils {
    
    template<typename F, typename S> inline void maxs ( F &a, S b ) { a = a > b ? a : b; }
    template<typename F, typename S> inline void mins ( F &a, S b ) { a = a < b ? a : b; }
    template<typename F, typename S> int max(F a, S b) { return a > b ? a : b; }
    template<typename F, typename S> int min(F a, S b) { return a < b ? a : b; }

    constexpr long long operator"" _E ( unsigned long long n ){ long long p = 1, a = 10; for( int i = 0; i < n; i++ ) p *= a; return p; }

    random_device rd; mt19937 mt( rd( ) );
    template<typename T> T rand ( T l, T r ) { uniform_int_distribution<T> dist( l, r ); return dist( mt ); };

} using namespace utils;


#ifdef sunnitov
#define print( ... ) cout << "[" << #__VA_ARGS__ << "]: "; io::print( __VA_ARGS__ );
#else 
#define print( ... ) 42
#endif

int mod = 9_E + 7;
const double EPS = 1e-7;
long long LLINF = 18_E + 10;
int INF = 9_E + 10;
const char nl = '\n';

int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

/*

*/

int n, m, tar;
vector<vector<int>> a;;

bool ok(int mid) {
    vector<bool> can(tar + 1);
    vector<int> bit(n + 1);
    for (int i = 0; i < n; i++) {
        int pw = 1;
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= mid) {
                bit[i] += pw;
            }
            pw *= 2;
        }
        for (int j = 0; j <= tar; j++) {
            if ((j | bit[i]) == bit[i]) {
                can[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= tar; j++) {
            if (can[j] and (j | bit[i]) == tar) {
                return true;
            }
        }
    }
    return false;
}

void solution( istream &cin, ostream &cout, const int &test_case ){
    cin >> n >> m;
    tar = (1 << m) - 1;
    a.assign(n, vector<int>(m));
    cin >> a;
    int l = 0, r = 1e9 + 100, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    // cout << ans;
    vector<bool> can(tar + 1);
    vector<int> bit(n + 1);
    for (int i = 0; i < n; i++) {
        int pw = 1;
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= ans) {
                bit[i] += pw;
            }
            pw *= 2;
        }
        for (int j = 0; j <= tar; j++) {
            if ((j | bit[i]) == bit[i]) {
                can[j] = 1;
            }
        }
    }
    int ia, ij;
    for (int x1 = 0; x1 <= tar; x1++) {
        for (int x2 = 0; x2 <= tar; x2++) {
            if (!can[x1] or !can[x2] or (x1 | x2) != tar) continue;
            for (int i = 0; i < n; i++) {
                if ((bit[i] | x1) == bit[i]) ia = i;
                if ((bit[i] | x2) == bit[i]) ij = i;
            }
        }
    }
    cout << ia + 1 << " " << ij + 1;
}

int32_t main(){
    clock_t startTime = clock();
    ios_base::sync_with_stdio( false ); cin.tie( nullptr ); cout.tie( nullptr );
    srand( time( 0 ) );

    std::istream& in( std::cin ) ;
    std::ostream& out( std::cout );

    int32_t queries = 1;
    
    #ifdef test_cases
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    cin >> queries;
    #else
    // cin >> queries;
    #endif

    for( int32_t test_case = 1; test_case <= queries; test_case++ ){
    	print(test_case);
        solution( cin, cout, test_case );
        cout << nl;
    }

    #ifdef sunnitov
    cout << "Time: " << (int)((double) (clock() - startTime) / CLOCKS_PER_SEC * 1000) << " ms" << endl;
    #endif

    return EXIT_SUCCESS;

}