//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define pii pair <int, int>
#define F first
#define S second
#define int int64_t

using namespace std;

const int N = 2e5+5, M = 1e9+7;

mt19937 gen(chrono::system_clock().now().time_since_epoch().count());

vector<int> g[N];
vector<int> w[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;++i) {
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        w[y].push_back(x);
    }
    int k;
    cin>> k;
    int p[k];
    for (int i=0;i<k;++i) {
        cin >> p[i];
        p[i]--;
    }
    int d[n];
    fill(d,d+n, 100000000);
    d[p[k-1]] = 0;
    queue <int>q;
    q.push(p[k-1]);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for(int i:w[v]) {
            if (d[i] > d[v] + 1) {
                d[i] = d[v]+1;
                q.push(i);
            }
        }
    }
    int mn = 0, mx = 0;
    bool lst = 0;
    for (int i=0;i<k-1;++i) {
        int x = 0, y = 0;
        for (int j:g[p[i]]) {
            if (d[j] < d[p[i+1]]) x++;
            if (d[j] == d[p[i+1]]) y++;
        }
//        cout << x << ' ' << y << '\n';
        if (x > 0) {
            mn += 1;
            mx += 1;
        }
        else {
            if (y > 1 && !lst) {
                mx += 1;
            }
        }
    }
    
    cout<< mn << ' ' << mx;
    return 0;
}
