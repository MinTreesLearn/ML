/// Author : Nguyễn Thái Sơn - Ti20 - THPT chuyên Lương Thế Vinh
/// Training VOI 2023

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//#include <ext/rope>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")

//using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

#define fi first
#define se second
#define TASK "test"
#define pb push_back
#define EL cout << endl
#define Ti20_ntson int main()
#define in(x) cout << x << endl
#define all(x) (x).begin(),(x).end()
#define getbit(x, i) (((x) >> (i)) & 1)
#define cntbit(x) __builtin_popcount(x)
#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FORD(i,l,r) for (int i = l; i >= r; i--)
#define Debug(a,n) for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> vii;
typedef unsigned long long ull;
typedef vector<vector<int>> vvi;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

const int N = 2e4 + 5;
const int oo = INT_MAX;
const int mod = 1e9 + 7;
const int d4x[4] = {-1, 0, 1, 0} , d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, a[55][N], m, k;
ll dp[55][N];

inline void Read_Input() {
    cin >> n >> m >> k;
    FOR(i, 1, n)
        FOR(j, 1, m) {
            cin >> a[i][j];
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
        }
}

int Get(int x, int y, int xx, int yy) {
    return a[xx][yy] - a[x - 1][yy] - a[xx][y - 1] + a[x - 1][y - 1];
}

struct Segment_Tree {
    ll st[4 * N + 5], lz[4 * N + 5];

    void build(int id, int l, int r, int cur) {
        lz[id] = 0;
        if (l == r) {
            st[id] = dp[cur][l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid, cur);
        build(id * 2 + 1, mid + 1, r, cur);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    void Down(int id) {
        if (lz[id] == 0)
            return;
        lz[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id];
        st[id * 2] += lz[id];
        st[id * 2 + 1] += lz[id];
        lz[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v) {
            st[id] += val;
            lz[id] += val;
            return;
        }
        int mid = (l + r) >> 1;
        Down(id);
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    ll Get(int id, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (l >= u && r <= v)
            return st[id];
        Down(id);
        int mid = (l + r) >> 1;
        return max(Get(id * 2, l, mid, u, v), Get(id * 2 + 1, mid + 1, r, u, v));
    }

}it;

inline void Solve() {
    const int mx = m - k + 1;
    ll Ans = 0;
    FOR(i, 1, mx)
        dp[1][i] = Get(1, i, 1, i + k - 1);
    if (n > 1)
        FOR(i, 1, mx)
            dp[1][i] += Get(2, i, 2, i + k - 1);
    FOR(i, 2, n) {
        it.build(1, 1, mx, i - 1);
        int val = Get(i, 1, i, k);
        FOR(j, 1, k) {
            it.update(1, 1, mx, j, j, -val),
            val -= Get(i, j, i, j);
        }
        FOR(j, 1, mx) {
            dp[i][j] = it.st[1] + Get(i, j, i, j + k - 1);
            if (i != n)
                dp[i][j] += Get(i + 1, j, i + 1, j + k - 1);
            if (j != mx) {
//                cout << "CHECK " << j << endl;
                int l = max(1, j - k + 1);
//                cout << "UPDATE " << l << " " << j << " " << Get(i, j, i, j) << endl;
                it.update(1, 1, mx, l, j, Get(i, j, i, j));
                int cur = j + k;
                cur = Get(i, cur, i, cur);
                int r = min(mx, j + k);
                it.update(1, 1, mx, j + 1, r, -cur);
//                cout << "UPDATE " << j + 1 << " " << r << " " << -cur << endl;
//                FOR(k, 1, mx)
//                    cout << it.Get(1, 1, mx, k, k) << " "; cout << endl;
            }
        }
//        FOR(j, 1, mx)
//            cout << dp[i][j] << " \n"[j == mx];
    }
    cout << *max_element(dp[n] + 1, dp[n] + mx + 1);
}

Ti20_ntson {
//    freopen(TASK".INP","r",stdin);
//    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
//    cin >> T;
    while (T -- ) {
        Read_Input();
        Solve();
    }
}

