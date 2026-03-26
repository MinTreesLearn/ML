//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define pii pair <int, int>
#define F first
#define S second
#define int int64_t

using namespace std;

const int N = 8e5+5, M = 1e9+7;

mt19937 gen(chrono::system_clock().now().time_since_epoch().count());

int f[N];

int get (int r) {
    int ans = 0;
    while (r > 0) {
        ans = max(ans, f[r]);
        r = ((r+1)&r)-1;
    }
    return ans;
}

void upd (int p, int x) {
    while (p < N) {
        f[p] = max(f[p],x);
        p = ((p+1)|p);
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int k[N] = {0};
    for (int i=0;i<n;++i) {
        cin >> a[i];
        k[a[i]-i+400000]+=a[i];
    }
    int ans = 0;
    for (int i=0;i<N;++i) {
        ans = max(ans, k[i]);
    }
    cout << ans;
    return 0;
}
