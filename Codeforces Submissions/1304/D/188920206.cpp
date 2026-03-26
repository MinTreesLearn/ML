#include <bits/stdc++.h>

using namespace std;

using LL = long long;
#define endl '\n'
using db = double;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto work = [&](string s) -> vector<int>
    {
        s += '>';
        vector<int> a;
        for (int i = 0, last = -1; i < n; ++i)
        {
            if (s[i] == '>')
            {
                for (int j = n - i; j <= n - last - 1; ++j)
                    a.push_back(j);
                last = i;
            }
        }
        return a;
    };
    auto ans = work(s);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    for (int i = 0; i < s.size(); ++i)
        s[i] = '>' + '<' - s[i];
    ans = work(s);
    for (auto x : ans)
        cout << n - x + 1 << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}