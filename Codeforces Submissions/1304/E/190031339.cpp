#pragma GCC target("arch=skylake")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef tree< ll , null_type , less < ll > , rb_tree_tag , tree_order_statistics_node_update > ordered_set;


#define pii pair < int , int >
#define pll pair< ll , ll >
#define pb push_back
#define S second
#define F first
#define sz(x) int32_t(x.size())
#define int ll
#define itn ll

const ll N = 5e5 + 123;
const ll mod = 998244353;
const ll INF = 1e18;
const ld eps = 5e-11;

vector< int > g[N];
int tin[N] , tout[N];
int up[N][30];
int t , h[N] , H;

void dfs( int v , int pr = 1 )
{
    cerr << v << '\n';
    H ++;
    h[v] = H;
	tin[v] = ++ t;
	up[v][0] = pr;
	for( int i = 1;i <= 22;++ i )
    {
//        cerr << i << '\n';
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
//    cerr << v << '\n';
	for( auto to : g[v] )
    {
		if( to != pr )
        {
            dfs( to , v );
        }
	}
	tout[v] = ++ t;
	-- H;
}

bool upper( int a , int b )
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca( int a , int b )
{
	if( upper( a , b ) )
    {
        return a;
    }
	if( upper( b , a ) )
    {
        return b;
    }
	for( int i = 22;i >= 0;-- i )
	{
	    if ( !upper( up[a][i] , b ) )
        {
            a = up[a][i];
        }
	}
	return up[a][0];
}

int len( int v , int u )
{
    int lc = lca( v , u );

//    cout << v << ' ' << u << ' ' << lc << '\n';
//
//    cout << h[v] << ' ' << h[u] << ' ' << h[lc] << "\n\n";

    return h[v] + h[u] - 2 * h[lc];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen("lca.in", "r", stdin);
//        freopen("lca.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    for( int i = 0;i < n - 1;++ i )
    {
        int v , u;
        cin >> v >> u;

        g[v].pb( u );
        g[u].pb( v );
    }

    dfs( 1 );

    int q;
    cin >> q;

    while( q -- )
    {
        int x , y , a , b , k;
        cin >> x >> y >> a >> b >> k;

        bool f = 0;

        int l1 = len( a , b );
        int l2 = len( a , x ) + 1 + len( b , y );
        int l3 = len( b , x ) + 1 + len( a , y );

//        cout << l1 << ' ' << l2 << ' ' << l3 << '\n';
        if( ( l1 <= k && l1 % 2 == k % 2 ) || ( l2 <= k && l2 % 2 == k % 2 )  || ( l3 <= k && l3 % 2 == k % 2 ) )
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }



}
