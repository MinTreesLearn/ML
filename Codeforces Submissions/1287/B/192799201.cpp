#include <iostream>
#include <utility>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>
#include <array>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#include <sstream>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define First cout<<"First"<<endl
#define Second cout<<"Second"<<endl
#define lll __int128
#define int long long
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#define lb(x) (x &-x)
const int N = 100;
vector<vector<int>>dp(N, vector<int>(N, -1));
int ncr(int n, int r)
{
    if (n == r)return 1;
    if (r == 1)return n;
    if (dp[n][r] != -1)return dp[n][r];
    return dp[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
}
long double power(long  double x, int y)
{
    if (y == 0)return 1;
    long double k = power(x, y / 2);
    return k * k * (y & 1 ? x : 1);
}
long double pr(int n)
{
    return ncr(70, n) * power(10.00/70, n) * (power(60.00 / 70, 70 - n));
}
void solver()
{
    int n, k;
    cin>>n>>k;
    int ans = 0;
    map<string, int>mp;string s[n] = {};
    for (int i = 0; i < n and cin>>s[i]; i ++)mp[s[i]] ++;
    for (int i = 0; i < n; i ++)
    {
        mp[s[i]] --;
        for (int j = i + 1; j < n; j ++)
        {
            mp[s[j]] --;
            string s1, s2;
            for (int l = 0; l < k; l ++)
            {
                if (s[i][l] == s[j][l])s1.push_back(s[i][l]);
                else
                {
                    string b = "SET";
                    for (char ch : b)if (s[i][l] != ch && s[j][l] != ch)s1.push_back(ch);
                }
            }
            if (mp.find(s1) != mp.end())ans += mp[s1];
        }
        for (int j = i + 1; j < n; j ++)mp[s[j]] ++;
    }
    cout<<ans<<endl;
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0);cout.tie(0);
   //freopen("outputcut2.in", "r", stdin);
    int t;t = 1;
    while (t --)
    {
        solver();
    }
}
