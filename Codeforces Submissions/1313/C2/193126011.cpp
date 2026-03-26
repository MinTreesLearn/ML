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
const int N =5e5+3;
ll Mul(ll x,ll y,ll mod=mod){R((x%mod)*(y%mod))%mod;}
ll Add(ll x,ll y,ll mod=mod){R((x%mod)+(y%mod)+2ll*mod)%mod;}
int n,a[N],nxt[N],prv[N],dub[N];
ll pre[N],suf[N];
void pr() {
    rep(i,n)prv[i]=-1;
    rep(i,n)nxt[i]=n;
    stack<int> st;
    rep(i,n) {
        while(!st.empty() && a[st.top()] > a[i]) {
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())st.pop();
    repr(i,n-1,0) {
        while(!st.empty() && a[st.top()] > a[i]) {
            prv[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}
/**
2 3 6 2 8 4
2 2 2 2 4 4
0:2+2+2+2+2+2 = 12
1:2+2+2+3+3+2 = 14
2:2+2+2+6+2+3 = 17
3:2+2+2+2+2+2 = 12
4:4+8+2+2+2+2 = 20
5:4+2+2+2+2+4 = 16
*/
void solve() {
    cin >> n;
    rep(i,n)cin>>a[i];
    pr();
    rep(i,n)dub[i]=1;
    rep(i,n) {
        int z = nxt[i];
        pre[i] += 1ll*dub[i]*a[i];
        pre[z] -= 1ll*dub[i]*a[i];
        dub[z] += dub[i];
        if(i)pre[i] += pre[i-1];
    }
    rep(i,n)dub[i]=1;
    repr(i,n-1,0) {
        int z = prv[i];
        suf[i] += 1ll*dub[i]*a[i];
        if(z>=0) {
            suf[z] -= 1ll*dub[i]*a[i];
            dub[z] += dub[i];
        }
        if(i<n-1) suf[i] += suf[i+1];
    }
    ll z=0;
    rep(i,n) Max(z,pre[i] += suf[i]-a[i]);
    vector<int> ans(n);
    rep(i,n) {
        if(pre[i] == z) {
            int mn = a[i];
            repr(j,i,0) {
                Min(mn,a[j]);
                ans[j] = mn;
            }
            mn = a[i];
            repn(j,i,n) {
                Min(mn,a[j]);
                ans[j] = mn;
            }
            for(auto it:ans)cout<<it<<" ";cout<<endl;
            R;
        }
    }

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
