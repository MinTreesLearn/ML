#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>

#define int long long
#define ll long long
#define II pair<int, int>
#define fs first
#define sc second
#define endl '\n'

const double PI = 3.141592653589793238;
const long long LINF = 1ll << 60;
const int INF = 1 << 30;
const int N = 8e5 + 10;

using namespace std;

int n, m = 0;
II a[N];
int c[N], pre[N];
int nxt[N], cum[N];

void compress() {
    m = 0;
    for(int i = 1; i <= n; i++) {
        c[++m] = a[i].fs; 
        c[++m] = a[i].sc; 
    }

    sort(c + 1, c + m + 1);
    m = unique(c + 1, c + m + 1) - c - 1;

    for(int i = 1; i <= n; i++) {
        a[i].fs = lower_bound(c + 1, c + m + 1, a[i].fs) - c;
        a[i].sc = lower_bound(c + 1, c + m + 1, a[i].sc) - c;

        a[i].fs *= 2;
        a[i].sc *= 2;
    }
    m = m * 2;
}

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fs >> a[i].sc;
    }

    compress();

    for(int i = 1; i <= max(n, m) + 10; i++) {
        pre[i] = nxt[i] = cum[i] = 0;
    }

    int mn = INF, mx = 0;
    for(int i = 1; i <= n; i++) {
        pre[a[i].fs]++;
        pre[a[i].sc + 1]--;

        mn = min(mn, a[i].fs);
        mx = max(mx, a[i].sc);
    }

    for(int i = 1; i <= m; i++) pre[i] += pre[i - 1];
    

    int last = m + 1;
    for(int i = m; i >= 1; i--) {
        if(pre[i] == 1) {
            if(last > i + 1) cum[i]++;
            nxt[i] = last;
            last = i;
        }
    }

    for(int i = 1; i <= m; i++) cum[i] += cum[i - 1];

    int cnt = 1;
    for(int i = mn; i <= mx; i++) {
        if(pre[i] != pre[i - 1] && pre[i] == 0) cnt++; 
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int val = cum[a[i].sc] - cum[a[i].fs - 1];
        if(pre[a[i].fs] == 1 && pre[a[i].fs - 1] == 0) val--;
        if(pre[a[i].sc] == 1 && pre[a[i].sc + 1] == 0) val--;
        ans = max(ans, val);
    }


    cout << min(ans + cnt, n - 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}