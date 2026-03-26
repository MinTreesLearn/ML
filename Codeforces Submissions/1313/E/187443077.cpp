#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, long long delta) {
        for (i++; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }
    long long sum(int i) {
        long long res = 0;
        for (i++; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }
    long long sum(int l, int r) {
        l = max(0, l);
        return sum(r) - sum(l - 1);
    }
};

vector<int> calcBasedZ(string base, string text) {
    string s = base + '#' + text;
    int n = s.length();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (r < i + z[i] - 1) r = i + z[i] - 1, l = i;
    }
    vector<int> res((int)text.size());
    for (int i = (int)base.size() + 1; i < n; i++) {
        res[i - (int)base.size() - 1] = z[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string a, b, s;
    cin >> a >> b >> s;

    vector<int> pre = calcBasedZ(s, a);
    string rs = s, rb = b;
    reverse(rs.begin(), rs.end());
    reverse(rb.begin(), rb.end());
    vector<int> suf = calcBasedZ(rs, rb);
    reverse(suf.begin(), suf.end());

    long long ans = 0;
    int toAdd = 0, toDel = 0;
    Fenwick cnt(m + 1), sum(m + 1);

    for (int L = 0; L < n; L++) {
        while (toAdd <= min(n - 1, L + m - 2)) {
            cnt.add(suf[toAdd], 1);
            sum.add(suf[toAdd], suf[toAdd]);
            toAdd++;
        }
        while (toDel < L) {
            cnt.add(suf[toDel], -1);
            sum.add(suf[toDel], -suf[toDel]);
            toDel++;
        }

        int r = L + pre[L] - 1;
        int C = min(r, m - 2 + L) - L - m + 2;

        ans += cnt.sum(-C, m - 1) * C + sum.sum(-C, m - 1);
        ans += cnt.sum(m, m) * max(0, C + m - 1);
    }
    cout << ans << "\n";
}
