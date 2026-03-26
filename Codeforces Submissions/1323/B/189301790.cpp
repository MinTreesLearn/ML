#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,fast-math")
using namespace std;
#define int long long

vector <int> a, b;
int ac(int x) {
    int ans = 0;
    int now = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i]) now++;
        else now = 0;
        if (now >= x) ans++;
    }
    return ans;
}
int bc(int x) {
    int ans = 0;
    int now = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) now++;
        else now = 0;
        if (now >= x) ans++;
    }
    return ans;
}
signed main() {
    int n, m;
    cin >> n >> m;
    a.resize(n), b.resize(m);
    int k; cin >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];
    long long answer = 0;
    for (int i = 1; i * i <= k; i++) {
        if (k % i != 0) continue;
        answer += ac(i) * bc(k / i);
        if (i * i != k) answer += ac(k / i) * bc(i);
    }
    cout << answer;
}