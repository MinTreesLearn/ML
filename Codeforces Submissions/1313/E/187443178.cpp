#include <bits/stdc++.h>
using namespace std;

/*
    Given L, r, l, R, m
    find number of ordered pair (i, j) such that
        L <= i <= r
        l <= j <= R
        i >= j
        (i - L + 1) + (R - j + 1) = m

    Since:	    i - L + 1 + R - j + 1 = m <=> i = (m - 2 + L - R) + j
    It follows:	L <= (i = X + j) <= r
                l + X <= (i = X + j) <= R + X
                (where X = m-2+L-R )
    So the number of pairs would be the number of i sastifying:
                max(L, l+X) <= i <= min(r, R+X)
    But because i >= j
                X must be non-negative
                m-2+L-R >= 0 or L + m - 2 >= R

    Therefore, naive algorithm could be:
        long long ans = 0;
        for (int L = 0; L < n; L++) {
            for (int R = L; R <= min(n - 1, L + m - 2); R++) {
                int r = L + pre[L] - 1;
                int l = R - suf[R] + 1;
                int X = m - 2 + L - R;
                ans += max(0, min(r, R + X) - max(L, l + X) + 1);
            }
        }

    HmmmmmmmMMMmmMmmMmmMm
    for each L, we need to find F(L)
        where F(L) := Σmax(0, min(r, m - 2 + L) - max(L, L + m - 2 + l - R) + 1)       for R = [L, min(n - 1, L + m - 2)]
        since suf[R] = R - l + 1, so we can have l - r as 1 - suf[R]
        F(L) := Σmax(0, min(r, m - 2 + L) - max(L, L + m - 1 - suf[R]) + 1)
        F(L) := Σmax(0, min(r, m - 2 + L) - (max(L - L - m + 1, -suf[R]) + L + m - 1) + 1)
        F(L) := Σmax(0, min(r, m - 2 + L) - max(1 - m, -suf[R]) - L - m + 2)
        F(L) := Σmax(0, min(r, m - 2 + L) + min(m - 1, suf[R]) - L - m + 2)
        let C = min(r, m - 2 + L) - L - m + 2
        F(L) := Σmax(0, C + min(m - 1, suf[R]))

        from here on, only consider R in range [L, min(n - 1, L + m - 2)]
        for those suf[R] > m - 1, then it'd be max(0, C + m - 1)
            then contribution be: cnt(m, INF).max(0, C + m - 1)
        for those suf[R] <= m - 1, then it'd be max(0, C + suf[R])
            only when C + suf[R] >= 0 or suf[R] >= -C
            that means those suf[R] in range [-C, m - 1]
            then contribution be: cnt(-C, m - 1).C + sum(-C, m - 1)
*/

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
