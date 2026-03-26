#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
#define int long long
const int N = 1e7 + 10;
int T, n = 0, m, k, l;
const int mod = 998244353;
#define ll long long
#define endl '\n'
bool flag = false;
int cnt = 0;
#define endl '\n'
int ans = 0, p;
int d;
int qp(int a, int b) {
    int res = 1;
    int q = a;
    while (b) {
        if (b & 1) {
            res *= q; res %= mod;

        }
        b >>= 1;
        q *= q;
        q %= mod;

    }
    return res;
}
void solve()
{
    int h, r;
    cin >> n >> h >> l >> r; vector<int>a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    int t = 0;
    vector<vector<int>>dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; i - j >= 0; j++) {
            int time = t - j;
            int k = 0; time += a[i];
            if (time % h >= l && time % h <= r) {
                k=1;
            }
            dp[i+1][j] = max(dp[i][j] + k,dp[i+1][j]);
            time--;
            if (time % h >= l && time % h <= r) {
                k = 1;
            }
            else k = 0;
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]+k);
        }
        t+= a[i];
    }
    
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
    
}


signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    T = 1;
    //cin >> T;


    while (T--)solve();


}
