//Author: Ankush Bhagat (https://github.com/ankushbhagat124)
//RFIPITIDS
#include <bits/stdc++.h>
#define int long long
const int N = (int)(3e5 + 1);
const int mod = (int)(1e9 + 7);
using namespace std;

void init()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

signed main()
{
    init();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    */

    int n;
    cin >> n;
    vector <int> a(n), t(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : t)
        cin >> x;

    map <int, vector <int>> mp;
    int back = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]].push_back(t[i]);
        back = min(back, a[i]);
    }

    priority_queue <int> pq;
    int sum = 0;
    int ans = 0;

    sort (a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int sz = (int)a.size();

    int i = 0;
    while (i < sz)
    {
        if (back == a[i])
        {
            for (auto x : mp[a[i]])
            {
                pq.push(x);
                sum += x;
            }
            i++;
        }
        if (!pq.empty())
        {
            sum -= pq.top();
            ans += sum;
            pq.pop();
        }
        back++;
    }

    while (!pq.empty())
    {
        sum -= pq.top();
        ans += sum;
        pq.pop();
    }

    cout << ans << endl;
}