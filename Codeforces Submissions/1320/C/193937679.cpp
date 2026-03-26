#include<bits/stdc++.h>
#define ll long long
#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
#define all(a) (a).begin() , (a).end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<pii,int>
#define plll pair<pll,ll>
#define R return
#define B break
#define C continue
#define SET(n , i) memset(n , i , sizeof(n))
#define SD ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i , n) for(int i = 0 ; i < n ; i++)
#define repn(i , j , n) for(int i = j ; i < n ; i++)
#define repr(i,n,j) for(int i=n;i>=j;i--)
#define posi(x) ((x%mod+mod)%mod)
#define YES(f)cout<<((f)?"YES":"NO")<<endl
#define F first
#define S second
#define endl '\n'
#define vi vector<int>
//#define int ll
using namespace std;
void readFromFile(string input = "input.txt",string output="output.txt") {
    #ifndef ONLINE_JUDGE
        freopen(input.c_str(),"r",stdin);
        freopen(output.c_str(),"w",stdout);
    #endif
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll x, ll y) {
    return uniform_int_distribution<ll>(x, y)(rng);
}
template <typename T> void Max(T& x,T y){x=max(x,y);}
template <typename T> void Min(T& x,T y){x=min(x,y);}
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-3;
const long double pi =  acos(-1.0);
const int mod = 998244353;
const int N =2e5+3;
ll Mul(ll x,ll y,ll mod=mod){R((x%mod)*(y%mod))%mod;}
ll Add(ll x,ll y,ll mod=mod){R((x%mod)+(y%mod)+2ll*mod)%mod;}
int n,m,p;
pii a[N],b[N];
piii dr[N];
struct ST {
    ll tree[1<<21],lazy[1<<21];
    void build(int st=1,int en=1e6,int idx=0) {
        lazy[idx]=0;
        if(st==en) {
            auto z = lower_bound(b,b+m,mp(st,-1))-b;
            if(z != m)tree[idx] = -b[z].S;
            else tree[idx] = -INFLL;
        }else {
            int mid=st+(en-st)/2, lf=2*idx+1,rt=2*idx+2;
            build(st,mid,lf);
            build(mid+1,en,rt);
            tree[idx] = max(tree[lf],tree[rt]);
        }
    }
    void laz(int st,int en,int idx) {
        if(lazy[idx]==0) return;
        tree[idx] += lazy[idx];
        if(st != en) {
            int lf=2*idx+1,rt=2*idx+2;
            lazy[lf] += lazy[idx];
            lazy[rt] += lazy[idx];
        }
        lazy[idx]=0;
    }
    void update(int qs,int qe,int val,int st=1,int en=1e6,int idx=0) {
        laz(st,en,idx);
        if(st > qe || en < qs) R ;
        if(st >= qs && en <= qe) {
            lazy[idx] += val;
            laz(st,en,idx);
            return;
        }
        int mid=st+(en-st)/2, lf=2*idx+1,rt=2*idx+2;
        update(qs,qe,val,st,mid,lf);
        update(qs,qe,val,mid+1,en,rt);
        tree[idx] = max(tree[lf],tree[rt]);
    }
    ll query(int qs,int qe,int st=0,int en=n-1,int idx=0) {
        laz(st,en,idx);
        R tree[idx];
    }
}sg;
void solve() {
    cin >> n >> m >> p;
    rep(i,n)cin >> a[i].F >> a[i].S;
    rep(i,m)cin >> b[i].F >> b[i].S;
    rep(i,p) cin >> dr[i].F.F >> dr[i].F.S >> dr[i].S;
    sort(a,a+n);
    sort(b,b+m);
    sort(dr,dr+p);
    repr(i,n-2,0) {
        Min(a[i].S,a[i+1].S);
    }
    repr(i,m-2,0) {
        Min(b[i].S,b[i+1].S);
    }
    sg.build();
    ll ans=-a[0].S-b[0].S;
    int l=0;
    rep(i,p) {
        sg.update(dr[i].F.S+1,1e6,dr[i].S);
        while(l < n && a[l].F <= dr[i].F.F)l++;
        if(l == n)B;
        Max(ans,-a[l].S+sg.query(1,1e6));
    }
    cout << ans << endl;
}
int32_t main() {
    readFromFile();
    SD;
    int t = 1;
//    cin >> t;
//    scanf("%d",&t);
    rep(i,t) {
        solve();
    }
}
