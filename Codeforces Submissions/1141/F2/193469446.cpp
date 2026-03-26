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
#define positive(x) ((x%mod+mod)%mod)
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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
const int N =2e3+3;
ll Mul(ll x,ll y,ll mod=mod){R((x%mod)*(y%mod))%mod;}
ll Add(ll x,ll y,ll mod=mod){R((x%mod)+(y%mod)+2ll*mod)%mod;}
int n,a[N];
void solve() {
    cin >> n;
    rep(i,n)cin >> a[i];
    map<int,vector<pii>> ma;
    rep(i,n) {
        int sum=0;
        repn(j,i,n) {
            sum += a[j];
            ma[sum].pb({j,i});
        }
    }
    int ans=-1,sum=-1;
    for(auto &it:ma) {
        sort(all(it.S));
        int prv=-1,cot=0;
        for(auto &x:it.S) {
            if(x.S > prv) {
                cot++;
                prv=x.F;
            }
        }
        if(cot > ans) {
            ans = cot;
            sum=it.F;
        }
    }
    int prv=-1;
    vector<pii> v;
    for(auto &x:ma[sum]) {
        if(x.S > prv) {
            v.pb({x.S,x.F});
            prv=x.F;
        }
    }
    cout << v.size() << endl;
    for(auto [l,r]:v)cout<<l+1<<" "<<r+1<<endl;
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
