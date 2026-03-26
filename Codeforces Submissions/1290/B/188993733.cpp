#include <bits/stdc++.h>

using namespace std;

using LL = long long;
#define endl '\n'
using db = double;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<vector<int>> pre(n + 1, vector<int>(26));
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1];
        pre[i][s[i] - 'a']++;
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        vector<int> cnt(26);
        for (int i = 0; i < 26; ++i)
            cnt[i] = pre[r][i] - pre[l - 1][i];
        bool ok = 0;
        sort(cnt.begin(), cnt.end(), greater<int>());
        if (cnt[2] > 0 || (cnt[1] > 0 && s[l] != s[r]))
            ok = 1;
        if (ok || r - l + 1 == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}