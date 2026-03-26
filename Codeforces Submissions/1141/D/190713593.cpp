#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> a(26);
        vector<vector<int>> b(26);
        vector<int> qa;
        vector<int>qb;
        int n;
        string x, y;
        cin >> n >> x >> y;
        for (int i = 0; i < n; i++) {
                if (x[i] == '?') qa.push_back(i + 1);
                else a[x[i] - 'a'].push_back(i + 1);
                if (y[i] == '?') qb.push_back(i + 1);
                else b[y[i] - 'a'].push_back(i + 1);
        }
        vector<pair<int, int>> ans;
        vector<int> sa;
        vector<int> sb;
        int z;
        for (int i = 0; i < 26; i++) {
                z = min((int)a[i].size(), (int)b[i].size());
                for (int j = 0; j < z; j++) {
                        ans.push_back({a[i].back(), b[i].back()});
                        a[i].pop_back();
                        b[i].pop_back();
                }
                for (auto z : a[i]) sa.push_back(z);
                for (auto z : b[i]) sb.push_back(z);
        }
        z = min((int)sa.size(), (int)qb.size());
        for (int i = 0; i < z; i++) {
                ans.push_back({sa.back(), qb.back()});
                sa.pop_back();
                qb.pop_back();
        }
        z = min((int)qa.size(), (int)sb.size());
        for (int i = 0; i < z; i++) {
                ans.push_back({qa.back(), sb.back()});
                qa.pop_back();
                sb.pop_back();
        }
        z = min((int)qa.size(), (int)qb.size());
        for (int i = 0; i < z; i++) {
                ans.push_back({qa.back(), qb.back()});
                qa.pop_back();
                qb.pop_back();
        }
        cout << ans.size() << '\n';
        for (auto [l, r] : ans) {
                cout << l << " " << r << '\n';
        }
}