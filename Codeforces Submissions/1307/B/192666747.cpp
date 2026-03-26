#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> func(vector<vector<int>> &roads, int x)
{
    int n = roads.size();
    queue<int> q;
    vector<int> dist(n, 1e9);
    q.push(x);
    dist[x] = 0;
    while (q.size())
    {
        int a = q.front(); q.pop();
        int d = dist[a];
        for (int child : roads[a])
        {
            if (dist[child] < 1e9) continue;

            dist[child] = d + 1;
            q.push(child);
        }
    }
    return dist;
}

// long loooooooooooooooong;
void solve(ll kkkk, ll tttt)
{
    int n; cin >> n;
    int x; cin >> x;

    vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    int ans = 1e9 + 70;
    for (int i = 0; i < n; i++)
    {
        if (x % arr[i] == 0)
            ans = min(ans, x / arr[i]);
    }

    int steps = x / arr[0] + 1;
    steps = max(steps, 2);

    cout << min(steps, ans) << endl;
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main()
{
    fast();
//    int t = 0, i = 0;
    int t; cin >> t;
    for (int i = 1; i <= t; i++)

        solve(t, i);
    return 0;
}

