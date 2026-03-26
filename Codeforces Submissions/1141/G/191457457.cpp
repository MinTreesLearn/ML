#include<iostream>
#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
//using L = __int128;
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define nd "\n"
#define all(x) (x).begin(), (x).end()
#define lol cout <<"i am here"<<nd;
#define py cout <<"YES"<<nd;
#define pp  cout <<"ppppppppppppppppp"<<nd;
#define pn cout <<"NO"<<nd;
#define popcount(x)  __builtin_popcount(x)
#define clz(n) __builtin_clz(n)//31 -x
const  double PI = acos(-1.0);
double EPS = 1e-9;
#define print2(x , y) cout <<x<<' '<<y<<nd;
#define print3(x , y , z) cout <<x<<' '<<y<<' '<<z<<nd;
#define watch(x) cout << (#x) << " = " << x << nd;
const ll N = 2e5+500 , LOG = 22 , inf = 1e8 , SQ= 550 , mod= 1e9+7;//998244353;
template<class container> void print(container v) { for (auto& it : v) cout << it << ' ' ;cout <<endl;}
//template <class Type1 , class Type2>
ll fp(ll a , ll p){ if(!p) return 1; ll v = fp(a , p/2); v*=v;return p & 1 ? v*a : v;  }

template <typename T> using ordered_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

ll mul (ll a, ll b){
    return ( ( a % mod ) * ( b % mod ) ) % mod;
}
ll add (ll a , ll b) {
    return (a + b + mod) % mod;
}

template< typename  T > using min_heap = priority_queue <T , vector <T >  , greater < T > > ;
vector < vector <pair <int , int > > > g;
vector <int > ans(N);
ll dfs(int node , int par , int mx , int prv){
    ll ret = 0;
    ret+= ((int)g[node].size() > mx);
    ll c = 1;
    for (auto &ch : g[node]){
        if (par == ch.first) continue;
        c+=(prv == c); if (c > mx) c = 1;
        ans[ch.second] = c;
        ret+= dfs(ch.first , node , mx , c);
        c++;  if (c > mx) c = 1;
    }
    return ret;
}
void hi(int tc) {
    ll n , k; cin >>n >> k;
    g = vector < vector <pair <int , int > > > (n+5);
    for (int u , v ,i = 1; i < n; ++i){
        cin >> u >> v;
        g[u].emplace_back(v , i);
        g[v].emplace_back(u , i);
    }
    ll st = 1 , end = n-1;
    while(st <= end){
        ll mid = st + end >> 1;
        ll ret = dfs(1 , 1 , mid ,-1);
        if (ret <= k) end = mid-1;
        else st = mid +1;
    }
    dfs(1 , 1 , st , -1);
    cout << st <<nd;
    for (int i = 1; i < n; ++i)
        cout << ans[i] <<" ";


}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int tt = 1 , tc = 0;
  //cin >> tt;
    while(tt--) hi(++tc);
    return 0;
}
/*
 * greedy
 * if k == 0 thw answer is equal to the maximum degree of a vertex
 * cuz if it was less/ then there at least two edges out of me with the same color
 */
