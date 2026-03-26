#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <math.h>
#include <assert.h>
 
using namespace std;
#define int ll
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
const ll MAXN = 1e3 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
 
#define fast_io     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io     freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb          push_back
#define F           first
#define S           second
#define Sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define cl          clear()
#define endll       '\n'

int n, m, k, lcp[MAXN][MAXN], dp[MAXN][MAXN], ps[MAXN][MAXN];
string s;
vector<pii> vec;

inline bool cmp(pii a, pii b){
    int l = lcp[a.F][b.F];
    if (a.F + l > a.S && b.F + l > b.S) return a.F + a.S < b.F + b.S;
    if (a.F + l > a.S) return 1;
    if (b.F + l > b.S) return 0;
    return s[a.F + l] < s[b.F + l];
}

inline bool valid(pll p){
    int l = p.F, r = p.S;
    dp[n][0] = 1;
    for (int i = 0; i <= n; i++) ps[i][0] = 1;
    for (int i = n; i >= 0; i --){
        ll x = -1;
        if (lcp[l][i] > r - l) x = i + r - l + 2;
        else if (s[l + lcp[l][i]] <= s[i + lcp[l][i]]) x = i + lcp[l][i] + 1;
        for (int j = 1; j <= m; j ++){
            dp[i][j] = 0;
            if (x != -1) dp[i][j] = ps[x][j - 1];
            ps[i][j] = dp[i][j] + ps[i + 1][j];
            if (ps[i][j] > INF) ps[i][j] = INF;
        }
    }
    return dp[0][m] < k;
}

int32_t main(){
    fast_io;
    cin >> n >> m >> k;
    cin >> s;
    s += '0';
    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            vec.pb({i, j});
        }
    }
    sort(all(vec), cmp);
    int l = -1, r = Sz(vec);
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if (valid(vec[mid])) r = mid;
        else l = mid;
    }
    for (int i = vec[r].F; i <= vec[r].S; i++) cout << s[i];
}