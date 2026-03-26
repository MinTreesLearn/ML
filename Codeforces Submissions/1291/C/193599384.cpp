#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <atcoder/all>
// using namespace atcoder;
using namespace __gnu_pbds;
using namespace std;
using uns = unsigned;
using ll = long long;
using ld = long double;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using vc = std::vector<char>;
using vvc = std::vector<vc>;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using vld = std::vector<ld>;
using vvld = std::vector<vld>;
using vvvld = std::vector<vvld>;
using pll = std::pair<ll, ll>;
using vpll = std::vector<pll>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;
using vu = std::vector<uns>;
using vs = std::vector<std::string>;
using ordered_set = tree<pll, null_type, std::less<pll>, rb_tree_tag, tree_order_statistics_node_update>;

#define siz(x) (ll) x.size()
#define all(v) (v).begin(), (v).end()

#ifdef DEBUG
#include "dbg.hpp"
#else
#define err(...)
#define deb(...)
#endif

const ll mod = 998244353;
//using mint = modint998244353;
const ll maxN = 1e5+5;
void run_brute(){
    //cout<<"\n................\n";
}
template<class T> inline T POW(T a,ll n){
    T r=1;
    for (; n>0; n>>=1,a*=a){
         if (n&1)r*=a;
    } 
    return r;
}
inline ll POW(int a,ll n){ return POW((ll)a,n); }

template<class T> vector<T> powers(T m,ll n){
	vector<T> ret(n+1,1);
	for (ll i=1;i<=n;++i) ret[i]=ret[i-1]*m;
	return ret;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{   
    ll n,m,k;
    cin>>n>>m>>k;
    vll nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }    


    if(m==1){
        cout<<max(nums[0],nums.back())<<"\n";
        return;
    }

    vvll dp(n+1,vll(n+1,LLONG_MIN));

    // dp[i][j] -> max coin i can get from [i,j]

    //  can choose k people

    // 0 to choose first then
    // min(dp[0][n-m],dp[1][n-1-(m-1)]...........dp[m][n-1-m])

    // 1 to choose first then
    // min(dp[1][(n-1)-(m-1)],dp[2][(n-1)-(m-2)].........dp[m][n-1-m])
    
    // 2 to choose first then
    // min(dp[3][n-m+2],dp[4][n-m+3]..........dp[m][n-m+1],dp[m+1][n-m])

    // 3 to choose first
    // min(dp[4][n-m+3],dp[5][n-m+4]..........dp[m][n-m+1],dp[m+1][n-m])

    // k to choose
    // min(dp[k][(n-1)-m+k],.....dp[m][n-1-m])


    // if(k>=m){
    //     ll ans = LLONG_MAX;
    //     for(int i=0;i<=m;i++){
    //         ans = min(ans,dp[i][n-1-(m-i)]);
    //     }
    //     cout<<ans<<"\n";
    //     return;
    // }
    
    ll ans  = 0;
    k = min(k, m-1);
    m--;
    for(int i=0;i<=k;i++){
        // i people front,k-i people back
        ll rem = m-k;
        ll cur = LLONG_MAX;
        for(int j=0;j<=rem;j++){
            // now need to choose m-k people
            // j people front,rem-j people back
            // i+j front,rem-j+k-i back
            // i+j,m-k-j+k-i
            // i+j,m-j-i
         //  err(i+j,n-1-(m-j-i));
            ll l = i+j;
            ll r = n-1-(m-i-j);
            err(i,j,l,r);
            cur = min(cur,max(nums[l],nums[r]));
        }
        err(cur,i);
        ans = max(ans,cur);
    }
    cout<<ans<<"\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;

    //cout << fixed << setprecision(20);
    cin >> t;
    // precompute(105);
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
       // run_brute();
    }
    return 0;
}