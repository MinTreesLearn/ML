#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll base = 37;//进制
const ll mod = 998244353;//质数
const int inf = 1e9+5;
const int maxn = 2e5+5;
const ll linf = 1e18+5ll;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>v(n+1);
    for(int i = 1;i<=n;i++)
    {
        cin>>v[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,inf));
    vector val = dp;
    for(int i = 1;i<=n;i++)
    {
        dp[i][i] = 1;
        val[i][i] = v[i];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int s = 1;i+s<=n+1;s++)
        {
            int t = i+s-1;
            for(int k = s+1;k<=t;k++)
            {
                if(dp[s][k-1] == 1 && dp[k][t] == 1 && val[s][k-1]==val[k][t])
                {
                    dp[s][t] = 1;
                    val[s][t] = val[s][k-1] + 1;
                }
                else
                {
                    dp[s][t] = min (dp[s][t] , dp[s][k-1]+dp[k][t]);
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
}  

