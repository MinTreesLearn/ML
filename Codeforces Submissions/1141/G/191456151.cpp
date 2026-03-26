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
vector <int > dep(N);
void dfs(int node , int par){
    for (auto &ch : g[node]){
        if (par == ch.first) continue;
        dep[ch.first] = 1 + dep[node];
        dfs(ch.first , node);
    }
}
void hi(int tc) {
    ll n , k; cin >>n >> k;
    g = vector < vector <pair <int , int > > > (n+5);
    for (int u , v ,i = 1; i < n; ++i){
        cin >> u >> v;
        g[u].emplace_back(v , i);
        g[v].emplace_back(u , i);
    }
    vector <pair <int , int > > bad;
    for (int i = 1; i <= n; ++i) bad.emplace_back((int)g[i].size() , i);

    sort(all(bad) , [&](pair <int , int > & a , pair <int , int > & b) {
        return a.first > b.first;
    });
    dfs(1 , 1);
    cout << bad[k].first <<nd;
    int u = bad[k].first;
    vector <pair <int , int > > order;
    vector <int > col(n+5 , -1);
   // for (int i = 0; i < k; ++i)
       // for (auto &ch : g[bad[i].second])
            //col[ch.second] = 1;
    for (int i = k; i < n; ++i)order.emplace_back(dep[bad[i].second] , bad[i].second);
    sort(all(order));

    for (auto &p : order){
        int node = p.second;
        set <int > st;
      //  cout << node <<" "<<p.first <<" "<<(int)g[node].size()<< nd;
        for (int i = 1; i <= (int)g[node].size(); ++i) st.emplace(i);
        for (auto &ch : g[node]) st.erase(col[ch.second]);

        for (auto &ch : g[node]){
            if (col[ch.second] != -1) continue;
            col[ch.second] = *st.begin();
            st.erase(st.begin());
        }
    }
    for (int i = 1; i < n; ++i){
        if (col[i] == -1) col[i] = 1;
        cout << col[i] <<" ";
    }


    


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
