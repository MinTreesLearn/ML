#include<bits/stdc++.h>

#define ll long long
#define pp push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
#define ld long double
#define PI acos(-1)
#define sin(a) sin((a)*PI/180)
#define cos(a) cos((a)*PI/180)
#define ones(x) __builtin_popcountll(x)
//#define int ll

#define Drakon  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


unsigned long long inf = 1e10;
const double EPS = 1e-6;
const int MOD = 1000000007, N = 3505, LOG = 25, M = 2;

typedef array<array<int, M>, M> matrix;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int dp[N][N],n, m, k, arr[N], tar;

int slv(int l, int r, int cnt) {
    if (cnt == m - 1) {
        return max(arr[l],arr[r]);
    }

    int &ret = dp[l][r];
    if (~ret)
        return ret;

    ret = min(slv(l + 1, r, cnt + 1), slv(l, r - 1, cnt + 1));
    return ret;
}


void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i + j > k)break;
            ans = max(ans, slv(i,n-1-j,i + j));
        }
    }
    cout << ans << endl;
}

signed main() {
    Drakon
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}