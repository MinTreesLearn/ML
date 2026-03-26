//______________"In The Name Of GOD"______________

#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;


const int lg        = 20;
const int mod       = 1e9 + 7;
const ll  inf       = 2e18 + 100;
const int maxn      = 1e3 + 100;
    

#define cl       	clear
#define F        	first
#define S       	second
#define pb       	push_back
#define Sz(x)    	int((x).size())
#define all(x)   	(x).begin(), (x).end()

ll lcp[maxn][maxn], ps[maxn][maxn], dp[maxn][maxn], n, m, k;
string s;
vector <pii> vec;

inline bool cmp(pii a, pii b){
    ll len = lcp[a.F][b.F];
    char c = ' ', d = ' ';
    if (a.F + len <= a.S) c = s[a.F + len];
    if (b.F + len <= b.S) d = s[b.F + len];
    if (c == ' ' && d == ' ') return a.S - a.F < b.S - b.F;
    return c < d;
}

inline ll cal(ll l, ll r){
    dp[n][0] = 1;
    for (int i = 0; i <= n; i ++) ps[i][0] = 1;
    for (int i = n; i >= 0; i --){
        ll x = -1;
        if (lcp[l][i] > r - l) x = i + r - l + 2;
        else if (s[l + lcp[l][i]] <= s[i + lcp[l][i]]) x = i + lcp[l][i] + 1;
        for (int j = 1; j <= m; j ++){
            dp[i][j] = 0;
            if (x != -1) dp[i][j] = ps[x][j - 1];
            ps[i][j] = dp[i][j] + ps[i + 1][j];
            if (ps[i][j] > inf) ps[i][j] = inf;
        }
    }
    return dp[0][m];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    cin >> s;
    s += ' ';
    lcp[n][n] = 0;
    for (int i = n; i >= 0; i --){
        for (int j = n; j >= 0; j --){
            lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
        }
    }
    for (int i = 0; i < n; i ++){
        for (int j = i; j < n; j ++) vec.pb({i, j});
    }
    sort(all(vec), cmp);
    ll l = -1, r = Sz(vec);
    while(r - l > 1){
        ll mid = (l + r) / 2;
        if (cal(vec[mid].F, vec[mid].S) < k) r = mid;
        else l = mid;
    }
    for (int i = vec[r].F; i <= vec[r].S; i ++) cout << s[i];
    cout << '\n';
    return 0;
}

/*test case :

*/