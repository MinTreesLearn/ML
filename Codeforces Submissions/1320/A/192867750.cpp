#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(a)  -> gives index of the element(number of elements smaller than a)
// find_by_order(a) -> gives the element at index a
#define accelerate ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int        long long int
#define ld         long double
#define mod1       998244353
#define endl       "\n"
#define ff         first
#define ss         second
#define all(x)     (x).begin(),(x).end()
#define ra(arr,n)  vector<int> arr(n);for(int in = 0; in < n; in++) {cin >> arr[in];}

const int mod = 1e9 + 7;
const int inf = 1e18;
int MOD(int x) {int a1 = (x % mod); if (a1 < 0) {a1 += mod;} return a1;}
int power( int a,  int b) {
    int p = 1; while (b > 0) {if (b & 1)p = (p * a); a = (a * a)  ; b >>= 1;}
    return p;
}
int go(int ind, vector<int>&arr, vector<vector<int>>&dp, int x)
{
    if (ind == arr.size())return 0;
    if (dp[ind][x] != -1)return dp[ind][x];
    if (x == arr.size())
    {
        return dp[ind][x] = max(arr[ind] + go(ind + 1, arr, dp, ind), go(ind + 1, arr, dp, x));
    }
    if (arr[ind] - arr[x] == ind - x)
    {
        return dp[ind][x] = max(arr[ind] + go(ind + 1, arr, dp, ind), go(ind + 1, arr, dp, x));
    }
    return dp[ind][x] = go(ind + 1, arr, dp, x);
}
void lessgoo()
{
    int n;
    cin >> n;
    ra(arr, n);
    int ans = 0;
    map<int, int>mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i] - i] += arr[i];
        ans = max(ans, mp[arr[i] - i]);
    }
    cout << ans << endl;


}

signed main()
{
    accelerate;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    // cin >> test;
    for (int tcase = 1; tcase <= test; tcase++)
    {
        // cout << "Case #" << tcase << ": ";
        lessgoo();

    }
    return 0;
}

