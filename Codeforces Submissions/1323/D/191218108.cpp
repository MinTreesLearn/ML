#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define dbg(x...) do { cout << #x << " -> "; err(x); } while(0);
#define  tententen ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
#define all(A) A.begin(), A.end()
typedef pair<int, int> pt;
const int N = 5e5+10;
#define int ll 
#define double long double
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll mod=1e9 + 7;
void err() { cout << endl;}
template<class T, class... Ts>
void err(const T &arg, const Ts &... args) {cout << arg << ' ';err(args...);}
ll ksm(ll a, ll b) {ll ans = 1;while (b > 0) {if (b & 1) {ans = ans * a ;}a = a * a ;b >>= 1;}return ans;}
inline ll Add(ll x,ll y){x+=y;return(x<mod)?x:x-mod;}
inline ll Dec(ll x,ll y){x-=y;return(x<0)?x+mod:x;}
inline ll Mul(ll x,ll y){return(x*y%mod);}
/*
两数之和，k位为1 成立的数的范围
[(1<<k)-x, (1<<(k+1))-x )

*/
int a[N],t[N];
void solve() {
    int n;
    cin>>n;
    vector<int> cnt(32,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        t[i]=a[i];
    }
    // sort(a+1,a+1+n);
    for(int k=0;k<=30;++k){
        for(int i=1;i<=n;++i){
            a[i]=t[i]%(1<<(k+1));
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;++i){
            int mn=(1<<k)-a[i],mx=(1<<(k+1))-a[i];
            cnt[k]+=((upper_bound(a+i+1,a+n+1,mx-1)-lower_bound(a+i+1,a+n+1,mn))&1);
            mn=(1<<(k+1))+(1<<k)-a[i],mx=(1<<(k+2))-a[i];
            cnt[k]+=((upper_bound(a+i+1,a+n+1,mx-1)-lower_bound(a+i+1,a+n+1,mn))&1);

        }
    }
    // cout<<"dd"<<endl;
    int ans=0;
    for(int i=0;i<29;++i){
        if(cnt[i]&1){
            ans+=(1<<i);
        }
        // dbg(ans);

    }
    cout<<ans<<endl;



}
signed main(){
    tententen;
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}