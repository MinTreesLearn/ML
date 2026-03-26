#include <bits/stdc++.h>

#define Source ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define int long long
#define ld long double
#define Endl '\n'
//#define t int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sz(a) (int)(a).size()
using namespace std;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int dp[N][3];
int freq[3];

int mul(int x, int y) {
    return ((x % mod) * (y % mod)) % mod;
}

int sum(int x, int y) {
    return ((x % mod) + (y % mod)) % mod;
}


void testCase(int cs) {
    int n;
    cin >> n;
    vector<int>v(n - 1);
    int mn = 0, sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> v[i];
        sum += v[i];
        mn = min(mn, sum);
    }
    vector<int>ans(n);
    ans[0] = 1 - mn; // 1 - mn + mn ==> 1
    set<int>st;
    st.insert(ans[0]);
    for (int i = 0; i < n - 1; ++i) {
        ans[i + 1] = ans[i] + v[i];
        st.insert(ans[i + 1]);
    }
    if(sz(st) != n)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if(ans[i] < 1 || ans[i] > n)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] <<" ";
    }
    cout << endl;
}

signed main() {
    // files();
    Source
    ll t = 1;
    int cs = 0;
//    cin >> t;
    while (t--) {
        testCase(++cs);
    }
    return 0;
}