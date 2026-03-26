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
const ll N = 4e5+500 , LOG = 22 , inf = 1e8 , SQ= 550 , mod= 1e9+7;//998244353;
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

void hi(int tc) {
   ll n; cin >> n;
    string a , b; cin >> a >> b;
    map <char , vector <int > > aa , bb;
    for (int i = 0; i < n; ++i){
        aa[a[i]].emplace_back(i);
        bb[b[i]].emplace_back(i);
    }
    vector <pair <int , int > > ans;

    for (char i = 'a'; i <= 'z'; ++i){
        while (!aa[i].empty() && !bb[i].empty()){
            ans.emplace_back(aa[i].back() , bb[i].back());
            aa[i].pop_back();
            bb[i].pop_back();
        }
        char c = '?';
        while (!aa[c].empty() && !bb[i].empty()){
            ans.emplace_back(aa[c].back() , bb[i].back());
            aa[c].pop_back();
            bb[i].pop_back();
        }
        while (!bb[c].empty() && !aa[i].empty()){
            ans.emplace_back(aa[i].back() , bb[c].back());
            aa[i].pop_back();
            bb[c].pop_back();
        }
    }
    char c = '?';
    while (!bb[c].empty() && !aa[c].empty()){
        ans.emplace_back(aa[c].back() , bb[c].back());
        aa[c].pop_back();
        bb[c].pop_back();
    }
    cout << (int)ans.size() << endl;
    for (auto &i : ans) cout << i.first+1 <<" "<<i.second+1<<nd;


}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int tt = 1 , tc = 0;
  //cin >> tt;
    while(tt--) hi(++tc);
    return 0;
}
