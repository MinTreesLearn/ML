#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key ------> return index
// find_by_order -----> use index

#define ll long long
#define ull unsigned long long
#define ld long double
#define dl double
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f first
#define s second
#define pb push_back
#define el '\n'
#define INF 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define ones(x) __builtin_popcountll(x)
#define memss(a, b, sz) memset(arr,b,sz * sizeof (arr[0]))
#define ii pair<int,int>

int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};

const int mod = 1e9 + 7, N = 1e5 + 9, mod2 = 998244353, M = 1e4 + 5;
const ld eps = 1e-10;
ll n,p,k,dp[N][1 << 7],a[N],s[N][7];
vector<pair<int,int>>t;
ll solve(int i,int cnt,int msk) {
     if(i == n) {
         return (msk == (1 << p) - 1) ? 0 : -1e18;

     }
     ll & ans = dp[i][msk];
     if(~ans)
         return ans;
     ans = solve(i + 1,cnt,msk);
    for (int l = 0; l < 7; ++l) {
          if(msk & (1 << l))
              continue;
          ans = max(ans, solve(i + 1,cnt + 1, msk | (1 << l)) + s[t[i].s][l]);
    }
    if(i < (cnt + k))
        ans = max(ans, solve(i + 1 ,cnt + 1 ,msk) + t[i].f);
    return ans;
}

void set_ans(int Case)  {
    ::memset(dp,-1,sizeof dp);

    cin >> n >> p >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        t.pb({a[i],i});
    }
    sort(allr(t));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            cin >> s[i][j];
        }
    }
    ll ans = 0;
  //  sort(all(t));
    ans = solve(0,0,0);
    cout << ans << el;

}


int main() {
    io
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int testCases = 1;
 //   cin >> testCases;
    for (int Case = 1; Case <= testCases; Case++)
        set_ans(Case);
    return 0;
}
  		 	 	  		 	   	 	 		  	   		