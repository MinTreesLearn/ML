#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <set>
#include <limits.h>
#include <assert.h>
#define ll long long
#define endl '\n'
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;
const int N = 1e5 + 10, md = 1e9 + 7, M = 1e7 + 10;
void pre()
{
}
bool cmp(pair<ll, vector<ll>> &x, pair<ll, vector<ll>> &y)
{
    return x.first > y.first;
}
int n, p, k;
pair<ll, vector<ll>> player[N];
ll dp[2][8][1 << 7];
void solve()
{
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> player[i].first;
    }
    for (int i = 1; i <= n; i++)
    {
        player[i].second = vector<ll>(p);
        for (auto &j : player[i].second)
        {
            cin >> j;
        }
    }
    sort(player + 1, player + n + 1, cmp);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<player[i].first<<' ';
    //     for(auto j:player[i].second) cout<<j<<' ';
    //     cout<<endl;
    // }
    for (int i = 0; i <= p; i++)
    {
        for (int j = 0; j < (1 << p); j++)
        {
            dp[1][i][j] = dp[0][i][j] = -1e17;
        }
    }
    int cur = 0;
    dp[cur][0][0] = 0;
    for (int idx = 1; idx <= n; idx++)
    {
        for (int aud = 0; aud <= p; aud++)
        {
            for (int mask = 0; mask < (1 << p); mask++)
            {
                if (idx <= k)
                {
                    dp[1 - cur][aud][mask] = max(dp[1 - cur][aud][mask], dp[cur][aud][mask] + player[idx].first);
                }
                else
                {
                    dp[1 - cur][max(0, aud - 1)][mask] = max(dp[1 - cur][max(0, aud - 1)][mask], dp[cur][aud][mask] + (aud ? player[idx].first : 0));
                }
                for (int j = 0; j < p; j++)
                {
                    if ((mask & (1 << j)) == 0)
                    {
                        dp[1 - cur][aud + bool(idx <= k)][(mask | (1 << j))] = max(dp[1 - cur][aud + bool(idx <= k)][(mask | (1 << j))], dp[cur][aud][mask] + player[idx].second[j]);
                    }
                }
            }
        }
        cur = 1 - cur;
    }
    cout << dp[cur][0][(1 << p) - 1] << endl;
}
int main()
{
    pre();
    fast;
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
}
  				  			   		 				  	 	 			