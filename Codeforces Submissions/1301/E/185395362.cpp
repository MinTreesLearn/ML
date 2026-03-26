#include<iostream>
#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
using L = __int128;
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
template<class container>
void print(container v) { for (auto& it : v) cout << it << ' ' ;cout <<endl;}
//template <class Type1 , class Type2>
ll fp(ll a , ll p){ if(!p) return 1; ll v = fp(a , p/2); v*=v;return p & 1 ? v*a : v;  }
ll inf = 1e9 , mod= 1e9+7;//998244353;//
template <typename T> using ordered_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
const int N = 500 +20 ,LOG = 10;
ll mul (ll a, ll b){
    return ( ( a % mod ) * ( b % mod ) ) % mod;
}
ll add (ll a , ll b){
    return (a + b + mod) % mod;
}
int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& a) {

}

template< typename  T > using min_heap = priority_queue <T , vector <T >  , greater < T > > ;
// m n

ll n , m;
int pref [4][N][N];
int mx[N][N];
int table[N][LOG][N][LOG];
int Log[N];
ll merge (ll u ,ll v){
    return max(u , v);
}
void build(){// zero based

    // rows - power of rows && cols - power of cols
    for (int i = 2; i <= max(n , m); ++i) Log[i] = Log[i >> 1] +1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            table[i][0][j][0] = mx[i][j];

    for (int i = 0; i < n; ++i)
        for (int l = 1; l < LOG; ++l)
            for (int j = 0; j + (1 << l)-1 < m; ++j)
                table[i][0][j][l] = merge(table[i][0][j][l-1] , table[i][0][j + (1 << (l-1))][l-1]);

    for (int k = 1; k < LOG; ++k)
        for (int i = 0; i + (1 << k)-1 < n; ++i)
            for (int l = 0; l < LOG; ++l)
                for (int j = 0; j + (1 << l)-1 < m; ++j)
                    table[i][k][j][l] = merge(table[i][k-1][j][l] , table[i+ (1 << (k-1))][k-1][j][l]);

}

ll query(ll x1 , ll y1 , ll x2 , ll y2){// zero based
    if (x1 > x2 || y1 > y2 || min({x1 , x2 , y1 , y2}) <0 || max(x1 , x2) >= n || max(y1 , y2) >= m) return 0;
    assert(x1 >=0 && x1 <n);  assert(y1 >=0 && y1 < m);
    assert(x2 >=0 && x2 < n &&x2 >= x1);assert(y2 >=0 &&y2 < m && y2 >= y1);
    ll lx = Log[x2-x1+1]; ll ly = Log[y2-y1+1];
    ll prob1 = merge(table[x1][lx][y1][ly] , table[x1][lx][1 + y2- (1 << ly)][ly]);
    ll prob2 = merge(table[1 + x2 -(1<< lx)][lx][y1][ly] , table[1 +x2 - (1 << lx)][lx][1 + y2- (1 << ly)][ly]);
   // cout <<lx<<" "<<ly <<" "<<prob1 <<" "<<prob2 <<" "<<x1<<" "<<y1 <<" "<<x2<<" "<<y2 << nd;
    return merge(prob1 , prob2);
}
//vector <vector <vector <int > > > pref;
vector<string > s;
void build_prefix (char c , int t){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char in = s[i-1][j-1];
            pref[t][i][j]+= (in == c);
            pref[t][i][j]+= pref[t][i-1][j];
            pref[t][i][j]+= pref[t][i][j-1];
            pref[t][i][j]-=pref[t][i-1][j-1];
        }
    }
}

ll get (ll x1 , ll y1 , ll x2 , ll y2 , int t ){
    ++x1 , ++y1 , ++x2 , ++y2;
    assert(x1 >=1 && x1 <=n);  assert(y1 >=1 && y1 <=m);
    assert(x2 >=1 && x2 <= n &&x2 >= x1);assert(y2 >=1 &&y2 <= m && y2 >= y1);
    return pref[t][x2][y2]- pref[t][x2][y1-1] - pref[t][x1-1][y2] +pref[t][x1-1][y1-1];
}
void main_(int tc){
    int q;
    cin >> n >> m >> q;
    s = vector<string  > (n);
    for (auto &i : s) cin >> i;
    build_prefix('R' , 0);build_prefix('G' , 1);build_prefix('Y' , 2);build_prefix('B' , 3);
    for (int i = 0;i < n; ++i){
        for (int j = 0; j < m; ++j){

            for (int k = 1;  min(i , j)-k +1 >= 0 && i+k < n && j+k < m; ++k){
                if (get(i-k+1 , j-k+1 , i , j , 0) != k * k) break;
                if (get(i-k+1 , j+1 , i , j+k , 1) != k *k) break;
                if (get(i+1 , j-k+1 , i+k , j , 2) != k *k) break;
                if (get(i+1 , j+1 , i+k , j+k , 3) != k * k) break;
                mx[i][j] = k;
            }

        }
    }
    build();

    while (q--){
        int r1 , r2 , c1 , c2;
        cin >> r1 >> c1 >> r2 >> c2; --r1 , --r2 , --c1 , --c2;
        ll s = 0 , e = n; ll ans = 0;
        while (s<= e){
            ll m = s + e >> 1;
            ll nr1 = r1+m -1 , nc1 = c1 + m-1;
            ll nr2 = r2-m; ll nc2 = c2-m;
            if (query(nr1 , nc1 , nr2 , nc2) >= m) {
                ans = m; s = m+1;
            }
            else e = m-1;
        }
        cout << 4 * ans * ans <<nd;
    }



}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    //the_best_is_still_yet_to_come();
    //freopen("red2.in ","r",stdin);//  freopen("output.txt","w",stdout);
    int tt = 1 , tc = 0;
  // cin>>tt;
    while(tt--) main_(++tc);
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
    return 0;
}