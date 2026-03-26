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
ll inf = 1e9+5 , mod= 1e9+7;//998244353;//
template <typename T> using ordered_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
const int N = 1e6,LOG = 12;
ll mul (ll a, ll b){
    return ( ( a % mod ) * ( b % mod ) ) % mod;
}
ll add (ll a , ll b){
    return (a + b + mod) % mod;
}

template< typename  T > using min_heap = priority_queue <T , vector <T >  , greater < T > > ;
// m n

ll f (ll a ,ll b){
    return (a + b - 1)/ b;
}
ll Fp (ll x  , ll p){
    if (!p) return 1;
    ll v = Fp(x , p/2);
    v = mul(v , v);
    if (p & 1)
        v = mul(x , v);
    return v;
}
int dx [] {0 , 0 , 1 ,-1};
int dy [] {1 ,-1 , 0 , 0};

void main_(int tc){
    ll n , m , k;scanf("%lli%lli%lli" , &n , &m , & k);
    vector < vector <int > > grid(n , vector <int > (m));
    vector < vector <pair <int , int > > > nodes (k+5);
    for (int i = 0; i  < n; ++i){
        for (int j = 0; j < m; ++j){
            scanf("%d" , &grid[i][j]);
            nodes[grid[i][j]].emplace_back(i , j);
        }
    }

    vector < vector < vector <int > > > dist(40+5 , vector <  vector <int > > (n+5 , vector <int > (m+5 , inf)));

    auto v =[&] (pair <int , int > p)-> bool{
        return p.first >=0 && p.second >=0 && p.first <n && p.second < m;
    };


    auto bfs =[&](int c){
       deque <pair <int , int > > q;
       vector < bool > mark(k+5);
       for (auto &i : nodes[c])
           q.emplace_back(i.first , i.second) ,dist[c][i.first][i.second] = 0;
       mark[c] = 1;
       while (!q.empty()){
            auto top = q.front(); q.pop_front();
            if (!mark[grid[top.first][top.second]]){
                mark[grid[top.first][top.second]] =1;
                for (auto &i : nodes[grid[top.first][top.second]]){
                    if (dist[c][i.first][i.second] > dist[c][top.first][top.second]+ 1) {
                        dist[c][i.first][i.second] = 1 + dist[c][top.first][top.second];
                        q.emplace_back(i.first, i.second);
                    }
                }
            }

            for (int i = 0; i < 4; ++i){
                int nr = top.first + dx[i];
                int nc = top.second + dy[i];
                if (!v({nr , nc})) continue;
                if (dist[c][nr][nc] > dist[c][top.first][ top.second]+1){
                    q.emplace_back( nr , nc);
                    dist[c][nr][nc] =dist[c][top.first][top.second]+1;
                }
            }
       }
    };

   for (int i = 1; i <= k; ++i) bfs(i);

    int q ,r1 , c1 , r2 , c2;
    scanf("%d" , &q);
    while (q--){
        scanf("%d%d%d%d" , &r1 , &c1 , &r2 , &c2);--r1 , --r2 , --c1 , --c2;
        int ans = abs(r1-r2) + abs(c1-c2);
        for (int i = 1; i <= k; ++i) ans = min(ans , 1 + dist[i][r1][c1] + dist[i][r2][c2]);
        printf("%d\n" , ans);
        ///cout << ans << nd;
    }



  
}
int main(){
   // ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
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
/*
 * if we dont use cells from the same color the ans = manhattan distance
 * else we will see for from each color what is the min  distance to reach this cell by bfs
 * and  add edge between the two cells from the same color with cost one
 *
 */

