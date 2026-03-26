// Judges with GCC >= 12 only needs Ofast
// #pragma GCC optimize("O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize")
// MLE optimization
// #pragma GCC optimize("conserve-stack")
// Old judges
// #pragma GCC target("sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2")
// New judges. Test with assert(__builtin_cpu_supports("avx2"));
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// Atcoder
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<> pp(0.0,1.0);
#define int long long
#define ld long double
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second
const int inf=1e18;
const int mod=998244353;
const int mod2=1e9+7;
const int maxn=500005;
const int maxm=200005;
const int maxq=500005;
const int maxl=20;
const int maxa=1000005;
int power(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;n>>=1;
    }
    return res;
}
map<int,vector<int>> mp;
set<int> s,rem;
int n,a[maxn],res[maxn],ans;
void update(int x){
    if(x<=1 || x>n) return;
    if(s.find(x)!=s.end()) s.erase(x);
    else s.insert(x);
}
void cal(int val,int x){
    if(x<=0 || x>n) return;
    auto it=s.upper_bound(x);
    int r=*it-1,l=*prev(it);
    //cout << l << ' ' << r << '\n';
    ans=max(ans,(r-l)/2);
    if(a[l]+a[r]==0) return;
    if(a[l]+a[r]==1){
        if(a[l]) r-=(r-l+1)/2;
        else l+=(r-l+1)/2;
    }
    while(true){
        auto it=rem.lower_bound(l);
        if(it==rem.end() || *it>r) break;
        res[*it]=val;
        rem.erase(it);
    }
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        mp[x].push_back(i);
    }
    for(int i=1;i<=n;i++) rem.insert(i);
    for(int i=1;i<=n+1;i++) s.insert(i);
    for(auto x:mp){
        for(int id:x.se){a[id]=1;update(id);update(id+1);}
        for(int id:x.se){cal(x.fi,id-1);cal(x.fi,id);cal(x.fi,id+1);}
    }
    cout << ans << '\n';
    for(int i=1;i<=n;i++) cout << res[i] << ' ';
    cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int test=1;//cin >> test;
    while(test--) solve();
}
