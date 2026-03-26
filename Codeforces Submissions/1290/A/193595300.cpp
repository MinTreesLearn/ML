// Akash Singh
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //Make less_equal for multiset
// find_by_order(k)  returns iterator to kth element || order_of_key(k) returns count of elements smaller than k
#define deb(x) cout << x << "\n";
#define deb2(x,y) cout << x << " " << y << "\n";
#define debv(v) for(auto e: v) cout << e << " "; cout << '\n';
#define int long long
#define ll long long
#define mod 1000000007
const int N = 3500;

void solver();
// vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(N+1, -1)));
vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
int func(vector<int> &v, int n, int m, int k, int i, int j, int cur) {
    if(cur == m) {
        return max(v[i], v[j]);
    }
    if(dp[i][cur] != -1) return dp[i][cur];
    int ans;
    if(cur <= k) {
        ans = max(func(v, n, m, k, i+1, j, cur+1), func(v, n, m, k, i, j-1, cur+1));
    }
    else ans = min(func(v, n, m, k, i+1, j, cur+1), func(v, n, m, k, i, j-1, cur+1));

    return dp[i][cur] = ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int KitniBar = 1;
    cin >> KitniBar;

    for(int tc = 1; tc <= KitniBar; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solver();
    }
    return 0;
}
void solver()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
    dp[i][j] = -1;
    
    cout << func(v, n, m, k, 0, n-1, 1) << endl;
}