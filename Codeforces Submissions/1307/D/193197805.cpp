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
const int mod = 1e9+9;
const int N =2e5+3;
ll Mul(ll x,ll y,ll mod=mod){R((x%mod)*(y%mod))%mod;}
ll Add(ll x,ll y,ll mod=mod){R((x%mod)+(y%mod)+2ll*mod)%mod;}
int n,m,k,a[N];
vector<vector<int>> gr;
int dist[2][N],ans;
vector<int> v;
void bfs(int src,int en) {
    queue<int> q;
    q.push(src);
    rep(i,n+1)dist[en][i]=INF;
    dist[en][src]=0;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(auto it:gr[top]) {
            if(dist[en][top]+1 < dist[en][it]) {
                dist[en][it] = dist[en][top]+1;
                q.push(it);
            }
        }
    }
    rep(i,n) if(a[i+1] && en) v.pb(dist[en][i+1]);
}
void solve() {
    cin >> n >> m >> k;
    rep(i,k) {
        int x;cin>>x;
        a[x]=1;
    }
    gr.resize(n+1);
    rep(i,m) {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    bfs(n,1);
    sort(all(v));
    bfs(1,0);
    int ans=0;
    repn(i,1,n+1) {
        if(!a[i])C;
        int it = dist[1][i];
        int z = lower_bound(all(v),it)-v.begin();
        if(v[z] > it)z--;
            if(z>=0 && v[z]==it) {
                if(z+1<v.size() && v[z+1] == it)
                    Max(ans,min(dist[0][n],dist[0][i]+1+v[z]));
                else {
                    z--;
                    if(z>=0)
                        Max(ans,min(dist[0][n],dist[0][i]+1+v[z]));
                }
            }else if(z >= 0) {
                Max(ans,min(dist[0][n],dist[0][i]+1+v[z]));
            }
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
