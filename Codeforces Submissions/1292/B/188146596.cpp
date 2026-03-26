#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep3(i,m,n) for(int i=(m);i<(n);i++)
#define foreach(x,a) for(auto& (x) : (a) )

#define endl '\n'
#define dump(x)  cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl

#define pb(a) push_back(a)

#define sz(x) ((int)(x).size())
#define in(a,us) (us).find(a)!=(us).end()

template<typename S>
using Vec = vector<S>;

template<typename S, typename T>
using P = pair<S,T>;

template<typename S, typename T, typename U>
using Tpl = tuple<S,T,U>;

using ll = long long;
using ld = long double;

using Pii = P<int, int>;
using Pll = P<ll,ll>;

using Tiii = Tpl<int,int,int>;
using Tll = Tpl<ll,ll,ll>;

using Vi = Vec<int>;
using VVi = Vec<Vi>;

template<typename S, typename T>
using umap = unordered_map<S,T>;

template<typename S>
using uset = unordered_set<S>;

using Graph = VVi;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll x0,y0,ax,ay,bx,by,xs,ys,t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    ll u = pow(10,16);
    Vec<Pll> data;
    data.push_back({x0,y0});
    while(x0<=u && y0<=u){
        x0 = ax*x0 + bx;
        y0 = ay*y0 + by;
        data.push_back({x0,y0});
    }
    int n = data.size();
    int ans = 0;
    rep(i,n) rep(j,i+1) rep3(k,i,n){
        auto [x,y] = data[i];
        auto [x1,y1] = data[j];
        auto [x2,y2] = data[k];
        ll d = abs(xs-x) + abs(ys-y);
        ll d1 = abs(x-x1) + abs(y-y1);
        ll d2 = abs(x-x2) + abs(y-y2);
        d = min(d+2*d1+d2, d+d1+2*d2);
        if(t>=d) ans = max(ans, k-j+1);
    }
    cout << ans << endl;
}
